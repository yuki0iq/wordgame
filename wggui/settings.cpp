#include "settings.h"

stg_data SettingsData = { false, false, false, false, stg_data::Game_Mode_Words };

Settings::Settings(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

Settings::~Settings()
{

}

void Settings::on_saveBtn_clicked()
{
	SettingsData.Hints_ShowFirstLetter = showFirstLetter->isChecked();
	SettingsData.Stats_Time = statsTime->isChecked();
	SettingsData.Stats_EnteredWords = statsEntered->isChecked();
	SettingsData.Stats_Wins = statsWins->isChecked();
	SettingsData.Game_Mode = (stg_data::enum_game_mode)gameMode->currentIndex();
}

void Settings::on_closeBtn_clicked()
{
	close();
}

void Settings::on_resetStats_clicked()
{
	emit sig_resetStats();
}

void Settings::on_showStats_clicked()
{
	emit sig_showStats();
}
