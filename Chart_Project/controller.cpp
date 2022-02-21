#include "controller.h"

const QDir Controller::project_path(PROJECT_PATH);
const QString Controller::dataSetDir("/RecordLabel/");

// WARNING : al nome della record label
Controller::Controller(QObject *parent) : QObject(parent), model(new Model()) { }

void Controller::setModel(Model *m) { model = m; }

void Controller::setViewer(Viewer *v) { view = v ; }

void Controller::readFromFile(const QString& label, QDomDocument& document){
    QFile file(project_path.absolutePath() + dataSetDir + label + ".xml");
    qDebug() << project_path.absolutePath() + dataSetDir + label + ".xml" << endl;

    if(!file.open(QFile::ReadOnly | QIODevice::Text))
        qDebug() << label + ".xml " << "opening failed" << endl;

    if(!document.setContent(&file))
        qDebug() << "Loaded input file failed" << endl;
    file.close();
}

void Controller::writeOnFile(const QString& label, const QDomDocument& document){
    QFile file(project_path.absolutePath() + dataSetDir + label + ".xml");
    qDebug() << project_path.absolutePath() + dataSetDir + label + ".xml" << endl;

    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << "Already opened or there is another issue" << endl;
        file.close();
    }

    QTextStream content(&file);
    content << document.toString();
    file.close();
}

void Controller::loadDataFrom(const QString& label){
    QDomDocument document;
    readFromFile(label, document);

    QDomElement root = document.documentElement();                  // get root node : <catalog> </catalog>
    QDomElement node = root.firstChildElement().toElement();        // get nodes inside root : <album ... />  : album non pubblicati
                                                                    //                         <PM> ... </PM> : album pubblicati su supporto fisico
                                                                    //                         <DM> ... </DM> : album pubblicati su supporto digitale
    while (!node.isNull()) {
        //qDebug() << node.tagName();
        // se e' un album non pubblicato
        if(node.tagName() == xml_IO::_album)
                model->insertMusic(xmlio.readAlbum(node));

        // se un album e' pubblicato su un supporto fisico
        if(node.tagName() == xml_IO::_pm)
                model->insertMusic(xmlio.readPM(node));

        // se un album e' pubblicato su una piattaforma digitale
        if(node.tagName() == xml_IO::_dm)
                model->insertMusic(xmlio.readDM(node));

        node = node.nextSiblingElement().toElement();
    }
    //model->getAllInfo();   // just TESTING
    // ALTRIMENTI IL FILE E' VUOTO?
}

void Controller::isExists(const QString& label, const Music* music){
    QFile file(project_path.absolutePath() + dataSetDir + label + ".xml");
    qDebug() << project_path.absolutePath() + dataSetDir + label + ".xml" << endl;

    if(file.exists())
        appendTo(label, music);
    else
        newSave(label, music);
}

void Controller::newSave(const QString& label, const Music *music){
    QDomDocument document;
    QDomElement root = document.createElement(xml_IO::catalog);
    document.appendChild(root);

    QDomElement node;

    if(music){
        if(dynamic_cast<const Album*>(music) && !dynamic_cast<const PM*>(music) && !dynamic_cast<const DM*>(music)) {
            node = document.createElement(xml_IO::_album);
            root.appendChild(xmlio.writeAlbum(node, static_cast<const Album*>(music)));
        }
        if(dynamic_cast<const PM*>(music))
            root.appendChild(xmlio.writePM(document, static_cast<const PM*>(music)));
        if (dynamic_cast<const DM*>(music))
            root.appendChild(xmlio.writeDM(document, static_cast<const DM*>(music)));
    }
    // altrimenti pointer nullo
    writeOnFile(label, document);
}

void Controller::appendTo(const QString& label, const Music *music){
    QDomDocument document;
    readFromFile(label, document);

    QDomElement root = document.documentElement();
    QDomElement node;

    if (music){
        if(dynamic_cast<const Album*>(music) && !dynamic_cast<const PM*>(music) && !dynamic_cast<const DM*>(music)){
            node = document.createElement(xml_IO::_album);
            document.firstChild().toElement().appendChild(xmlio.writeAlbum(node, static_cast<const Album*>(music)));
        }
        if(dynamic_cast<const PM*>(music))
            document.firstChild().toElement().appendChild(xmlio.writePM(document, static_cast<const PM*>(music)));
        if(dynamic_cast<const DM*>(music))
            document.firstChild().toElement().appendChild(xmlio.writeDM(document, static_cast<const DM*>(music)));
    }
    // altrimenti pointer nullo

    writeOnFile(label, document);
}

void Controller::releasePMToFile(const QString& label, const Album *album, const Date &date, uint num, Support support){
    QDomDocument document;
    readFromFile(label, document);

    if(album){
        if(support != None_Support){
            QDomNodeList list = document.elementsByTagName(xml_IO::_album);
            QDomElement result = xmlio.searchByName(list, album->getName());

            appendTo(label, new PM(album->getGenre(), album->getName(), album->getArtist(), date, support, num));
        }// else => ECCEZIONE medium nullo
        // inserire questa eccezione dovunque serva e dove manca
    }// else => music nullo
}

void Controller::releaseDMToFile(const QString& label, const Album *album, const Date &date, uint num, Platform platform){
    QDomDocument document;
    readFromFile(label, document);

    if(album){
        if(platform != None_Platform){
            QDomNodeList list = document.elementsByTagName(xml_IO::_album);
            QDomElement result = xmlio.searchByName(list, album->getName());

            appendTo(label, new DM(album->getGenre(), album->getName(), album->getArtist(), date, platform, num));
        }// else => ECCEZIONE medium nullo
        // inserire questa eccezione dovunque serva e dove manca

    } // else => music nullo
}

void Controller::removeFromFile(const QString& label, const Music* music) {
    QDomDocument document;
    readFromFile(label, document);

    QDomNodeList list = document.elementsByTagName(xml_IO::_album);

    xmlio.removeByName(list, music->getName());

    writeOnFile(label, document);
}

QVector<const Music*> Controller::initData() {
    loadDataFrom("sample_1");       // ATTENZIONE : QUANDO NECESSARIO CAMBIARE NOME DEL FILE

    auto data = model->getData();
    QVector<const Music*> myVector = QVector<const Music*>::fromStdVector(data);

    return myVector;
}

// SLOTS
void Controller::showDialog() { view->showFormDialog(); }
void Controller::closeDialog() { view->closeFormDialog(); }
void Controller::enableDialog() { view->enableFormDialogComponents(); }
void Controller::getNewMusic() {
    auto newMusic = view->getMusicInput();
    if (newMusic){
        if (!model->isPresent(newMusic))
            view->addNewMusic(newMusic);
        else{
            view->showWarning("The following: \n" + QString::fromStdString(newMusic->getInfo()) + "\nalready exists");
            view->closeFormDialog();
        }
    }
    else
        view->showWarning("Campi obbligatori");
}

/*




void Controller::addMusic() {
    view->addNewMusic();

    view->closeFormDialog();
}

void Controller::showTextEdit() {
    view->showEditLine();
}
*/
