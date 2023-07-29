#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "person.h"
#include "QGridLayout"
#include "QGroupBox"
#include "QLabel"
#include "QLineEdit"
#include "QDebug"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlError"
#include "chatobject.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(chatObject *me, QWidget *parent = nullptr);
    ~Widget();
    QGroupBox* addNewPYQ(QString userName, QDateTime currentTime, QString personText, QPixmap personPixmap);
    void initialSQL();
    void createTable(QString userName);
    void insertTable(QString userName,QString personName, QDateTime currentTime, QString personText, QString imagePath);
    void initPYQ();
    void initPersonalPYQ(QString userName,Widget* personalWidget);
    QWidget* PYQWidget;
    person* user;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
};
#endif // WIDGET_H
