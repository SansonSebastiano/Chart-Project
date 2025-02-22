#include "controller.h"

const QDir Controller::project_path(PROJECT_PATH);
const QString Controller::fileName("catalog");
const QString Controller::completePath(project_path.absolutePath() + "/");

Controller::Controller(QObject *parent) : QObject(parent), model(new Model()), xmlio(new xml_IO()) { }

Controller::~Controller() {
    delete view;
    delete model;

    delete xmlio;

    delete chart;
    delete chartWindow;

    catalog.clear();
    catalog.squeeze();

    toSave.clear();
    toSave.squeeze();
}

void Controller::setModel(Model *m) { model = m; }

void Controller::setViewer(Viewer *v) { view = v ; }

// I/O operations

void Controller::readFromFile(const QString& label, QDomDocument& document){
    QFile file(completePath + label + ".xml");  // preleva file nel percorso specificato
    qDebug() << completePath + label + ".xml" << endl;

    if(!file.open(QFile::ReadOnly | QIODevice::Text))       // controlla se e' possibile aprirlo in letture
        qDebug() << label + ".xml " << "opening failed" << endl;
    else
        qDebug() << label + ".xml " << "opening successed" << endl;

    if(!document.setContent(&file))     // controlla se la lettura ha successo
        qDebug() << "Loaded input file failed" << endl;
    else
        qDebug() << "Loaded input file successed" << endl;

    file.close();
}

void Controller::writeOnFile(const QString& label, const QDomDocument& document){
    QFile file(completePath + label + ".xml");  // preleva file nel percorso specificato
    qDebug() << completePath + label + ".xml" << endl;

    if(!file.open(QFile::WriteOnly | QFile::Text)){ // controlla se e' possibile aprirlo in scrittura
        qDebug() << "Already opened or there is another issue" << endl;
        file.close();
    }

    QTextStream content(&file);
    content << document.toString(); // scrittura su file
    file.close();
    qDebug() << "Written with successful" << endl;
}

void Controller::loadDataFrom(const QString& label){
    QDomDocument document;
    readFromFile(label, document);

    QDomElement root = document.documentElement();                  // get root node : <catalog> </catalog>
    QDomElement node = root.firstChildElement().toElement();        // get nodes inside root : <album ... />  : album non pubblicati
                                                                    //                         <PM> ... </PM> : album pubblicati su supporto fisico
                                                                    //                         <DM> ... </DM> : album pubblicati su supporto digitale
    while (!node.isNull()) {
        // se e' un album non pubblicato
        if(node.tagName() == xml_IO::_album)
                model->insertMusic(xmlio->readAlbum(node));

        // se un album e' pubblicato su un supporto fisico
        if(node.tagName() == xml_IO::_pm)
                model->insertMusic(xmlio->readPM(node));

        // se un album e' pubblicato su una piattaforma digitale
        if(node.tagName() == xml_IO::_dm)
                model->insertMusic(xmlio->readDM(node));

        node = node.nextSiblingElement().toElement();
    }

}

void Controller::isExists(const QString& label, const Music* music){
    QFile file(completePath + label + ".xml");
    qDebug() << completePath + label + ".xml" << endl;

    if(file.exists())   // controlla l'esistenza del file
        appendTo(label, music);     // scrive in coda
    else
        newSave(label, music);      // crea un nuovo file
}

void Controller::newSave(const QString& label, const Music *music){
    QDomDocument document;
    QDomElement root = document.createElement(xml_IO::catalog);
    document.appendChild(root);

    QDomElement node;

    if(music){
        if(dynamic_cast<const Album*>(music) && !dynamic_cast<const PM*>(music) && !dynamic_cast<const DM*>(music)) {
            node = document.createElement(xml_IO::_album);
            root.appendChild(xmlio->writeAlbum(node, static_cast<const Album*>(music)));
        }
        if(dynamic_cast<const PM*>(music))
            root.appendChild(xmlio->writePM(document, static_cast<const PM*>(music)));
        if (dynamic_cast<const DM*>(music))
            root.appendChild(xmlio->writeDM(document, static_cast<const DM*>(music)));
    }

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
            document.firstChild().toElement().appendChild(xmlio->writeAlbum(node, static_cast<const Album*>(music)));
        }
        if(dynamic_cast<const PM*>(music))
            document.firstChild().toElement().appendChild(xmlio->writePM(document, static_cast<const PM*>(music)));
        if(dynamic_cast<const DM*>(music))
            document.firstChild().toElement().appendChild(xmlio->writeDM(document, static_cast<const DM*>(music)));
    }

    writeOnFile(label, document);
}

void Controller::releasePMToFile(const QString& label, const Album *album, const Date &date, uint num, Support support){
    QDomDocument document;
    readFromFile(label, document);

    if(album){
        if(support != None_Support){
            QDomNodeList list = document.elementsByTagName(xml_IO::_album);
            QDomElement result = xmlio->searchByName(list, album);

            appendTo(label, new PM(album->getGenre(), album->getName(), album->getArtist(), date, support, num));
        }
    }
}

void Controller::releaseDMToFile(const QString& label, const Album *album, const Date &date, uint num, Platform platform){
    QDomDocument document;
    readFromFile(label, document);

    if(album){
        if(platform != None_Platform){
            QDomNodeList list = document.elementsByTagName(xml_IO::_album);
            QDomElement result = xmlio->searchByName(list, album);

            appendTo(label, new DM(album->getGenre(), album->getName(), album->getArtist(), date, platform, num));
        }
    }
}

void Controller::removeFromFile(const QString& label, const Music* music, const QString& music_type) {
    QDomDocument document;
    readFromFile(label, document);

    QDomNodeList list = document.elementsByTagName(music_type); // lista di album nella quale cercare l'album non publicato da eliminare

    xmlio->removeByName(list, music);

    writeOnFile(label, document);
}

QVector<const Music*> Controller::initData() {
    loadDataFrom(fileName);

    auto data = model->getCatalog();
    QVector<const Music*> myVector = QVector<const Music*>::fromStdVector(data);

    return myVector;
}

const QVector<const Music*> Controller::getToSave() const { return toSave; }

//------------------------------------------------------------
//                          SLOTS
//------------------------------------------------------------
void Controller::showTable() {
    if (catalog.isEmpty()) {
        catalog = initData();
        qDebug() << "Is catalog loaded? " << !catalog.isEmpty() << endl;

        view->setTable(catalog);        // imposta i dati nella tabella
    }else
        view->showWarning("Dati già caricati");
}

void Controller::closeDialog(FormDialog *dialog) { view->closeDialog(dialog); }

void Controller::removeFromToSave(const Music *music) {
    bool found (false);
    for (auto it = toSave.begin(); it != toSave.end() && !found; ++it){
        if(!dynamic_cast<const Release*>(*it) && model->areEquals((*it), music)){
            qDebug() << QString::fromStdString((*it)->getInfo()) << endl;
            it = toSave.erase(it);
            it--;
            found = true;
            qDebug() << "REMOVED FROM TOSAVE" << endl;
        }
    }
}

void Controller::saveToFile() {
    QVector<const Music*> v (toSave);
    toSave.clear();
    // controllo se 'v' e' vuoto
    if (!v.isEmpty())
        for (auto it = v.begin(); it != v.end(); ++it){
            appendTo(fileName, *it);

            if(dynamic_cast<const Release*>(*it))
                removeFromFile(fileName, *it, xml_IO::_album);
        }
    else view->showWarning("Nuova musica non inserita");
}

void Controller::showMusicDialog() {
    auto dialog = view->getMusicDialog();
    auto data = model->getCatalog();
    if (!data.empty())
        view->showDialog(dialog);
    else
        view->showWarning("Dati non caricati");
}

void Controller::addNewMusic() {
    auto dialog = view->getMusicDialog();
    auto newMusic = dialog->getInput(); // preleva i dati in input

    if (newMusic){
        if (!model->isPresent(newMusic)){
            auto ask = view->showQuestion("Sei sicuro di inserire: \n" + QString::fromStdString(newMusic->getInfo()));

            if (ask == QMessageBox::Yes){
                // aggiungo 'newMusic' a RecordLabel
                model->insertMusic(newMusic);
                // aggiungo 'newMusic' alla tabella
                view->addMusicToTable(newMusic);
                // aggiungo 'newMusic' a toSave
                toSave.push_back(newMusic);

                view->closeDialog(dialog);
            }
        }
        else{
            view->showWarning(QString::fromStdString(newMusic->getInfo()) + "\n\n è già esistente");
            view->resetComponents(dialog);
        }
    }
    else
        view->showWarning("Campi obbligatori");
}

void Controller::showReleaseDialog() {
    auto dialog = view->getReleaseDialog();
    auto data = model->getNotReleasedMusic();

    if (!data.empty()) {
        dialog->setMusicToPublic(data); // set music to release into release dialog combobox
        view->showDialog(dialog);
    }
    else
        view->showWarning("Non c'e' nulla da pubblicare");
}

void Controller::enableRDComponents() { view->getReleaseDialog()->enableComponents(); }

int Controller::getIndex(const Music* music) {
    auto catalog = model->getCatalog();

    for (auto it = catalog.begin(); it != catalog.end(); ++it){

        if (!dynamic_cast<const Release*>(*it) && model->areEquals(*it, music))
            return it - catalog.begin();
    }
    return -1;
}

void Controller::releaseMusic() {
    auto dialog = view->getReleaseDialog();

    if (dialog->isAllUnchecked())
        // nessuna checkbox selezionata
        view->showWarning("Scegliere almeno una Piattaforma/Supporto!");
    else {
        // almeno una checkbox selezionata
        if (dialog->isAllEmpty())
            // edit line vuota
            view->showWarning("Compilare almeno un campo");
        else {            
            auto ask = view->showQuestion("Dati inseriti correttamente? \nSei sicuro di continuare con la pubblicazione?");
            if (ask == QMessageBox::Yes){
                // rispettiva edit line non vuota => acquisizione input
                auto not_released = model->getNotReleasedMusic();
                auto toRelease = dialog->getInput(not_released);
                auto toRemove = toRelease.at(0);

                // rimuovere la versione non pubblica del prodotto musicale appena pubblicato:
                    // dalla lista di salvataggio
                removeFromToSave(toRemove);
                    // dalla tabella
                view->removeMusicFromTable(getIndex(toRemove));

                for (auto it = toRelease.begin(); it != toRelease.end(); ++it){
                    model->insertMusic((*it)); // inserisce la pubblicazione dell'album nel catalogo
                    // se trascorso almeno un anno
                    if (model->isElapsed1Year(*it))
                        view->addMusicToTable((*it));   // inserisce la pubblicazione dell'album nella tabella

                    toSave.push_back(*it);  // inserisce la pubblicazione dell'album nella lista di salvataggio
                }
                model->removeMusic(toRemove); // rimuove l'album dal catalogo

                view->closeDialog(dialog);
            }
        }
    }
}

void Controller::showLineChartDialog() {
    auto dialog = view->getLineChartDialog();
    auto genres = model->getGenres();   // preleva i generi musicali

    if (!genres.empty()){
        dialog->setGenreCB(genres);     // imposta i generi nella combobox
        view->showDialog(dialog);
    }else
        view->showWarning("Non e' stato caricato nessun dato");
}

void Controller::enableLDComponents() { view->getLineChartDialog()->enableComponents(); }

void Controller::showLineChartWindow() {
    auto dialog = view->getLineChartDialog();

    if (dialog->getGenreRB()->isChecked()) {
        // preleva l'intervallo di anni
        uint from = dialog->getYearFrom(),
             to = dialog->getYearTo();

        if (from == to || from > to)    // controlla la validita' dell'intervallo
            view->showWarning("Date errate!");
        else {
            string genre(dialog->getGenreSelected());

            vector<const Music*> result;

            QString title("Profitto per anno in base al genere musicale: " + QString::fromStdString(genre));

            // imposta il grafico
            chart = new LineChart(title, model->lineChartOp1(genre, from, to, result), from, to);
            chart->setChart();
            // imposta la schermata per visualizzare il grafico
            chartWindow = new ChartScreen();
            chartWindow->setTableView(QVector<const Music*>::fromStdVector(result));
            chartWindow->setChartView(chart);
            chartWindow->show();

            dialog->resetComponents();
            dialog->close();
        }
    }else
        view->showWarning("Seleziona un genere");
}

void Controller::showPieChartDialog() {
    auto dialog(view->getPieChartDialog());
    auto data(model->getCatalog());

    if (!data.empty())
        view->showDialog(dialog);
    else
        view->showWarning("Non e' stato caricato nessun dato");
}

void Controller::changeDescription() { view->getPieChartDialog()->switchDescription(); }

void Controller::showPieChartWindow() {
    auto dialog(view->getPieChartDialog());

    switch (dialog->getOptionsIndex()) {
    case 0:
        setPieOp1();
        break;
    case 1:
        setPieOp2();
        break;
    case 2:
        setPieOp3();
        break;
    default:
        break;
    }
    dialog->resetComponents();
    dialog->close();
}

void Controller::setPieOp1(){
    chart = new PieChart("Top 5", model->pieChartOp1());
    chart->setChart();

    chartWindow = new ChartScreen();
    chartWindow->setChartView(chart);
    chartWindow->show();
}

void Controller::setPieOp2() {
    auto data(model->pieChartOp2());

    QList<qreal> ydata;
    ydata.push_back(data.first);   // released music
    ydata.push_back(data.second);  // not released music

    chart = new PieChart("Catalogo musica:", {"Rilasciata", "Non rilasciata"}, ydata);
    chart->setChart();

    chartWindow = new ChartScreen();
    chartWindow->setChartView(chart);
    chartWindow->show();
}

void Controller::setPieOp3() {
    auto data(model->pieChartOp3());

    QList<qreal> ydata;
    ydata.push_back(data.first);   //  support's profit
    ydata.push_back(data.second);  // platform's profit

    chart = new PieChart("Musica pubblicata:", {"Supporti Fisici", "Piattaforme Digitali"}, ydata);
    chart->setChart();

    chartWindow = new ChartScreen();
    chartWindow->setChartView(chart);
    chartWindow->show();
}

void Controller::showBarChartDialog() {
    auto dialog(view->getBarChartDialog());
    auto data(model->getCatalog());

    if (!data.empty())
        view->showDialog(dialog);
    else
        view->showWarning("Non e' stato caricato nessun dato");
}

// BAR CHART

void Controller::setBarOp1(uint year){
    chart = new BarChart("Profitto per supporto", model->barChartOp1(year), QString::number(year));
    chart->setChart();

    chartWindow = new ChartScreen();
    chartWindow->setChartView(chart);
    chartWindow->show();
}

void Controller::setBarOp2(uint year){
    chart = new BarChart("Profitto per piattaforma", model->barChartOp2(year), QString::number(year));
    chart->setChart();

    chartWindow = new ChartScreen();
    chartWindow->setChartView(chart);
    chartWindow->show();
}

void Controller::showBarChartWindow() {
      auto dialog(view->getBarChartDialog());

      switch (dialog->getOptionsIndex()) {
      case 0:
          setBarOp1(dialog->getSelectedYear());
          break;
      case 1:
          setBarOp2(dialog->getSelectedYear());
          break;
      default:
          break;
      }

      dialog->resetComponents();
      dialog->close();
}
