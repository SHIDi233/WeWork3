/**
* QT窗体子类，展示聊天时的气泡效果
*/

#ifndef MSGITEM_H
#define MSGITEM_H

#include <QWidget>
#include "command.h"

namespace Ui {
class MsgItem;
}
class QLabel;
class MsgItem : public QWidget
{
    Q_OBJECT

public:
    explicit MsgItem(QWidget *parent = nullptr, E_WHOSAY = E_WHOSAY::eMe);
    ~MsgItem();

    void paintEvent(QPaintEvent *);

    void setMsg(QString strMsg);
    QString getMsg();

    void setMsgBackgroudColor(E_COLOR);

private:
    Ui::MsgItem *ui;
    QString m_strMsg;
    QLabel *m_pLbMsg;
    QColor m_colorBackgroundMsg;

    E_WHOSAY m_eWhoSay;
};

#endif // MSGITEM_H
