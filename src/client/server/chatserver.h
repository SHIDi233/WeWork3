#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QString>
#include "pojo/chatobject.h"

namespace ChatServer {
    void wordChat(int chatID, QString content, TYPE type, int groupID = -1);
    void wordStorage(int chatID, QString content, TYPE type, int groupID = -1); //将文字信息存入本地
}

#endif // CHATSERVER_H
