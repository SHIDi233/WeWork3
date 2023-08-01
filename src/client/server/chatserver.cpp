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
    qDebug() << User::getUser()->getID();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QDir dbDir(setting::getGlobalPath() + + "\\storage\\" + QString::number(User::getUser()->getID()));
    qDebug() << setting::getGlobalPath() + + "\\storage\\" + QString::number(User::getUser()->getID());
    if (!dbDir.exists()) {
        dbDir.mkpath(".");
    }
    db.setDatabaseName(setting::getGlobalPath() + "\\storage\\" + QString::number(User::getUser()->getID()) + "\\chat_record.db");
    QString create_sql = "create table record (recordID INTEGER PRIMARY KEY, ID int, chatID int, record text, time time, type varchar(20), isRead int DEFAULT 0)";
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
    qDebug() << User::getUser()->getID();
    int recordID = 0;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(setting::getGlobalPath() + "\\storage\\" + QString::number(User::getUser()->getID()) + "\\chat_record.db");
    QString insert_sql = QString("insert into record(ID, chatID, record, time, type) values(%1,%2,%3,%4,%5)")
                             .arg(ID).arg(chatID).arg("\'" + content + "\'").arg("\'" + time + "\'").arg(type);
    if(db.open()){
        QSqlQuery query = db.exec(insert_sql);
        recordID = query.lastInsertId().toInt();
    }
    db.close();
    return recordID;

}



QVector<ChatMsg *> ChatServer::getMsgs()
{
    qDebug() << User::getUser()->getID();
    QVector<ChatMsg *> result_;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(setting::getGlobalPath() + "\\storage\\" + QString::number(User::getUser()->getID()) + "\\chat_record.db");
    QString sql = QString("select * from record");
    if(db.open()){
        QSqlQuery result = db.exec(sql);
        while(result.next()){
            ChatMsg* temp = new ChatMsg();
            temp->setChatID(result.value("chatID").toInt());
            temp->setID(result.value("ID").toInt());
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

QVector<ChatMsg *> ChatServer::getMsgs(QString sTime, QString eTime)
{
    QVector<ChatMsg *> result_;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(setting::getGlobalPath() + "\\storage\\" + QString::number(User::getUser()->getID()) + "\\chat_record.db");
    QString sql = QString("select * from record where time1 <= %1 and time1 >= %2")
                      .arg("\'" + sTime + "\'").arg("\'" + eTime + "\'");
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
