#ifndef FRIENDFRAME_H
#define FRIENDFRAME_H

#include <QWidget>
#include <QPushButton>

class FriendFrame : public QPushButton
{
    Q_OBJECT
public:
    explicit FriendFrame(QWidget *parent = nullptr);
    FriendFrame(int headIndex, QString name, QWidget *parent = nullptr);
private:
    int headIndex_;//头像
    QString lastMessage;//最后一次消息
    QString name_;//昵称
signals:

};

#endif // FRIENDFRAME_H
