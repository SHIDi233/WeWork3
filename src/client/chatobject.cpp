#include "chatobject.h"

chatObject::chatObject(QString name, int head, int ID, TYPE type) :
    name_(name),
    head_(head),
    ID_(ID),
    type_(type)
{

}

QString chatObject::getName() {
    return name_;
}

int chatObject::getID() {
    return ID_;
}

int chatObject::getHead() {
    return head_;
}

TYPE chatObject::getType() {
    return type_;
}
