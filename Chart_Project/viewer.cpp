#include "viewer.h"
#include "controller.h"

// ATTENZIONE AI MEMORY LEAK
// MEGLIO CREARE DIFFERENTI WIDGET CUSTOM CLASS ?

QPushButton *Viewer::createButton(const QString& title){
    QPushButton *button = new QPushButton(title);

    // Aggiungere caratteristiche...

    return button;
}

// WARNING : impostare i parent tra i widget

void Viewer::addMenus(QVBoxLayout *mainLayout)
{
    QMenuBar *menuBar = new QMenuBar(this);

    file = new QMenu ("File", menuBar);
    edit = new QMenu ("Edit", menuBar);
    chart = new QMenu ("Grafici", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(edit);
    menuBar->addMenu(chart);

    //file->addAction(new QAction("Carica dati", file));
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
    //btn_uploadData = createButton("Carica dati");
    btn_saveData = createButton("Salva dati");

    //dataBtnLayout->addWidget(btn_uploadData);
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
    btn_filter = createButton("Filtra");

    buttonLayout_2->addWidget(btn_addItem);
    buttonLayout_2->addWidget(btn_filter);

    buttonLayout_2->setSpacing(5);
    buttonLayout_2->setContentsMargins(0, 25, 10, 300);

    screenLayout->addLayout(buttonLayout_2);
}

void Viewer::addScreen(QVBoxLayout *mainLayout) {
    QHBoxLayout *screenLayout = new QHBoxLayout;

    // button
    addControll_2(screenLayout);

    // table + chart layout
    QHBoxLayout *tc_layout = new QHBoxLayout;

    // layout table
    QTableView *table = new QTableView;

    // USARE UNO SIGNAL - SLOT ?
    catalog = controller->initData();
    qDebug() << "catalog is empty : " << catalog.isEmpty() << endl;
    myModel = new TableModel(catalog);

    table->setModel(myModel);
    //table->setWindowTitle();

    tc_layout->addWidget(table);

    // layout chart
    /*
    QFrame *frame = new QFrame; // ci andra chartlayout

    frame->setStyleSheet(".QFrame{background-color: rgb(211, 211, 211); border-radius: 10px}");
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    tc_layout->addWidget(frame);
    */

    screenLayout->addLayout(tc_layout);

    mainLayout->addLayout(screenLayout);
}

// DA SISTEMARE
void Viewer::customForm() {
    formDialog = new QDialog;

    // dialog layout
    QVBoxLayout *formLayout = new QVBoxLayout();

    // dialog's button
    //btn_add = createButton("Aggiungi");
    //btn_cancel = createButton("Cancella");

    // music info layout
    // USE QGroupBox    <---------------------------------------------------------
    QVBoxLayout *musicInfoLayout = new QVBoxLayout();
    QVBoxLayout *releaseInfoLayout = new QVBoxLayout();
    QVBoxLayout *pmLayout = new QVBoxLayout();
    QVBoxLayout *dmLayout = new QVBoxLayout();
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // music edit line layout
    QHBoxLayout *nameLine = new QHBoxLayout();
    QHBoxLayout *artistLine = new QHBoxLayout();
    QHBoxLayout *genreLine = new QHBoxLayout();
    // release edit line layout
    QHBoxLayout *releaseLine = new QHBoxLayout();
    // pm edit line layout
    QHBoxLayout *supportLine = new QHBoxLayout();
    QVBoxLayout *supportCKB = new QVBoxLayout();
    QHBoxLayout *salesLine = new QHBoxLayout();
    //dm edit line layout
    QHBoxLayout *platformLine = new QHBoxLayout();
    QVBoxLayout *platformCKB = new QVBoxLayout();
    QHBoxLayout *listenersLine = new QHBoxLayout();

    // widget component
    //  - Music
    QLabel *nameLabel = new QLabel("Nome: ");
    QLabel *artistLabel = new QLabel("Artista: ");
    QLabel *genreLable = new QLabel("Genere: ");

    QLineEdit *nameEdit = new QLineEdit;
    QLineEdit *artistEdit = new QLineEdit;
    QLineEdit *genreEdit = new QLineEdit;

    //  - Release
    QLabel *releaseLabel = new QLabel("Data Pubblicazione");
    QDateEdit *releaseDE = new QDateEdit();

    releaseDE->setMaximumDate(QDate::currentDate());
    //  - PhisycalMedium
    QLabel *pmLabel = new QLabel("Supporti: ");
    QList<QCheckBox*> *pmCKB = new QList<QCheckBox*>();

    pmCKB->push_back(new QCheckBox("CD"));
    pmCKB->push_back(new QCheckBox("Vinile"));
    pmCKB->push_back(new QCheckBox("Cassetta"));

    QLabel *salesLabel = new QLabel("Vendite: ");
    QLineEdit *salesEdit = new QLineEdit;
    //  -DigitalMedium
    QLabel *dmLabel = new QLabel("Piattaforme: ");
    QList<QCheckBox*> *dmCKB = new QList<QCheckBox*>();

    dmCKB->push_back(new QCheckBox("Spotify"));
    dmCKB->push_back(new QCheckBox("Apple Music"));
    dmCKB->push_back(new QCheckBox("Tidal"));
    dmCKB->push_back(new QCheckBox("Deezer"));
    dmCKB->push_back(new QCheckBox("YouTube Music"));
    dmCKB->push_back(new QCheckBox("Amazon Music"));

    QLabel *listenersLabel = new QLabel("Ascolti: ");
    QLineEdit *listenersEdit = new QLineEdit;

    // adding widget component to corresponding layout
    nameLine->addWidget(nameLabel);
    nameLine->addWidget(nameEdit);

    artistLine->addWidget(artistLabel);
    artistLine->addWidget(artistEdit);

    genreLine->addWidget(genreLable);
    genreLine->addWidget(genreEdit);

    releaseLine->addWidget(releaseLabel);
    releaseLine->addWidget(releaseDE);

    supportLine->addWidget(pmLabel);

    supportCKB->addWidget(pmCKB->at(0));
    supportCKB->addWidget(pmCKB->at(1));
    supportCKB->addWidget(pmCKB->at(2));

    supportLine->addLayout(supportCKB);

    salesLine->addWidget(salesLabel);
    salesLine->addWidget(salesEdit);

    platformLine->addWidget(dmLabel);

    platformCKB->addWidget(dmCKB->at(0));
    platformCKB->addWidget(dmCKB->at(1));
    platformCKB->addWidget(dmCKB->at(2));
    platformCKB->addWidget(dmCKB->at(3));
    platformCKB->addWidget(dmCKB->at(4));
    platformCKB->addWidget(dmCKB->at(5));

    platformLine->addLayout(platformCKB);

    listenersLine->addWidget(listenersLabel);
    listenersLine->addWidget(listenersEdit);

    // adding edit line layout
    musicInfoLayout->setContentsMargins(10, 10 ,10, 20);
    musicInfoLayout->addLayout(nameLine);
    musicInfoLayout->addLayout(artistLine);
    musicInfoLayout->addLayout(genreLine);

    releaseInfoLayout->setContentsMargins(10, 10, 10, 20);
    releaseInfoLayout->addLayout(releaseLine);

    pmLayout->setContentsMargins(10, 10, 10, 20);
    pmLayout->addLayout(supportLine);
    pmLayout->addLayout(salesLine);

    dmLayout->setContentsMargins(10, 10, 10, 20);
    dmLayout->addLayout(platformLine);
    dmLayout->addLayout(listenersLine);

    buttonLayout->setContentsMargins(500, 10, 10, 10);
    buttonLayout->addWidget(btn_add);
    buttonLayout->addWidget(btn_cancel);

    // adding music info layout
    formLayout->addLayout(musicInfoLayout);
    formLayout->addLayout(releaseInfoLayout);
    formLayout->addLayout(pmLayout);
    formLayout->addLayout(dmLayout);
    formLayout->addLayout(buttonLayout);

    // setting dialog
    formDialog->resize(QSize(720, 360));
    formDialog->setLayout(formLayout);
    formDialog->setModal(true);
    formDialog->show();
}

void Viewer::closeFormDialog() {
    formDialog->close();
}

Viewer::Viewer(QWidget *parent) : QWidget(parent), controller(new Controller) {


    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Aggiungere la barra dei menu
    addMenus(mainLayout);

    // Aggiungere i pulsanti
    addControll_1(mainLayout);

    // Aggiungere schermo

        // dialog's button
        btn_add = createButton("Aggiungi");
        btn_cancel = createButton("Cancella");

    addScreen(mainLayout);

    // Aggiungere ...

    //mainLayout->setSpacing(0);
    setLayout(mainLayout);
    resize(QSize(1920, 1080));
}

void Viewer::setController(Controller *c) {
    controller = c;

    // IMPLEMENTAZIONE SEGNALI E SLOT
    connect(btn_addItem, SIGNAL(clicked()), controller, SLOT(showDialog()));
    connect(btn_cancel, SIGNAL(clicked()), controller, SLOT(closeDialog()));
    connect(btn_add, SIGNAL(clicked()), controller, SLOT(addMusic()));
}

void Viewer::addNewMusic() {
    // get all attribute to create new music -> to invoke constructor
    DigitalMedium *example = new DigitalMedium("Genre", "Name", "Artist", Date(2, 5, 1983), AppleMusic, 1000);

    myModel->addEntry(example);
}
