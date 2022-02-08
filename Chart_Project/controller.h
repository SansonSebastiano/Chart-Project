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

    static const QString catalog;
    static const QString release;
    static const QString _album;
    static const QString _pm;
    static const QString _dm;

    static const QString album_name;
    static const QString album_artist;
    static const QString genre;

    static const QString day;
    static const QString month;
    static const QString year;
    //static const QString profit;

    static const QString sales;
    static const QString support;

    static const QString listeners;
    static const QString platform;

    const Album* readAlbum(QDomElement node);
    const Date readDate(QDomElement node);
    const Album* readPM(QDomElement node);
    const Album* readDM(QDomElement node);

    QDomElement writeAlbum(QDomDocument& document, const Album* album);
    QDomElement writeDate(QDomDocument& document, const Release* album);
    QDomElement writePM(QDomDocument& document, const PM* album);
    QDomElement writeDM(QDomDocument& document, const DM* album);
public:
    Controller() = default;
    ~Controller() = default; // ??

    // DA COMMENTARE
    // DA DEFINIRE SE CONST

    void loadDataFrom(QString label);   // MARCARE CONST ??
    void isExists(QString label, const Album* album);
    void newSave(QFile& file, const Album* album);
    void appendTo(QFile& file, const Album* album);

    uint str_to_uint(string input);
};

#endif // CONTROLLER_H
