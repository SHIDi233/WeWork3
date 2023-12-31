﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils/setting.h"
#include "pojo/user.h"

#include "server/global.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->mainframe = new logWindow;
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //设置无边框
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //实例阴影shadow
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    //设置阴影距离
    shadow->setOffset(-7, 5);
    //设置阴影颜色
    shadow->setColor(QColor("#888888"));
    //设置阴影圆角
    shadow->setBlurRadius(30);
    //给嵌套QWidget设置阴影
    ui->label_2->setGraphicsEffect(shadow);
    //给垂直布局器设置边距(此步很重要, 设置宽度为阴影的宽度)
    ui->label_2->setContentsMargins(1,1,1,1);
    setting::init();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //    if(event->buttons() == Qt::LeftButton){  //如果这里写这行代码，拖动会有点问题
    if(mouse_press){
        move(event->globalPos() - mousePoint);
        //        event->accept();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if( (event->button() == Qt::LeftButton) ){
        mouse_press = true;
        mousePoint = event->globalPos() - this->pos();
        //        event->accept();
    }
    else if(event->button() == Qt::RightButton){
        //如果是右键
        this->close();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}

//登录函数，返回存有好友列表的chatObject对象指针
chatObject *MainWindow::log(QString ID, QString pw) {
    //从服务器获取本人信息，如果登录失败返回nullptr*************************







}



void MainWindow::on_log_button_clicked()
{
    QString ID = ui->log_id_line->text();
    if(ID.isEmpty()) {
        ui->hint_1->setText("请输入账号！");
        return;
    }
    QString pw = ui->log_pass_line->text();
    if(pw.isEmpty()) {
        ui->hint_1->setText("请输入密码！");
        return;
    }


    Config::get()->server = new Server();
    if(Config::get()->server->login(ID,pw)){

        //登录成功，获取好友列表
        QStringList peos = Config::get()->server->rece_peo();

        chatObject *p = new chatObject("test name", 0, ID.toInt(), TYPE::Me);
        for(int i=0;i<peos.length();i++){
//            QListWidgetItem *widgetItem = new QListWidgetItem(ui->listWidget);
//            widgetItem->setSizeHint(QSize(60, 108));
//            widgetItem->setText("1");
//            ui->listWidget->addItem(widgetItem);
//            People*  p = new People(this);
//            p->setID(peos[i].toInt());
//            p->setName(peos[i]);
//            ui->listWidget->setItemWidget(widgetItem, p);

//            connect(p, SIGNAL(clicked(int)), this, SLOT(onListMailItemClicked(int)));

             chatObject *p1 = new chatObject(peos[i], 3, peos[i].toInt(), TYPE::Person);
             p->members.push_back(p1);

        }
        User::getUser()->setID(ID.toInt());
        User::getUser()->setName("Apple");

        this->mainframe = new logWindow(p);
        this->hide();
        this->mainframe->show();
    }
    else{//密码错误

    }

    //测试数据
//    chatObject *p = new chatObject("Apple", 0, 111, TYPE::Me);
//    chatObject *p1 = new chatObject("童雪", 3, 123, TYPE::Person);
//    chatObject *p2 = new chatObject("刘海明", 2, 345, TYPE::Person);
//    chatObject *p3 = new chatObject("钱波", 4, 456, TYPE::Person);
//    p->members.push_back(p1);
//    p->members.push_back(p2);
//    p->members.push_back(p3);
//    User::getUser()->setID(111);
//    User::getUser()->setName("Apple");
//    User::getUser().set


}

void MainWindow::on_reg_button_clicked()
{
//    QString ID = ui->reg_id_line->text();
//    if(ID.isEmpty()) {
//        ui->hint_2->setText("请输入账号！");
//        return;
//    }
//    QString name = ui->reg_name_line->text();
//    if(name.isEmpty()) {
//        ui->hint_2->setText("请输入昵称！");
//        return;
//    }
//    QString pw = ui->reg_pass_line->text();
//    if(pw.isEmpty()) {
//        ui->hint_2->setText("请输入密码！");
//        return;
//    }
//    if(pw.size() < 6) {
//        ui->hint_2->setText("密码长度至少为6位！");
//        return;
//    }
//    QString pwc = ui->reg_pass_confirm_line->text();
//    if(pw.compare(pwc) != 0) {
//        ui->hint_2->setText("两次输入密码不一致！");
//        return;
//    }

//    ui->hint_2->setStyleSheet("color:rgb(255, 255, 255)");
//    ui->hint_2->setText("注册成功，登录中……");

    //网络部分注册********************************





}

void MainWindow::on_minus_buton_clicked()
{
    this->showMinimized();
}


void MainWindow::on_quit_button_clicked()
{
    this->close();
}

