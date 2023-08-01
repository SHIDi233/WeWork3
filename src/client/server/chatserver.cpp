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

void ChatStorage(int ID, QString content, ChatMsg::MsgType type, int chatID, QString time) {

}
