/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *log_id_line;
    QLineEdit *log_pass_line;
    QPushButton *log_button;
    QLabel *password_icon;
    QLabel *account_icon;
    QPushButton *minus_buton;
    QPushButton *quit_button;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(873, 542);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setAutoFillBackground(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(530, 150, 171, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Algerian"));
        font.setPointSize(72);
        font.setBold(false);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 871, 541));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/bg/image/login_background.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(460, 120, 311, 381));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/bg/image/login_background2.png")));
        label_3->setScaledContents(true);
        log_id_line = new QLineEdit(centralwidget);
        log_id_line->setObjectName(QString::fromUtf8("log_id_line"));
        log_id_line->setGeometry(QRect(550, 240, 160, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\256\213\344\275\223"));
        log_id_line->setFont(font1);
        log_id_line->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    font-size:13px;\n"
"    background:transparent;\n"
"    border:none;\n"
"    border-bottom:1px solid rgb(229, 229, 229);\n"
"}\n"
" \n"
"QLineEdit:hover{\n"
"    border-bottom:1px solid rgb(40,159, 191);\n"
"}\n"
" \n"
"QLineEdit:focus{\n"
"    border-bottom:1px solid rgb(18, 183, 245);\n"
"}"));
        log_pass_line = new QLineEdit(centralwidget);
        log_pass_line->setObjectName(QString::fromUtf8("log_pass_line"));
        log_pass_line->setGeometry(QRect(550, 290, 160, 30));
        log_pass_line->setFont(font1);
        log_pass_line->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"    font-size:13px;\n"
"    background:transparent;\n"
"    border:none;\n"
"    border-bottom:1px solid rgb(229, 229, 229);\n"
"}\n"
" \n"
"QLineEdit:hover{\n"
"    border-bottom:1px solid rgb(40,159, 191);\n"
"}\n"
" \n"
"QLineEdit:focus{\n"
"    border-bottom:1px solid rgb(18, 183, 245);\n"
"}"));
        log_pass_line->setEchoMode(QLineEdit::Password);
        log_button = new QPushButton(centralwidget);
        log_button->setObjectName(QString::fromUtf8("log_button"));
        log_button->setGeometry(QRect(520, 350, 191, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200"));
        font2.setPointSize(13);
        font2.setBold(false);
        font2.setItalic(false);
        log_button->setFont(font2);
        log_button->setStyleSheet(QString::fromUtf8("/**\346\255\243\345\270\270\346\203\205\345\206\265\344\270\213\346\240\267\345\274\217**/\n"
"QPushButton{\n"
"	font: 13pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
"    color: #FCFAF7;\n"
"    background-color: #A0D4BD;\n"
"    border-color: #BEE0D0;\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/**\351\274\240\346\240\207\345\201\234\347\225\231\345\234\250\346\214\211\351\222\256\344\270\212\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::hover{	\n"
"    color: #FCFAF7;\n"
"    background-color: #63BE9D;\n"
"    border-color: #176F57;\n"
"}\n"
"\n"
"/**\351\274\240\346\240\207\346\214\211\345\216\213\344\270\213\345\216\273\347\232\204\346\240\267\345\274\217**/\n"
"QPushButton::pressed,QPushButton::checked{\n"
"    color: #FCFAF7;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #63BE9D, stop:1 #46B797);\n"
"}\n"
"\n"
"/**\346\214\211\351\222\256\345\244\261\350\203\275\346"
                        "\203\205\345\206\265\344\270\213\346\240\267\345\274\217**/\n"
"QPushButton::disabled{\n"
"    color: #FCFAF7;\n"
"    background-color: #dcdde1;\n"
"    border-color: #dcdde1;\n"
"}\n"
""));
        password_icon = new QLabel(centralwidget);
        password_icon->setObjectName(QString::fromUtf8("password_icon"));
        password_icon->setGeometry(QRect(510, 240, 30, 30));
        password_icon->setPixmap(QPixmap(QString::fromUtf8(":/new/icon/image/account_icon.png")));
        password_icon->setScaledContents(true);
        account_icon = new QLabel(centralwidget);
        account_icon->setObjectName(QString::fromUtf8("account_icon"));
        account_icon->setGeometry(QRect(510, 290, 30, 30));
        account_icon->setPixmap(QPixmap(QString::fromUtf8(":/new/icon/image/password_icon.png")));
        account_icon->setScaledContents(true);
        minus_buton = new QPushButton(centralwidget);
        minus_buton->setObjectName(QString::fromUtf8("minus_buton"));
        minus_buton->setGeometry(QRect(750, 40, 30, 30));
        minus_buton->setAutoFillBackground(false);
        minus_buton->setStyleSheet(QString::fromUtf8("color: rgba(255, 255, 255, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/image/shrink_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        minus_buton->setIcon(icon);
        minus_buton->setIconSize(QSize(30, 30));
        quit_button = new QPushButton(centralwidget);
        quit_button->setObjectName(QString::fromUtf8("quit_button"));
        quit_button->setGeometry(QRect(790, 40, 30, 30));
        quit_button->setAutoFillBackground(false);
        quit_button->setStyleSheet(QString::fromUtf8("color: rgba(255, 255, 255, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icon/image/quit_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        quit_button->setIcon(icon1);
        quit_button->setIconSize(QSize(30, 30));
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        label_3->raise();
        log_id_line->raise();
        log_pass_line->raise();
        log_button->raise();
        label->raise();
        account_icon->raise();
        password_icon->raise();
        minus_buton->raise();
        quit_button->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:700; color:#2f394e;\">We Work</span></p></body></html>", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        log_id_line->setText(QString());
        log_id_line->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267", nullptr));
        log_pass_line->setInputMask(QString());
        log_pass_line->setText(QString());
        log_pass_line->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        log_button->setText(QCoreApplication::translate("MainWindow", "\347\231\273      \345\275\225", nullptr));
        password_icon->setText(QString());
        account_icon->setText(QString());
        minus_buton->setText(QString());
        quit_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
