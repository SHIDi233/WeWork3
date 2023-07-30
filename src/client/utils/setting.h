#ifndef SETTING_H
#define SETTING_H

#include <QtCore/QCoreApplication>
#include <QSettings>
#include <QDebug>

namespace setting {

//    static QSettings *settings = new QSettings("setting.ini",QSettings::IniFormat);

    void init();

    void setRootPath();

    QString getGlobalPath();

    void setKey(QString key);

    QString getKey();

    void setIv(QString iv);

    QString getIv();

}

#endif // SETTING_H
