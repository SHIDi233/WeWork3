#include "user.h"

User* User::user = new User();

User* User::getUser() {
    return user;
}

void User::setName(QString name) {
    _name = name;
}

void User::setToken(QString token) {
    _token = token;
}

void User::setHead(QString head) {
    _head = head;
}

void User::setID(int ID) {
    _ID = ID;
}

QString User::getName() {
    return _name;
}

int User::getID() {
    return _ID;
}

QString User::getToken() {
    return _token;
}

QString User::getHead() {
    return _head;
}

User::User()
{
}
