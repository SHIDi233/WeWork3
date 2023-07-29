/**
* QT窗体子类，用于显示对方发送的信息，包括文字、图片、视频
*/

#ifndef FRIENDSEND_H
#define FRIENDSEND_H

#include <QWidget>
#include "command.h"

namespace Ui {
class FriendSend;
}

class FriendSend : public QWidget
{
    Q_OBJECT

public:
    explicit FriendSend(QWidget* parent, QWidget *chat, int head, QString name);
    FriendSend(QWidget* parent, QString path, int head, QString name, F_TYPE type);
    ~FriendSend();

private:
    QWidget *chat_;
    int head_;//头像
    QString name_;//名字
    Ui::FriendSend *ui;
};

#endif // FRIENDSEND_H
