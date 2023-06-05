/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingsForm
{
public:
    QGroupBox *groupBox;
    QCheckBox *showFirstLetter;
    QPushButton *saveBtn;
    QPushButton *closeBtn;
    QGroupBox *groupBox_2;
    QCheckBox *statsTime;
    QCheckBox *statsEntered;
    QCheckBox *statsWins;
    QPushButton *resetStats;
    QPushButton *showStats;
    QGroupBox *groupBox_3;
    QLabel *label;
    QGroupBox *groupBox_4;
    QComboBox *gameMode;
    QLabel *label_2;
    QGroupBox *groupBox_5;
    QPushButton *exportSettings;
    QPushButton *importSettings;

    void setupUi(QDialog *SettingsForm)
    {
        if (SettingsForm->objectName().isEmpty())
            SettingsForm->setObjectName(QStringLiteral("SettingsForm"));
        SettingsForm->resize(469, 230);
        SettingsForm->setMinimumSize(QSize(469, 230));
        SettingsForm->setMaximumSize(QSize(469, 230));
        SettingsForm->setModal(true);
        groupBox = new QGroupBox(SettingsForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 221, 51));
        showFirstLetter = new QCheckBox(groupBox);
        showFirstLetter->setObjectName(QStringLiteral("showFirstLetter"));
        showFirstLetter->setGeometry(QRect(10, 20, 191, 18));
        saveBtn = new QPushButton(SettingsForm);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));
        saveBtn->setGeometry(QRect(300, 200, 77, 25));
        closeBtn = new QPushButton(SettingsForm);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setGeometry(QRect(380, 200, 77, 25));
        groupBox_2 = new QGroupBox(SettingsForm);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(240, 70, 221, 121));
        statsTime = new QCheckBox(groupBox_2);
        statsTime->setObjectName(QStringLiteral("statsTime"));
        statsTime->setGeometry(QRect(11, 21, 54, 18));
        statsEntered = new QCheckBox(groupBox_2);
        statsEntered->setObjectName(QStringLiteral("statsEntered"));
        statsEntered->setGeometry(QRect(11, 45, 145, 18));
        statsWins = new QCheckBox(groupBox_2);
        statsWins->setObjectName(QStringLiteral("statsWins"));
        statsWins->setGeometry(QRect(11, 69, 64, 18));
        resetStats = new QPushButton(groupBox_2);
        resetStats->setObjectName(QStringLiteral("resetStats"));
        resetStats->setGeometry(QRect(90, 90, 71, 23));
        showStats = new QPushButton(groupBox_2);
        showStats->setObjectName(QStringLiteral("showStats"));
        showStats->setGeometry(QRect(10, 90, 75, 23));
        groupBox_3 = new QGroupBox(SettingsForm);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 130, 221, 81));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 191, 51));
        groupBox_4 = new QGroupBox(SettingsForm);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(240, 10, 221, 51));
        gameMode = new QComboBox(groupBox_4);
        gameMode->setObjectName(QStringLiteral("gameMode"));
        gameMode->setGeometry(QRect(79, 21, 131, 20));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(11, 21, 60, 16));
        groupBox_5 = new QGroupBox(SettingsForm);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 70, 221, 51));
        exportSettings = new QPushButton(groupBox_5);
        exportSettings->setObjectName(QStringLiteral("exportSettings"));
        exportSettings->setGeometry(QRect(10, 20, 101, 23));
        importSettings = new QPushButton(groupBox_5);
        importSettings->setObjectName(QStringLiteral("importSettings"));
        importSettings->setGeometry(QRect(110, 20, 101, 23));

        retranslateUi(SettingsForm);
        QObject::connect(saveBtn, SIGNAL(clicked()), SettingsForm, SLOT(accept()));
        QObject::connect(closeBtn, SIGNAL(clicked()), SettingsForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(SettingsForm);
    } // setupUi

    void retranslateUi(QDialog *SettingsForm)
    {
        SettingsForm->setWindowTitle(QApplication::translate("SettingsForm", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 WordGame", 0));
        groupBox->setTitle(QApplication::translate("SettingsForm", "\320\237\320\276\320\264\321\201\320\272\320\260\320\267\320\272\320\270", 0));
        showFirstLetter->setText(QApplication::translate("SettingsForm", "\320\237\320\276\320\272\320\260\320\267\321\213\320\262\320\260\321\202\321\214 \320\277\320\265\321\200\320\262\321\203\321\216 \320\261\321\203\320\272\320\262\321\203 \321\201\320\273\320\276\320\262\320\260", 0));
        saveBtn->setText(QApplication::translate("SettingsForm", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        closeBtn->setText(QApplication::translate("SettingsForm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0));
        groupBox_2->setTitle(QApplication::translate("SettingsForm", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", 0));
        statsTime->setText(QApplication::translate("SettingsForm", "\320\222\321\200\320\265\320\274\321\217", 0));
        statsEntered->setText(QApplication::translate("SettingsForm", "\320\232\320\276\320\273-\320\262\320\276 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\321\213\321\205 \321\201\320\273\320\276\320\262", 0));
        statsWins->setText(QApplication::translate("SettingsForm", "\320\237\320\276\320\261\320\265\320\264\321\213", 0));
        resetStats->setText(QApplication::translate("SettingsForm", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214", 0));
        showStats->setText(QApplication::translate("SettingsForm", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", 0));
        groupBox_3->setTitle(QApplication::translate("SettingsForm", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0));
        label->setText(QApplication::translate("SettingsForm", "WordGame \320\240\321\203\321\201\321\201\320\272\320\270\320\271, \320\262\320\265\321\200\321\201\320\270\321\217 1.0\n"
"Open Source \320\277\321\200\320\276\320\265\320\272\321\202\n"
"\320\241\320\264\320\265\320\273\320\260\320\275\320\276 \320\262 \320\240\320\276\321\201\321\201\320\270\320\270 (2018 \320\263\320\276\320\264)\n"
"\320\230\321\201\320\277\320\276\320\273\321\214\320\267\321\203\320\265\321\202 Qt 5.2.1", 0));
        groupBox_4->setTitle(QApplication::translate("SettingsForm", "\320\230\320\263\321\200\320\260", 0));
        gameMode->clear();
        gameMode->insertItems(0, QStringList()
         << QApplication::translate("SettingsForm", "\320\241\320\273\320\276\320\262\320\260 \320\270 \320\263\320\265\320\276\320\263\321\200. \320\275\320\260\320\267\320\262.", 0)
         << QApplication::translate("SettingsForm", "\320\223\320\265\320\276\321\200\320\260\321\204\320\270\321\207. \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\217", 0)
        );
        label_2->setText(QApplication::translate("SettingsForm", "\320\240\320\265\320\266\320\270\320\274 \320\270\320\263\321\200\321\213", 0));
        groupBox_5->setTitle(QApplication::translate("SettingsForm", "\320\236\321\201\320\275\320\276\320\262\320\275\320\276\320\265", 0));
        exportSettings->setText(QApplication::translate("SettingsForm", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272", 0));
        importSettings->setText(QApplication::translate("SettingsForm", "\320\230\320\274\320\277\320\276\321\200\321\202 \320\275\320\260\321\201\321\202\321\200\320\276\320\265\320\272", 0));
    } // retranslateUi

};

namespace Ui {
    class SettingsForm: public Ui_SettingsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
