/*-------------------------------------------------
#
# Project created by QtCreator
# Author: 沙振宇
# CreateTime: 2018-07-23
# UpdateTime: 2019-12-27
# Info: Qt5气泡式聊天框——QListWidget+QPainter实现
# Url:https://shazhenyu.blog.csdn.net/article/details/81505832
# Github:https://github.com/ShaShiDiZhuanLan/Demo_MessageChat_Qt
#
#-------------------------------------------------*/
#ifndef QNCHATMESSAGE_H
#define QNCHATMESSAGE_H

#include <QWidget>
#include "piclabel.h"

class QPaintEvent;
class QPainter;
class QLabel;
class QMovie;

class QNChatMessage : public QWidget
{
    Q_OBJECT
public:
    explicit QNChatMessage(QWidget *parent = nullptr);

    enum User_Type{
        User_System,//系统
        User_Me,    //自己
        User_She,   //用户
        User_Time,  //时间
    };

    enum Chat_Type{
        Chat_Msg,  //文字消息
        Chat_Pic,  //图片
        Chat_Video,//视频
        Chat_File  //文件
    };

    void setTextSuccess();
    void setText(QString text, QString time, QSize allSize, User_Type userType);
    void setPic(QString path, QString time, QSize allSize, User_Type userType);
    void setName(QString name);

    QSize getRealString(QString src);
    QSize fontRect(QString str);
    QSize fontRectPic(QString path, Chat_Type chatType=Chat_Pic);

    inline QString text() {return m_msg;}
    inline QString time() {return m_time;}
    inline User_Type userType() {return m_userType;}
protected:
    void paintEvent(QPaintEvent *event);
private:
    QString m_msg;
    QString m_time;
    QString m_curTime;

    QSize m_allSize;
    User_Type m_userType = User_System;
    Chat_Type m_chatType;

    int m_kuangWidth;
    int m_textWidth;
    int m_spaceWid;
    int m_lineHeight;

    QRect m_iconLeftRect;
    QRect m_iconRightRect;
    QRect m_sanjiaoLeftRect;
    QRect m_sanjiaoRightRect;
    QRect m_kuangLeftRect;
    QRect m_kuangRightRect;
    QRect m_textLeftRect;
    QRect m_textRightRect;
    QPixmap m_leftPixmap;
    QPixmap m_rightPixmap;
    QPixmap pic;
    PicLabel *picLabel;
    int widthOfPic;
    QLabel* m_loading = Q_NULLPTR;
    QMovie* m_loadingMovie = Q_NULLPTR;
    bool m_isSending = false;
    int nameHeight;
    QLabel* nameLabel = Q_NULLPTR;
};

#endif // QNCHATMESSAGE_H
