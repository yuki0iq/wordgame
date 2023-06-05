#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QScrollBar>
#include <QString>
#include <algorithm>
#include <utility>
#include <vector>
#include <math.h>
#include "ui_window.h"
#include "settings.h"

QString a(char *in);

class Window : public QMainWindow
{
	Q_OBJECT;

public:
	Window(QWidget *parent = 0);
	~Window();

	void addText(QString text)
	{
		QString aaa = ui.textEdit->toHtml();
		aaa.insert(aaa.size()-14, text);
		ui.textEdit->setHtml(aaa);
	}
	void addWord(QString word__)
	{
		char *arr = new char[word__.size()+1];
		memset(arr, 0, word__.size()+1);
		memcpy(arr, word__.toLocal8Bit().data(), word__.size());
		QString word = a(arr);
		word.insert(0, CCC?"<font color=\"red\">":"");
		word.append(CCC?"</font>":"");
		CCC = !CCC;
		addText(word);

		QScrollBar *aaa = ui.textEdit->verticalScrollBar();
		aaa->setValue(aaa->maximum());
		prev = word__;
	}
	std::pair<QString, bool> __find(std::vector<std::pair<QString, bool>>& vec, const QString& item)
	{
		for(int i = 0; i < vec.size(); ++i)
			if(vec[i].first == item)
				return vec[i];
		return std::pair<QString, bool>(QString(), false);
	}

	std::vector<std::pair<QString, bool>>& getVecByLetter(int a)
	{
		int b = (unsigned char)'а';
		return vecWords[abs((unsigned char)a - b)];
	}

public slots:
	void on_textInput_returnPressed();
	void on_textBtn_pressed();
	void on_startGame_pressed();
	void on_settingsBtn_pressed();

	void resetStats()
	{
		EnteredWords = 0;
		Wins = 0;
		Seconds = 0;
	}
	void showStats()
	{
		QMessageBox::information(stg, a("WordGame Русский - Статистика"),
			a("Ваша статистика:\nВремя: %1 секунд\nВведенные слова: %2\nВыигрыши: %3")
				.arg(Seconds)
				.arg(EnteredWords)
				.arg(Wins));
	}

private:
	Ui::WindowClass ui;
	std::vector<std::vector< std::pair<QString, bool> >> vecWords;
	QString now, prev;
	bool CCC;
	Settings *stg;

	unsigned EnteredWords;
	unsigned Wins;
	unsigned Seconds;
};

#endif // WINDOW_H
