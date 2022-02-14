#include "viewer.h"
#include "controller.h"
#include "model.h"

#include <QApplication>

#include "test.cpp"

int main(int argc, char *argv[]){
    // TESTING
    //test t;
    //t.testing();

    QApplication a(argc, argv);

    Viewer v;
    Controller c;
    Model m;

    c.setModel(&m);
    c.setViewer(&v);
    v.setController(&c);

    v.show();

    return a.exec();
}
