#include "logwindow.h"
#include "ui_logwindow.h"
#include <QLayout>
#include <QSpacerItem>
#include "msgitem.h"
#include "mesend.h"
#include "friendsend.h"
#include "utils/setting.h"
#include <QFileDialog>

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
    //测试数据
//    chatObject *p1 = new chatObject("童雪", 0, 123, TYPE::Person);
//    chatObject *p2 = new chatObject("刘海明", 0, 345, TYPE::Person);
//    chatObject *p3 = new chatObject("钱波", 0, 456, TYPE::Person);
//    chats.push_back(p1);
//    chats.push_back(p2);
//    chats.push_back(p3);

//    m_pVboxLayout = new QVBoxLayout();
//    m_pVboxLayout->setSpacing(0);
//    ui->chat_area_content->setLayout(m_pVboxLayout);

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
    //QSpacerItem *spacer = new QSpacerItem(232, 70);
//    fLayout->setVerticalSpacing(0);
//    fLayout->setHorizontalSpacing(0);
    fLayout->setSpacing(0);
    fLayout->setMargin(0);
    fLayout->setDirection(QBoxLayout::TopToBottom);
//    for(int i = 0; i < 9; i++) {
//        QPushButton *qpb = new QPushButton();

//        friends.push_back(qpb);
//        qpb->setText(QString("按钮%1").arg(i));
//        qpb->setMinimumSize(QSize(232, 70));
//        fLayout->addWidget(qpb);
//        //ui->gridLayout->addWidget(qpb);
//    }
    //fLayout->addSpacerItem(new QSpacerItem(20, 227, QSizePolicy::Expanding));
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
    pyq = new Widget(me, ui->scrollArea_3);
    pyq->show();

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

}

logWindow::~logWindow()
{
    delete ui;
}

//void logWindow::on_send_button_clicked()
//{
//    if(cur_index < 0) return;

//    QString strInput = ui->texteditInputInput->toPlainText();
//    //去除回车
//    strInput.remove(QChar('\n'));
//    ui->texteditInputInput->clear();

//    //判断输入框是否为空
//    if (strInput.isEmpty()) {
//        return ;
//    }

//    QHBoxLayout *pHboxLayout = new QHBoxLayout();

//    MsgItem *pItem = new MsgItem(ui->chat_stack_widget->widget(cur_index + 2), E_WHOSAY::eMe);
//    pItem->setMsg(strInput);
//    //pHboxLayout->addWidget(new QPushButton);
//    MeSend *meSend = new MeSend(ui->chat_stack_widget->widget(cur_index + 2), pItem, me->getHead(), me->getName());
//    pHboxLayout->insertStretch(0);
//    pHboxLayout->addWidget(meSend);
//    //m_pVboxLayout->addLayout(pHboxLayout);
//    chat_layouts[cur_index]->addLayout(pHboxLayout);

//    //m_pIknow->setQuestion(strInput);
//    //receiveMsg(strInput, 123, "童雪");

//    //通过网络发送文字(strInput)**************************
//}

void logWindow::on_send_button_clicked()
{
    /* 将信息存入本地 */


    QString msg = ui->texteditInput->toPlainText();
    if(msg == "") { return; }
    ui->texteditInput->clear();
    setMsg(msg, chats[cur_index]->getID(), QNChatMessage::User_Me, me->getID());


//    } else {
//        if(msg != "") {
//            dealMessageTime(time);

//            QNChatMessage* messageW = new QNChatMessage(chat_lists[cur_index]->parentWidget());
//            QListWidgetItem* item = new QListWidgetItem(chat_lists[cur_index]);
//            dealMessage(messageW, item, msg, time, QNChatMessage::User_She);
//        }
//    }
}

void logWindow::setMsg(QString msg, int ID, QNChatMessage::User_Type type, int chatID) {

    int index = -1;
    //寻找消息发送对象
    for(int i = 0; i < chats.size(); i++) {
        if(chats[i]->getID() == ID) {
            index = i;
            break;
        }
    }
    if(index == -1) { return; }
    QString name;
    if(type == QNChatMessage::User_Me) {
        name = me->getName();
    }
    else if(ID == chatID) {
        name = chats[index]->getName();
    } else {
        for(int i = 0; i < chats[index]->members.size(); i++) {
            if(chats[index]->members[i]->getID() == chatID) {
                name = chats[index]->members[i]->getName();
                break;
            }
        }
    }

    bool isSending = false; // 发送中
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳

    qDebug()<<"addMessage" << msg << time << chat_lists[cur_index]->count();
    if(isSending) {
        dealMessageTime(time);

        QNChatMessage* messageW = new QNChatMessage(chat_lists[cur_index]->parentWidget());
        QListWidgetItem* item = new QListWidgetItem(chat_lists[cur_index]);
        messageW->setName(name);
        dealMessage(messageW, item, msg, time, type);
    } else {
        bool isOver = true;
        for(int i = chat_lists[index]->count() - 1; i > 0; i--) {
            QNChatMessage* messageW = (QNChatMessage*)chat_lists[index]->itemWidget(chat_lists[index]->item(i));
            if(messageW->text() == msg) {
                isOver = false;
                messageW->setTextSuccess();
            }
        }
        if(1) {
            dealMessageTime(time);

            QNChatMessage* messageW = new QNChatMessage(chat_lists[index]->parentWidget());
            QListWidgetItem* item = new QListWidgetItem(chat_lists[index]);
            messageW->setName(name);
            dealMessage(messageW, item, msg, time, type);
            messageW->setTextSuccess();
        }
    }
    chat_lists[index]->setCurrentRow(chat_lists[index]->count()-1);
}

void logWindow::setPic(QString path, int ID, QNChatMessage::User_Type type, int chatID) {

    int index = -1;
    //寻找消息发送对象
    for(int i = 0; i < chats.size(); i++) {
        if(chats[i]->getID() == ID) {
            index = i;
            break;
        }
    }
    if(index == -1) { return; }

    QString name;
    if(type == QNChatMessage::User_Me) {
        name = me->getName();
    }
    else if(ID == chatID) {
        name = chats[index]->getName();
    } else {
        for(int i = 0; i < chats[index]->members.size(); i++) {
            if(chats[index]->members[i]->getID() == chatID) {
                name = chats[index]->members[i]->getName();
                break;
            }
        }
    }

    bool isSending = false; // 发送中
    QString time = QString::number(QDateTime::currentDateTime().toTime_t()); //时间戳

//    qDebug()<<"addMessage" << msg << time << chat_lists[cur_index]->count();
    if(isSending) {
        dealMessageTime(time);

        QNChatMessage* messageW = new QNChatMessage(chat_lists[cur_index]->parentWidget());
        QListWidgetItem* item = new QListWidgetItem(chat_lists[cur_index]);
        messageW->setName(name);
        dealPic(messageW, item, path, time, type);
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
            dealMessageTime(time);

            QNChatMessage* messageW = new QNChatMessage(chat_lists[index]->parentWidget());
            QListWidgetItem* item = new QListWidgetItem(chat_lists[index]);
            messageW->setName(name);
            dealPic(messageW, item, path, time, type);
            messageW->setTextSuccess();
        }
    }
    chat_lists[index]->setCurrentRow(chat_lists[index]->count()-1);
}

void logWindow::dealMessage(QNChatMessage *messageW, QListWidgetItem *item, QString text, QString time,  QNChatMessage::User_Type type)
{
    messageW->setFixedWidth(ui->chat_stack_widget->width() - 4);
    QSize size = messageW->fontRect(text);
    item->setSizeHint(size);

//    item->setSizeHint(QSize(5, 100));
    messageW->setText(text, time, size, type);
    messageW->setGeometry(0, 0, ui->chat_stack_widget->width(), ui->chat_stack_widget->height());
//    item->setSizeHint()
    chat_lists[cur_index]->setItemWidget(item, messageW);
}

void logWindow::dealPic(QNChatMessage *messageW, QListWidgetItem *item, QString path, QString time,  QNChatMessage::User_Type type)
{
    messageW->setFixedWidth(ui->chat_stack_widget->width() - 4);
    QSize size = messageW->fontRectPic(path);
    item->setSizeHint(size);

//    item->setSizeHint(QSize(5, 100));
    messageW->setPic(path, time, size, type);
    messageW->setGeometry(0, 0, ui->chat_stack_widget->width(), ui->chat_stack_widget->height());
//    item->setSizeHint()
    chat_lists[cur_index]->setItemWidget(item, messageW);
}

void logWindow::dealMessageTime(QString curMsgTime)
{
    bool isShowTime = false;
    if(chat_lists[cur_index]->count() > 0) {
        QListWidgetItem* lastItem = chat_lists[cur_index]->item(chat_lists[cur_index]->count() - 1);
        QNChatMessage* messageW = (QNChatMessage*)chat_lists[cur_index]->itemWidget(lastItem);
        int lastTime = messageW->time().toInt();
        int curTime = curMsgTime.toInt();
        qDebug() << "curTime lastTime:" << curTime - lastTime;
        isShowTime = ((curTime - lastTime) > 180); // 两个消息相差一分钟
//        isShowTime = true;
    } else {
        isShowTime = true;
    }
    if(isShowTime) {
        QNChatMessage* messageTime = new QNChatMessage(chat_lists[cur_index]->parentWidget());
        QListWidgetItem* itemTime = new QListWidgetItem(chat_lists[cur_index]);

        QSize size = QSize(ui->chat_stack_widget->width() - 4, 40);
        messageTime->resize(size);
        itemTime->setSizeHint(size);
        messageTime->setText(curMsgTime, curMsgTime, size, QNChatMessage::User_Time);
        chat_lists[cur_index]->setItemWidget(itemTime, messageTime);
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

//    QHBoxLayout *pHboxLayout = new QHBoxLayout();
//    MeSend *meSend = new MeSend(ui->chat_stack_widget->widget(cur_index + 2), picPath, me->getHead(), me->getName(), F_TYPE::fPic);
//    pHboxLayout->insertStretch(0);
//    pHboxLayout->addWidget(meSend);
//    //m_pVboxLayout->addLayout(pHboxLayout);
//    chat_layouts[cur_index]->addLayout(pHboxLayout);

//    //receivePic(picPath, 123, "童雪");
//    //通过网络发送图片(picPath路径的图片)****************************
    setPic(picPath, chats[cur_index]->getID(), QNChatMessage::User_Me, me->getID());






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

    QHBoxLayout *pHboxLayout = new QHBoxLayout();
    MeSend *meSend = new MeSend(ui->chat_stack_widget->widget(cur_index + 2), videoPath, me->getHead(), me->getName(), F_TYPE::fVideo);
    pHboxLayout->insertStretch(0);
    pHboxLayout->addWidget(meSend);
    //m_pVboxLayout->addLayout(pHboxLayout);
    chat_layouts[cur_index]->addLayout(pHboxLayout);

    //通过网络发送视频(videoPath路径的图片)*************************








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

    QString videoPath = QFileDialog::getOpenFileName(this, tr("选择要发送的文件"), "/");

    QHBoxLayout *pHboxLayout = new QHBoxLayout();
    MeSend *meSend = new MeSend(ui->chat_stack_widget->widget(cur_index + 2), videoPath, me->getHead(), me->getName(), F_TYPE::fFile);
    pHboxLayout->insertStretch(0);
    pHboxLayout->addWidget(meSend);
    //m_pVboxLayout->addLayout(pHboxLayout);
    chat_layouts[cur_index]->addLayout(pHboxLayout);

    //通过网络发送视频(videoPath路径的图片)*************************





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

