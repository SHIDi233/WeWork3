#ifndef SETTING_H
#define SETTING_H

#include <QtCore/QCoreApplication>
#include <QSettings>
#include <QDebug>

namespace setting {

    void init();

    void setRootPath();

    QString getGlobalPath();

}

#endif // SETTING_H
