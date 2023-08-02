/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton_2;
    QLabel *head_label;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *name_label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(485, 639);
        Widget->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(400, 50, 61, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton:!hover\n"
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
        head_label = new QLabel(Widget);
        head_label->setObjectName(QString::fromUtf8("head_label"));
        head_label->setGeometry(QRect(30, 20, 51, 51));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 10, 61, 31));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton:!hover\n"
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
        scrollArea = new QScrollArea(Widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 90, 491, 551));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 489, 549));
        scrollArea->setWidget(scrollAreaWidgetContents);
        name_label = new QLabel(Widget);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(100, 40, 241, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(16);
        name_label->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Form", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\345\210\267\346\226\260", nullptr));
        head_label->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "\346\267\273\345\212\240", nullptr));
        name_label->setText(QCoreApplication::translate("Widget", "\345\220\215\345\255\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
