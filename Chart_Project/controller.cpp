#include "controller.h"
#include "EnumResolver.h"

const QDir Controller::project_path(PROJECT_PATH);
const QString Controller::dataSetDir("/RecordLabel/");

const Album* Controller::readAlbum(QDomElement node){
        return new Album(node.attribute("genre", "genre").toStdString(),        // genere musicale
                         node.attribute("name", "name").toStdString(),          // nome album
                         node.attribute("artist", "artist").toStdString()       // artista
                        );
}

const Date Controller::readDate(QDomElement childNode){
    qDebug() << childNode.tagName();
    if(childNode.tagName() == "release")
        return Date (str_to_uint(childNode.attribute("day", "day").toStdString()),       // giorno
                     str_to_uint(childNode.attribute("month", "month").toStdString()),   // mese
                     str_to_uint(childNode.attribute("year", "year").toStdString())      // anno
                    );
    else{
        qDebug() << "Read date failed" << endl;
        return {};
    }
}

const Album* Controller::readPM(QDomElement node){
    return new PM(node.attribute("genre", "genre").toStdString(),        // genere musicale
                  node.attribute("name", "name").toStdString(),          // nome album
                  node.attribute("artist", "artist").toStdString(),      // artista
                  readDate(node.firstChildElement().toElement()),        // data pubblicazione
                  // supporto fisico
                  enum_to_string<Support>(node.attribute("support", "support").toStdString(), support_names, MAX_PVALUES),
                  // numero vendite
                  str_to_uint(node.attribute("num_sales", "num_sales").toStdString())
                 );
}

const Album* Controller::readDM(QDomElement node){
    return new DM(node.attribute("genre", "genre").toStdString(),        // genere musicale
                  node.attribute("name", "name").toStdString(),          // nome album
                  node.attribute("artist", "artist").toStdString(),      // artista
                  readDate(node.firstChildElement().toElement()),        // data pubblicazione
                  // piattaforma digitale
                  enum_to_string<Platform>(node.attribute("platform", "platform").toStdString(), platform_names, MAX_SVALUES),
                  // numero vendite
                  str_to_uint(node.attribute("listeners", "listeners").toStdString())
                );
}

void Controller::loadDataFrom(QString label){
    QDomDocument document;
    QFile file(project_path.absolutePath() + dataSetDir + label + ".xml");
    qDebug() << project_path.absolutePath() + dataSetDir + label + ".xml" << endl;

    if(!file.open(QIODevice::ReadOnly))
        qDebug() << label + ".xml " << "opening failed" << endl;
    document.setContent(&file);
    file.close();

    QDomElement root = document.documentElement();
    QDomElement node = root.firstChildElement().toElement();

    //double profit;

    while (!node.isNull()) {
        // se e' un album non pubblicato
        qDebug() << node.tagName();
        if(node.tagName() == "album")
                model.insertAlbum(readAlbum(node));

        // se un album e' pubblicato su un supporto fisico
        qDebug() << node.tagName();
        if(node.tagName() == "PM")
                model.insertAlbum(readPM(node));

        // se un album e' pubblicato su una piattaforma digitale
        qDebug() << node.tagName();
        if(node.tagName() == "DM")
                model.insertAlbum(readDM(node));

        model.getAllInfo();   // test
        node = node.nextSiblingElement().toElement();
    }
    // ALTRIMENTI IL FILE E' VUOTO?
}

void Controller::saveDataTo(QString label){
    QFile file(project_path.absolutePath() + dataSetDir + label + ".xml");
    qDebug() << project_path.absolutePath() + dataSetDir + label + ".xml" << endl;
    if(!file.open(QFile::WriteOnly | QFile::Text))
        qDebug() << "Already opened or there is another issue" << endl;

    QTextStream content(&file);

    QDomDocument document;
    QDomElement root = document.createElement("catalog");

}

uint Controller::str_to_uint(string input){
    return std::stoul(input, nullptr, 0);
}
