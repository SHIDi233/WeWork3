#ifndef CHATMSG_H
#define CHATMSG_H

#include <QString>



class ChatMsg
{
public:

    enum MsgType {
        Word = 0,
        Pic = 1,
        Video = 2,
        File = 3
    };

    ChatMsg();

    void setID(int ID);

    void setChatID(int chatID);

    void setType(int type);

    void setIsRead(int isRead);

    void setTime(QString time);

    void setContent(QString content);

    void setWebID(QString webID);

    int getID();

    int getChatID();

    MsgType getType();

    bool getIsRead();

    QString getTime();

    QString getContent();

    QString getWebId();
private:
    int _ID; //聊天ID，如果是私聊则是对方ID，如果是群则是群ID
    int _chatID; //消息发送者ID
    MsgType _type; //消息类型
    bool _isRead; //是否已读
    QString _time; //时间戳
    QString _content;
    QString _webID;
};

#endif // CHATMSG_H
