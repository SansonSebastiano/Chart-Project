#include "viewer.h"

#include <QApplication>

#include "test.cpp"

int main(int argc, char *argv[]){
    // TESTING
    //test t;
    //t.testing();

    QApplication a(argc, argv);
    Viewer v;
    v.show();
    return a.exec();
}
