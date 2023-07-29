/**
* QT窗体子类，用于显示本人发送的信息，包括文字、图片、视频
*/

#ifndef MESEND_H
#define MESEND_H

#include <QWidget>
#include "command.h"

namespace Ui {
class MeSend;
}

class MeSend : public QWidget
{
    Q_OBJECT

public:
    explicit MeSend(QWidget* parent, QWidget *chat, int head, QString name);
    MeSend(QWidget* parent, QString picPath, int head, QString name, F_TYPE type);//图像信息面板
    ~MeSend();

private:
    QWidget *chat_;
    int head_;//头像
    QString name_;//名字
    Ui::MeSend *ui;
};

#endif // MESEND_H
