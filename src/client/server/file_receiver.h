#ifndef FILE_RECEIVER_H
#define FILE_RECEIVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QDataStream>
#include <QThread>

class File_Receiver : public QThread
{
    Q_OBJECT
public:
    File_Receiver(QString port);
    File_Receiver(QString name, QString ip, QString port);//有ip
    void run();
protected slots:
    void read_data();
    void connected();
protected:

private:
    QTcpServer *server;
    QString port;
    QString ip;
    QFile file;
    QString filename;
    quint64 filesize;
    quint64 recvsize;
    QString name;
    quint64 sendsize;

    QTcpSocket *msocket;

    bool isIP = false;

    int rate=10;
};

#endif // FILE_RECEIVER_H
