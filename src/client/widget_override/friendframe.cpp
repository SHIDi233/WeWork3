#include "friendframe.h"
#include "QBoxLayout"
#include "QLabel"

FriendFrame::FriendFrame(QWidget *parent) : QWidget(parent)
{

}

FriendFrame::FriendFrame(int headIndex, QString name, QWidget *parent) : QWidget(parent), headIndex_(headIndex), name_(name)
{
    QPixmap headPix(QString(":/new/head/image/head_%1.png").arg(headIndex_));
    headPix = headPix.scaled(41, 41, Qt::KeepAspectRatio);
    QHBoxLayout *hLayout = new QHBoxLayout();
    QLabel *head = new QLabel();
    head->setMaximumSize(41, 41);
    QLabel *nameText = new QLabel();
    nameText->setText(name_);
    nameText->setFont(QFont("宋体", 12));
    head->setPixmap(headPix);
    hLayout->setSpacing(20);
    hLayout->addWidget(head);
    hLayout->addWidget(nameText);
    setLayout(hLayout);
//    setStyleSheet(QString("QWidget:pressed{ \
//                          background-color:rgb(200,200,200);\
//                          border-style:inset;\
//                          color:rgb(0,255,0);\
//                          }\
//                          QPushButton:!hover{background-color:qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(159, 191, 207, 255), stop:1 rgba(255, 255, 255, 255)); \
//                          border-style:inset;}"));
}
