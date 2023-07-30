#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:

    static User* getUser();
    void setName(QString name);
    void setToken(QString token);
    void setHead(QString head);
    void setID(int ID);
    QString getName();
    int getID();
    QString getToken();
    QString getHead();

private:

    //将构造函数与析构函数设置为私有，构造单例模式
    User();
    ~User();
    //不允许复制与赋值
    User(const User&);
    const User &operator=(const User&);

    QString _name; //用户名
    int _ID; //账号
    QString _token; //令牌
    QString _head; //头像url

    //唯一实例
    static User* user;
};

#endif // USER_H
