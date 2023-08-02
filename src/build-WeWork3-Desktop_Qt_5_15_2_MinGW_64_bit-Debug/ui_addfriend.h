/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriend
{
public:
    QTabWidget *tabWidget;
    QWidget *new_friend_tab;
    QWidget *search_tab;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLabel *head_label;
    QLabel *name_label;
    QPushButton *pushButton_2;
    QLabel *hint_label_2;
    QLabel *hint_label;

    void setupUi(QWidget *AddFriend)
    {
        if (AddFriend->objectName().isEmpty())
            AddFriend->setObjectName(QString::fromUtf8("AddFriend"));
        AddFriend->resize(280, 345);
        tabWidget = new QTabWidget(AddFriend);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 280, 345));
        new_friend_tab = new QWidget();
        new_friend_tab->setObjectName(QString::fromUtf8("new_friend_tab"));
        tabWidget->addTab(new_friend_tab, QString());
        search_tab = new QWidget();
        search_tab->setObjectName(QString::fromUtf8("search_tab"));
        label = new QLabel(search_tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 61, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(11);
        font.setBold(false);
        label->setFont(font);
        lineEdit = new QLineEdit(search_tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 40, 161, 20));
        pushButton = new QPushButton(search_tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 80, 75, 23));
        groupBox = new QGroupBox(search_tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 140, 231, 161));
        head_label = new QLabel(groupBox);
        head_label->setObjectName(QString::fromUtf8("head_label"));
        head_label->setGeometry(QRect(30, 40, 41, 41));
        name_label = new QLabel(groupBox);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setGeometry(QRect(90, 60, 131, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font1.setPointSize(11);
        name_label->setFont(font1);
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 100, 75, 23));
        hint_label_2 = new QLabel(groupBox);
        hint_label_2->setObjectName(QString::fromUtf8("hint_label_2"));
        hint_label_2->setGeometry(QRect(40, 130, 141, 16));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font2.setPointSize(9);
        hint_label_2->setFont(font2);
        hint_label = new QLabel(search_tab);
        hint_label->setObjectName(QString::fromUtf8("hint_label"));
        hint_label->setGeometry(QRect(60, 110, 141, 16));
        tabWidget->addTab(search_tab, QString());

        retranslateUi(AddFriend);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AddFriend);
    } // setupUi

    void retranslateUi(QWidget *AddFriend)
    {
        AddFriend->setWindowTitle(QCoreApplication::translate("AddFriend", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(new_friend_tab), QCoreApplication::translate("AddFriend", "\346\226\260\346\234\213\345\217\213", nullptr));
        label->setText(QCoreApplication::translate("AddFriend", "\350\276\223\345\205\245ID\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("AddFriend", "\346\220\234\347\264\242", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AddFriend", "\346\220\234\347\264\242\347\273\223\346\236\234", nullptr));
        head_label->setText(QString());
        name_label->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("AddFriend", "\346\267\273\345\212\240", nullptr));
        hint_label_2->setText(QString());
        hint_label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(search_tab), QCoreApplication::translate("AddFriend", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriend: public Ui_AddFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
