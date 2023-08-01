#ifndef CHATLISTITEM_H
#define CHATLISTITEM_H

#include <qlistwidget.h>

class ChatListItem : public QListWidgetItem
{
public:
    ChatListItem(QListWidget *widget = nullptr);
    ChatListItem(int ID, QListWidget *widget = nullptr);
    void setID(int ID);
    int getID();
private:
    int _ID;
};

#endif // CHATLISTITEM_H
