// wordgame.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>
using namespace std;

char *greeting =
		"WORDGAME РУССКИЙ -\n"
		"игра в слова (с режимом игры только в города и программы для компьютера)\n"
		"Запас слов можно пополнить: файлы\n"
		"    'list.wgc' города,\n"
		"    'list.wgw' слова,\n"
		"    'list.wgp' проги   <--- эти файлы изменяйте,\n"
		"                            добавяя слова в конец с новой строки\n"
		"\n"
		"Чтобы завершить игру ЗДЕСЬ, введите 0\n"
		"Чтобы ВЕРНУТЬСЯ сюда, введите 'exit' в игре\n"
		"Чтобы СДАТЬСЯ, введите 'giveup' в игре\n"
		"\n"
		"  Выбери режим: (напиши цифру, 1 - по умолчанию)\n"
		"1 Слова и города*\n"
		"2 Только города\n"
		"3 Программы для компьютера (английский)\n"
		"    *города - немного расширенная версия со странами мира и частями света\n"
		"Ваш выбор: ";
char *citiespath = "list.wgc"
	, *wordspath = "list.wgw"
	, *prognamepath = "list.wgp";

vector<bool> played_ids;
vector<string> words;

pair<string,int> findWord(char startsWith = ' ');
void Game(int mode = 1);
template<class InputIt, class T> InputIt find_(InputIt first, InputIt last, const T& value)
{
    for (; first != last; ++first) {
        if (0 == strcmp((*first).c_str(), value)) {
            return first;
        }
    }
    return last;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, ".1251");

	int ch = '\0';
	while(true)
	{
	loop_begin:
		printf(greeting);
		ch = getche();
		if(ch == '0') goto loop_end;
		puts("\n\nДавайте начнем!");
		Game(ch - '0');
		system("cls");
		goto loop_begin;
		loop_end: break;
	}

	return 0;
}

pair<string,int> findWord(char startsWith)
{
	for(int i = 0; i < words.size(); ++i)
	{
		if(played_ids[i]) continue;
		if(words[i][0] == startsWith) return make_pair(words[i], i);
	}
	return make_pair("", 0);
}

void __load(FILE* pf)
{
	char buf[500];
	while(!feof(pf))
	{
		memset(buf, 0, 500);
		fgets(buf, 499, pf);
		char *p = strrchr(buf, '\n');
		if(p) *p = '\0';
		words.push_back(buf);
	}
}
char endsWith(char* word)
{
	char a = word[strlen(word)-1];
	if(a == 'ь' || a == 'ы') a = word[strlen(word)-2];
	return a;
}
#define startsWith(word) (word[0])
bool isBlacklisted(string word)
{
	int id = 0;
	for(; id < words.size(); ++id)
		if(0 == strcmp(words[id].c_str(), word.c_str()))
			break;
	return played_ids[id];
}

void Game(int mode)
{
	words.clear();
	FILE *pFile = fopen(mode == 1 ? wordspath : (mode == 2 ? citiespath : prognamepath), "r");
	if(pFile == 0)
	{
		puts("О неет! База слов сломалась!!");
		puts("Похоже, что доступа к списку слов нет");
		puts("Возможные причины: файла не существует, доступ к нему ограничен, защита от чтения");
		puts("Эххх неповезло.. Восстанови базу из резервной копии или сделай ее сам с нуля");
		puts("Имена файлов найдешь сверху при запуске");
		goto end;
	}
	__load(pFile);
	fclose(pFile);
	if(mode == 1)
	{
		pFile = fopen(citiespath, "r");
		__load(pFile);
		fclose(pFile);
	}

	//Now we have a word base....
	//let's trace it (for debug only!)
	/*for(int i = 0; i < words.size(); ++i)
		printf("%s\n", words[i].c_str());*/

	//Sooo... the game will START!!!
	/*Пример игры: арбуЗ - ЗагаР - РозА - АмстердаМ - МолокО - ...*/
	char word[500], prev[500];
	int wsize = words.size();
	played_ids.resize(wsize);
	int tempnum = rand() % wsize;
	played_ids[tempnum] = true;
	printf("Комп: %s\n", words[tempnum].c_str());
	strcpy(prev, words[tempnum].c_str());
	while(true)
	{
		//Сначала ходит ИГРОК, затем КОМП
		//PLAYER
		while(true)
		{
			int CP = GetConsoleCP();
			gets(word);
			SetConsoleCP(CP);
			for(int i = 0; i < 500; ++i) tolower(word[i]);
			if(0 == strcmp(word, "exit"))
				goto end;
			if(0 == strcmp(word, "giveup"))
				goto giveup;
	printf("DEBUG: prev %s word %s ends %i%c starts %i%c\n", prev, word, endsWith(prev), endsWith(prev), startsWith(word), startsWith(word));
			if(endsWith(prev) != startsWith(word))
			{
				puts("Слово не подходит: не по цепочке");
				continue;
			}
			if(isBlacklisted(word))
			{
				puts("Слово не подходит: было использовано");
				continue;
			}
			if(words.end() == find_(words.begin(), words.end(), word))
			{
				puts("Слово не подходит: нет в базе слов");
				continue;
			}
			break;
		}
		for(int id = 0; id < words.size(); ++id)
			if(0 == strcmp(words[id].c_str(), word))
			{
				played_ids[id] = true;
				break;
			}
		strcpy(prev, word);

		//PC
		pair<string, int> temp = findWord(endsWith(prev));
		if(0 == strcmp(temp.first.c_str(), ""))
		{
			puts("Ну поздравляю теюя, победитель!");
			goto end;
		}
		played_ids[temp.second] = true;
		printf("Комп: %s\n", temp.first.c_str());
		strcpy(prev, temp.first.c_str());
	}

giveup:
	puts("Эхх... ты проиграл");
end:
	system("pause");
	system("cls");
}
