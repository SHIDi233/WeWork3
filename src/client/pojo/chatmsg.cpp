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

void ChatMsg::setType(int type) {
    switch (type) {
    case 0:
        _type = Word;
        break;
    case 1:
        _type = Pic;
        break;
    case 2:
        _type = Video;
        break;
    default:
        _type = File;
        break;
    }

}

void ChatMsg::setIsRead(int isRead) {
    if(isRead == 0){
        _isRead = false;
    }else{
        _isRead = true;
    }
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
