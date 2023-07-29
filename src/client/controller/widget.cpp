#include "widget.h"
#include "ui_widget.h"

Widget::Widget(chatObject *me, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    PYQWidget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;  //设置垂直布局
    PYQWidget->setLayout(layout);
    ui->scrollArea->setWidget(PYQWidget);
    //user = new person("qb");

    //初始化用户信息，示例如下
    QVector<person*> friends;
    person *m = new person();
    m->setUserName(me->getName());
    friends.push_back(m);
    for(int i = 0; i < me->members.size(); i++) {
        if(me->members[i]->getType() == TYPE::Person) {
            person *p = new person();
            p->setUserName(me->members[i]->getName());
            friends.push_back(p);
        }
    }

    //当前用户初始化
    user = new person();
    user->setUserName(me->getName());
    user->setFriendsID(friends);

    initialSQL();
    initPYQ();

    //显示头像
    QPixmap headPix(QString(":/new/head/image/head_%1.png").arg(me->getHead()));
    //headPix = headPix.scaled(41, 41, Qt::KeepAspectRatio);
    ui->head_label->setScaledContents(true);
    ui->head_label->setPixmap(headPix);
    ui->name_label->setText(me->getName());
}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //添加新的朋友圈
    user->show();
    connect(user,&person::sendPersonInfo, this, [=](){
        QDateTime currentTime = user->currentTime;
        QPixmap personPixmap = user->personPixmap;
        QString personText = user->personText;
        QGroupBox* newPYQ = addNewPYQ(user->userName, currentTime, personText, personPixmap);
        PYQWidget->layout()->addWidget(newPYQ);
    });

    //ui->scrollArea->addWidget(newPYQ);
}

//完全遍历数据库的算法
void Widget::initPYQ(){
    if(!db.open())
    {
        qDebug() << "Error: Failed to connect database." << db.lastError();
        return;
    }

    QString select_all_sql = QString("select * from %1").arg(user->userName);
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

            QString personName = sql_query.value(0).toString();//获取名字
            qDebug() << "personName:" << personName;
//            int id = sql_query.value(0).toInt();
            QString currentTime = sql_query.value(1).toString();//获取当前时间
            qDebug() << "currentTime:" << currentTime;
            QDateTime currentTime1 = QDateTime::fromString(currentTime);
//            int age = sql_query.value(2).toInt();
            QString personText = sql_query.value(2).toString();//获取朋友圈文本内容
            qDebug() << "personText:" << personText;

            /** 获取朋友圈图片内容 **/
            QByteArray imageByte = sql_query.value(3).toByteArray();
            QPixmap personPixmap = QPixmap();
            personPixmap.loadFromData(imageByte);
            QGroupBox* newPYQ = addNewPYQ(personName, currentTime1, personText, personPixmap);
            PYQWidget->layout()->addWidget(newPYQ);
            //qDebug()<<QString("id:%1    name:%2    age:%3").arg(id).arg(name).arg(age);
        }
    }
    db.close();

}


void Widget::initPersonalPYQ(QString personName, Widget* personalWidget){
    QList<QGroupBox *> PYQ_List= personalWidget->findChildren<QGroupBox *>();
    QList<QPushButton *> pushButton_List = personalWidget->findChildren<QPushButton *>();
    for (int i=0;i<PYQ_List.count();i++)
    {
        PYQ_List.at(i)->hide();
    }
    for (int i=0;i<pushButton_List.count();i++)
    {
        pushButton_List.at(i)->hide();
    }



    if(!db.open())
    {
        qDebug() << "Error: Failed to connect database." << db.lastError();
        return;
    }
    QString select_sql = QString("select * from '%1' where personName = '%2' ").arg(user->userName).arg(personName);
    QSqlQuery sql_query;
    if(!sql_query.exec(select_sql))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        while(sql_query.next())
        {
            QString personName = sql_query.value(0).toString();//获取名字
            qDebug() << "personName:" << personName;
//            int id = sql_query.value(0).toInt();
            QString currentTime = sql_query.value(1).toString();//获取当前时间
            qDebug() << "currentTime:" << currentTime;
            QDateTime currentTime1 = QDateTime::fromString(currentTime);
//            int age = sql_query.value(2).toInt();
            QString personText = sql_query.value(2).toString();//获取朋友圈文本内容
            qDebug() << "personText:" << personText;

            /** 获取朋友圈图片内容 **/
            QByteArray imageByte = sql_query.value(3).toByteArray();
            QPixmap personPixmap = QPixmap();
            personPixmap.loadFromData(imageByte);
            QGroupBox* newPYQ = addNewPYQ(personName, currentTime1, personText, personPixmap);
            PYQWidget->layout()->addWidget(newPYQ);
            //qDebug()<<QString("id:%1    name:%2    age:%3").arg(id).arg(name).arg(age);
        }
    }
    db.close();
}


/**你可以用这个函数来实现往添加新的朋友圈内容，只需要从数据库调取用户的相应信息
    userName：用户名
    currentTime：发送朋友圈的时间
    personText：朋友圈的文本信息
    personPixmap：朋友圈的图片信息
**/

/** 创建朋友圈的主函数 **/
QGroupBox* Widget::addNewPYQ(QString userName, QDateTime currentTime, QString personText, QPixmap personPixmap){
    QString title = userName + " " + currentTime.toString();
    QGroupBox* content = new QGroupBox(title);
    content->setFixedSize(450,460);

    /** 用户填入的文本内容 **/
    QLineEdit* text = new QLineEdit();
    text->setGeometry(0,0,340,70);
    text->setText(personText);
    text->setFixedSize(340,70);

    /** 用户插入的图片 **/
    QLabel* imageLabel = new QLabel();
    imageLabel->setGeometry(0,0,340,310);
    imageLabel->setPixmap(personPixmap);
    imageLabel->setScaledContents(true);
    imageLabel->setFixedSize(340,310);

    /** 将控件加入布局管理器 **/
    QVBoxLayout* layout1 = new QVBoxLayout();
    layout1->setSpacing(10);
    //layout1->SetFixedSize(340,300);
    layout1->setAlignment(this,Qt::AlignHCenter);
    layout1->addWidget(text);
    layout1->addWidget(imageLabel);

//    /** 进入当前指定好友朋友圈 **/
//    QPushButton* friend_PYQ = new QPushButton("进入");
//    friend_PYQ->setFixedSize(50,50);
//    QVBoxLayout* layout2 = new QVBoxLayout();
//    layout2->setSpacing(10);
//    //layout2->setAlignment(this,Qt::AlignHCenter);
//    layout2->addWidget(friend_PYQ);

//    connect(friend_PYQ,&QPushButton::clicked,this,[=](){
//        Widget* personalPYQ = new Widget();
//        personalPYQ->initPersonalPYQ(userName, personalPYQ);
//        personalPYQ->show();

//    });

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->addLayout(layout1);
//    mainLayout->addLayout(layout2);



    content->setLayout(mainLayout);
    return content;
}


//创建数据库
void Widget::initialSQL(){
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        qDebug()<<"连接到PYQ";
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        qDebug()<<"新建PYQ，并连接";
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("PYQ.db");
        db.setUserName("PYQ");
        db.setPassword("PYQ");
    }
}

//创建表格
void Widget::createTable(QString userName){

    if(!db.open())
    {
        qDebug() << "Error: Failed to connect database." << db.lastError();
        return;
    }

    QSqlQuery sql_query;
    QString creat_sql = QString("create table %1 (personName text, currentTime text, personText text, personImage blob)").arg(userName);//创建表格名字
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

//插入数据
void Widget::insertTable(QString userName, QString personName, QDateTime currentTime, QString personText, QString ImagePath){
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
    QString insert_sql = QString("insert into %1 values (?, ?, ?, ?)").arg(userName);
//    QString insert_sql = QString("insert into %1 values (?, ?)").arg(userName);
    QSqlQuery sql_query;
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(personName);
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



void Widget::on_pushButton_2_clicked()
{

    QList<QGroupBox *> PYQ_List= this->findChildren<QGroupBox *>();
    for (int i=0;i<PYQ_List.count();i++)
    {
        PYQ_List.at(i)->deleteLater();
    }
    initPYQ();
}
