#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->mainframe = new logWindow;

    ui->tabWidget->setTabText(0, "登录");
    ui->tabWidget->setTabText(1, "注册");

}

MainWindow::~MainWindow()
{
    delete ui;
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

    //测试数据
    chatObject *p = new chatObject("Apple", 0, 111, TYPE::Me);
    chatObject *p1 = new chatObject("童雪", 3, 123, TYPE::Person);
    chatObject *p2 = new chatObject("刘海明", 2, 345, TYPE::Person);
    chatObject *p3 = new chatObject("钱波", 4, 456, TYPE::Person);
    p->members.push_back(p1);
    p->members.push_back(p2);
    p->members.push_back(p3);

    this->mainframe = new logWindow(p);
    this->hide();
    this->mainframe->show();
}

void MainWindow::on_reg_button_clicked()
{
    QString ID = ui->reg_id_line->text();
    if(ID.isEmpty()) {
        ui->hint_2->setText("请输入账号！");
        return;
    }
    QString name = ui->reg_name_line->text();
    if(name.isEmpty()) {
        ui->hint_2->setText("请输入昵称！");
        return;
    }
    QString pw = ui->reg_pass_line->text();
    if(pw.isEmpty()) {
        ui->hint_2->setText("请输入密码！");
        return;
    }
    if(pw.size() < 6) {
        ui->hint_2->setText("密码长度至少为6位！");
        return;
    }
    QString pwc = ui->reg_pass_confirm_line->text();
    if(pw.compare(pwc) != 0) {
        ui->hint_2->setText("两次输入密码不一致！");
        return;
    }

    ui->hint_2->setStyleSheet("color:rgb(255, 255, 255)");
    ui->hint_2->setText("注册成功，登录中……");

    //网络部分注册********************************





}
