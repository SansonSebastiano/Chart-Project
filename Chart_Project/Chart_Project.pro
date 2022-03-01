
DEFINES += PROJECT_PATH=\"\\\"$${_PRO_FILE_PWD_}/\\\"\"

QT       += core gui
QT       += xml
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractchart.cpp \
    album.cpp \
    barchart.cpp \
    controller.cpp \
    date.cpp \
    digitalmedium.cpp \
    formdialog.cpp \
    io_handler.cpp \
    linechart.cpp \
    main.cpp \
    model.cpp \
    music.cpp \
    musicdialog.cpp \
    phisycalmedium.cpp \
    piechart.cpp \
    recordlabel.cpp \
    release.cpp \
    releasedialog.cpp \
    tablemodel.cpp \
    test.cpp \
    viewer.cpp

HEADERS += \
    abstractchart.h \
    album.h \
    barchart.h \
    controller.h \
    date.h \
    digitalmedium.h \
    exceptions.h \
    formdialog.h \
    helper.h \
    io_handler.h \
    linechart.h \
    model.h \
    music.h \
    musicdialog.h \
    phisycalmedium.h \
    piechart.h \
    recordlabel.h \
    release.h \
    releasedialog.h \
    tablemodel.h \
    viewer.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    RecordLabel/sample_1.xml
