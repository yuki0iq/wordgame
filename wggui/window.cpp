#include "window.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

extern stg_data SettingsData;

QString a(char *in)
{
	return QString::fromLocal8Bit(in);
}

char endsWith(QString word)
{
	char a = word.toLower().toLocal8Bit().data()[word.size()-1];
	if(a == 'ь' || a == 'ы') a = word.toLower().toLocal8Bit().data()[word.size()-2];
	return a;
}
char startsWith(QString word)
{
		return word.toLower().toLocal8Bit().data()[0];
}
#define err(msg) QMessageBox::critical(this, a("WordGame Ошибка"), msg, QMessageBox::Ok);
bool sortStrI(QString aaa, QString bbb)
{
	return (stricmp(aaa.toLower().toLocal8Bit().data(), bbb.toLower().toLocal8Bit().data()) < 0);
}

Window::Window(QWidget *parent)
	: QMainWindow(parent)
	, stg(new Settings)
{
	ui.setupUi(this);
	srand((quint32)time(0));
	vecWords.resize(32);

	QObject::connect(stg, SIGNAL(sig_resetStats()), this, SLOT(resetStats()));
	QObject::connect(stg, SIGNAL(sig_showStats()), this, SLOT(showStats()));

	resetStats();
	CCC = true;
}

Window::~Window()
{

}


/*****/
bool searchPred(const pair<QString, bool> &x) {return !x.second;}

void Window::on_textInput_returnPressed()
{
	//PLAYER
	now = ui.textInput->text();
	if(now == QString())
	{
		err(a("Слово не подходит: слово не введено"));
		return;
	}
	if(endsWith(prev) != startsWith(now))
	{
		err(a("Слово не подходит: не по цепочке"));
		return;
	}
	pair<QString, bool>* nnn;
	bool found = false, found2 = false;
	for(int i = 0; i < getVecByLetter(startsWith(now)).size(); ++i)
	{
		nnn = &getVecByLetter(startsWith(now))[i];
		if(now.toLower() == nnn->first.toLower())
		{
			found = true;
			if(!nnn->second)
			{
				nnn->second = found2 = true;
				break;
			}
		}
	}
	if(!found) //can't find word
	{
		int iRes = QMessageBox::warning(this,
			a("WordGame Русский"),
			a("В словаре такого слова нет. Добавить слово или желаете ввести другое?"),
			QMessageBox::Yes, QMessageBox::No);
		if(iRes == QMessageBox::Yes)
		{
			iRes = QMessageBox::information(this,
				a("WordGame Русский"),
				a("Как добавить слово - как географическое название(да) или как обычное слово(ок)?"),
				QMessageBox::Yes, QMessageBox::Ok);
			//MIAO MI tv channel (Chinese)
			getVecByLetter(startsWith(now)).push_back(pair<QString, bool>(now, true));
			FILE *pFile = 0;
			if(iRes == QMessageBox::Yes)
				pFile = fopen("list.wgc", "a");
			else if(iRes == QMessageBox::Ok)
				pFile = fopen("list.wgw", "a");

			if(!pFile)
			{
				err(a("Сломалась база слов!"));
				return;
			}
			fprintf(pFile, "\n%s", now.toLocal8Bit().data());
			fclose(pFile);

			goto __aaa__;
		}
		return;
	}
	if(!found2) //word was used
	{
		err(a("Слово не подходит: было использовано"));
		return;
	}
__aaa__:

	addWord(now);
	EnteredWords++;
	ui.textInput->setText("");

	//COMPUTER
	pair<QString, bool> *bbb;
	/*bool NoSuchWord = true;
	for(int i = 0; i < getVecByLetter(endsWith(prev)).size(); ++i)
	{
		bbb = &getVecByLetter(endsWith(prev))[i];
		if(!bbb->second)
		{
			NoSuchWord = false;
			bbb->second = true;
			break;
		}
	}*/
	
	//if(NoSuchWord)
	if(find_if(getVecByLetter(endsWith(prev)).begin(),
		getVecByLetter(endsWith(prev)).end(), searchPred) ==
		getVecByLetter(endsWith(prev)).end())
	{
		QMessageBox::information(this,
			a("WordGame Русский"),
			a("Ну поздравляю теюя, победитель!"),
			QMessageBox::Ok);
		Wins++;
		EnteredWords = 0;
		Seconds = 0;
		return;
	}

	//Now I can safely use this loop because
	//we know there's at least one word that
	//we need to write.
	while(true)
	{
		int i = rand() % getVecByLetter(endsWith(prev)).size();
		bbb = &getVecByLetter(endsWith(prev))[i];
		if(!bbb->second)
		{
			bbb->second = true;
			break;
		}
	}

	addWord(bbb->first);
	if(SettingsData.Hints_ShowFirstLetter)
	{
		char *str = new char[2];
		str[1] = 0;
		str[0] = endsWith(bbb->first);
		ui.textInput->setText(QString::fromLocal8Bit(str));
		delete str;
	}
}

void Window::on_textBtn_pressed()
{
	on_textInput_returnPressed();
}

void Window::on_startGame_pressed()
{
	addText("<hr>");
	CCC = true;
	EnteredWords = 0;
	Seconds = 0;
	vecWords.clear();
	vecWords.resize(33);

	//Load cities
	FILE *pFile = fopen("list.wgc", "r");
	if(!pFile)
	{
		err(a("Сломалась база слов!"));
		return;
	}
	char buf[500];
	while(!feof(pFile))
	{
		memset(buf, 0, 500);
		fgets(buf, 499, pFile);
		char *p = strrchr(buf, '\n');
		if(p) *p = '\0';
		QString jjj = a(buf);
		char iii = jjj.toLower().toLocal8Bit().data()[0];
		getVecByLetter(iii).push_back(make_pair(jjj, false));
	}

	if(SettingsData.Game_Mode == stg_data::Game_Mode_Words)
	{
		//Load words
		pFile = freopen("list.wgw", "r", pFile);
		if(!pFile)
		{
			err(a("Сломалась база слов!"));
			return;
		}
		while(!feof(pFile))
		{
			memset(buf, 0, 500);
			fgets(buf, 499, pFile);
			char *p = strrchr(buf, '\n');
			if(p) *p = '\0';
			QString jjj = a(buf);
			char iii = buf[0];
			getVecByLetter(iii).push_back(make_pair(jjj, false));
		}
	}
	fclose(pFile);

	int templ = rand() % 26, tempnum = rand() % getVecByLetter(templ + 'а').size();
	addWord(getVecByLetter(templ + 'а')[tempnum].first);
	getVecByLetter(templ + 'а')[tempnum].second = true;
	if(SettingsData.Hints_ShowFirstLetter)
	{
		char *str = new char[2];
		str[1] = 0;
		str[0] = templ + 'а';
		ui.textInput->setText(QString::fromLocal8Bit(str));
		delete str;
	}
}

void Window::on_settingsBtn_pressed()
{
	stg->exec();
}
