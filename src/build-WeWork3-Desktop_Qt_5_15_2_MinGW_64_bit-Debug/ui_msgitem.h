/********************************************************************************
** Form generated from reading UI file 'msgitem.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSGITEM_H
#define UI_MSGITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MsgItem
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *MsgItem)
    {
        if (MsgItem->objectName().isEmpty())
            MsgItem->setObjectName(QString::fromUtf8("MsgItem"));
        MsgItem->resize(173, 89);
        horizontalLayout_2 = new QHBoxLayout(MsgItem);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(MsgItem);

        QMetaObject::connectSlotsByName(MsgItem);
    } // setupUi

    void retranslateUi(QWidget *MsgItem)
    {
        MsgItem->setWindowTitle(QCoreApplication::translate("MsgItem", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MsgItem: public Ui_MsgItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSGITEM_H
