QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/addfriend.cpp \
    chatobject.cpp \
    widget_override/friendframe.cpp \
    controller/friendsend.cpp \
    server/logserver.cpp \
    controller/logwindow.cpp \
    main.cpp \
    controller/mainwindow.cpp \
    controller/mesend.cpp \
    controller/msgitem.cpp \
    controller/person.cpp \
    piclabel.cpp \
    controller/widget.cpp \
    encryption/fileencryption.cpp \
    controller/home.cpp \
    peoplelist.cpp \
    server/logserver.cpp

HEADERS += \
    controller/addfriend.h \
    chatobject.h \
    command.h \
    widget_override/friendframe.h \
    controller/friendsend.h \
    server/logserver.h \
    controller/logwindow.h \
    controller/mainwindow.h \
    controller/mesend.h \
    controller/msgitem.h \
    controller/person.h \
    piclabel.h \
    controller/widget.h \
    encryption/fileencryption.h \
    controller/home.h \
    peoplelist.h \
    server/logserver.h

FORMS += \
    ui/addfriend.ui \
    ui/friendsend.ui \
    ui/logwindow.ui \
    ui/mainwindow.ui \
    ui/mesend.ui \
    ui/msgitem.ui \
    ui/person.ui \
    ui/widget.ui \
    ui/home.ui

TRANSLATIONS += \
    WeWork_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc