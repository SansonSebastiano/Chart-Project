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
    // Music
    static const QString genre;
    static const QString music_name;
    static const QString music_artist;
    // Release
    static const QString day;
    static const QString month;
    static const QString year;
    // PhisycalMedium
    static const QString sales;
    static const QString support;
    // DigitalMedium
    static const QString listeners;
    static const QString platform;
public:
    // xml's nodes
    static const QString catalog;
    static const QString release;
    static const QString _album;
    static const QString _pm;
    static const QString _dm;

    // USARE I TEMPLATE?
    // Lettura
    /*
     * @brief   legge un album non pubblicato da file
     * @param   QDomELement
     * @return  const Album*
     */
    const Album* readAlbum(QDomElement node);
    /*
     * @brief   legge la data di rilascio da file
     * @param   QDomELement
     * @return  const Date
     */
    const Date readDate(QDomElement node);
    /*
     * @brief   legge un album pubblicato su supporto fisico da file
     * @param   QDomELement
     * @return  const PM*
     */
    const PM* readPM(QDomElement node);
    /*
     * @brief   legge un album pubblicato su piattaforma digitale da file
     * @param   QDomELement
     * @return  const DM*
     */
    const DM* readDM(QDomElement node);

    // Scrittura
    /*
     * @brief   scrive un album su file
     * @param   QDomELement
     * @param   const Album*
     * @return  const QDomElement&
     */
    QDomElement writeAlbum(QDomElement node, const Album* album);
    /*
     * @brief   scrive una data di rilascio su file
     * @param   QDomELement
     * @param   const Date&
     * @return  const QDomElement&
     */
    QDomElement writeDate(QDomDocument& document, const Date& date);
    /*
     * @brief   scrive un album pubblicato su supporto fisico su file
     * @param   QDomELement
     * @param   const PM*
     * @return  const QDomElement&
     */
    QDomElement writePM(QDomDocument& document, const PM* pm);
    /*
     * @brief   scrive un album pubblicato su piattaforma digitale su file
     * @param   QDomELement
     * @param   const DM*
     * @return  const QDomElement&
     */
    QDomElement writeDM(QDomDocument& document, const DM* dm);

    // Ricerca

    /*
     * @pre     non esistono prodotti musicali con lo stesso: artista, nome, genere
     * @brief   ricerca musica non pubblicato
     * @param   QDomElement
     * @param   const string&
     * @return  QDomElement
     */
    QDomElement searchByName(QDomNodeList list, const Music* music) const;
    /*
     * @brief   rimuove musica non pubblicata da file, dato un nome in input
     * @param   const string&
     * @return  void
     */
    void removeByName(QDomNodeList list, const Music* music);
};

#endif // IO_HANDLER_H
