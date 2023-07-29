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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *log_tab;
    QLineEdit *log_id_line;
    QLineEdit *log_pass_line;
    QPushButton *log_button;
    QLabel *hint_1;
    QWidget *reg_tab;
    QLineEdit *reg_id_line;
    QLineEdit *reg_pass_line;
    QPushButton *reg_button;
    QLineEdit *reg_pass_confirm_line;
    QLineEdit *reg_name_line;
    QLabel *hint_2;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(910, 640);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralwidget\n"
"{\n"
"background-image: url(:/new/bg/image/background-1.png);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(530, 230, 301, 351));
        tabWidget->setStyleSheet(QString::fromUtf8("::tab {\n"
"color: rgb(235, 223, 48);\n"
"	font: 28pt \"\345\255\227\344\275\223\347\256\241\345\256\266\346\243\211\350\212\261\347\263\226\";\n"
"height: 60px;\n"
"width: 150px;\n"
"background-color: rgba(223, 223, 223, 130);\n"
"}\n"
"\n"
"::pane {\n"
"border-top: 0px solid #e8f3f9;\n"
"background-color: rgba(223, 223, 223, 100);\n"
"}"));
        log_tab = new QWidget();
        log_tab->setObjectName(QString::fromUtf8("log_tab"));
        log_id_line = new QLineEdit(log_tab);
        log_id_line->setObjectName(QString::fromUtf8("log_id_line"));
        log_id_line->setGeometry(QRect(60, 40, 191, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\256\213\344\275\223"));
        font.setPointSize(14);
        log_id_line->setFont(font);
        log_id_line->setStyleSheet(QString::fromUtf8("border-radius: 5px"));
        log_pass_line = new QLineEdit(log_tab);
        log_pass_line->setObjectName(QString::fromUtf8("log_pass_line"));
        log_pass_line->setGeometry(QRect(60, 110, 191, 31));
        log_pass_line->setFont(font);
        log_pass_line->setStyleSheet(QString::fromUtf8("border-radius: 5px"));
        log_pass_line->setEchoMode(QLineEdit::Password);
        log_button = new QPushButton(log_tab);
        log_button->setObjectName(QString::fromUtf8("log_button"));
        log_button->setGeometry(QRect(60, 210, 191, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\255\227\344\275\223\347\256\241\345\256\266\346\243\211\350\212\261\347\263\226"));
        font1.setPointSize(18);
        log_button->setFont(font1);
        log_button->setStyleSheet(QString::fromUtf8("#log_button:!hover\n"
"{\n"
"border-radius: 10px;\n"
"background-color:rgb(255, 255, 127);\n"
"}\n"
"#log_button:hover\n"
"{\n"
"border-radius: 10px;\n"
"background-color: rgb(19, 216, 234);\n"
"}"));
        hint_1 = new QLabel(log_tab);
        hint_1->setObjectName(QString::fromUtf8("hint_1"));
        hint_1->setGeometry(QRect(60, 260, 191, 16));
        hint_1->setStyleSheet(QString::fromUtf8("color:rgb(255, 25, 25)"));
        tabWidget->addTab(log_tab, QString());
        reg_tab = new QWidget();
        reg_tab->setObjectName(QString::fromUtf8("reg_tab"));
        reg_id_line = new QLineEdit(reg_tab);
        reg_id_line->setObjectName(QString::fromUtf8("reg_id_line"));
        reg_id_line->setGeometry(QRect(60, 40, 191, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\256\213\344\275\223"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        reg_id_line->setFont(font2);
        reg_id_line->setStyleSheet(QString::fromUtf8("border-radius: 5px"));
        reg_pass_line = new QLineEdit(reg_tab);
        reg_pass_line->setObjectName(QString::fromUtf8("reg_pass_line"));
        reg_pass_line->setGeometry(QRect(60, 120, 191, 31));
        reg_pass_line->setFont(font);
        reg_pass_line->setStyleSheet(QString::fromUtf8("border-radius: 5px"));
        reg_pass_line->setEchoMode(QLineEdit::Password);
        reg_button = new QPushButton(reg_tab);
        reg_button->setObjectName(QString::fromUtf8("reg_button"));
        reg_button->setGeometry(QRect(60, 210, 191, 41));
        reg_button->setFont(font1);
        reg_button->setStyleSheet(QString::fromUtf8("#reg_button:!hover\n"
"{\n"
"border-radius: 10px;\n"
"background-color:rgb(255, 255, 127);\n"
"}\n"
"#reg_button:hover\n"
"{\n"
"border-radius: 10px;\n"
"background-color: rgb(19, 216, 234);\n"
"}"));
        reg_pass_confirm_line = new QLineEdit(reg_tab);
        reg_pass_confirm_line->setObjectName(QString::fromUtf8("reg_pass_confirm_line"));
        reg_pass_confirm_line->setGeometry(QRect(60, 160, 191, 31));
        reg_pass_confirm_line->setFont(font);
        reg_pass_confirm_line->setStyleSheet(QString::fromUtf8("border-radius: 5px"));
        reg_pass_confirm_line->setEchoMode(QLineEdit::Password);
        reg_name_line = new QLineEdit(reg_tab);
        reg_name_line->setObjectName(QString::fromUtf8("reg_name_line"));
        reg_name_line->setGeometry(QRect(60, 80, 191, 31));
        reg_name_line->setFont(font);
        reg_name_line->setStyleSheet(QString::fromUtf8("border-radius: 5px"));
        hint_2 = new QLabel(reg_tab);
        hint_2->setObjectName(QString::fromUtf8("hint_2"));
        hint_2->setGeometry(QRect(60, 260, 191, 16));
        hint_2->setStyleSheet(QString::fromUtf8("color:rgb(255, 25, 25)"));
        tabWidget->addTab(reg_tab, QString());
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 421, 161));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\255\227\344\275\223\347\256\241\345\256\266\346\243\211\350\212\261\347\263\226"));
        font3.setPointSize(72);
        label->setFont(font3);
        label->setTextFormat(Qt::AutoText);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        log_id_line->setText(QString());
        log_id_line->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267", nullptr));
        log_pass_line->setInputMask(QString());
        log_pass_line->setText(QString());
        log_pass_line->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        log_button->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        hint_1->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(log_tab), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        reg_id_line->setText(QString());
        reg_id_line->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\264\246\345\217\267", nullptr));
        reg_pass_line->setPlaceholderText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201", nullptr));
        reg_button->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214", nullptr));
        reg_pass_confirm_line->setPlaceholderText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        reg_name_line->setText(QString());
        reg_name_line->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\230\265\347\247\260", nullptr));
        hint_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(reg_tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:72pt; color:#ffffff;\">We Work</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
