QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
    controller/addfriend.cpp \
    pojo/chatmsg.cpp \
    pojo/chatobject.cpp \
    pojo/user.cpp \
    server/chatserver.cpp \
    utils/encryption.cpp \
    utils/setting.cpp \
    web/chatweb.cpp \
    web/logweb.cpp \
    widget_override/friendframe.cpp \
    controller/friendsend.cpp \
    server/logserver.cpp \
    controller/logwindow.cpp \
    main.cpp \
    controller/mainwindow.cpp \
    controller/mesend.cpp \
    controller/msgitem.cpp \
    controller/person.cpp \
    widget_override/piclabel.cpp \
    controller/widget.cpp \
    controller/home.cpp \
    server/logserver.cpp \
    widget_override/qnchatmessage.cpp

HEADERS += \
    controller/addfriend.h \
    pojo/chatmsg.h \
    pojo/chatobject.h \
    command.h \
    pojo/user.h \
    server/chatserver.h \
    utils/encryption.h \
    utils/setting.h \
    web/chatweb.h \
    web/logweb.h \
    widget_override/friendframe.h \
    controller/friendsend.h \
    server/logserver.h \
    controller/logwindow.h \
    controller/mainwindow.h \
    controller/mesend.h \
    controller/msgitem.h \
    controller/person.h \
    widget_override/piclabel.h \
    controller/widget.h \
    controller/home.h \
    server/logserver.h \
    widget_override/qnchatmessage.h

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

LIBS += -LC:/OpenSSL-Win64/lib/libssl.lib \
          C:/OpenSSL-Win64/lib/libcrypto.lib

INCLUDEPATH += C:/OpenSSL-Win64/include
