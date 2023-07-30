/********************************************************************************
** Form generated from reading UI file 'logwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWINDOW_H
#define UI_LOGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_logWindow
{
public:
    QFrame *frame;
    QLabel *head;
    QPushButton *chat_choose_button;
    QPushButton *pyq_choose_button;
    QPushButton *item_choose_button;
    QPushButton *set_choose_button;
    QStackedWidget *stackedWidget;
    QWidget *chat_page;
    QLabel *label;
    QScrollArea *friendsArea;
    QWidget *scrollAreaWidgetContents;
    QPlainTextEdit *texteditInput;
    QPushButton *send_button;
    QPushButton *pic_send;
    QPushButton *video_send;
    QStackedWidget *chat_stack_widget;
    QWidget *page;
    QLabel *label_4;
    QWidget *page_2;
    QFrame *line;
    QLabel *chat_title;
    QPushButton *pushButton;
    QPushButton *video_send_2;
    QWidget *pyq_page;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *label_2;
    QWidget *item_page;
    QLabel *label_3;
    QWidget *page_3;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *logWindow)
    {
        if (logWindow->objectName().isEmpty())
            logWindow->setObjectName(QString::fromUtf8("logWindow"));
        logWindow->resize(918, 640);
        frame = new QFrame(logWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 61, 641));
        frame->setStyleSheet(QString::fromUtf8("background:rgb(0, 170, 255)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        head = new QLabel(frame);
        head->setObjectName(QString::fromUtf8("head"));
        head->setGeometry(QRect(10, 10, 41, 41));
        chat_choose_button = new QPushButton(frame);
        chat_choose_button->setObjectName(QString::fromUtf8("chat_choose_button"));
        chat_choose_button->setGeometry(QRect(10, 60, 41, 41));
        chat_choose_button->setStyleSheet(QString::fromUtf8("#chat_choose_button:!hover\n"
"{\n"
"border-style:inset;\n"
"border-radius: 5px;\n"
"background-color:rgb(0, 170, 255);\n"
"}\n"
"#chat_choose_button:hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color: rgb(1, 142, 235);\n"
"}\n"
"#chat_choose_button:pressed{\n"
"border-radius: 5px;\n"
"background-color: rgb(0, 130, 230);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/image/chat_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        chat_choose_button->setIcon(icon);
        chat_choose_button->setIconSize(QSize(40, 40));
        pyq_choose_button = new QPushButton(frame);
        pyq_choose_button->setObjectName(QString::fromUtf8("pyq_choose_button"));
        pyq_choose_button->setGeometry(QRect(10, 110, 41, 41));
        pyq_choose_button->setStyleSheet(QString::fromUtf8("#pyq_choose_button:!hover\n"
"{\n"
"border-style:inset;\n"
"border-radius: 5px;\n"
"background-color:rgb(0, 170, 255);\n"
"}\n"
"#pyq_choose_button:hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color: rgb(1, 142, 235);\n"
"}\n"
"#pyq_choose_button:pressed{\n"
"border-radius: 5px;\n"
"background-color: rgb(0, 130, 230);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/icon/image/pyq_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pyq_choose_button->setIcon(icon1);
        pyq_choose_button->setIconSize(QSize(50, 50));
        item_choose_button = new QPushButton(frame);
        item_choose_button->setObjectName(QString::fromUtf8("item_choose_button"));
        item_choose_button->setGeometry(QRect(10, 160, 41, 41));
        item_choose_button->setStyleSheet(QString::fromUtf8("#item_choose_button:!hover\n"
"{\n"
"border-style:inset;\n"
"border-radius: 5px;\n"
"background-color:rgb(0, 170, 255);\n"
"}\n"
"#item_choose_button:hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color: rgb(1, 142, 235);\n"
"}\n"
"#item_choose_button:pressed{\n"
"border-radius: 5px;\n"
"background-color: rgb(0, 130, 230);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/icon/image/item_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        item_choose_button->setIcon(icon2);
        item_choose_button->setIconSize(QSize(37, 37));
        set_choose_button = new QPushButton(frame);
        set_choose_button->setObjectName(QString::fromUtf8("set_choose_button"));
        set_choose_button->setGeometry(QRect(10, 210, 41, 41));
        set_choose_button->setStyleSheet(QString::fromUtf8("#set_choose_button:!hover\n"
"{\n"
"border-style:inset;\n"
"border-radius: 5px;\n"
"background-color:rgb(0, 170, 255);\n"
"}\n"
"#set_choose_button:hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color: rgb(1, 142, 235);\n"
"}\n"
"#set_choose_button:pressed{\n"
"border-radius: 5px;\n"
"background-color: rgb(0, 130, 230);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/icon/image/set_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        set_choose_button->setIcon(icon3);
        set_choose_button->setIconSize(QSize(46, 46));
        stackedWidget = new QStackedWidget(logWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(60, 0, 851, 641));
        stackedWidget->setStyleSheet(QString::fromUtf8("#pyq_page\n"
"{\n"
"background-image: url(:/new/bg/image/background-pyq.png);\n"
"}"));
        chat_page = new QWidget();
        chat_page->setObjectName(QString::fromUtf8("chat_page"));
        label = new QLabel(chat_page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 15, 131, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(20);
        label->setFont(font);
        label->setCursor(QCursor(Qt::ArrowCursor));
        friendsArea = new QScrollArea(chat_page);
        friendsArea->setObjectName(QString::fromUtf8("friendsArea"));
        friendsArea->setGeometry(QRect(0, 60, 251, 581));
        friendsArea->setStyleSheet(QString::fromUtf8(""));
        friendsArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 249, 579));
        friendsArea->setWidget(scrollAreaWidgetContents);
        texteditInput = new QPlainTextEdit(chat_page);
        texteditInput->setObjectName(QString::fromUtf8("texteditInput"));
        texteditInput->setGeometry(QRect(270, 510, 561, 91));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        font1.setBold(false);
        texteditInput->setFont(font1);
        texteditInput->setStyleSheet(QString::fromUtf8("border:transparent"));
        texteditInput->setFrameShadow(QFrame::Plain);
        texteditInput->setLineWidth(0);
        send_button = new QPushButton(chat_page);
        send_button->setObjectName(QString::fromUtf8("send_button"));
        send_button->setGeometry(QRect(750, 610, 75, 23));
        send_button->setStyleSheet(QString::fromUtf8("#send_button:!hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color:rgb(0, 170, 255);\n"
"}\n"
"#send_button:hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color: rgb(85, 170, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-radius: 5px;\n"
"background-color: rgb(0, 130, 230);\n"
"}"));
        pic_send = new QPushButton(chat_page);
        pic_send->setObjectName(QString::fromUtf8("pic_send"));
        pic_send->setGeometry(QRect(300, 485, 51, 21));
        pic_send->setStyleSheet(QString::fromUtf8("QPushButton:!hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color:rgb(0, 170, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color: rgb(85, 170, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-radius: 5px;\n"
"background-color: rgb(0, 130, 230);\n"
"}"));
        video_send = new QPushButton(chat_page);
        video_send->setObjectName(QString::fromUtf8("video_send"));
        video_send->setGeometry(QRect(360, 485, 51, 21));
        video_send->setStyleSheet(QString::fromUtf8("QPushButton:!hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color:rgb(0, 170, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color: rgb(85, 170, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-radius: 5px;\n"
"background-color: rgb(0, 130, 230);\n"
"}"));
        chat_stack_widget = new QStackedWidget(chat_page);
        chat_stack_widget->setObjectName(QString::fromUtf8("chat_stack_widget"));
        chat_stack_widget->setGeometry(QRect(250, 60, 601, 421));
        chat_stack_widget->setStyleSheet(QString::fromUtf8(""));
        chat_stack_widget->setLineWidth(1);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(150, 110, 321, 131));
        QFont font2;
        font2.setFamily(QString::fromUtf8("AR PShinChanPOP"));
        font2.setPointSize(48);
        font2.setBold(true);
        label_4->setFont(font2);
        chat_stack_widget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        chat_stack_widget->addWidget(page_2);
        line = new QFrame(chat_page);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(242, 0, 16, 61));
        line->setFrameShadow(QFrame::Raised);
        line->setFrameShape(QFrame::VLine);
        chat_title = new QLabel(chat_page);
        chat_title->setObjectName(QString::fromUtf8("chat_title"));
        chat_title->setGeometry(QRect(270, 10, 441, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(16);
        font3.setBold(false);
        chat_title->setFont(font3);
        pushButton = new QPushButton(chat_page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(175, 21, 21, 23));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton:!hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color:rgb(0, 170, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color: rgb(85, 170, 255);\n"
"}"));
        video_send_2 = new QPushButton(chat_page);
        video_send_2->setObjectName(QString::fromUtf8("video_send_2"));
        video_send_2->setGeometry(QRect(420, 485, 51, 21));
        video_send_2->setStyleSheet(QString::fromUtf8("QPushButton:!hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color:rgb(0, 170, 255);\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"border-radius: 5px;\n"
"background-color: rgb(85, 170, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"border-radius: 5px;\n"
"background-color: rgb(0, 130, 230);\n"
"}"));
        stackedWidget->addWidget(chat_page);
        pyq_page = new QWidget();
        pyq_page->setObjectName(QString::fromUtf8("pyq_page"));
        scrollArea_3 = new QScrollArea(pyq_page);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(200, 0, 487, 641));
        scrollArea_3->setStyleSheet(QString::fromUtf8("#scrollAreaWidgetContents_3{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.614, stop:0 rgba(156, 190, 207, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 485, 639));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);
        label_2 = new QLabel(pyq_page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 10, 131, 31));
        label_2->setFont(font);
        label_2->setCursor(QCursor(Qt::ArrowCursor));
        stackedWidget->addWidget(pyq_page);
        item_page = new QWidget();
        item_page->setObjectName(QString::fromUtf8("item_page"));
        label_3 = new QLabel(item_page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(290, 210, 54, 12));
        stackedWidget->addWidget(item_page);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 30, 131, 31));
        label_5->setFont(font);
        label_5->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_2 = new QPushButton(page_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 130, 75, 23));
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(80, 170, 75, 23));
        pushButton_4 = new QPushButton(page_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(80, 210, 75, 23));
        stackedWidget->addWidget(page_3);

        retranslateUi(logWindow);

        stackedWidget->setCurrentIndex(0);
        chat_stack_widget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(logWindow);
    } // setupUi

    void retranslateUi(QWidget *logWindow)
    {
        logWindow->setWindowTitle(QCoreApplication::translate("logWindow", "Form", nullptr));
        head->setText(QCoreApplication::translate("logWindow", "\345\244\264\345\203\217", nullptr));
        chat_choose_button->setText(QString());
        pyq_choose_button->setText(QString());
        item_choose_button->setText(QString());
        set_choose_button->setText(QString());
        label->setText(QCoreApplication::translate("logWindow", "\350\201\212\345\244\251\347\225\214\351\235\242", nullptr));
        send_button->setText(QCoreApplication::translate("logWindow", "\345\217\221\351\200\201", nullptr));
        pic_send->setText(QCoreApplication::translate("logWindow", "\345\233\276\347\211\207", nullptr));
        video_send->setText(QCoreApplication::translate("logWindow", "\350\247\206\351\242\221", nullptr));
        label_4->setText(QCoreApplication::translate("logWindow", "<html><head/><body><p><span style=\" color:#b5b5b5;\">We Work</span></p></body></html>", nullptr));
        chat_title->setText(QString());
        pushButton->setText(QCoreApplication::translate("logWindow", "+", nullptr));
        video_send_2->setText(QCoreApplication::translate("logWindow", "\346\226\207\344\273\266", nullptr));
        label_2->setText(QCoreApplication::translate("logWindow", "\346\234\213\345\217\213\345\234\210", nullptr));
        label_3->setText(QCoreApplication::translate("logWindow", "\345\276\205\345\212\236\347\225\214\351\235\242", nullptr));
        label_5->setText(QCoreApplication::translate("logWindow", "\350\256\276\347\275\256\347\225\214\351\235\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("logWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("logWindow", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("logWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class logWindow: public Ui_logWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWINDOW_H
