#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QtXml>
#include <QtDebug>
#include <QTextStream>

#include "io_handler.h"

//#include "viewer.h"
#include "model.h"

class Controller : public QObject{
    Q_OBJECT
private:
    //Viewer *view;
    Model *model;

    xml_IO xmlio;

    static const QDir project_path;
    static const QString dataSetDir;

    void writeOnFile(const QString& label, const QDomDocument& document);
    void readFromFile(const QString& label, QDomDocument& document);
public:
    Controller();
    ~Controller() = default; // ??

    // pensare alle funzioni di parsing: dati in input e convertirli (in Date, uint, Support e Platform

    // DA COMMENTARE
    // DA DEFINIRE SE CONST

    void loadDataFrom(const QString& label);   // MARCARE CONST ??

    void isExists(const QString& label, const Music* music);
    void newSave(const QString& label, const Music* music);
    void appendTo(const QString& label, const Music* music);

    void releasePMToFile(const QString& label, const Album* album, const Date& date, uint num, Support support);
    void releaseDMToFile(const QString& label, const Album* album, const Date& date, uint num, Platform platform);

    void removeFromFile(const QString& label, const Music* music);

    // MANCANO LE MODIFICHE QUANDO AVVIENE UNA PUBBLICAZIONE E DI CONSEGUENZA LA RIMOZIONE
};

#endif // CONTROLLER_H
