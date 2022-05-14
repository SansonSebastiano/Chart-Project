#include "io_handler.h"
#include "helper.h"

// xml's tag
const QString xml_IO::catalog("catalog");
const QString xml_IO::release("release");
const QString xml_IO::_album("album");
const QString xml_IO::_pm("PM");
const QString xml_IO::_dm("DM");

const QString xml_IO::music_name("name");
const QString xml_IO::music_artist("artist");
const QString xml_IO::genre("genre");

const QString xml_IO::day("day");
const QString xml_IO::month("month");
const QString xml_IO::year("year");

const QString xml_IO::sales("num_sales");
const QString xml_IO::support("support");

const QString xml_IO::listeners("listeners");
const QString xml_IO::platform("platform");


// Lettura
const Album* xml_IO::readAlbum(QDomElement node){
    return new Album(node.attribute(genre, genre).toStdString(),                    // genere musicale
                     node.attribute(music_name, music_name).toStdString(),          // nome
                     node.attribute(music_artist, music_artist).toStdString());     // artista
}

const Date xml_IO::readDate(QDomElement childNode){
    if(childNode.tagName() == release)
        return Date (helper::str_to_uint(childNode.attribute(day, day).toStdString()),       // giorno
                     helper::str_to_uint(childNode.attribute(month, month).toStdString()),   // mese
                     helper::str_to_uint(childNode.attribute(year, year).toStdString())      // anno
                    );
    else{   // ECCEZIONI??
        qDebug() << "Read date failed" << endl;
        return {};
    }
}

const PM* xml_IO::readPM(QDomElement node){
    return new PM(node.attribute(genre, genre).toStdString(),                    // genere musicale
                  node.attribute(music_name, music_name).toStdString(),          // nome
                  node.attribute(music_artist, music_artist).toStdString(),      // artista
                  readDate(node.firstChildElement().toElement()),                // data pubblicazione
                  // supporto fisico
                  helper::uint_to_enum<Support>(helper::str_to_uint(node.attribute(support, support).toStdString())),
                  // vendite
                  helper::str_to_uint(node.attribute(sales, sales).toStdString())
                 );
}

const DM* xml_IO::readDM(QDomElement node){
    return new DM(node.attribute(genre, genre).toStdString(),                    // genere musicale
                  node.attribute(music_name, music_name).toStdString(),          // nome album
                  node.attribute(music_artist, music_artist).toStdString(),      // artista
                  readDate(node.firstChildElement().toElement()),                // data pubblicazione
                  // piattaforma digitale
                  helper::uint_to_enum<Platform>(helper::str_to_uint(node.attribute(platform, platform).toStdString())),
                  // ascolti
                  helper::str_to_uint(node.attribute(listeners, listeners).toStdString())
                 );
}

// Scrittura

QDomElement xml_IO::writeAlbum(QDomElement node, const Album* album) {
    node.setAttribute(music_name, QString::fromStdString(album->getName()));        // nome
    node.setAttribute(music_artist, QString::fromStdString(album->getArtist()));    // artista
    node.setAttribute(genre, QString::fromStdString(album->getGenre()));            // genere

    return node;
}

QDomElement xml_IO::writeDate(QDomDocument &document, const Date& date) {
    QDomElement date_node = document.createElement(release);
    date_node.setAttribute(day, QString::fromStdString(std::to_string(date.getDay())));         // giorno
    date_node.setAttribute(month, QString::fromStdString(std::to_string(date.getMonth())));     // mese
    date_node.setAttribute(year, QString::fromStdString(std::to_string(date.getYear())));       // anno

    return date_node;
}

QDomElement xml_IO::writePM(QDomDocument &document, const PM *album){
    QDomElement pm_node = document.createElement(_pm);  // crea nodo 'PM'
    writeAlbum(pm_node, album); // scrive i dati dell'album

    pm_node.setAttribute(sales, QString::fromStdString(std::to_string(album->getNumbers())));   // scrive il numero di vendite
    pm_node.setAttribute(support, album->getSupport());                                         // scrive il supporto fisico

    pm_node.appendChild(writeDate(document, album->getReleaseDate()));                          // scrive la data e diventa sottonodo di 'PM'
    return pm_node;
}

QDomElement xml_IO::writeDM(QDomDocument &document, const DM *album) {
    QDomElement dm_node = document.createElement(_dm);                                              // crea nodo 'DM'
    writeAlbum(dm_node, album);                                                                     // scrive i dati dell'album

    dm_node.setAttribute(listeners, QString::fromStdString(std::to_string(album->getNumbers())));   // scrive il numero di ascolti
    dm_node.setAttribute(platform, album->getPlatform());                                           // scrive la piattaforma digitale

    dm_node.appendChild(writeDate(document, album->getReleaseDate()));                              // scrive la data e diventa sottonodo di 'DM'
    return dm_node;
}

// Ricerca

QDomElement xml_IO::searchByName(QDomNodeList list, const Music* music) const {
    qDebug() << "# elements: " << list.count() << endl;                                         // conta i prodotti musicali
    qDebug() << "to find: " << QString::fromStdString(music->getInfo()) << endl;

    QDomNode node;
    QDomElement element;

    if(!list.isEmpty()){                                                                        // se il file non e' vuoto
        for(int i = 0; i < list.count(); i++){                                                  // scorre i nodi nel file
            node = list.at(i);                                                                  // preleva nodo i-esimo nel file
            element = node.toElement();

            if(element.attribute(music_name, music_name).toStdString() == music->getName() &&
               element.attribute(music_artist, music_artist).toStdString() == music->getArtist() &&
               element.attribute(genre, genre).toStdString() == music->getGenre()){                // ritorna il nodo se il suo nome e' uguale al nome dato in input
                qDebug() << "found: " << element.attribute(music_name, music_name) << endl;
                return element;
            }
        }
    }

    // ATTENZIONE: gestire con le eccezioni?
    return QDomElement();
}

// Rimozione

void xml_IO::removeByName(QDomNodeList list, const Music* music) {
    qDebug() << "# elements: " << list.count() << endl;
    qDebug() << "to find: " << QString::fromStdString(music->getInfo()) << endl;

    QDomNode node;
    QDomElement element;

    if(!list.isEmpty()){
        for(int i = 0; i < list.count(); i++){
            node = list.at(i);
            element = node.toElement();

            if( element.attribute(music_name, music_name).toStdString() == music->getName() &&
                element.attribute(music_artist, music_artist).toStdString() == music->getArtist() &&
                element.attribute(genre, genre).toStdString() == music->getGenre()){
                element.parentNode().removeChild(element);  // esegue lo stesso algoritmo della funzione precedente, il nodo pero' viene rimosso dal file
                qDebug() << QString::fromStdString(music->getInfo() + " DELETED FROM FILE SUCCESSED") << endl << endl;
            }
        }
    }else
        qDebug() << QString::fromStdString(music->getInfo() + " NOT PRESENT TO DELETE FROM FILE") << endl << endl;
}

























