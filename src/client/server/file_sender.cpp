#include "file_sender.h"

File_Sender::File_Sender(QString port){
    this->moveToThread(this);
    isIP=false;
    this->port=port;
}

File_Sender::File_Sender(QString name, QString ip, QString port)
{
    this->moveToThread(this);

    this->name = name;
    this->name = name;
    this->ip = ip;
    this->port=port;

//    //连接服务器
//    socket.connectToHost(ip, port.toUShort());

//    //发送文件信息
//    qDebug()<<"connect";

//    //初始化
//    filesize = 0;
//    sendsize = 0;

//    //连接成功会发送connected
//    connect(&socket, &QTcpSocket::connected, this, &File_Sender::send_header);

//    //发送完毕信号
//    connect(&socket, &QTcpSocket::bytesWritten, this, &File_Sender::send_file);
}

void File_Sender::run(){

    if(isIP){
        //连接服务器
    //    delete socket;
        socket = new QTcpSocket(this);
        socket->connectToHost(ip, port.toUShort());
        //初始化
        filesize = 0;
        sendsize = 0;

        qDebug()<<"文件发送-连接1";
    //    //连接成功信号
    //    connect(socket, &QTcpSocket::connected, this, &File_Sender::send_header);

    //    //发送完毕信号
    //    connect(socket, &QTcpSocket::bytesWritten, this, &File_Sender::send_file);

        if(socket->waitForConnected(2000)){
            qDebug()<<"客户端CHN连接成功";
            qDebug()<<"文件发送-连接2";

            //发送文件名，文件大小
            QFileInfo info(name);//文件信息对象

            filename = info.fileName();
            filesize = info.size();

            qDebug()<<filename;

            QByteArray array;
            //把array与数据流绑定
            QDataStream stream(&array, QIODevice::WriteOnly);
            stream<<filesize<<filename;

            //打开文件准备读取数据发送
            file.setFileName(name);
            file.open(QIODevice::ReadOnly);

            //发送
            socket->write(array);

            while(1){
                if(socket->waitForBytesWritten(2000)){
                    if(sendsize < filesize)
                    {
                        QByteArray array = file.read(1024*rate);//读取
                        socket->write(array);//发送
                        sendsize += array.size();

                        qDebug()<<"发送进度:"+QString::number((float)sendsize/filesize);
                    }
                    if(sendsize == filesize)
                    {
                        socket->flush();
                        file.close();//关闭文件
                        break;
                    }
                }
            }
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
                socket = server->nextPendingConnection();
                //关联读数据信号readyRead
        //        connect(msocket, &QTcpSocket::readyRead, this, &File_Receiver::read_data);
                filesize = 0;
                recvsize = 0;

                if(socket->waitForReadyRead(2000)){
                    qDebug()<<"文件接收-连接2";
                    if(filesize == 0) //表达第一次读取数据--读文件信息
                    {
                        QByteArray array = socket->readAll();
                        QDataStream stream(&array, QIODevice::ReadOnly);//把套接字与数据流绑定
                        stream>>filesize>>filename;//获取文件大小， 文件名

                        //打开文件
                        file.setFileName(filename);
                        file.open(QIODevice::WriteOnly);

                    }

                    while(1){
                        if(socket->waitForReadyRead(2000)){
                            //读文件内容
                            if(recvsize <  filesize)
                            {
                                //读取一段写一段
                                QByteArray array = socket->readAll();
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
                                socket->disconnectFromHost();
                                break;
                            }
                        }
                    }
                }
            }
            server->close();
            qDebug()<<"endddddd";
    }



}

File_Sender::File_Sender(QString name, QString ip, QString port, int rate)
{
    this->moveToThread(this);

    this->name = name;
    this->ip = ip;
    this->port=port;
    this->rate = rate;
}

//发送文件头信息
void File_Sender::send_header()
{
    qDebug()<<"文件发送-连接2";

    //发送文件名，文件大小
    QFileInfo info(name);//文件信息对象

    filename = info.fileName();
    filesize = info.size();

        qDebug()<<filename;

    QByteArray array;
    //把array与数据流绑定
    QDataStream stream(&array, QIODevice::WriteOnly);
    stream<<filesize<<filename;

    //打开文件准备读取数据发送
    file.setFileName(name);
    file.open(QIODevice::ReadOnly);

    //发送
    socket->write(array);
}

void File_Sender::send_file()
{
    if(sendsize < filesize)
    {
        QByteArray array = file.read(1024*rate);//读取
        socket->write(array);//发送
        sendsize += array.size();

        qDebug()<<"发送进度:"+QString::number((float)sendsize/filesize);
    }
    if(sendsize == filesize)
    {
        file.close();//关闭文件
    }
}
