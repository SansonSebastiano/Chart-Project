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

QHBoxLayout *Viewer::createHEditLine(QList<QWidget*> *lw) {
    QHBoxLayout *layout = new QHBoxLayout();

    for (auto it = lw->begin(); it != lw->end(); ++it)
        layout->addWidget(*it);

    return layout;
}

QVBoxLayout *Viewer::createVEditLine(QList<QWidget*> *lw) {
    QVBoxLayout *layout = new QVBoxLayout();

    for (auto it = lw->begin(); it != lw->end(); ++it)
        layout->addWidget(*it);

    return layout;
}

QVBoxLayout *Viewer::createLineLayout(QList<QLayout*> *vbl, int leftMargin, int topMargin, int rightMargin, int bottomMargin){
    QVBoxLayout *layout = new QVBoxLayout();

    layout->setContentsMargins(leftMargin, topMargin, rightMargin, bottomMargin);

    for (auto it = vbl->begin(); it != vbl->end(); ++it)
        layout->addLayout(*it);

    return layout;
}

QVBoxLayout * Viewer::addMusicLine(QList<QLayout*> *layoutList, QList<QWidget*> *lineEdit) {
    //QGroupBox *musicGB = new QGroupBox("Info Musica");
    // name line
    QFormLayout *nameLine = new QFormLayout();
    nameLine->addRow(tr("Nome:"), nameEdit);

    // artist line
    QFormLayout *artistLine = new QFormLayout();
    artistLine->addRow(tr("Artista:"), artistEdit);

    // genre line
    QFormLayout *genreLine = new QFormLayout();
    genreLine->addRow(tr("Genere:"), genreEdit);

    // adding music info layout
    layoutList->clear();
    layoutList->push_back(nameLine);
    layoutList->push_back(artistLine);
    layoutList->push_back(genreLine);
    return createLineLayout(layoutList, 10, 10 ,10, 20);
    //musicGB->setLayout(musicInfoLayout);
}

QVBoxLayout * Viewer::addRelaseLine(QList<QLayout*> *layoutList, QList<QWidget*> *lineEdit){
    // release line
    QFormLayout *releaseLine = new QFormLayout();
    releaseLine->addRow(tr("Data Pubblicazione:"), releaseDE);

    // adding release info layout
    layoutList->clear();
    layoutList->push_back(releaseLine);
    return createLineLayout(layoutList, 10, 10 ,10, 20);
}

QVBoxLayout * Viewer::addPMLine(QList<QLayout*> *layoutList, QList<QWidget*> *lineEdit) {
    // support line
    QFormLayout *pmLine = new QFormLayout();

    QLabel *supportLabel = new QLabel("Supporti: ");

    lineEdit->clear();
    lineEdit->push_back(cdCKB);
    lineEdit->push_back(cdSalesEdit);
    QHBoxLayout *cdLine = createHEditLine(lineEdit);
    cdLine->setSpacing(60);

    lineEdit->clear();
    lineEdit->push_back(vnlCKB);
    lineEdit->push_back(vnlSalesEdit);
    QHBoxLayout *vnlLine = createHEditLine(lineEdit);
    vnlLine->setSpacing(45);

    lineEdit->clear();
    lineEdit->push_back(cstCKB);
    lineEdit->push_back(cstSalesEdit);
    QHBoxLayout *cstLine = createHEditLine(lineEdit);
    cstLine->setSpacing(25);

    pmLine->addWidget(supportLabel);
    pmLine->addItem(cdLine);
    pmLine->addItem(vnlLine);
    pmLine->addItem(cstLine);

    // adding pm info layout
    layoutList->clear();
    layoutList->push_back(pmLine);
    return createLineLayout(layoutList, 10, 10, 10, 20);
}

QVBoxLayout * Viewer::addDMLine(QList<QLayout*> *layoutList, QList<QWidget*> *lineEdit) {
    // platform line
    QFormLayout *dmLine = new QFormLayout();

    QLabel *platformLabel = new QLabel("Piattaforme: ");

    lineEdit->clear();
    lineEdit->push_back(spotifyCKB);
    lineEdit->push_back(spoListenersEdit);
    QHBoxLayout *spotifyLine = createHEditLine(lineEdit);
    spotifyLine->setSpacing(72);

    lineEdit->clear();
    lineEdit->push_back(appMusicCKB);
    lineEdit->push_back(appMListenersEdit);
    QHBoxLayout *applLine = createHEditLine(lineEdit);
    applLine->setSpacing(41);

    lineEdit->clear();
    lineEdit->push_back(tidalCKB);
    lineEdit->push_back(tidListenersEdit);
    QHBoxLayout *tdlLine = createHEditLine(lineEdit);
    tdlLine->setSpacing(87);

    lineEdit->clear();
    lineEdit->push_back(deezerCKB);
    lineEdit->push_back(deeListenersEdit);
    QHBoxLayout *dzrLine = createHEditLine(lineEdit);
    dzrLine->setSpacing(74);

    lineEdit->clear();
    lineEdit->push_back(youMusicCKB);
    lineEdit->push_back(youListenersEdit);
    QHBoxLayout *ytmLine = createHEditLine(lineEdit);
    ytmLine->setSpacing(25);

    lineEdit->clear();
    lineEdit->push_back(amMusicCKB);
    lineEdit->push_back(AmListenersEdit);
    QHBoxLayout *amzLine = createHEditLine(lineEdit);
    amzLine->setSpacing(30);

    dmLine->addWidget(platformLabel);
    dmLine->addItem(spotifyLine);
    dmLine->addItem(applLine);
    dmLine->addItem(tdlLine);
    dmLine->addItem(dzrLine);
    dmLine->addItem(ytmLine);
    dmLine->addItem(amzLine);

    // adding dm info lauout
    layoutList->clear();
    layoutList->push_back(dmLine);
    return createLineLayout(layoutList, 10, 10, 10, 20);
}

void Viewer::createCustomDialog() {
    formDialog = new QDialog();

    // add QGroupBox
    QList<QWidget*> *lineEdit = new QList<QWidget*>();
    QList<QLayout*> *layoutList = new QList<QLayout*>();

    // create layout
    // Music info
    auto musicLayout = addMusicLine(layoutList, lineEdit);

    // ADD to release or not possibility

    // Release info
    auto releaseLayout = addRelaseLine(layoutList, lineEdit);
    // PhisycalMedium info
    auto pmLayout = addPMLine(layoutList, lineEdit);
    // add DigitalMedium info
    auto dmLayout = addDMLine(layoutList, lineEdit);

    // buttons layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(btn_add);
    buttonLayout->addWidget(btn_cancel);
    buttonLayout->setContentsMargins(500, 10, 20, 20);

    // compose layout
    layoutList->clear();
    layoutList->push_back(musicLayout);
    layoutList->push_back(releaseLayout);
    layoutList->push_back(pmLayout);
    layoutList->push_back(dmLayout);
    layoutList->push_back(buttonLayout);


    formDialog->setLayout(createLineLayout(layoutList));
    formDialog->setModal(true);
}

void Viewer::addMenus(QVBoxLayout *mainLayout) {
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
    table = new QTableView;

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

void Viewer::initDialogComponets(){
    nameEdit = new QLineEdit();             // solo string
    artistEdit = new QLineEdit();           // solo string
    genreEdit = new QLineEdit();            // solo string
    cdSalesEdit = new QLineEdit("Vendite");          // solo uint
    vnlSalesEdit = new QLineEdit("Vendite");         // solo uint
    cstSalesEdit = new QLineEdit("Vendite");         // solo uint
    spoListenersEdit = new QLineEdit("Ascolti");     // solo uint
    appMListenersEdit = new QLineEdit("Ascolti");    // solo uint
    tidListenersEdit = new QLineEdit("Ascolti");     // solo uint
    deeListenersEdit = new QLineEdit("Ascolti");     // solo uint
    youListenersEdit = new QLineEdit("Ascolti");     // solo uint
    AmListenersEdit = new QLineEdit("Ascolti");      // solo uint
    // Dialog-Form's date picker
    releaseDE = new QDateEdit();
    // Dialog-Form's checkbox
    cdCKB = new QCheckBox("CD");
    vnlCKB = new QCheckBox("Vinile");
    cstCKB = new QCheckBox("Cassetta");
    spotifyCKB = new QCheckBox("Spotify");
    appMusicCKB = new QCheckBox("Apple Music");
    tidalCKB = new QCheckBox("Tidal");
    deezerCKB = new QCheckBox("Deezer");
    youMusicCKB = new QCheckBox("YouTube Music");
    amMusicCKB = new QCheckBox("Amazon Music");
    // Dialog-Form's button
    btn_add = createButton("Aggiungi");
    btn_cancel = createButton("Cancella");
}

Viewer::Viewer(QWidget *parent) : QWidget(parent), controller(new Controller) {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // init components
    // Dialog-Form's edit line
    initDialogComponets();

    // AddDialog-Form's layout
    createCustomDialog();

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
    connect(btn_addItem, SIGNAL(clicked()), controller, SLOT(showDialog()));
    connect(btn_cancel, SIGNAL(clicked()), controller, SLOT(closeDialog()));
    connect(btn_add, SIGNAL(clicked()), controller, SLOT(addMusic()));
}

void Viewer::showFormDialog() { formDialog->show(); }

void Viewer::closeFormDialog() { formDialog->close(); }

void Viewer::getDataInput() {
    string name = nameEdit->text().toStdString();
    string genre = genreEdit->text().toStdString();
    string artist = artistEdit->text().toStdString();

    // prelevare sse selezionato 'to public'
    uint day = releaseDE->date().day();
    uint month = releaseDE->date().month();
    uint year = releaseDE->date().year();

    // prelevare sse selezionato almeno un supporto
    QList<Support> *ls = new QList<Support>();

}

void Viewer::addNewMusic() {
    // get all attribute to create new music -> to invoke constructor

    // ATTENZIONE : aggiornare anche su file e su RecordLabel per evitare inconsistenza
    DigitalMedium *example = new DigitalMedium("Genre", "Name", "Artist", Date(2, 5, 1983), AppleMusic, 1000);

    myModel->addEntry(example);
}
