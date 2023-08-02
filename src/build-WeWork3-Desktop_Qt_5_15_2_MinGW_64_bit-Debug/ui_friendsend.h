/********************************************************************************
** Form generated from reading UI file 'friendsend.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDSEND_H
#define UI_FRIENDSEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendSend
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *head_label_2;
    QLabel *name_label_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *FriendSend)
    {
        if (FriendSend->objectName().isEmpty())
            FriendSend->setObjectName(QString::fromUtf8("FriendSend"));
        FriendSend->resize(600, 114);
        gridLayout_3 = new QGridLayout(FriendSend);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        head_label_2 = new QLabel(FriendSend);
        head_label_2->setObjectName(QString::fromUtf8("head_label_2"));

        horizontalLayout_2->addWidget(head_label_2);

        name_label_2 = new QLabel(FriendSend);
        name_label_2->setObjectName(QString::fromUtf8("name_label_2"));

        horizontalLayout_2->addWidget(name_label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout_3->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 1, 1, 1);


        retranslateUi(FriendSend);

        QMetaObject::connectSlotsByName(FriendSend);
    } // setupUi

    void retranslateUi(QWidget *FriendSend)
    {
        FriendSend->setWindowTitle(QCoreApplication::translate("FriendSend", "Form", nullptr));
        head_label_2->setText(QCoreApplication::translate("FriendSend", "\345\244\264\345\203\217", nullptr));
        name_label_2->setText(QCoreApplication::translate("FriendSend", "name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendSend: public Ui_FriendSend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDSEND_H
