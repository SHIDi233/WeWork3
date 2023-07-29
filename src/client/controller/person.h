#ifndef PERSON_H
#define PERSON_H

#include <QWidget>
#include <QFileDialog>
#include <QDateTime>
#include "QDebug"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlError"
#include "QBuffer"
namespace Ui {
class person;
}



class person : public QWidget
{
    Q_OBJECT

public:
    explicit person(QWidget *parent = nullptr);
    person(QString userName,QVector<QString> friendsID);
    ~person();
    QString getFileName();

    QDateTime currentTime;
    QPixmap personPixmap;
    QString personText;

    void initialSQL();
    void createTable();
    void insertTable(QString personName, QDateTime currentTime, QString personText, QString imagePath);
    void readTabel(QString &personName, QString &currentTime, QString &personText, QPixmap &personPixmap);

    void setUserName(QString userName);
    void setFriendsID(QVector<person*> friends);
    Ui::person *ui;

    QString userName;
    QSqlDatabase db;
    QVector<person*> friends;

signals:
    void sendPersonInfo();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:

};

#endif // PERSON_H
