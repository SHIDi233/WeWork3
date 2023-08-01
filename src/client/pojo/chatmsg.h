#ifndef CHATMSG_H
#define CHATMSG_H

#include <QString>

class ChatMsg
{
public:

    enum MsgType {
        Word,
        Pic,
        Video,
        File
    };

    ChatMsg();

    void setID(int ID);

    void setChatID(int chatID);

    void setType(MsgType type);

    void setIsRead(bool isRead);

    void setTime(QString time);

    void setContent(QString content);

    int getID();

    int getChatID();

    MsgType getType();

    bool getIsRead();

    QString getTime();

    QString getContent();
private:
    int _ID; //聊天ID，如果是私聊则是对方ID，如果是群则是群ID
    int _chatID; //消息发送者ID
    MsgType _type; //消息类型
    bool _isRead; //是否已读
    QString _time; //时间戳
    QString _content;
};

#endif // CHATMSG_H
