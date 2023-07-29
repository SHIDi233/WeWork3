/**
* QT窗体子类，实现添加好友功能
* 目前还未完成
*/

#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QWidget>

namespace Ui {
class AddFriend;
}

class AddFriend : public QWidget
{
    Q_OBJECT

public:
    explicit AddFriend(QWidget *parent = nullptr);
    ~AddFriend();

private:
    Ui::AddFriend *ui;
};

#endif // ADDFRIEND_H
