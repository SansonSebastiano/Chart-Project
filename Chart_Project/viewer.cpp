#include "viewer.h"
#include "controller.h"

// ATTENZIONE AI MEMORY LEAK
// MEGLIO CREARE DIFFERENTI WIDGET CUSTOM CLASS ?
// WARNING : impostare le parentelle tra i widget/layout

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
    QHBoxLayout *buttonLayout_1 = new QHBoxLayout;
    QHBoxLayout *dataBtnLayout = new QHBoxLayout;
    QHBoxLayout *chartBtnLayout = new QHBoxLayout;

    //QPushButton *newLabel = new QPushButton("Nuova Label");
    btn_uploadData = createButton("Carica dati");   // DA IMPLEMENTARE
    btn_saveData = createButton("Salva dati");

    dataBtnLayout->addWidget(btn_uploadData);
    dataBtnLayout->addWidget(btn_saveData);

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

void Viewer::addControll_2(QHBoxLayout *screenLayout)
{
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

Viewer::Viewer(QWidget *parent) : QWidget(parent), controller(new Controller) {
    mainLayout = new QVBoxLayout;

    // init Dialog-Form
    cfd = new CustomFormDialog();
    cfd->createAddMusicLayout();

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
    connect(btn_uploadData, SIGNAL(clicked()), controller, SLOT(showTable()));
        // to show/close custom form dialog
    connect(btn_addItem, SIGNAL(clicked()), controller, SLOT(showDialog()));
    connect(cfd->getCancbtn(), SIGNAL(clicked()), controller, SLOT(closeDialog()));
        // checkbox's cfd signal/slot
    connect(cfd->getcdCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(cfd->getvnlCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(cfd->getcstCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));

    connect(cfd->getsptfCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(cfd->getapplmCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(cfd->gettdlCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(cfd->getdzrCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(cfd->getytmCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));
    connect(cfd->getamzCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableDialog()));

    /*
    connect(cfd->getCdEdit(), SIGNAL(editingFinished()), controller, SLOT(enableDialog()));
    connect(cfd->getVnlEdit(), SIGNAL(editingFinished()), controller, SLOT(enableDialog()));
    connect(cfd->getCstEdit(), SIGNAL(editingFinished()), controller, SLOT(enableDialog()));
    */
    connect(cfd->getAddbtn(), SIGNAL(clicked()), controller, SLOT(getNewMusic()));
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

void Viewer::showFormDialog() { cfd->show(); }

void Viewer::resetComponent() { cfd->resetComponents(); }

void Viewer::closeFormDialog() {
    cfd->resetComponents();
    cfd->close();
}

void Viewer::enableFormDialogComponents() {
    cfd->enableReleaseComponents();
}

// non sono molto convinto : dovrebbe farlo il controller??
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

Music *Viewer::getMusicInput() {
    string name;
    string artist;
    string genre;

    // validazione
    if (cfd->checkMusicInput()){

        name = cfd->getNameEdit()->text().toStdString();
        capitalizeInput(name);
        artist = cfd->getArtistEdit()->text().toStdString();
        capitalizeInput(artist);
        genre = cfd->getGenreEdit()->text().toStdString();
        capitalizeInput(genre);

        return new Album(genre, name, artist);
    }

    return nullptr;
}

void Viewer::getReleaseInput() {
    // ADATTARE ALLA COMBOBOX
    string name;
    string artist;
    string genre;

    uint day = 0;
    uint month = 0;
    uint year = 0;

    QPair<Support, uint> *pm = new QPair<Support, uint>();
    QPair<Platform, uint> *dm = new QPair<Platform, uint>();

    // controlli
    if (cfd->checkMusicInput()){

        name = cfd->getNameEdit()->text().toStdString();
        artist = cfd->getArtistEdit()->text().toStdString();
        genre = cfd->getGenreEdit()->text().toStdString();

        // controllo validita' della data di pubblicazione delegata a RecordLabel
        day = cfd->getReleaseDE()->date().day();
        month = cfd->getReleaseDE()->date().month();
        year = cfd->getReleaseDE()->date().year();

         if(!cfd->checkPMInput() && !cfd->checkDMInput())
             addNewMusic(new Album(genre, name, artist));

        if(cfd->checkPMInput()){
            if (cfd->getcdCKB()->isChecked()) {
                pm->first = CD;
                pm->second = cfd->getCdEdit()->text().toUInt();
                addNewMusic(new PM(genre, name, artist, Date(day, month, year), pm->first, pm->second));
            }
            if (cfd->getvnlCKB()->isChecked()) {
                pm->first = Vinile ;
                pm->second = cfd->getVnlEdit()->text().toUInt();
                addNewMusic(new PM(genre, name, artist, Date(day, month, year), pm->first, pm->second));
            }
            if (cfd->getcstCKB()->isChecked()) {
                pm->first = Cassetta;
                pm->second = cfd->getCstEdit()->text().toUInt();
                addNewMusic(new PM(genre, name, artist, Date(day, month, year), pm->first, pm->second));
            }
        }

        if (cfd->checkDMInput()){
            if(cfd->getsptfCKB()->isChecked()){
                dm->first = Spotify;
                dm->second = cfd->getSptfEdit()->text().toUInt();
                addNewMusic(new DM(genre, name, artist, Date(day, month, year), dm->first, dm->second));
            }
            if(cfd->getapplmCKB()->isChecked()){
                dm->first = AppleMusic;
                dm->second = cfd->getApplmEdit()->text().toUInt();
                addNewMusic(new DM(genre, name, artist, Date(day, month, year), dm->first, dm->second));
            }
            if(cfd->gettdlCKB()->isChecked()){
                dm->first = Tidal;
                dm->second = cfd->getTdlEdit()->text().toUInt();
                addNewMusic(new DM(genre, name, artist, Date(day, month, year), dm->first, dm->second));
            }
            if(cfd->getdzrCKB()->isChecked()){
                dm->first = Deezer;
                dm->second = cfd->getDzrEdit()->text().toUInt();
                addNewMusic(new DM(genre, name, artist, Date(day, month, year), dm->first, dm->second));
            }if(cfd->getytmCKB()->isChecked()){
                dm->first = YoutubeMusic;
                dm->second = cfd->getYtmEdit()->text().toUInt();
                addNewMusic(new DM(genre, name, artist, Date(day, month, year), dm->first, dm->second));
            }
            if(cfd->getamzCKB()->isChecked()){
                dm->first = AmazonMusic;
                dm->second = cfd->getAmzEdit()->text().toUInt();
                addNewMusic(new DM(genre, name, artist, Date(day, month, year), dm->first, dm->second));
            }
        }
    }else {
        QMessageBox::warning(this, tr("Campi vuoti"), tr("I campi 'Nome', 'Artista', 'Genre' sono obbligatori"), QMessageBox::Ok);
    }
    delete pm;
    delete dm;
}

void Viewer::addNewMusic(const Music* newMusic) {
    toSave.push_back(newMusic);

    myTableModel->addEntry(newMusic);
    qDebug() << QString::fromStdString(newMusic->getName()) << " inserted" << endl;
    closeFormDialog();
}

