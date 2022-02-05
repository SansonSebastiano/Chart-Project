
DEFINES += PROJECT_PATH=\"\\\"$${_PRO_FILE_PWD_}/\\\"\"

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    album.cpp \
    controller.cpp \
    date.cpp \
    digitalmedium.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    music.cpp \
    phisycalmedium.cpp \
    recordlabel.cpp \
    release.cpp \
    test.cpp

HEADERS += \
    album.h \
    controller.h \
    date.h \
    digitalmedium.h \
    exceptions.h \
    mainwindow.h \
    model.h \
    music.h \
    phisycalmedium.h \
    recordlabel.h \
    release.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
