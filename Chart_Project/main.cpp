#include "mainwindow.h"

#include <QApplication>

#include "test.cpp"

int main(int argc, char *argv[]){
    test t;
    t.testing();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
