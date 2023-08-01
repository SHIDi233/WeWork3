#include "chatmsg.h"

ChatMsg::ChatMsg()
{

}

void ChatMsg::setID(int ID) {
    _ID = ID;
}

void ChatMsg::setChatID(int chatID) {
    _chatID = chatID;
}

void ChatMsg::setType(MsgType type) {
    _type = type;
}

void ChatMsg::setIsRead(bool isRead) {
    _isRead = isRead;
}

void ChatMsg::setTime(QString time) {
    _time = time;
}

void ChatMsg::setContent(QString content) {
    _content = content;
}

int ChatMsg::getID() {
    return _ID;
}

int ChatMsg::getChatID() {
    return _chatID;
}

ChatMsg::MsgType ChatMsg::getType() {
    return _type;
}

bool ChatMsg::getIsRead() {
    return _isRead;
}

QString ChatMsg::getTime() {
    return _time;
}

QString ChatMsg::getContent() {
    return _content;
}
