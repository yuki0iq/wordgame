// wordgame.cpp: ���������� ����� ����� ��� ����������� ����������.
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
		"WORDGAME ������� -\n"
		"���� � ����� (� ������� ���� ������ � ������ � ��������� ��� ����������)\n"
		"����� ���� ����� ���������: �����\n"
		"    'list.wgc' ������,\n"
		"    'list.wgw' �����,\n"
		"    'list.wgp' �����   <--- ��� ����� ���������,\n"
		"                            ������� ����� � ����� � ����� ������\n"
		"\n"
		"����� ��������� ���� �����, ������� 0\n"
		"����� ��������� ����, ������� 'exit' � ����\n"
		"����� �������, ������� 'giveup' � ����\n"
		"\n"
		"  ������ �����: (������ �����, 1 - �� ���������)\n"
		"1 ����� � ������*\n"
		"2 ������ ������\n"
		"3 ��������� ��� ���������� (����������)\n"
		"    *������ - ������� ����������� ������ �� �������� ���� � ������� �����\n"
		"��� �����: ";
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
		puts("\n\n������� ������!");
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
	if(a == '�' || a == '�') a = word[strlen(word)-2];
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
		puts("� ����! ���� ���� ���������!!");
		puts("������, ��� ������� � ������ ���� ���");
		puts("��������� �������: ����� �� ����������, ������ � ���� ���������, ������ �� ������");
		puts("���� ���������.. ���������� ���� �� ��������� ����� ��� ������ �� ��� � ����");
		puts("����� ������ ������� ������ ��� �������");
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
	/*������ ����: ����� - ����� - ���� - ��������� - ������ - ...*/
	char word[500], prev[500];
	int wsize = words.size();
	played_ids.resize(wsize);
	int tempnum = rand() % wsize;
	played_ids[tempnum] = true;
	printf("����: %s\n", words[tempnum].c_str());
	strcpy(prev, words[tempnum].c_str());
	while(true)
	{
		//������� ����� �����, ����� ����
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
				puts("����� �� ��������: �� �� �������");
				continue;
			}
			if(isBlacklisted(word))
			{
				puts("����� �� ��������: ���� ������������");
				continue;
			}
			if(words.end() == find_(words.begin(), words.end(), word))
			{
				puts("����� �� ��������: ��� � ���� ����");
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
			puts("�� ���������� ����, ����������!");
			goto end;
		}
		played_ids[temp.second] = true;
		printf("����: %s\n", temp.first.c_str());
		strcpy(prev, temp.first.c_str());
	}

giveup:
	puts("���... �� ��������");
end:
	system("pause");
	system("cls");
}
