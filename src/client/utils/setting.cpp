#include "setting.h"

//初始化配置文件，若文件信息丢失则进行补全
void setting::init()
{
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);

//    qDebug() << QCoreApplication::applicationDirPath();
    if(!settings->contains("global/path")) {
        settings->setValue("global/path", "D:\\Qt\\WeWork3\\test");
    }
    if(!settings->contains("key/AesKey")) {
        settings->setValue("key/AesKey", "DefaultAesKey123");
    }
    if(!settings->contains("key/iv")) {
        settings->setValue("key/iv", "DefaultIv1234567");
    }

    delete settings;

}

QString setting::getGlobalPath() {
    init();
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);
    return settings->value("global/path").toString();
    delete settings;
}

void setting::setKey(QString key) {
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);
    settings->setValue("key/AesKey", key);
    delete settings;
}

QString setting::getKey() {
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);
    return settings->value("key/AesKey").toString();
    delete settings;
}

void setting::setIv(QString iv) {
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);
    settings->setValue("key/iv", iv);
    delete settings;
}

QString setting::getIv() {
    QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);
    return settings->value("key/iv").toString();
    delete settings;
}
