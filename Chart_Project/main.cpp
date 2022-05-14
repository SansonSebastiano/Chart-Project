#include "viewer.h"
#include "controller.h"
#include "model.h"

#include <QApplication>

int main(int argc, char *argv[]){
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
