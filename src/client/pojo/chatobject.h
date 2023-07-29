/**
* 存储用户信息及好友信息的类
*/

#ifndef CHATOBJECT_H
#define CHATOBJECT_H

#include <QString>
#include "QVector"

enum TYPE {
    Person,
    Group,
    Me
};

class chatObject
{
public:
    chatObject(QString name, int head, int ID, TYPE type);
    QString getName();
    int getID();
    QVector<chatObject*> members;
    int getHead();
    TYPE getType();
protected:
    QString name_;//名字
    int head_;//头像
    int ID_;//编号
    TYPE type_;//类型
};

#endif // CHATOBJECT_H
