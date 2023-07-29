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

void User::setNumber(QString number) {
    _number = number;
}

QString User::getName() {
    return _name;
}

QString User::getNumber() {
    return _number;
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
