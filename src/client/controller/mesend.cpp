#include "mesend.h"
#include "ui_mesend.h"
#include "piclabel.h"

MeSend::MeSend(QWidget* parent, QWidget *chat, int head, QString name) :
    QWidget(parent),
    chat_(chat),
    head_(head),
    name_(name),
    ui(new Ui::MeSend)
{
    ui->setupUi(this);
    ui->name_label->setText(name_);
    ui->gridLayout->addWidget(chat_);

    setFixedWidth(70 + this->parentWidget()->width() / 2);

    QPixmap headPix(QString(":/new/head/image/head_%1.png").arg(head_));
    headPix = headPix.scaled(41, 41, Qt::KeepAspectRatio);
    ui->head_label->setScaledContents(true);
    ui->head_label->setPixmap(headPix);
}

MeSend::MeSend(QWidget* parent, QString path, int head, QString name, F_TYPE type) :
    QWidget(parent),
    head_(head),
    name_(name),
    ui(new Ui::MeSend)
{
    ui->setupUi(this);
    ui->name_label->setText(name_);
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
    ui->gridLayout->addWidget(pic);
    setFixedWidth(70 + this->parentWidget()->width() / 2);

    QPixmap headPix(QString(":/new/head/image/head_%1.png").arg(head_));
    headPix = headPix.scaled(41, 41, Qt::KeepAspectRatio);
    ui->head_label->setScaledContents(true);
    ui->head_label->setPixmap(headPix);
    ui->head_label->resize(41, 41);
}

MeSend::~MeSend()
{
    delete ui;
}
