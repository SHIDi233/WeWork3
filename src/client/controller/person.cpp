#include "person.h"
#include "ui_person.h"

person::person(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::person)
{
    ui->setupUi(this);
    initialSQL();
    //friends.push_back("qb");
//    createTable(friends[0]);
//    createTable(friends[1]);
//    createTable(friends[2]);
//    friends[0]->createTable();
//    friends[1]->createTable();
//    friends[2]->createTable();
}

person::~person()
{
    delete ui;
}

QString person::getFileName(){
    QString file_name = QFileDialog::getOpenFileName(this, tr("选择一张图片"), "C:/Users/jiage/Desktop", tr("Image Files (*.png *.jpg *.bmp)"));
    return file_name;
}

void person::setUserName(QString userName){
    this->userName = userName;
}



void person::setFriendsID(QVector<person*> friends){


    this->friends.swap(friends);//用于和传进来的friends交换赋值

    //添加好友ID （测试用），下面三个由于friends只有三个，你可以自行写
    this->friends[0]->createTable();
    this->friends[1]->createTable();
    this->friends[2]->createTable();

    qDebug() << "set success";
}



void person::on_pushButton_clicked()
{
    QString fileName = getFileName();//获取选中文件的名字
    //QLabel *label = new QLabel();
    ui->label->setPixmap(QPixmap(fileName).scaled(350, 250));
    QString imageFormat = fileName.right(3);

    /** 用于保存需要传入数据库的内容 **/
    currentTime = QDateTime::currentDateTime();;
    personPixmap = QPixmap(fileName);
    personText = ui->textEdit->toPlainText();

    //保存进入数据库 （测试用）
    insertTable(userName,currentTime,personText,fileName);
    insertTable(friends[1]->userName,currentTime,personText,fileName);
    insertTable(friends[2]->userName,currentTime,personText,fileName);
    qDebug() << "success" ;

}

void person::on_pushButton_2_clicked()
{
    emit sendPersonInfo();
    this->close();
}



//创建数据库
void person::initialSQL(){
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
        qDebug()<<"连接到PYQ_connetion";
    }
    else
    {
        qDebug()<<"新建PYQ_connetion，并连接";
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("PYQ.db");
        db.setUserName("PYQ");
        db.setPassword("PYQ");
    }
}

//创建表格
void person::createTable(){


    if(!db.open())
    {
        qDebug() << "Error: Failed to connect database." << db.lastError();
        return;
    }

    QSqlQuery sql_query(db);
    QString creat_sql = QString("create table %1 (personName text, currentTime text, personText text, personImage blob);").arg(userName);//创建表格名字
//    QString creat_sql = QString("create table %1 (personName text, personText text)").arg(userName);//创建表格名字
    sql_query.prepare(creat_sql);//创建表格
    if(!sql_query.exec())
    {
        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    }
    else
    {
        qDebug() << "Table created!";
    }
    db.close();
}

//插入数据(userName表示当前用户， personName表示好友)
void person::insertTable(QString personName, QDateTime currentTime, QString personText, QString ImagePath){
    QString currentTime1 = currentTime.toString();

    if(!db.open())
    {
        qDebug() << "Error: Failed to connect database." << db.lastError();
        return;
    }
    QFile image(ImagePath);
    if (!image.open(QIODevice::ReadOnly))
    {
        qDebug()<<"图片文件打开失败";
    }
    QByteArray imageByteArray = image.readAll();


    QString insert_sql = QString("insert into %1 values (?, ?, ?, ?)").arg(personName);

    /** 插入数据 **/
    QSqlQuery sql_query;
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(userName);
    sql_query.addBindValue(currentTime1);
    sql_query.addBindValue(personText);
    sql_query.addBindValue(imageByteArray);
    if(!sql_query.exec())
    {
        qDebug() << sql_query.lastError();
    }
    else
    {
        qDebug() << "插入成功";
    }
    db.close();
}

void person::readTabel(QString &personName, QString &currentTime, QString &personText, QPixmap &personPixmap){
    if(!db.open())
    {
        qDebug() << "Error: Failed to connect database." << db.lastError();
        return;
    }

    QString select_all_sql = QString("select * from %1").arg(userName);
    QSqlQuery sql_query;
    sql_query.prepare(select_all_sql);
    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
            personName = sql_query.value(0).toString();//获取名字
//            int id = sql_query.value(0).toInt();
            currentTime = sql_query.value(1).toString();//获取当前时间
//            int age = sql_query.value(2).toInt();
            personText = sql_query.value(2).toString();//获取朋友圈文本内容
            /** 获取朋友圈图片内容 **/
            QByteArray imageByte = sql_query.value(3).toByteArray();
            personPixmap = QPixmap();
            personPixmap.loadFromData(imageByte);

            //qDebug()<<QString("id:%1    name:%2    age:%3").arg(id).arg(name).arg(age);
        }
    }
}


