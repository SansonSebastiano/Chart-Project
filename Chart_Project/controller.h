#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QtXml>
#include <QtDebug>
#include <QTextStream>

//#include "viewer.h"
#include "model.h"

class Controller : public QObject{
    Q_OBJECT
private:
    //Viewer *view;
    Model model;

    static const QDir project_path;
    static const QString dataSetDir;

    const Album* readAlbum(QDomElement node);
    const Date readDate(QDomElement node);
    const Album* readPM(QDomElement node);
    const Album* readDM(QDomElement node);
public:
    Controller() = default;
    ~Controller() = default; // ??

    // DA COMMENTARE
    // DA DEFINIRE SE CONST

    void loadDataFrom(QString label);
    void saveDataTo(QString label);
    void newSave(QString newLabel);

    uint str_to_uint(string input);
};

#endif // CONTROLLER_H
