#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QString>
#include "pojo/chatobject.h"
#include <QSqlDatabase>
#include <QSqlQuery> //sql查询语句
#include <QDebug>
#include "utils/setting.h"
#include "pojo/user.h"

namespace ChatServer {
    void initDatabase();//每次使用时必须先调用该函数初始化数据库，为第一次使用该应用的用户不存在该数据库而设置
    void wordChat(int chatID, QString content, TYPE type, int groupID = -1);
    void wordStorage(int chatID, QString content, TYPE type, QString time); //将文字信息存入本地
    void readStorage(int chatID);
}

#endif // CHATSERVER_H
