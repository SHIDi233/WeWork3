/**
* 登录注册窗口
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private slots:
    void on_log_button_clicked();

    void on_reg_button_clicked();

    void on_minus_buton_clicked();

    void on_quit_button_clicked();


private:
    Ui::MainWindow *ui;
    logWindow *mainframe;
    chatObject *log(QString ID, QString pw);//登录函数，返回存有好友列表的chatObject对象指针
    QPoint mousePoint;
    bool mouse_press;
};
#endif // MAINWINDOW_H
