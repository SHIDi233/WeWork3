/********************************************************************************
** Form generated from reading UI file 'mesend.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESEND_H
#define UI_MESEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeSend
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *name_label;
    QLabel *head_label;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *MeSend)
    {
        if (MeSend->objectName().isEmpty())
            MeSend->setObjectName(QString::fromUtf8("MeSend"));
        MeSend->resize(368, 70);
        gridLayout_2 = new QGridLayout(MeSend);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        name_label = new QLabel(MeSend);
        name_label->setObjectName(QString::fromUtf8("name_label"));

        horizontalLayout->addWidget(name_label);

        head_label = new QLabel(MeSend);
        head_label->setObjectName(QString::fromUtf8("head_label"));

        horizontalLayout->addWidget(head_label);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 2, 2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 5, 1, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 6, 0, 1, 1);


        retranslateUi(MeSend);

        QMetaObject::connectSlotsByName(MeSend);
    } // setupUi

    void retranslateUi(QWidget *MeSend)
    {
        MeSend->setWindowTitle(QCoreApplication::translate("MeSend", "Form", nullptr));
        name_label->setText(QCoreApplication::translate("MeSend", "name", nullptr));
        head_label->setText(QCoreApplication::translate("MeSend", "\345\244\264\345\203\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeSend: public Ui_MeSend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESEND_H
