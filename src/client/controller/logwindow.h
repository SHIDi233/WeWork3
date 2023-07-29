/**
* 登录或注册后显示的窗口
*/

#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "chatobject.h"
#include "friendframe.h"
#include "widget.h"

namespace Ui {
class logWindow;
}
class QVBoxLayout;
class logWindow : public QWidget
{
    Q_OBJECT

public:
    explicit logWindow(chatObject *me ,QWidget *parent = nullptr);
    ~logWindow();
    bool receiveMsg(QString msg, int ID, QString name);//接收消息（将消息显示在聊天窗口上）
    bool receivePic(QString path, int ID, QString name);//接收图片（将图片显示在聊天窗口上）
    bool receiveVideo(QString path, int ID, QString name);//接收图片（将视频显示在聊天窗口上）
    bool receiveFile(QString path, int ID, QString name);//接收文件
    bool getCall(int ID, int type);//调出电话界面，type=0表示视频电话，type=1表示语音通话
private slots:
    void on_send_button_clicked();

    void on_pic_send_clicked();

    void on_video_send_clicked();

    void on_video_send_2_clicked();

    void on_voice_call_clicked();

private:
    Widget *pyq;//朋友圈
    chatObject *me;
    int cur_index;//当前选中
    Ui::logWindow *ui;
    QVector<FriendFrame*> friends;
    //QVBoxLayout *m_pVboxLayout;
    QVector<chatObject*> chats;//聊天对象们
    QVector<QVBoxLayout*> chat_layouts;
};

#endif // LOGWINDOW_H
