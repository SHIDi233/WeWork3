#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTimer>
#include <QThread>

#include "file_receiver.h"
#include "file_sender.h"

class Server : public QThread
{
    Q_OBJECT
public:
    Server();

    //功能函数接口
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

    void setLast(int num);

    bool login(QString acc, QString pass);//登录
    bool send_msg(QString receiver, QString text);//发信息
    bool send_file(QString receiver,QString url);//发文件
    QVector<QStringList> rece_msg();//消息推送接收
    bool rece_file(QString fileName);

    QStringList rece_peo();//好友推送接收

    int getID();
    int getSID();

private slots:
//    void on_pushButton_clicked();
    void update();//token更新

//    void disconnect();

private:
    QTcpSocket* socket;
    QString filename;
    quint64 filesize;
    quint64 sendsize;
    QString name;
    QString ip="192.168.10.51";
    QString port="9000";

    int rate=10;

    QString token;

    QTimer *m_pTimer;

    bool isOnline = false;

    int chatNum = 1;



private slots:
//    void send_login();
//    void send_msg();
//    void send_file();
//    void send_heart();

//    void rece_msg();
//    void rece_file();

    void online_check();
};

#endif // SERVER_H
