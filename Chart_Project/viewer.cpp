#include "viewer.h"
#include "controller.h"

// ATTENZIONE AI MEMORY LEAK
// MEGLIO CREARE DIFFERENTI WIDGET CUSTOM CLASS ?
// WARNING : impostare le parentelle tra i widget/layout
// OCCHIO AI PARENT

void Viewer::closeEvent(QCloseEvent *event) {
    // DA SISTEMARE
    QMessageBox::StandardButton resBtn = QMessageBox::Yes;
    // controllo se toSave ha elementi
    if(!toSave.isEmpty())
        resBtn = QMessageBox::question(this, "APP NAME", tr("Non hai salvato la nuova musica inserita!\nContinuare?\n"), QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);

    if (resBtn != QMessageBox::Yes)
        event->ignore();
    else
        event->accept();
}

QPushButton *Viewer::createButton(const QString& title){
    QPushButton *button = new QPushButton(title);

    // Aggiungere caratteristiche...

    return button;
}

void Viewer::addMenus(QVBoxLayout *mainLayout) {
    QMenuBar *menuBar = new QMenuBar(this);

    file = new QMenu ("File", menuBar);
    edit = new QMenu ("Edit", menuBar);
    chart = new QMenu ("Grafici", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(edit);
    menuBar->addMenu(chart);

    file->addAction(new QAction("Carica dati", file));  // DA IMPLEMENTARE
    file->addAction(new QAction("Salva dati", file));
    file->addAction(new QAction("Chiudi", file));

    edit->addAction(new QAction("Aggiungi nuova musica", edit));
    edit->addAction(new QAction("Filtra", edit));

    chart->addAction(new QAction("Line Chart", chart));
    chart->addAction(new QAction("Pie Chart", chart));
    chart->addAction(new QAction("Histogram Chart", chart));

    mainLayout->addWidget(menuBar);
}

void Viewer::addControll_1(QVBoxLayout *mainLayout)
{
    // QGROUPBUTTONS
    QHBoxLayout *buttonLayout_1 = new QHBoxLayout;
    QHBoxLayout *dataBtnLayout = new QHBoxLayout;
    QHBoxLayout *chartBtnLayout = new QHBoxLayout;

    //QPushButton *newLabel = new QPushButton("Nuova Label");
    btn_saveData = createButton("Salva dati");
    btn_uploadData = createButton("Carica dati");   // DA IMPLEMENTARE

    dataBtnLayout->addWidget(btn_saveData);
    dataBtnLayout->addWidget(btn_uploadData);

    dataBtnLayout->setSpacing(10);
    dataBtnLayout->setContentsMargins(160, 0, 500 ,0);

    btn_lineChart = createButton("Line Chart");
    btn_pieChart = createButton("Pie Chart");
    btn_histogram = createButton("Histogram");

    chartBtnLayout->addWidget(btn_lineChart);
    chartBtnLayout->addWidget(btn_pieChart);
    chartBtnLayout->addWidget(btn_histogram);

    chartBtnLayout->setSpacing(50);
    chartBtnLayout->setContentsMargins(250, 0, 100 ,0);

    buttonLayout_1->addLayout(dataBtnLayout);
    buttonLayout_1->addLayout(chartBtnLayout);

    mainLayout->addLayout(buttonLayout_1);
}

void Viewer::addControll_2(QHBoxLayout *screenLayout){
    // QGROUPBUTTONS
    QVBoxLayout *buttonLayout_2 = new QVBoxLayout;

    btn_addItem = createButton("Aggiungi musica");
    btn_release = createButton("Pubblica");
    btn_filter = createButton("Filtra");

    buttonLayout_2->addWidget(btn_addItem);
    buttonLayout_2->addWidget(btn_release);
    buttonLayout_2->addWidget(btn_filter);

    buttonLayout_2->setSpacing(5);
    buttonLayout_2->setContentsMargins(0, 25, 10, 300);

    screenLayout->addLayout(buttonLayout_2);
}

void Viewer::addScreen(QVBoxLayout *mainLayout) {
    screenLayout = new QHBoxLayout;

    // button
    addControll_2(screenLayout);
    // table layout
    table_layout = new QHBoxLayout;

    frame = new QFrame;
    frame->setStyleSheet(".QFrame{background-color: rgb(211, 211, 211); border-radius: 10px}");
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //table_layout->addWidget(frame);
    screenLayout->addWidget(frame);
    mainLayout->addLayout(screenLayout);
}

Viewer::Viewer(QWidget *parent) : QDialog(parent), controller(new Controller) {
    mainLayout = new QVBoxLayout;

    // init Custom-Dialog-Form
    md = new MusicDialog(parent);
    md->createAddMusicLayout();

    rd = new ReleaseDialog(parent);
    rd->createReleaseMusicLayout();

    // Add menu bar
    addMenus(mainLayout);

    // Add main buttons
    addControll_1(mainLayout);

    // add main screen
    addScreen(mainLayout);

    // Aggiungere ...

    //mainLayout->setSpacing(0);
    setLayout(mainLayout);
    resize(QSize(1920, 1080));
}

void Viewer::setController(Controller *c) {
    controller = c;

    // IMPLEMENTAZIONE SEGNALI E SLOT
    connect(btn_saveData, SIGNAL(clicked()), controller, SLOT(saveToFile()));

    connect(btn_uploadData, SIGNAL(clicked()), controller, SLOT(showTable()));
        // to show/close Music custom form dialog
    connect(btn_addItem, SIGNAL(clicked()), controller, SLOT(showMusicDialog()));
    connect(md->getCancBtn(), SIGNAL(clicked()), controller, SLOT(closeDialog()));
    connect(md->getAddBtn(), SIGNAL(clicked()), controller, SLOT(addNewMusic()));
        // to show/close Release custo form dialog and checkbox's signal
    connect(btn_release, SIGNAL(clicked()), controller, SLOT(showReleaseDialog()));
    connect(rd->getCancBtn(), SIGNAL(clicked()), controller, SLOT(closeDialog()));
    connect(rd->getAddBtn(), SIGNAL(clicked()), controller, SLOT(releaseMusic()));

    connect(rd->getcdCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(rd->getvnlCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(rd->getcstCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));

    connect(rd->getsptfCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(rd->getapplmCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(rd->gettdlCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(rd->getdzrCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(rd->getytmCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(rd->getamzCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
}

void Viewer::setTable() {
    table = new QTableView;

    catalog = controller->initData();       // NON MI CONVINCE MOLTO
    qDebug() << "Is catalog loaded? " << !catalog.isEmpty() << endl;
    myTableModel = new TableModel(catalog);

    table->setModel(myTableModel);
    //table->setWindowTitle();

    table_layout->addWidget(table);
    frame->setLayout(table_layout);
    /*
    screenLayout->addLayout(table_layout);
    mainLayout->addLayout(screenLayout);
    */
}

void Viewer::addMusic(const Music* newMusic) {
    // FORSE SAREBBE MEGLIO FARLO FARE AL CONTROLLER??
    toSave.push_back(newMusic);

    myTableModel->addEntry(newMusic);
    qDebug() << QString::fromStdString(newMusic->getInfo()) << " inserted" << endl;

    closeDialog();
}

void Viewer::removeMusic(uint index) {
    // per rimuovere
    myTableModel->removeEntry(index);
}

void Viewer::resetComponent() {
    md->resetComponents();
    rd->resetComponents();
}

void Viewer::closeDialog() {
    resetComponent();

    md->close();
    rd->close();
}

void Viewer::showMusicDialog() { md->show(); }

// non sono molto convinto : non dovrebbe farlo il controller??
void Viewer::capitalizeInput(string& input) {
    if (!input.empty()){
        input[0] = std::toupper(input[0]);

        for (uint i = 1; i < input.length(); ++i){
            if (input[i - 1] == ' ')
                input[i] = std::toupper(input[i]);
            else
                input[i] = std::tolower(input[i]);
        }
    }
}

void Viewer::showWarning(const QString &message) {
    QMessageBox::warning(this, tr("Campi vuoti"), message, QMessageBox::Ok);
}

const Music *Viewer::getMusicInput() {
    string name;
    string artist;
    string genre;

    // validazione
    if (md->checkMusicInput()){

        name = md->getNameEdit()->text().toStdString();
        capitalizeInput(name);
        artist = md->getArtistEdit()->text().toStdString();
        capitalizeInput(artist);
        genre = md->getGenreEdit()->text().toStdString();
        capitalizeInput(genre);

        return new Album(genre, name, artist);
    }

    return nullptr;
}

// ReleaseDialog
void Viewer::showReleaseDialog(const QVector<const Music*> &notReleased) {
    // get data for combo box
    rd->setMusicToPublic(notReleased);
    rd->show();
}

std::vector<const Release*> Viewer::getReleaseInput() {
    std::vector<const Release*> result;
    // ADATTARE ALLA COMBOBOX
    uint index = rd->getToPubliCB()->currentIndex();
    auto selectedMusic = controller->getFromNotReleased(index);
    qDebug() << "selected item: " << QString::fromStdString(selectedMusic->getInfo()) << endl;

    uint day(0);
    uint month(0);
    uint year(0);

    uint numbers(0);

    // controllo validita' della data di pubblicazione delegata a RecordLabel
    day = rd->getReleaseDE()->date().day();
    month = rd->getReleaseDE()->date().month();
    year = rd->getReleaseDE()->date().year();


    if(rd->checkPMInput()){
        if (rd->getcdCKB()->isChecked()) {
            numbers = rd->getCdEdit()->text().toUInt();
            result.push_back(new PM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), CD, numbers));
            //addNewMusic(new PM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), pm->first, pm->second));
        }
        if (rd->getvnlCKB()->isChecked()) {
            numbers = rd->getVnlEdit()->text().toUInt();
            result.push_back(new PM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Vinile, numbers));
            //addNewMusic(new PM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Vinile, numbers));
        }
        if (rd->getcstCKB()->isChecked()) {
            numbers = rd->getCstEdit()->text().toUInt();
            result.push_back(new PM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Cassetta, numbers));
            //addNewMusic(new PM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Cassetta, numbers));
        }
    }

    if (rd->checkDMInput()){
        if(rd->getsptfCKB()->isChecked()){
            numbers = rd->getSptfEdit()->text().toUInt();
            result.push_back(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Spotify, numbers));
            //addNewMusic(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Spotify, numbers));
        }
        if(rd->getapplmCKB()->isChecked()){
            numbers = rd->getApplmEdit()->text().toUInt();
            result.push_back(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), AppleMusic, numbers));
            //addNewMusic(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), AppleMusic, numbers));
        }
        if(rd->gettdlCKB()->isChecked()){
            numbers = rd->getTdlEdit()->text().toUInt();
            result.push_back(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Tidal, numbers));
            //addNewMusic(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Tidal, numbers));
        }
        if(rd->getdzrCKB()->isChecked()){
            numbers = rd->getDzrEdit()->text().toUInt();
            result.push_back(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Deezer, numbers));
            //addNewMusic(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Deezer, numbers));
        }
        if(rd->getytmCKB()->isChecked()){
            numbers = rd->getYtmEdit()->text().toUInt();
            result.push_back(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), YoutubeMusic, numbers));
            //addNewMusic(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), YoutubeMusic, numbers));
        }
        if(rd->getamzCKB()->isChecked()){
            numbers = rd->getAmzEdit()->text().toUInt();
            result.push_back(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), AmazonMusic, numbers));
            //addNewMusic(new DM(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), AmazonMusic, numbers));
        }
    }
    return result;
}

void Viewer::enableReleaseDialogComponents() { rd->enableComponents(); }

QVector<const Music*> Viewer::getToSave() const{ return toSave; }

void Viewer::clearToSave() { toSave.clear(); }
