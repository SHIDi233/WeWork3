#include "piclabel.h"
#include <QDesktopServices>
#include <QUrl>
#include <QTextCodec>

PicLabel::PicLabel(QWidget *parent, QString path) : QLabel(parent), path_(path)
{
    setCursor(Qt::PointingHandCursor);
    QTextCodec *code = QTextCodec::codecForName("GBK");//解决中文路径问题
    path_ = code->fromUnicode(path_).data();
}

void PicLabel::mousePressEvent(QMouseEvent *ev) {
    //打开图片大图
    QDesktopServices::openUrl(QUrl(path_));
}
