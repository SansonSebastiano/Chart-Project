#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include <QtXml>
#include <QtDebug>
#include <QTextStream>

#include "digitalmedium.h"
#include "phisycalmedium.h"

typedef DigitalMedium DM;
typedef PhisycalMedium PM ;

class xml_IO{
private:
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
public:
    static const QString catalog;
    static const QString release;
    static const QString _album;
    static const QString _pm;
    static const QString _dm;

    // USARE I TEMPLATE?
    // Lettura
    const Album* readAlbum(QDomElement node);
    const Date readDate(QDomElement node);
    const PM* readPM(QDomElement node);
    const DM* readDM(QDomElement node);

    // Scrittura
    QDomElement writeAlbum(QDomDocument& document, const Album* album);
    QDomElement writeDate(QDomDocument& document, const Release* album);
    QDomElement writePM(QDomDocument& document, const PM* album);
    QDomElement writeDM(QDomDocument& document, const DM* album);
};

#endif // IO_HANDLER_H
