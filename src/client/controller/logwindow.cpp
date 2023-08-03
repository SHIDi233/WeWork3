#include "logwindow.h"
#include "server/chatserver.h"
#include "ui_logwindow.h"
#include <QLayout>
#include <QSpacerItem>
#include "msgitem.h"
#include "mesend.h"
#include "friendsend.h"
#include "utils/encryption.h"
#include "utils/setting.h"
#include <QFileDialog>

#include "server/global.h"
#include <QtConcurrent>

#include "server/file_receiver.h"


logWindow::logWindow(chatObject *me ,QWidget *parent) :
    QWidget(parent),
    me(me),
    ui(new Ui::logWindow),
    chats(me->members)
{
    ui->setupUi(this);

    cur_index = -1;

    QPixmap headPix(QString(":/new/head/image/head_%1.png").arg(me->getHead()));
    ui->head->setScaledContents(true);
    ui->head->setPixmap(headPix);

    connect(ui->chat_choose_button, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->pyq_choose_button, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->item_choose_button, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->set_choose_button, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(3);
    });



    QVBoxLayout *fLayout = new QVBoxLayout();

    fLayout->setSpacing(0);
    fLayout->setMargin(0);
    fLayout->setDirection(QBoxLayout::TopToBottom);

    ui->friendsArea->widget()->setLayout(fLayout);

    //初始化聊天窗口
    for(int i = 0; i < chats.size(); i++) {
        FriendFrame *qpb = new FriendFrame(chats[i]->getHead(), chats[i]->getName(), ui->chat_list);

        //friends.push_back(qpb);
        //qpb->setText(QString(chats[i]->getName()));
        qpb->setMinimumSize(QSize(232, 70));
        //friends.push_back(qpb);
        ChatListItem *item = new ChatListItem(chats[i]->getID(), ui->chat_list);
        item->setSizeHint(QSize(232, 70));
        qpb->setVisible(true);
        ui->chat_list->setItemWidget(item, qpb);
//        ui->chat_list->addItem(item);
        //fLayout->addWidget(qpb);

//        QScrollArea *chat_area = new QScrollArea();
        QListWidget *chat_area = new QListWidget();
//        QWidget *widget = new QWidget();
        QVBoxLayout *chat_area_layout = new QVBoxLayout();
        chat_area_layout->setSpacing(0);
        chat_layouts.push_back(chat_area_layout);
        //chat_area->setLayout(chat_area_layout);
        chat_area->setLayout(chat_area_layout);
        chat_area->show();
        chat_area->setGeometry(0, 0, ui->chat_stack_widget->width(), ui->chat_stack_widget->height());
//        chat_area->setLineWidth(ui->chat_stack_widget->width());
//        chat_area->setGridSize(QSize(ui->chat_stack_widget->width() - 2, ui->chat_stack_widget->height() - 2));
//        chat_area->setFixedWidth(300);
        chat_area->setAutoScroll(true);
        chat_area->setAutoScrollMargin(16);
        chat_area->setSelectionRectVisible(false);
        chat_area->setSelectionMode(QAbstractItemView::NoSelection);
//        chat_area->setGeometry(0, 0, ui->chat_stack_widget->width(), ui->chat_stack_widget->height());
        chat_area_layout->setMargin(0);
//        chat_area->setWidget(widget);
//        chat_area->setWidgetResizable(true);
        //chat_area->setStyleSheet(QString::fromUtf8("border:3px solid blue"));
        chat_lists.append(chat_area);
        ui->chat_stack_widget->addWidget(chat_area);

    }
    if(chats.size() <= 8) {
        fLayout->addSpacerItem(new QSpacerItem(20, 9 + (9 - chats.size()) * 70, QSizePolicy::Expanding));
    }
    //设置点击事件
//    for(int i = 0; i < friends.size(); i++) {
//        QPushButton *qpb = friends[i];
//        connect(qpb, &QPushButton::clicked, this, [=](){
//            cur_index = i;
//            ui->chat_title->setText(chats[i]->getName());
//            ui->chat_stack_widget->setCurrentIndex(i + 2);
//        });
//    }

//    QPushButton *qpb = friends[1];
//    fLayout->removeWidget(qpb);
//    fLayout->insertWidget(0, qpb);

    //初始化朋友圈
//    pyq = new Widget(me, ui->scrollArea_3);
//    pyq->show();

    //初始化设置界面
    ui->path_line->setText(setting::getGlobalPath());
    ui->key_hint->setVisible(false);
    ui->iv_hint->setVisible(false);
    ui->key_line->setText(setting::getKey());
    ui->iv_line->setText(setting::getIv());

    //初始化系统托盘
    systemtrayicon = new QSystemTrayIcon(this);
    QIcon icon = QIcon(":/lib/qusefdogicon.png");
    //添加图标
    systemtrayicon->setIcon(icon);
    //当鼠标悬浮，显示文字
    systemtrayicon->setToolTip(QObject::trUtf8("Fdog"));
    //显示图标
    systemtrayicon->show();

    connect(ui->chat_list, SIGNAL(itemClicked(QListWidgetItem*)),
                this, SLOT(onListMailItemClicked(QListWidgetItem*)));

    QTimer* m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(refresh_msg()));
    m_pTimer->start(500);

    QTimer* m_pTimer_2 = new QTimer(this);
    connect(m_pTimer_2, SIGNAL(timeout()), this, SLOT(update_msg()));
    m_pTimer_2->start(1000);

    init();

    //下载队列
    QtConcurrent::run([=](){
                    while(1){
            if(downloading.length()>0 &&id1.length()>0 &&id2.length()>0 &&wid.length()>0 && Config::get()->server->rece_file(downloading[0])){
                qDebug()<<"1d";

                qDebug()<<"2d";
                //下载
                File_Receiver* fr = new File_Receiver(downloading[0],"192.168.10.51",QString::number(10000+Config::get()->server->getSID()));
                QString name = downloading[0];
                qDebug()<<"3d";

                QStringList list;

                list.append(name);
                list.append(id1[0]);
                list.append(id2[0]);
                list.append(wid[0]);

                fr->run();
                qDebug()<<"4d";
                //更新


                pics.append(list);

                downloading.pop_front();
                id1.pop_front();
                id2.pop_front();
                wid.pop_front();
//                            break;

            }
            else{
//                            downloading.pop_front();
//                            break;
                        }
        }
    });
}

void logWindow::update_msg(){
    QtConcurrent::run([=]() {
        res = Config::get()->server->rece_msg();
    });
}

void logWindow::refresh_msg(){
    for(int i=0;i<pics.length();i++){
        if(pics[i].length()!=4){
            i-=1;
            continue;
        }
        setPic(pics[i][0], pics[i][1].toInt(), QNChatMessage::User_She,pics[i][2].toInt());
        QString time = QString::number(QDateTime::currentDateTime().toTime_t());
        ChatServer::ChatStorage(pics[i][1].toInt(), pics[i][0], ChatMsg::Pic, pics[i][2].toInt(), time, pics[i][3]);
        pics.pop_front();
    }

//    pics.clear();

    for(int i=0;i<res.count();i++){

        if(res[i][2]=="text"){//文本
            QString eMsg = res[i][4];
            std::string m = Encryption::decryptWords(std::string(eMsg.toLatin1()), setting::getKey().toStdString(), setting::getIv().toStdString());
            QString msg = QString::fromStdString(m);
            setMsg(msg,res[i][1].toInt(),QNChatMessage::User_She,res[i][1].toInt());
            QString time = QString::number(QDateTime::currentDateTime().toTime_t());
            ChatServer::ChatStorage(res[i][1].toInt(), eMsg, ChatMsg::Word, res[i][1].toInt(), time, res[i][0]);
        }
        else if(res[i][2]=="source"){//资源

            QStringList list = res[i][4].split('.');
//            list[list.count()-1]=list[list.count()-1].toLower();
            if(list[list.count()-1]=="jpg" ||list[list.count()-1]=="png" ||list[list.count()-1]=="gif" ||list[list.count()-1]=="jpeg" ||list[list.count()-1]=="webp" ||list[list.count()-1]=="bmp"){
                //图片格式
                setMsg("[图片]"+res[i][4],res[i][1].toInt(),QNChatMessage::User_She,res[i][1].toInt());
                QString time = QString::number(QDateTime::currentDateTime().toTime_t());
//                ChatServer::ChatStorage(res[i][1].toInt(), "[图片]"+res[i][4], ChatMsg::Word, res[i][1].toInt(), time, res[i][0]);
                downloading.append(res[i][4]);
                id1.append(res[i][1]);
                id2.append(res[i][1]);
                wid.append(res[i][0]);

            }
            else if(list[list.count()-1]=="mp4" ||list[list.count()-1]=="mepg" ||list[list.count()-1]=="flv"  ||list[list.count()-1]=="avi"){
                //视频格式
            }
            else if(list[list.count()-1]=="mp3" ||list[list.count()-1]=="wma" ||list[list.count()-1]=="wav" ||list[list.count()-1]=="flac"){
                //音频格式
            }
            else{
                //文件格式
            }
//            setPic(picPath, chats[cur_index]->getID(), QNChatMessage::User_Me, me->getID());
//            setMsg("图片",res[i][1].toInt(),QNChatMessage::User_She,res[i][1].toInt());
//            QString time = QString::number(QDateTime::currentDateTime().toTime_t());
//            ChatServer::ChatStorage(res[i][1].toInt(), eMsg, ChatMsg::Word, res[i][1].toInt(), time, res[i][0]);
        }


    }
    res.clear();
}

void logWindow::onListMailItemClicked(QListWidgetItem* item)
{
//    if (ui->listMail->item(0) == item) {
//        // This is the first item.
//    }
    auto item2 = (ChatListItem*) item;
    int ID = item2->getID();
//    qDebug() << "select" << ID;
    for(int i = 0; i < chats.size(); i++) {
        if(chats[i]->getID() == ID) {
            ui->chat_title->setText(chats[i]->getName());
            ui->chat_stack_widget->setCurrentIndex(i + 2);
            cur_index = i;
        }
    }
}

/**
 * @brief 从本地数据库中获取数据并展示
 */
void logWindow::init() {
    ChatServer::initDatabase();
    QVector<ChatMsg*> msg = ChatServer::getMsgs();
    for(auto &m : msg) {
        if(m->getType() == ChatMsg::Word) {
            QNChatMessage::User_Type t;
            if(m->getChatID() == me->getID()) { t = QNChatMessage::User_Me; }
            else { t = QNChatMessage::User_She; }
            setMsg(m->getContent(), m->getID(), t, m->getChatID(), false);
        }
        if(m->getType() == ChatMsg::Pic) {
            QNChatMessage::User_Type t;
            if(m->getChatID() == me->getID()) { t = QNChatMessage::User_Me; }
            else { t = QNChatMessage::User_She; }
            setPic(m->getContent(), m->getID(), t, m->getChatID(), false);
        }
    }
}

logWindow::~logWindow()
{
    delete ui;
}

void logWindow::on_send_button_clicked()
{
    /* 将信息存入本地 */


    QString msg = ui->texteditInput->toPlainText();
    if(msg == "") { return; }
    ui->texteditInput->clear();
    int index = setMsg(msg, chats[cur_index]->getID(), QNChatMessage::User_Me, me->getID());
    QString time = QString::number(QDateTime::currentDateTime().toTime_t());
    ChatServer::ChatStorage(chats[cur_index]->getID(), msg, ChatMsg::Word, me->getID(), time,"0");


    //网络发送
    if(Config::get()->server==nullptr){
        qDebug()<<"bug";
        return;
    }
//    QString eMsg = Encryption::encryptWords()

    bool is;
    QtConcurrent::run([=]() {
        std::string eMsg =Encryption::encryptWords(msg.toStdString(), setting::getKey().toStdString(), setting::getIv().toStdString());
        QString qeMsg = QString::fromLatin1(eMsg.c_str());
        if(Config::get()->server->send_msg(QString::number(chats[index]->getID()),qeMsg))
            qDebug()<<"已发送(异步)";
        else
            qDebug()<<"未发送(异步)";
    });
}

int logWindow::setMsg(QString msg, int ID, QNChatMessage::User_Type type, int chatID, bool needTime) {

    int index = -1;
    //寻找消息发送对象
    for(int i = 0; i < chats.size(); i++) {
        if(chats[i]->getID() == ID) {
            index = i;
            break;
        }
    }
    if(index == -1) { return -1; }
    QString name;
    if(type == QNChatMessage::User_Me) {
        name = me->getName();
    }
    else if(ID == chatID) {
        name = chats[index]->getName();
    } else {
        bool isFound = false;
        for(int i = 0; i < chats[index]->members.size(); i++) {
            if(chats[index]->members[i]->getID() == chatID) {
                name = chats[index]->members[i]->getName();
                isFound = true;
                break;
            }
        }
        if(!isFound) { return -1; }
    }

    bool isSending = false; // 发送中
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳

//    qDebug()<<"addMessage" << msg << time << chat_lists[cur_index]->count();
    if(isSending) {
        if(needTime) { dealMessageTime(time, index); }

        QNChatMessage* messageW = new QNChatMessage(chat_lists[cur_index]->parentWidget());
        QListWidgetItem* item = new QListWidgetItem(chat_lists[cur_index]);
        messageW->setName(name);
        dealMessage(messageW, item, msg, time, type, index);
    } else {
        bool isOver = true;
//        for(int i = chat_lists[index]->count() - 1; i > 0; i--) {
//            QNChatMessage* messageW = (QNChatMessage*)chat_lists[index]->itemWidget(chat_lists[index]->item(i));
//            if(messageW->text() == msg) {
//                isOver = false;
//                messageW->setTextSuccess();
//            }
//        }
        if(1) {
            if(needTime) { dealMessageTime(time, index); }

            QNChatMessage* messageW = new QNChatMessage(chat_lists[index]->parentWidget());
            QListWidgetItem* item = new QListWidgetItem(chat_lists[index]);
            messageW->setName(name);
            dealMessage(messageW, item, msg, time, type, index);
            messageW->setTextSuccess();
        }
    }
    chat_lists[index]->setCurrentRow(chat_lists[index]->count()-1);
    return index;
}

int logWindow::setPic(QString path, int ID, QNChatMessage::User_Type type, int chatID, bool needTime, QNChatMessage::Chat_Type msgType) {

    int index = -1;
    //寻找消息发送对象
    for(int i = 0; i < chats.size(); i++) {
        if(chats[i]->getID() == ID) {
            index = i;
            break;
        }
    }
    if(index == -1) { return -1; }

    QString name;
    if(type == QNChatMessage::User_Me) {
        name = me->getName();
    }
    else if(ID == chatID) {
        name = chats[index]->getName();
    } else {
        bool isFound = false;
        for(int i = 0; i < chats[index]->members.size(); i++) {
            if(chats[index]->members[i]->getID() == chatID) {
                name = chats[index]->members[i]->getName();
                isFound = true;
                break;
            }
        }
        if(!isFound) { return -1; }
    }

    bool isSending = false; // 发送中
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳

//    qDebug()<<"addMessage" << msg << time << chat_lists[cur_index]->count();
    if(isSending) {
        if(needTime) { dealMessageTime(time, index); }

        QNChatMessage* messageW = new QNChatMessage(chat_lists[index]->parentWidget());
        QListWidgetItem* item = new QListWidgetItem(chat_lists[index]);
        messageW->setName(name);
        dealPic(messageW, item, path, time, type, index, msgType);
    } else {
        bool isOver = true;
        for(int i = chat_lists[index]->count() - 1; i > 0; i--) {
            QNChatMessage* messageW = (QNChatMessage*)chat_lists[index]->itemWidget(chat_lists[index]->item(i));
            if(messageW->text() == path) {
                isOver = false;
                messageW->setTextSuccess();
            }
        }
        if(1) {
            if(needTime) { dealMessageTime(time, index); }

            QNChatMessage* messageW = new QNChatMessage(chat_lists[index]->parentWidget());
            QListWidgetItem* item = new QListWidgetItem(chat_lists[index]);
            messageW->setName(name);
            dealPic(messageW, item, path, time, type, index, msgType);
            messageW->setTextSuccess();
        }
    }
    chat_lists[index]->setCurrentRow(chat_lists[index]->count()-1);
    return index;
}


void logWindow::dealMessage(QNChatMessage *messageW, QListWidgetItem *item, QString text, QString time,  QNChatMessage::User_Type type, int index)
{
    messageW->setFixedWidth(ui->chat_stack_widget->width() - 4);
    QSize size = messageW->fontRect(text);
    item->setSizeHint(size);

//    item->setSizeHint(QSize(5, 100));
    messageW->setText(text, time, size, type);
    messageW->setGeometry(0, 0, ui->chat_stack_widget->width(), ui->chat_stack_widget->height());
//    item->setSizeHint()
    chat_lists[index]->setItemWidget(item, messageW);
}

void logWindow::dealPic(QNChatMessage *messageW, QListWidgetItem *item, QString path, QString time,  QNChatMessage::User_Type type, int index, QNChatMessage::Chat_Type msgType)
{
    messageW->setFixedWidth(ui->chat_stack_widget->width() - 4);
    QSize size = messageW->fontRectPic(path, msgType);
    item->setSizeHint(size);

//    item->setSizeHint(QSize(5, 100));
    messageW->setPic(path, time, size, type);
    messageW->setGeometry(0, 0, ui->chat_stack_widget->width(), ui->chat_stack_widget->height());
//    item->setSizeHint()
    chat_lists[index]->setItemWidget(item, messageW);
}

void logWindow::dealMessageTime(QString curMsgTime, int index)
{
    bool isShowTime = false;
    if(chat_lists[index]->count() > 0) {
        QListWidgetItem* lastItem = chat_lists[index]->item(chat_lists[index]->count() - 1);
        QNChatMessage* messageW = (QNChatMessage*)chat_lists[index]->itemWidget(lastItem);
        int lastTime = messageW->time().toInt();
        int curTime = curMsgTime.toInt();
        qDebug() << "curTime lastTime:" << curTime - lastTime;
        isShowTime = ((curTime - lastTime) > 180); // 两个消息相差一分钟
//        isShowTime = true;
    } else {
        isShowTime = true;
    }
    if(isShowTime) {
        QNChatMessage* messageTime = new QNChatMessage(chat_lists[index]->parentWidget());
        QListWidgetItem* itemTime = new QListWidgetItem(chat_lists[index]);

        QSize size = QSize(ui->chat_stack_widget->width() - 4, 40);
        messageTime->resize(size);
        itemTime->setSizeHint(size);
        messageTime->setText(curMsgTime, curMsgTime, size, QNChatMessage::User_Time);
        chat_lists[index]->setItemWidget(itemTime, messageTime);
    }
}

void logWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);


//    ui->texteditInput->resize(this->width() - 20, ui->widget->height() - 20);
//    ui->texteditInput->move(10, 10);

//    ui->pushButton->move(ui->texteditInput->width()+ui->texteditInput->x() - ui->pushButton->width() - 10,
//                         ui->texteditInput->height()+ui->texteditInput->y() - ui->pushButton->height() - 10);


//    for(int i = 0; i < chat_lists[cur_index]->count(); i++) {
//        QNChatMessage* messageW = (QNChatMessage*)chat_lists[cur_index]->itemWidget(chat_lists[cur_index]->item(i));
//        QListWidgetItem* item = chat_lists[cur_index]->item(i);

//        dealMessage(messageW, item, messageW->text(), messageW->time(), messageW->userType());
//    }
}

//发送图片
void logWindow::on_pic_send_clicked()
{
    if(cur_index < 0) return;

    QString picPath = QFileDialog::getOpenFileName(this, tr("选择要发送的图片"), "/", tr("图片文件 (*.jpg *.png *.bmg *.jpeg)"));

    if(picPath == "")
        return;
    else{
        int index = setPic(picPath, chats[cur_index]->getID(), QNChatMessage::User_Me, me->getID());
        Config::get()->server->send_file(QString::number(chats[index]->getID()),picPath);

        QString time = QString::number(QDateTime::currentDateTime().toTime_t());
        ChatServer::ChatStorage(chats[cur_index]->getID(),picPath , ChatMsg::Pic, me->getID(), time, "0");
    }

//    //通过网络发送图片(picPath路径的图片)****************************
}

bool logWindow::receiveMsg(QString msg, int ID, QString name) {
    int index = -1;
    //寻找消息发送对象
    for(int i = 0; i < chats.size(); i++) {
        if(chats[i]->getID() == ID) {
            index = i;
            break;
        }
    }
    if(index == -1) { return false; }

    QHBoxLayout *pHboxLayout = new QHBoxLayout();

    MsgItem *pItem = new MsgItem(ui->chat_stack_widget->widget(cur_index + 2), E_WHOSAY::eFriend);
    pItem->setMsg(msg);
    //pHboxLayout->addWidget(new QPushButton);
    FriendSend *friendSend = new FriendSend(ui->chat_stack_widget->widget(cur_index + 2), pItem, chats[index]->getHead(), name);
    pHboxLayout->addWidget(friendSend);
    pHboxLayout->insertStretch(0);
    pHboxLayout->addSpacing(100);
    //m_pVboxLayout->addLayout(pHboxLayout);
    chat_layouts[index]->addLayout(pHboxLayout);
}

//接收图片
bool logWindow::receivePic(QString path, int ID, QString name) {
    int index = -1;
    //寻找消息发送对象
    for(int i = 0; i < chats.size(); i++) {
        if(chats[i]->getID() == ID) {
            index = i;
            break;
        }
    }
    if(index == -1) { return false; }

    QHBoxLayout *pHboxLayout = new QHBoxLayout();
    FriendSend *friendSend = new FriendSend(ui->chat_stack_widget->widget(cur_index + 2), path, chats[index]->getHead(), name, F_TYPE::fPic);
    pHboxLayout->insertStretch(0);
    pHboxLayout->addWidget(friendSend);
    chat_layouts[cur_index]->addLayout(pHboxLayout);
}

//发送视频
void logWindow::on_video_send_clicked()
{
    if(cur_index < 0) return;

    QString videoPath = QFileDialog::getOpenFileName(this, tr("选择要发送的视频"), "/", tr("视频文件 (*.mp4 *.avi *.rmvb *.wmv)"));

    if(videoPath == "")
        return;
    else{
        int index = setPic(videoPath, chats[cur_index]->getID(), QNChatMessage::User_Me, me->getID(), true, QNChatMessage::Chat_Video);
        Config::get()->server->send_file(QString::number(chats[index]->getID()),videoPath);

        QString time = QString::number(QDateTime::currentDateTime().toTime_t());
        ChatServer::ChatStorage(chats[cur_index]->getID(),videoPath , ChatMsg::Video, me->getID(), time, "0");
    }
}

//接收视频
bool logWindow::receiveVideo(QString path, int ID, QString name) {
    int index = -1;
    //寻找消息发送对象
    for(int i = 0; i < chats.size(); i++) {
        if(chats[i]->getID() == ID) {
            index = i;
            break;
        }
    }
    if(index == -1) { return false; }

    QHBoxLayout *pHboxLayout = new QHBoxLayout();
    FriendSend *friendSend = new FriendSend(ui->chat_stack_widget->widget(cur_index + 2), path, chats[index]->getHead(), name, F_TYPE::fVideo);
    pHboxLayout->insertStretch(0);
    pHboxLayout->addWidget(friendSend);
    chat_layouts[cur_index]->addLayout(pHboxLayout);
}

void logWindow::on_video_send_2_clicked()
{
    if(cur_index < 0) return;

    QString videoPath = QFileDialog::getOpenFileName(this, tr("选择要发送的视频"), "/", tr("视频文件 (*.mp4 *.avi *.rmvb *.wmv)"));

    if(videoPath == "")
        return;
    else{
        int index = setPic(videoPath, chats[cur_index]->getID(), QNChatMessage::User_Me, me->getID(), true, QNChatMessage::Chat_File);
        Config::get()->server->send_file(QString::number(chats[index]->getID()),videoPath);

        QString time = QString::number(QDateTime::currentDateTime().toTime_t());
        ChatServer::ChatStorage(chats[cur_index]->getID(),videoPath , ChatMsg::File, me->getID(), time, "0");
    }
}

//接收文件
bool logWindow::receiveFile(QString path, int ID, QString name) {
    int index = -1;
    //寻找消息发送对象
    for(int i = 0; i < chats.size(); i++) {
        if(chats[i]->getID() == ID) {
            index = i;
            break;
        }
    }
    if(index == -1) { return false; }

    QHBoxLayout *pHboxLayout = new QHBoxLayout();
    FriendSend *friendSend = new FriendSend(ui->chat_stack_widget->widget(cur_index + 2), path, chats[index]->getHead(), name, F_TYPE::fFile);
    pHboxLayout->insertStretch(0);
    pHboxLayout->addWidget(friendSend);
    chat_layouts[cur_index]->addLayout(pHboxLayout);
}

void logWindow::on_path_change_clicked()
{

}


void logWindow::on_path_open_clicked()
{

}


void logWindow::on_key_change_clicked()
{
    ui->key_line->setReadOnly(false);
    ui->key_line->selectAll();
}




void logWindow::on_key_save_clicked()
{
    QString key = ui->key_line->text();
    if(key.size() != 16) {
        ui->key_hint->setVisible(true);
        return;
    }
    ui->key_hint->setVisible(false);
    ui->key_line->setReadOnly(true);
    setting::setKey(key);
}


void logWindow::on_iv_change_clicked()
{
    ui->iv_line->setReadOnly(false);
    ui->iv_line->selectAll();
}


void logWindow::on_iv_save_clicked()
{
    QString iv = ui->iv_line->text();
    if(iv.size() != 16) {
        ui->iv_hint->setVisible(true);
        return;
    }
    ui->iv_hint->setVisible(false);
    ui->iv_line->setReadOnly(true);
    setting::setKey(iv);
}

