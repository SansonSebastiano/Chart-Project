#include "controller.h"

const QDir Controller::project_path(PROJECT_PATH);
const QString Controller::dataSetDir("/RecordLabel/");

void Controller::loadDataFrom(QString label){
    QDomDocument document;
    QFile file(project_path.absolutePath() + dataSetDir + label + ".xml");
    qDebug() << project_path.absolutePath() + dataSetDir + label + ".xml" << endl;

    if(!file.open(QIODevice::ReadOnly))
        qDebug() << label + ".xml " << "opening failed" << endl;
    document.setContent(&file);
    file.close();

    QDomElement root = document.documentElement();                  // get root node : <catalog> </catalog>
    QDomElement node = root.firstChildElement().toElement();        // get node inside root : <album ... />  : album non pubblicati
                                                                    //                        <PM> ... </PM> : album pubblicati su supporto fisico
                                                                    //                        <DM> ... </DM> : album pubblicati su supporto digitale
    //double profit;

    while (!node.isNull()) {
        qDebug() << node.tagName();
        // se e' un album non pubblicato
        if(node.tagName() == xml_IO::_album)
                model.insertAlbum(xmlio.readAlbum(node));

        // se un album e' pubblicato su un supporto fisico
        if(node.tagName() == xml_IO::_pm)
                model.insertAlbum(xmlio.readPM(node));

        // se un album e' pubblicato su una piattaforma digitale
        if(node.tagName() == xml_IO::_dm)
                model.insertAlbum(xmlio.readDM(node));

        node = node.nextSiblingElement().toElement();
    }
    //model.getAllInfo();   // FOR TESTING
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
    QDomElement root = document.createElement(xml_IO::catalog);
    document.appendChild(root);

    // create node : album, PM or DM
    if(album && !dynamic_cast<const PM*>(album) && !dynamic_cast<const DM*>(album))
        root.appendChild(xmlio.writeAlbum(document, album));
    if(dynamic_cast<const PM*>(album))
        root.appendChild(xmlio.writePM(document, dynamic_cast<const PM*>(album)));
    if (dynamic_cast<const DM*>(album))
        root.appendChild(xmlio.writeDM(document, dynamic_cast<const DM*>(album)));


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

    if(album && !dynamic_cast<const PM*>(album) && !dynamic_cast<const DM*>(album))
        document.firstChild().toElement().appendChild(xmlio.writeAlbum(document, album));
    if(dynamic_cast<const PM*>(album))
        document.firstChild().toElement().appendChild(xmlio.writePM(document, dynamic_cast<const PM*>(album)));
    if(dynamic_cast<const DM*>(album))
        document.firstChild().toElement().appendChild(xmlio.writeDM(document, dynamic_cast<const DM*>(album)));

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << "Already opened or there is another issue" << endl;
        file.close();
    }

    QTextStream content(&file);
    content << document.toString();
    file.close();
}
