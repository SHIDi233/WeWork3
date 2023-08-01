#include "chatserver.h"
#include "utils/setting.h"
#include "pojo/user.h"


/**
 * @brief 将聊天内容存入本地
 * @param chatID: 文字发送对象的ID
 * @param content: 文字内容
 * @param type: 聊天类型(私聊-TYPE::Person/群组-TYPE::Group)
 * @param groupID: 可选参数，若聊天类型是私聊，则该参数无意义，反之为群组ID
 */
void ChatServer::wordStorage(int chatID, QString content, TYPE type, QString time) {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(setting::getGlobalPath() + "//chat_record.db");
    QString create_sql = "create table record (ID varchar(10) , chatID varchar(10), content text, time text, type int)";
    QString insert_sql = QString("insert into record values(%1,%2,%3,%4,%5)").arg(User::getUser()->getID()).arg(chatID).arg(content).arg(time).arg(type);
    if(db.open()){
        db.exec(create_sql);
        db.exec(insert_sql);
    }
    db.close();
}

//调用前必须使用
void ChatServer::initDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QDir dbDir(setting::getGlobalPath() + + "/storage/" + User::getUser()->getID());
    if (!dbDir.exists()) {
        dbDir.mkpath(".");
    }
    db.setDatabaseName(setting::getGlobalPath() + "/storage/" + User::getUser()->getID() + "/chat_record.db");
    QString create_sql = "create table record (recordID INTEGER PRIMARY KEY, ID int, chatID int, record text, time varchar(50), type varchar(20), isRead int DEFAULT 0)";
    if(db.open()){
        qDebug() << create_sql;
        QSqlQuery result = db.exec(create_sql);
    }else{
        qDebug() << "数据库打开失败";
    }
    db.close();
}


int ChatServer::ChatStorage(int ID, QString content, ChatMsg::MsgType type, int chatID, QString time)
{
    int recordID = 0;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(setting::getGlobalPath() + "/storage/" + User::getUser()->getID() + "/chat_record.db");
    QString insert_sql = QString("insert into record(ID, chatID, record, time, type) values(%1,%2,%3,%4,%5)")
                             .arg(ID).arg(chatID).arg(content).arg(time).arg(type);
    if(db.open()){
        QSqlQuery query = db.exec(insert_sql);
        recordID = query.lastInsertId().toInt();
    }
    db.close();
    return recordID;

}



QVector<ChatMsg *> ChatServer::getMsgs()
{
    QVector<ChatMsg *> result_;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(setting::getGlobalPath() + "/storage/" + User::getUser()->getID() + "/chat_record.db");
    QString sql = QString("select * from record where ID = %1").arg(User::getUser()->getID());
    if(db.open()){
        QSqlQuery result = db.exec(sql);
        while(result.next()){
            ChatMsg* temp = new ChatMsg();
            temp->setChatID(result.value("chatID").toInt());
            temp->setID(User::getUser()->getID());
            temp->setContent(result.value("record").toString());
            temp->setTime(result.value("time").toString());
            temp->setType(result.value("type").toInt());
            temp->setIsRead(result.value("isRead").toInt());
            result_.append(temp);
        }
    }
    db.close();
    return result_;
}
