#include "server.h"
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>

Server::Server()
{

}

bool Server::login(QString acc, QString pass){
    QTcpSocket* socket=new QTcpSocket;
    socket->connectToHost(ip, port.toUShort());
    if(socket->waitForConnected(2000)){
        //身份码-信息码-数据
        QString s = "0,1,"+acc+","+pass;
        socket->write(s.toUtf8());
        qDebug()<<"发送";
        if(socket->waitForReadyRead(1000)){
            QByteArray array = socket->readAll();
            QString s(array);
            qDebug()<<s;
            qDebug()<<"(客户端)单次通信成功";

            if(s=="0"){//错误
                qDebug()<<"(客户端)登录失败";
                return false;
            }
            else{
                QStringList res = s.split(",");

                int code = res[0].toInt();
                if(code==1){
                    token = res[1];
                    qDebug()<<"(客户端)登录成功,token="+token;
                    isOnline = true;

                    m_pTimer = new QTimer(this);
                    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(update()));
                    m_pTimer->start(2000);




                    return true;
                }
            }
        }
    }
    return false;
}

void Server::update()
{
    isOnline=false;
    delete socket;
    QTcpSocket* socket=new QTcpSocket;
    socket->connectToHost(ip, port.toUShort());

    if(socket->waitForConnected(2000)){
        //身份码-信息码-数据
        QString s = token+",0,0";
        socket->write(s.toUtf8());
        qDebug()<<"发送";
        if(socket->waitForReadyRead(1000)){
            QByteArray array = socket->readAll();
            QString s(array);
            qDebug()<<s;
            qDebug()<<"(客户端)单次通信成功";

            QStringList res = s.split(",");

            int code = res[0].toInt();
            if(code==1){
                token = res[1];
                qDebug()<<"(客户端)token已更新,token="+token;
                isOnline = true;
            }
            else{
                qDebug()<<"(客户端)token已过期,强制下线";
            }
        }
    }
    if(isOnline)
        qDebug()<<"(客户端)在线";
    else {
        qDebug()<<"(客户端)掉线";
        m_pTimer->stop();
    }

}

void Server::online_check()
{
//    if(isOnline)
//        qDebug()<<"(客户端)在线";
//    else
//        qDebug()<<"(客户端)掉线";
}

bool Server::send_msg(QString receiver,QString text){
    QTcpSocket* socket=new QTcpSocket;
    socket->connectToHost(ip, port.toUShort());

    if(socket->waitForConnected(2000)){
        //身份码-信息码-数据
        QString s = token+",3,"+receiver+","+text;
        socket->write(s.toUtf8());
        qDebug()<<"发送";

            if(socket->waitForReadyRead(1000)){
                QByteArray array = socket->readAll();
                QString s(array);
                qDebug()<<"(客户端)单次通信成功";
                if(s=="1"){
                    qDebug()<<"(客户端)信息发送成功";
                    return true;
                }
            }
    }
    return false;
}

bool Server::send_file(QString receiver,QString url){
    QTcpSocket* socket=new QTcpSocket;
    socket->connectToHost(ip, port.toUShort());
    if(socket->waitForConnected(2000)){
        //身份码-信息码-数据

        QFileInfo info(url);//文件信息对象
        QString filename = info.fileName();

        QString s = token+",4,"+receiver+","+filename;
        socket->write(s.toUtf8());
        qDebug()<<"发送";
            if(socket->waitForReadyRead(1000)){
                QByteArray array = socket->readAll();
                QString s(array);
                if(s=="1"){
                    qDebug()<<"(客户端)文件开始发送";
                }
                File_Sender *fs = new File_Sender(url,"192.168.10.51","8000");
                fs->start();
            }
    }
}

QVector<QStringList> Server::rece_msg(){
    //身份码-信息码-数据
    QTcpSocket* socket=new QTcpSocket;
    socket->connectToHost(ip, port.toUShort());
    QVector<QStringList> res;
    if(socket->waitForConnected(2000)){
        QString s = token+",11,"+QString::number(chatNum);//当前最新聊天记录标识号
        socket->write(s.toUtf8());
        qDebug()<<"发送";
        if(socket->waitForReadyRead(1000)){
            QByteArray array = socket->readAll();
            QString s(array);
            qDebug()<<"(客户端)单次通信成功";

            QJsonParseError err;
            QJsonDocument document=QJsonDocument::fromJson(s.toUtf8(), &err);
            QJsonArray  jsons(document.array());

            for(int i=0;i<jsons.count();i++){
                QJsonValue x  = jsons[i];
                QJsonObject x2 = x.toObject();

                QJsonValue msgID = x2.value("msgID");
                QJsonValue senderID = x2.value("senderID");
                QJsonValue Type = x2.value("Type");
                QJsonValue Time = x2.value("Time");
                QJsonValue Content = x2.value("Content");

                QStringList qs;
                qs.append(msgID.toString());
                qs.append(senderID.toString());
                qs.append(Type.toString());
                qs.append(Time.toString());
                chatNum = msgID.toString().toInt();
                qDebug()<<chatNum;
                qs.append(Content.toString());

                res.append(qs);
            }
        }
    }
    return res;
}

void Server::setLast(int num){
    this->chatNum = num;
}

int Server::getID(){
    QStringList tinf = token.split("|");
    QString acc = tinf[0];
    return acc.toInt();
}

QStringList Server::rece_peo(){
    QTcpSocket* socket=new QTcpSocket;
    socket->connectToHost(ip, port.toUShort());
    if(socket->waitForConnected(2000)){
        QString s = token+",13";//当前最新聊天记录标识号
        socket->write(s.toUtf8());
        qDebug()<<"发送";
        if(socket->waitForReadyRead(1000)){
            QByteArray array = socket->readAll();
            QString s(array);
            qDebug()<<"(客户端)单次通信成功";
            QStringList ret = s.split(",");
            return ret;
        }
    }
    return QStringList();
}
