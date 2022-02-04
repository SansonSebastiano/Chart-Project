#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

//#include "viewer.h"
#include "model.h"

class Controller : public QObject{
    Q_OBJECT
private:
    //Viewer *view;
    Model *model;
public:
    Controller();
    ~Controller() = default; // ??
};

#endif // CONTROLLER_H
