/********************************************************************************
** Form generated from reading UI file 'Sushi.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUSHI_H
#define UI_SUSHI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SushiClass
{
public:
    QLineEdit *lineEdit_totle_budget;
    QLabel *label_2;
    QTextEdit *textEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_Sushi_num;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPlainTextEdit *LogOutput;
    QLabel *label_5;

    void setupUi(QWidget *SushiClass)
    {
        if (SushiClass->objectName().isEmpty())
            SushiClass->setObjectName(QString::fromUtf8("SushiClass"));
        SushiClass->resize(580, 427);
        lineEdit_totle_budget = new QLineEdit(SushiClass);
        lineEdit_totle_budget->setObjectName(QString::fromUtf8("lineEdit_totle_budget"));
        lineEdit_totle_budget->setGeometry(QRect(320, 40, 121, 21));
        label_2 = new QLabel(SushiClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(320, 10, 51, 20));
        textEdit = new QTextEdit(SushiClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 110, 431, 121));
        label_3 = new QLabel(SushiClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 90, 161, 16));
        label_4 = new QLabel(SushiClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 10, 91, 16));
        lineEdit_Sushi_num = new QLineEdit(SushiClass);
        lineEdit_Sushi_num->setObjectName(QString::fromUtf8("lineEdit_Sushi_num"));
        lineEdit_Sushi_num->setGeometry(QRect(30, 40, 91, 21));
        pushButton = new QPushButton(SushiClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(470, 110, 93, 28));
        pushButton_2 = new QPushButton(SushiClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 200, 93, 28));
        LogOutput = new QPlainTextEdit(SushiClass);
        LogOutput->setObjectName(QString::fromUtf8("LogOutput"));
        LogOutput->setGeometry(QRect(20, 300, 431, 87));
        label_5 = new QLabel(SushiClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 270, 41, 16));

        retranslateUi(SushiClass);
        QObject::connect(pushButton, SIGNAL(clicked()), textEdit, SLOT(clear()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), SushiClass, SLOT(Calculate()));
        QObject::connect(pushButton, SIGNAL(clicked()), LogOutput, SLOT(clear()));
        QObject::connect(pushButton, SIGNAL(clicked()), lineEdit_Sushi_num, SLOT(clear()));
        QObject::connect(pushButton, SIGNAL(clicked()), lineEdit_totle_budget, SLOT(clear()));

        QMetaObject::connectSlotsByName(SushiClass);
    } // setupUi

    void retranslateUi(QWidget *SushiClass)
    {
        SushiClass->setWindowTitle(QApplication::translate("SushiClass", "Sushi", nullptr));
        label_2->setText(QApplication::translate("SushiClass", "\346\200\273\351\242\204\347\256\227", nullptr));
        textEdit->setHtml(QApplication::translate("SushiClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("SushiClass", "\350\276\223\345\205\245\357\274\232\345\257\277\345\217\270\347\232\204\344\273\267\346\240\274/\347\255\211\347\272\247", nullptr));
        label_4->setText(QApplication::translate("SushiClass", "\345\257\277\345\217\270\347\247\215\347\261\273\346\225\260", nullptr));
        pushButton->setText(QApplication::translate("SushiClass", "\346\270\205\351\231\244", nullptr));
        pushButton_2->setText(QApplication::translate("SushiClass", "\347\273\223\346\236\234", nullptr));
        label_5->setText(QApplication::translate("SushiClass", "\346\211\223\345\215\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SushiClass: public Ui_SushiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSHI_H
