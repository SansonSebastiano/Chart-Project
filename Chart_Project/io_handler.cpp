#include "io_handler.h"
#include "cast_helper.h"

const QString xml_IO::catalog("catalog");
const QString xml_IO::release("release");
const QString xml_IO::_album("album");
const QString xml_IO::_pm("PM");
const QString xml_IO::_dm("DM");

const QString xml_IO::album_name("name");
const QString xml_IO::album_artist("artist");
const QString xml_IO::genre("genre");

const QString xml_IO::day("day");
const QString xml_IO::month("month");
const QString xml_IO::year("year");

const QString xml_IO::sales("num_sales");
const QString xml_IO::support("support");

const QString xml_IO::listeners("listeners");
const QString xml_IO::platform("platform");

const Album* xml_IO::readAlbum(QDomElement node){
    return new Album(node.attribute(genre, genre).toStdString(),                    // genere musicale
                     node.attribute(album_name, album_name).toStdString(),          // nome album
                     node.attribute(album_artist, album_artist).toStdString());     // artista
}

// Lettura

const Date xml_IO::readDate(QDomElement childNode){
    qDebug() << childNode.tagName();
    if(childNode.tagName() == release)
        return Date (converter::str_to_uint(childNode.attribute(day, day).toStdString()),       // giorno
                     converter::str_to_uint(childNode.attribute(month, month).toStdString()),   // mese
                     converter::str_to_uint(childNode.attribute(year, year).toStdString())      // anno
                    );
    else{
        qDebug() << "Read date failed" << endl;
        return {};
    }
}

const PM* xml_IO::readPM(QDomElement node){
    return new PM(node.attribute(genre, genre).toStdString(),                    // genere musicale
                  node.attribute(album_name, album_name).toStdString(),          // nome album
                  node.attribute(album_artist, album_artist).toStdString(),      // artista
                  readDate(node.firstChildElement().toElement()),                // data pubblicazione
                  // supporto fisico
                  converter::string_to_enum<Support>(node.attribute(support, support).toStdString(), PhisycalMedium::support_names, PhisycalMedium:: MAX_PVALUES),
                  // vendite
                  converter::str_to_uint(node.attribute(sales, sales).toStdString())
                 );
}

const DM* xml_IO::readDM(QDomElement node){
    return new DM(node.attribute(genre, genre).toStdString(),                    // genere musicale
                  node.attribute(album_name, album_name).toStdString(),          // nome album
                  node.attribute(album_artist, album_artist).toStdString(),      // artista
                  readDate(node.firstChildElement().toElement()),                // data pubblicazione
                  // piattaforma digitale
                  converter::string_to_enum<Platform>(node.attribute(platform, platform).toStdString(), DigitalMedium::platform_names, DigitalMedium::MAX_SVALUES),
                  // ascolti
                  converter::str_to_uint(node.attribute(listeners, listeners).toStdString())
                 );
}

// Scrittura

QDomElement xml_IO::writeAlbum(QDomDocument &document, const Album* album) {
    QDomElement album_node = document.createElement(_album);
    album_node.setAttribute(album_name, QString::fromStdString(album->getName()));
    album_node.setAttribute(album_artist, QString::fromStdString(album->getArtist()));
    album_node.setAttribute(genre, QString::fromStdString(album->getGenre()));

    return album_node;
}

QDomElement xml_IO::writeDate(QDomDocument &document, const Release *album) {
    QDomElement date_node = document.createElement(release);
    date_node.setAttribute(day, QString::fromStdString(std::to_string(album->getReleaseDate().getDay())));
    date_node.setAttribute(month, QString::fromStdString(std::to_string(album->getReleaseDate().getMonth())));
    date_node.setAttribute(year, QString::fromStdString(std::to_string(album->getReleaseDate().getYear())));

    return date_node;
}

QDomElement xml_IO::writePM(QDomDocument &document, const PM *album){
    QDomElement pm_node = document.createElement(_pm);
    pm_node.setAttribute(album_name, QString::fromStdString(album->getName()));
    pm_node.setAttribute(album_artist, QString::fromStdString(album->getArtist()));
    pm_node.setAttribute(genre, QString::fromStdString(album->getGenre()));
    pm_node.setAttribute(sales, QString::fromStdString(std::to_string(album->getNumbers())));
    pm_node.setAttribute(support, QString::fromStdString(converter::enum_to_string(PM::support_names, album->getSupport())));

    //album->enum_to_string(album->getSupport()))

    pm_node.appendChild(writeDate(document, album));
    return pm_node;
}

QDomElement xml_IO::writeDM(QDomDocument &document, const DM *album) {
    QDomElement pm_node = document.createElement(_dm);
    pm_node.setAttribute(album_name, QString::fromStdString(album->getName()));
    pm_node.setAttribute(album_artist, QString::fromStdString(album->getArtist()));
    pm_node.setAttribute(genre, QString::fromStdString(album->getGenre()));
    pm_node.setAttribute(listeners, QString::fromStdString(std::to_string(album->getNumbers())));
    pm_node.setAttribute(platform, QString::fromStdString(converter::enum_to_string(DM::platform_names, album->getPlatform())));

    //album->enum_to_string(album->getPlatform())

    pm_node.appendChild(writeDate(document, album));
    return pm_node;
}
