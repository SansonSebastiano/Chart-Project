#include "controller.h"

const QDir Controller::project_path(PROJECT_PATH);
const QString Controller::dataSetDir("/RecordLabel/");

const Album* Controller::readAlbum(QDomElement node){
        return new Album(node.attribute("name", "name").toStdString(),          // nome album
                         node.attribute("artist", "artist").toStdString(),      // artista
                         node.attribute("genre", "genre").toStdString()         // genere musicale
                        );
}

const Date Controller::readDate(QDomElement node){
    return Date (str_to_uint(node.attribute("day", "day").toStdString()),       // giorno
                 str_to_uint(node.attribute("month", "month").toStdString()),   // mese
                 str_to_uint(node.attribute("year", "year").toStdString())      // anno
                );
}
/*
const Album* Controller::readPM(QDomElement node){
    return new PM(node.attribute("name", "name").toStdString(),          // nome album
                  node.attribute("artist", "artist").toStdString(),      // artista
                  node.attribute("genre", "genre").toStdString(),        // genere musicale
                  readDate(node),
                  node.attribute("support", "support").toStdString(),
                  str_to_uint(node.attribute("num_sales", "num_sales").toStdString())
                 );
}
*/
void Controller::loadDataFrom(QString label){
    QDomDocument document;
    QFile file(project_path.absolutePath() + dataSetDir + label + ".xml");

    if(!file.open(QIODevice::ReadOnly))
        qDebug() << label + ".xml " << "opening failed" << endl;
    document.setContent(&file);
    file.close();

    QDomElement root = document.documentElement();
    QDomElement node = root.firstChildElement().toElement();

    double profit;

    uint num_sales;
    Support support;

    uint listeners;
    Platform platform;

    while (!node.isNull()) {
        // se e' un album non pubblicato
        if(node.tagName() == "album"){
            while (!node.isNull()) {
                model->insertAlbum(readAlbum(node));

                node = node.nextSiblingElement().toElement();
            }
        }
        // se un album e' pubblicato su un support fisico
        if(node.tagName() == "PM"){

        }
        // se un album e' pubblicato su una piattaforma digitale
        if(node.tagName() == "DM"){

        }
        node = node.nextSiblingElement().toElement();
    }
    // ALTRIMENTI IL FILE E' VUOTO?
}

uint Controller::str_to_uint(string input){
    return std::stoul(input, nullptr, 0);
}
