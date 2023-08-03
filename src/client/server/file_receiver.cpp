#include "file_receiver.h"

#include <QFileInfo>

File_Receiver::File_Receiver(QString port)
{
    this->moveToThread(this);
    this->port = port;
}

File_Receiver::File_Receiver(QString name, QString ip, QString port)
{
    this->isIP = true;
    this->moveToThread(this);
    this->ip = ip;
    this->port = port;
    this->name = name;
}

void File_Receiver::connected()
{
//    this->moveToThread(this);

    qDebug()<<"文件接收-连接1";
    //创建与客户端通信的套接字
    msocket = server->nextPendingConnection();
    //关联读数据信号readyRead
//    connect(msocket, &QTcpSocket::readyRead, this, &File_Receiver::read_data);
    filesize = 0;
    recvsize = 0;
}

void File_Receiver::read_data()
{
    qDebug()<<"文件接收-连接2";
    if(filesize == 0) //表达第一次读取数据--读文件信息
    {
        QByteArray array = msocket->readAll();
        QDataStream stream(&array, QIODevice::ReadOnly);//把套接字与数据流绑定
        stream>>filesize>>filename;//获取文件大小， 文件名

        //打开文件
        file.setFileName(filename);
        file.open(QIODevice::WriteOnly);

    }

    //读文件内容
    if(recvsize <  filesize)
    {
        //读取一段写一段
        QByteArray array = msocket->readAll();
        file.write(array);
        recvsize += array.size();

        qDebug()<<"接收进度:"+QString::number((float)recvsize/filesize);
    }

    if(recvsize == filesize)
    {
        qDebug()<<"receive end";
        //读完，关闭文件
        file.close();
        //关闭套接字
        msocket->disconnectFromHost();
        exit(0);

    }
}

void File_Receiver::run(){

    qDebug()<<"33d";

    if(isIP){
        //连接服务器
    //    delete socket;
        QTcpSocket* msocket = new QTcpSocket(this);
        msocket->connectToHost(ip, QString(port).toUShort());
            filesize = 0;
            recvsize = 0;
            qDebug()<<"34d";
        if(msocket->waitForConnected(2000)){
            qDebug()<<"34d-连接成功";
            if(msocket->waitForReadyRead(2000)){
                qDebug()<<"34d-可读";
                qDebug()<<"文件接收-连接2";
                if(filesize == 0) //表达第一次读取数据--读文件信息
                {
                    QByteArray array = msocket->readAll();
                    QDataStream stream(&array, QIODevice::ReadOnly);//把套接字与数据流绑定
                    stream>>filesize>>filename;//获取文件大小， 文件名

                    //打开文件
                    file.setFileName(filename);
                    file.open(QIODevice::WriteOnly);

                }
                qDebug()<<"34d-文件名已读取";
                qDebug()<<recvsize;
                qDebug()<<filesize;
                while(1){
                    qDebug()<<"35d-开始下载";
                    if(msocket->waitForReadyRead(2000)){
                        //读文件内容
                        if(recvsize <  filesize)
                        {
                            //读取一段写一段
                            QByteArray array = msocket->readAll();
                            file.write(array);
                            recvsize += array.size();

                            qDebug()<<"接收进度:"+QString::number((float)recvsize/filesize);
                        }

                        if(recvsize == filesize)
                        {
                            qDebug()<<"receive end";
                            //读完，关闭文件
                            file.close();
                            //关闭套接字
                            msocket->close();
                            break;
                        }
                    }
                }
            }
            qDebug()<<"end";
        }
    }
    else{
        //    delete server;
            server = new QTcpServer(this);

        //    connect(server, &QTcpServer::newConnection, this, &File_Receiver::connected);

            //启动服务器
            server->listen(QHostAddress::Any,port.toUShort());

            if(server->waitForNewConnection(2000)){
                qDebug()<<"服务端CHW连接成功";
                qDebug()<<"文件接收-连接1";
                //创建与客户端通信的套接字
        //        delete msocket;
                msocket = server->nextPendingConnection();
                //关联读数据信号readyRead
        //        connect(msocket, &QTcpSocket::readyRead, this, &File_Receiver::read_data);
                filesize = 0;
                recvsize = 0;

                if(msocket->waitForReadyRead(2000)){
                    qDebug()<<"文件接收-连接2";
                    if(filesize == 0) //表达第一次读取数据--读文件信息
                    {
                        QByteArray array = msocket->readAll();
                        QDataStream stream(&array, QIODevice::ReadOnly);//把套接字与数据流绑定
                        stream>>filesize>>filename;//获取文件大小， 文件名

                        //打开文件
                        file.setFileName(filename);
                        file.open(QIODevice::WriteOnly);

                    }

                    while(1){
                        if(msocket->waitForReadyRead(2000)){
                            //读文件内容
                            if(recvsize <  filesize)
                            {
                                //读取一段写一段
                                QByteArray array = msocket->readAll();
                                file.write(array);
                                recvsize += array.size();

                                qDebug()<<"接收进度:"+QString::number((float)recvsize/filesize);
                            }

                            if(recvsize == filesize)
                            {
                                qDebug()<<"receive end";
                                //读完，关闭文件
                                file.close();
                                //关闭套接字
//                                msocket->close();
                                break;
                            }
                        }
                    }
                }
            }
            qDebug()<<"end";
    }
}
