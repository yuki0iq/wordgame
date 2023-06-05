#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "ui_settings.h"

struct stg_data
{
	bool Hints_ShowFirstLetter;

	bool Stats_Time;
	bool Stats_EnteredWords;
	bool Stats_Wins;

	enum enum_game_mode { Game_Mode_Words, Game_Mode_GeoNames } Game_Mode;
};

class Settings : public QDialog, public Ui::SettingsForm
{
	Q_OBJECT;

public:
	Settings(QWidget *parent = 0);
	~Settings();

public slots:
	void on_saveBtn_clicked();
	void on_closeBtn_clicked();
	void on_resetStats_clicked();
	void on_showStats_clicked();

signals:
	void sig_resetStats();
	void sig_showStats();
};

#endif // SETTINGS_H
