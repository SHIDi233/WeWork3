#include "chatserver.h"


/**
 * @brief 将聊天内容存入本地
 * @param chatID: 文字发送对象的ID
 * @param content: 文字内容
 * @param type: 聊天类型(私聊-TYPE::Person/群组-TYPE::Group)
 * @param groupID: 可选参数，若聊天类型是私聊，则该参数无意义，反之为群组ID
 */
void ChatServer::wordStorage(int chatID, QString content, TYPE type, int groupID) {

}
