#include "friendsend.h"
#include "ui_friendsend.h"
#include "widget_override/piclabel.h"

FriendSend::FriendSend(QWidget* parent, QWidget *chat, int head, QString name) :
    QWidget(parent),
    chat_(chat),
    head_(head),
    name_(name),
    ui(new Ui::FriendSend)
{
    ui->setupUi(this);
    ui->name_label_2->setText(name_);
    ui->gridLayout_2->addWidget(chat_);

    setFixedWidth(170 + this->parentWidget()->width() / 2);

    QPixmap headPix(QString(":/new/head/image/head_%1.png").arg(head_));
    headPix = headPix.scaled(41, 41, Qt::KeepAspectRatio);
    ui->head_label_2->setScaledContents(true);
    ui->head_label_2->setPixmap(headPix);
    ui->head_label_2->resize(41, 41);
}

FriendSend::FriendSend(QWidget* parent, QString path, int head, QString name, F_TYPE type) :
    QWidget(parent),
    head_(head),
    name_(name),
    ui(new Ui::FriendSend)
{
    ui->setupUi(this);
    ui->name_label_2->setText(name_);
    PicLabel *pic = new PicLabel(this, path);
    if(type == F_TYPE::fPic) {
        QPixmap pixmap(path);
        //让图像大小合适
        if(pixmap.width() > 200 || pixmap.height() > 200) {
            pixmap = pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio);
        }
        pic->setPixmap(pixmap);
        pic->setMaximumSize(QSize(200, 200));
    }
    if(type == F_TYPE::fVideo) {
        QPixmap pixmap(":/new/bg/image/video_icon.png");
        //让图像大小合适
        if(pixmap.width() > 200 || pixmap.height() > 200) {
            pixmap = pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio);
        }
        pic->setPixmap(pixmap);
        pic->setMaximumSize(QSize(200, 200));
    }
    if(type == F_TYPE::fFile) {
        QPixmap pixmap(":/new/bg/image/file_icon.png");
        //让图像大小合适
        if(pixmap.width() > 200 || pixmap.height() > 200) {
            pixmap = pixmap.scaled(QSize(200, 200), Qt::KeepAspectRatio);
        }
        pic->setPixmap(pixmap);
        pic->setMaximumSize(QSize(200, 200));
    }
    ui->gridLayout_2->addWidget(pic);

    setFixedWidth(270 + this->parentWidget()->width() / 2);

    QPixmap headPix(QString(":/new/head/image/head_%1.png").arg(head_));
    headPix = headPix.scaled(41, 41, Qt::KeepAspectRatio);
    ui->head_label_2->setScaledContents(true);
    ui->head_label_2->setPixmap(headPix);
    ui->head_label_2->resize(41, 41);
}

FriendSend::~FriendSend()
{
    delete ui;
}
