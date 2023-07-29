/********************************************************************************
** Form generated from reading UI file 'person.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSON_H
#define UI_PERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_person
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *person)
    {
        if (person->objectName().isEmpty())
            person->setObjectName(QString::fromUtf8("person"));
        person->resize(400, 440);
        person->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(person);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 350, 250));
        textEdit = new QTextEdit(person);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 20, 350, 50));
        QFont font;
        font.setPointSize(12);
        textEdit->setFont(font);
        textEdit->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(person);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 390, 71, 31));
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
        pushButton_2 = new QPushButton(person);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 390, 71, 31));
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

        retranslateUi(person);

        QMetaObject::connectSlotsByName(person);
    } // setupUi

    void retranslateUi(QWidget *person)
    {
        person->setWindowTitle(QCoreApplication::translate("person", "Form", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("person", "\346\267\273\345\212\240\345\233\276\347\211\207", nullptr));
        pushButton_2->setText(QCoreApplication::translate("person", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class person: public Ui_person {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSON_H
