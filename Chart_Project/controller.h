#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QtXml>
#include <QtDebug>
#include <QTextStream>

#include "io_handler.h"

//#include "viewer.h"
#include "model.h"

// CONTROLLARE IL POLIMORFISMO:
    // - Model *model

class Controller : public QObject{
    Q_OBJECT
private:
    //Viewer *view;
    Model model;

    xml_IO xmlio;

    static const QDir project_path;
    static const QString dataSetDir;
public:
    Controller() = default;
    ~Controller() = default; // ??

    // DA COMMENTARE
    // DA DEFINIRE SE CONST

    void loadDataFrom(QString label);   // MARCARE CONST ??
    void isExists(QString label, const Album* album);
    void newSave(QFile& file, const Album* album);
    void appendTo(QFile& file, const Album* album);
    void releaseAlbumToFile(const Album* album, const Date& date, uint sales, Support support);
    void releaseAlbumToFile(const Album* album, const Date& date, uint listeners, Platform platform);
    void removeAlbumToFile(const Album* album);

    // MANCANO LE MODIFICHE QUANDO AVVIENE UNA PUBBLICAZIONE E DI CONSEGUENZA LA RIMOZIONE
};

#endif // CONTROLLER_H
