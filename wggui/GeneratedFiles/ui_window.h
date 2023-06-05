/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *startGame;
    QPushButton *settingsBtn;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *textInput;
    QPushButton *textBtn;

    void setupUi(QMainWindow *WindowClass)
    {
        if (WindowClass->objectName().isEmpty())
            WindowClass->setObjectName(QStringLiteral("WindowClass"));
        WindowClass->resize(417, 298);
        centralWidget = new QWidget(WindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        startGame = new QPushButton(centralWidget);
        startGame->setObjectName(QStringLiteral("startGame"));

        horizontalLayout_2->addWidget(startGame);

        settingsBtn = new QPushButton(centralWidget);
        settingsBtn->setObjectName(QStringLiteral("settingsBtn"));

        horizontalLayout_2->addWidget(settingsBtn);

        horizontalLayout_2->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textInput = new QLineEdit(centralWidget);
        textInput->setObjectName(QStringLiteral("textInput"));

        horizontalLayout->addWidget(textInput);

        textBtn = new QPushButton(centralWidget);
        textBtn->setObjectName(QStringLiteral("textBtn"));

        horizontalLayout->addWidget(textBtn);


        verticalLayout->addLayout(horizontalLayout);

        WindowClass->setCentralWidget(centralWidget);

        retranslateUi(WindowClass);

        QMetaObject::connectSlotsByName(WindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *WindowClass)
    {
        WindowClass->setWindowTitle(QApplication::translate("WindowClass", "WordGame \320\240\321\203\321\201\321\201\320\272\320\270\320\271", 0));
        label->setText(QApplication::translate("WindowClass", "\320\230\321\201\321\202\320\276\321\200\320\270\321\217 \321\201\320\273\320\276\320\262: (\320\275\320\276\320\262\321\213\320\265 \320\262 \320\272\320\276\320\275\321\206\320\265)", 0));
        startGame->setText(QApplication::translate("WindowClass", "\320\235\320\260\321\207\320\260\321\202\321\214 \321\201\320\275\320\260\321\207\320\260\320\273\320\260", 0));
        settingsBtn->setText(QApplication::translate("WindowClass", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        textEdit->setHtml(QApplication::translate("WindowClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; font-style:italic;\">WordGame </span><span style=\" font-size:8pt; font-weight:600; font-style:italic; color:#ffffff; background-color:#000000;\">\320\240\321\203</span><span style=\" font-size:8pt; font-weight:600; font-style:italic; color:#0000ff; background-color:#000000;\">\321\201\321\201</span><span style=\" font-size:8pt; font-weight:600; font-style:italic; color:#ff0000; background-color:#000000;\">\320\272\320\270\320\271 </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px"
                        "; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#ff0000;\">\320\241\320\273\320\276\320\262\320\276 \320\272\320\276\320\274\320\277\320\260 </span><span style=\" font-size:8pt; color:#000000;\">\320\222\320\260\321\210\320\265 \321\201\320\273\320\276\320\262\320\276</span></p></body></html>", 0));
        textInput->setText(QString());
        textBtn->setText(QApplication::translate("WindowClass", "\320\222\320\262\320\276\320\264", 0));
    } // retranslateUi

};

namespace Ui {
    class WindowClass: public Ui_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
