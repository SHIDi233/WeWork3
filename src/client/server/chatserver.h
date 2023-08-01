#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QString>
#include "pojo/chatobject.h"
#include <QSqlDatabase>
#include <QSqlQuery> //sql查询语句
#include <QDebug>
#include <QVector>
#include "pojo/chatmsg.h"

namespace ChatServer {
    void initDatabase();//每次使用时必须先调用该函数初始化数据库，为第一次使用该应用的用户不存在该数据库而设置
    void ChatStorage(int ID, QString content, ChatMsg::MsgType type, int chatID, QString time);
    void wordStorage(int chatID, QString content, TYPE type, QString time); //将文字信息存入本地
    void readStorage(int chatID);
    QVector<ChatMsg*> getMsgs(); //获取所有聊天记录
    QVector<ChatMsg*> getMsgs(QString sTime, QString eTime); //获取某一时间段聊天记录
}

#endif // CHATSERVER_H
