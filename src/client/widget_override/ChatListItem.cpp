#include "ChatListItem.h"

ChatListItem::ChatListItem(QListWidget *widget) : QListWidgetItem(widget){}

ChatListItem::ChatListItem(int ID, QListWidget *widget) : QListWidgetItem(widget), _ID(ID) {}

void ChatListItem::setID(int ID) {
    _ID = ID;
}

int ChatListItem::getID() {
    return _ID;
}
