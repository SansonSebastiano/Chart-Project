#include "controller.h"
#include "EnumResolver.h"

const QDir Controller::project_path(PROJECT_PATH);
const QString Controller::dataSetDir("/RecordLabel/");

const QString Controller::catalog("catalog");
const QString Controller::release("release");
const QString Controller::_album("album");
const QString Controller::_pm("PM");
const QString Controller::_dm("DM");

const QString Controller::album_name("name");
const QString Controller::album_artist("artist");
const QString Controller::genre("genre");

const QString Controller::day("day");
const QString Controller::month("month");
const QString Controller::year("year");

const QString Controller::sales("num_sales");
const QString Controller::support("support");

const QString Controller::listeners("listeners");
const QString Controller::platform("platform");

const Album* Controller::readAlbum(QDomElement node){
        return new Album(node.attribute(genre, genre).toStdString(),        // genere musicale
                         node.attribute(album_name, album_name).toStdString(),          // nome album
                         node.attribute(album_artist, album_artist).toStdString()       // artista
                        );
}

const Date Controller::readDate(QDomElement childNode){
    qDebug() << childNode.tagName();
    if(childNode.tagName() == release)
        return Date (str_to_uint(childNode.attribute(day, day).toStdString()),       // giorno
                     str_to_uint(childNode.attribute(month, month).toStdString()),   // mese
                     str_to_uint(childNode.attribute(year, year).toStdString())      // anno
                    );
    else{
        qDebug() << "Read date failed" << endl;
        return {};
    }
}

const Album* Controller::readPM(QDomElement node){
    return new PM(node.attribute(genre, genre).toStdString(),        // genere musicale
                  node.attribute(album_name, album_name).toStdString(),          // nome album
                  node.attribute(album_artist, album_artist).toStdString(),      // artista
                  readDate(node.firstChildElement().toElement()),        // data pubblicazione
                  // supporto fisico
                  enum_to_string<Support>(node.attribute(support, support).toStdString(), support_names, MAX_PVALUES),
                  // vendite
                  str_to_uint(node.attribute(sales, sales).toStdString())
                 );
}

const Album* Controller::readDM(QDomElement node){
    return new DM(node.attribute(genre, genre).toStdString(),        // genere musicale
                  node.attribute(album_name, album_name).toStdString(),          // nome album
                  node.attribute(album_artist, album_artist).toStdString(),      // artista
                  readDate(node.firstChildElement().toElement()),        // data pubblicazione
                  // piattaforma digitale
                  enum_to_string<Platform>(node.attribute(platform, platform).toStdString(), platform_names, MAX_SVALUES),
                  // ascolti
                  str_to_uint(node.attribute(listeners, listeners).toStdString())
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

    QDomElement catalog = document.documentElement();                  // get root node : <catalog> </catalog>
    QDomElement node = catalog.firstChildElement().toElement();        // get node inside root : <album ... />  : album non pubblicati
                                                                       //                        <PM> ... </PM> : album pubblicati su supporto fisico
                                                                       //                        <DM> ... </DM> : album pubblicati su supporto digitale

    //double profit;

    while (!node.isNull()) {
        qDebug() << node.tagName();
        // se e' un album non pubblicato
        if(node.tagName() == _album)
                model.insertAlbum(readAlbum(node));

        // se un album e' pubblicato su un supporto fisico
        if(node.tagName() == _pm)
                model.insertAlbum(readPM(node));

        // se un album e' pubblicato su una piattaforma digitale
        if(node.tagName() == _dm)
                model.insertAlbum(readDM(node));

        node = node.nextSiblingElement().toElement();
    }
    model.getAllInfo();   // test
    // ALTRIMENTI IL FILE E' VUOTO?
}

void Controller::isExists(QString label, const Album* album){
    QFile file(project_path.absolutePath() + dataSetDir + label + ".xml");
    qDebug() << project_path.absolutePath() + dataSetDir + label + ".xml" << endl;

    if(file.exists())
        appendTo(file, album);
    else
        newSave(file, album);
}

void Controller::newSave(QFile& file, const Album *album){
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << "Already opened or there is another issue" << endl;
        file.close();
    }
    QTextStream content(&file);

    QDomDocument document;
    QDomElement root = document.createElement(catalog);
    document.appendChild(root);

    // create node : album, PM or DM
    if(album && !dynamic_cast<const PM*>(album) && !dynamic_cast<const DM*>(album))
        root.appendChild(writeAlbum(document, album));
    if(dynamic_cast<const PM*>(album))
        root.appendChild(writePM(document, dynamic_cast<const PM*>(album)));
    if (dynamic_cast<const DM*>(album))
        root.appendChild(writeDM(document, dynamic_cast<const DM*>(album)));


    content << document.toString();
    file.close();
}

void Controller::appendTo(QFile &file, const Album *album){
    if(!file.open(QFile::ReadOnly | QIODevice::Text))
        qDebug() << "Errore while loading file" << endl;

    QDomDocument document;
    if(!document.setContent(&file))
        qDebug() << "Loaded input file failed" << endl;
    file.close();

    QDomElement root = document.documentElement();

    // create node : album, PM or DM
    if(album && !dynamic_cast<const PM*>(album) && !dynamic_cast<const DM*>(album))
        document.firstChild().toElement().appendChild(writeAlbum(document, album));
    if(dynamic_cast<const PM*>(album))
        document.firstChild().toElement().appendChild(writePM(document, dynamic_cast<const PM*>(album)));
    if(dynamic_cast<const DM*>(album))
        document.firstChild().toElement().appendChild(writeDM(document, dynamic_cast<const DM*>(album)));

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << "Already opened or there is another issue" << endl;
        file.close();
    }

    QTextStream content(&file);
    content << document.toString();
    file.close();
}

QDomElement Controller::writeAlbum(QDomDocument &document, const Album* album) {
    QDomElement album_node = document.createElement(_album);
    album_node.setAttribute(album_name, QString::fromStdString(album->getAlbumName()));
    album_node.setAttribute(album_artist, QString::fromStdString(album->getAlbumArtist()));
    album_node.setAttribute(genre, QString::fromStdString(album->getGenre()));
    return album_node;
}

QDomElement Controller::writeDate(QDomDocument &document, const Release *album) {
    QDomElement date_node = document.createElement(release);
    date_node.setAttribute(day, QString::fromStdString(std::to_string(album->getReleaseDate().getDay())));
    date_node.setAttribute(month, QString::fromStdString(std::to_string(album->getReleaseDate().getMonth())));
    date_node.setAttribute(year, QString::fromStdString(std::to_string(album->getReleaseDate().getYear())));

    return date_node;
}

QDomElement Controller::writePM(QDomDocument &document, const PM *album){
    QDomElement pm_node = document.createElement(_pm);
    pm_node.setAttribute(album_name, QString::fromStdString(album->getAlbumName()));
    pm_node.setAttribute(album_artist, QString::fromStdString(album->getAlbumArtist()));
    pm_node.setAttribute(genre, QString::fromStdString(album->getGenre()));
    pm_node.setAttribute(sales, QString::fromStdString(std::to_string(album->getNumSales())));
    pm_node.setAttribute(support, QString::fromStdString(album->support_to_string(album->getSupport())));

    pm_node.appendChild(writeDate(document, album));
    return pm_node;
}

QDomElement Controller::writeDM(QDomDocument &document, const DM *album) {
    QDomElement pm_node = document.createElement(_dm);
    pm_node.setAttribute(album_name, QString::fromStdString(album->getAlbumName()));
    pm_node.setAttribute(album_artist, QString::fromStdString(album->getAlbumArtist()));
    pm_node.setAttribute(genre, QString::fromStdString(album->getGenre()));
    pm_node.setAttribute(listeners, QString::fromStdString(std::to_string(album->getListeners())));
    pm_node.setAttribute(platform, QString::fromStdString(album->platform_to_string(album->getPlatform())));

    pm_node.appendChild(writeDate(document, album));
    return pm_node;
}

uint Controller::str_to_uint(string input){ return std::stoul(input, nullptr, 0); }
