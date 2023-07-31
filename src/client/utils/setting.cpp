#include "setting.h"

//初始化配置文件，若文件信息丢失则进行补全
void setting::init()
{
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);

//    qDebug() << QCoreApplication::applicationDirPath();
    if(!settings->contains("global/path")) {
        settings->setValue("global/path", "D:\\Qt\\WeWork3\\test");
    }

    delete settings;

}

QString setting::getGlobalPath() {
    init();
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);
    return settings->value("global/path").toString();
}

void setting::setKey(QString key) {
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);
    settings->setValue("key/AesKey", key);
}

QString setting::getKey() {
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);
    return settings->value("key/AesKey").toString();
}

void setting::setIv(QString iv) {
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);
    settings->setValue("key/iv", iv);
}

QString setting::getIv() {
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);
    return settings->value("key/iv").toString();
}
