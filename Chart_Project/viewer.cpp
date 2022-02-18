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

QFormLayout *Viewer::createFormLayout(const QString &label, QWidget *w) {
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setFormAlignment(Qt::AlignLeft);
    formLayout->addRow(label, w);

    return formLayout;
}

QHBoxLayout *Viewer::createHEditLine(QList<QWidget*> *lw, QWidget *parent) {
    QHBoxLayout *layout = new QHBoxLayout(parent);

    for (auto it = lw->begin(); it != lw->end(); ++it)
        layout->addWidget(*it);

    return layout;
}

QVBoxLayout *Viewer::createLineLayout(QList<QLayout*> *vbl, int leftMargin, int topMargin, int rightMargin, int bottomMargin, QWidget *parent){
    QVBoxLayout *layout = new QVBoxLayout(parent);

    layout->setContentsMargins(leftMargin, topMargin, rightMargin, bottomMargin);

    for (auto it = vbl->begin(); it != vbl->end(); ++it)
        layout->addLayout(*it);

    return layout;
}

QVBoxLayout * Viewer::addMusicLine(QList<QLayout*> *layoutList) {
    // name line
    QFormLayout *nameLine = createFormLayout("Nome:", nameEdit);
    // artist line
    QFormLayout *artistLine = createFormLayout("Artista: ", artistEdit);
    // genre line
    QFormLayout *genreLine = createFormLayout("Genere:", genreEdit);

    // adding music info layout
    layoutList->clear();
    layoutList->push_back(nameLine);
    layoutList->push_back(artistLine);
    layoutList->push_back(genreLine);
    return createLineLayout(layoutList, 10, 10 ,10, 20);
}

QVBoxLayout * Viewer::addRelaseLine(QList<QLayout*> *layoutList, QWidget *parent){
    // release line
    QFormLayout *releaseLine = createFormLayout("Data Pubblicazione:", releaseDE);

    // adding release info layout
    layoutList->clear();
    layoutList->push_back(releaseLine);
    return createLineLayout(layoutList, 10, 10 ,10, 20, parent);
}

QVBoxLayout * Viewer::addPMLine(QList<QLayout*> *layoutList, QList<QWidget*> *lineEdit, QWidget *parent) {
    // support line
    QFormLayout *pmLine = new QFormLayout(parent);
    pmLine->setFormAlignment(Qt::AlignLeft);

    QLabel *supportLabel = new QLabel("Supporti: ");

    lineEdit->clear();
    lineEdit->push_back(cdCKB);
    lineEdit->push_back(cdSalesEdit);
    QHBoxLayout *cdLine = createHEditLine(lineEdit, parent);
    cdLine->setSpacing(60);

    lineEdit->clear();
    lineEdit->push_back(vnlCKB);
    lineEdit->push_back(vnlSalesEdit);
    QHBoxLayout *vnlLine = createHEditLine(lineEdit, parent);
    vnlLine->setSpacing(45);

    lineEdit->clear();
    lineEdit->push_back(cstCKB);
    lineEdit->push_back(cstSalesEdit);
    QHBoxLayout *cstLine = createHEditLine(lineEdit, parent);
    cstLine->setSpacing(25);

    pmLine->addWidget(supportLabel);
    pmLine->addItem(cdLine);
    pmLine->addItem(vnlLine);
    pmLine->addItem(cstLine);

    // adding pm info layout
    layoutList->clear();
    layoutList->push_back(pmLine);
    return createLineLayout(layoutList, 10, 10, 10, 20, parent);
}

QVBoxLayout * Viewer::addDMLine(QList<QLayout*> *layoutList, QList<QWidget*> *lineEdit, QWidget *parent) {
    // platform line
    QFormLayout *dmLine = new QFormLayout(parent);
    dmLine->setFormAlignment(Qt::AlignLeft);

    QLabel *platformLabel = new QLabel("Piattaforme: ");

    lineEdit->clear();
    lineEdit->push_back(spotifyCKB);
    lineEdit->push_back(spoListenersEdit);
    QHBoxLayout *spotifyLine = createHEditLine(lineEdit, parent);
    spotifyLine->setSpacing(72);

    lineEdit->clear();
    lineEdit->push_back(appMusicCKB);
    lineEdit->push_back(appMListenersEdit);
    QHBoxLayout *applLine = createHEditLine(lineEdit, parent);
    applLine->setSpacing(41);

    lineEdit->clear();
    lineEdit->push_back(tidalCKB);
    lineEdit->push_back(tidListenersEdit);
    QHBoxLayout *tdlLine = createHEditLine(lineEdit, parent);
    tdlLine->setSpacing(87);

    lineEdit->clear();
    lineEdit->push_back(deezerCKB);
    lineEdit->push_back(deeListenersEdit);
    QHBoxLayout *dzrLine = createHEditLine(lineEdit, parent);
    dzrLine->setSpacing(74);

    lineEdit->clear();
    lineEdit->push_back(youMusicCKB);
    lineEdit->push_back(youListenersEdit);
    QHBoxLayout *ytmLine = createHEditLine(lineEdit, parent);
    ytmLine->setSpacing(25);

    lineEdit->clear();
    lineEdit->push_back(amMusicCKB);
    lineEdit->push_back(AmListenersEdit);
    QHBoxLayout *amzLine = createHEditLine(lineEdit, parent);
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
    return createLineLayout(layoutList, 10, 10, 10, 20, parent);
}

void Viewer::createCustomDialog() {
    formDialog = new QDialog();

    QList<QWidget*> *lineEdit = new QList<QWidget*>();
    QList<QLayout*> *layoutList = new QList<QLayout*>();

    // create layout
    // Music info
    QVBoxLayout *prova = new QVBoxLayout();
    QGroupBox * test = new QGroupBox(tr("TEST"));
    auto musicLayout = addMusicLine(layoutList);
    test->setLayout(musicLayout);
    prova->addWidget(test);

    QHBoxLayout *toPublicLayout = new QHBoxLayout();
    toPublicLayout->addWidget(publicRB);

    // Release info
    auto releaseLayout = addRelaseLine(layoutList);
    // PhisycalMedium info
    auto pmLayout = addPMLine(layoutList, lineEdit);
    // add DigitalMedium info
    auto dmLayout = addDMLine(layoutList, lineEdit);

    // buttons layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(btn_add);
    buttonLayout->addWidget(btn_cancel);
    buttonLayout->setAlignment(Qt::AlignRight);

    // compose layout
    layoutList->clear();
    layoutList->push_back(prova);
    layoutList->push_back(toPublicLayout);

    releaseFormLayout->addLayout(releaseLayout);
    releaseFormLayout->addLayout(pmLayout);
    releaseFormLayout->addLayout(dmLayout);

    layoutList->push_back(releaseFormLayout);
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
    releaseFormLayout = new QVBoxLayout();
    container_1 = new QWidget();
    container_1->setEnabled(false);

    container_2 = new QWidget();
    container_2->setEnabled(false);

    container_3 = new QWidget();
    container_3->setEnabled(false);

    releaseFormLayout->addWidget(container_1);
    releaseFormLayout->addWidget(container_2);
    releaseFormLayout->addWidget(container_3);

    nameEdit = new QLineEdit();             // solo string
    artistEdit = new QLineEdit();           // solo string
    genreEdit = new QLineEdit();            // solo string

    publicRB = new QRadioButton("Da pubblicare");

    cdSalesEdit = new QLineEdit("Vendite");          // solo uint
    cdSalesEdit->setDisabled(true);

    vnlSalesEdit = new QLineEdit("Vendite");         // solo uint
    vnlSalesEdit->setDisabled(true);

    cstSalesEdit = new QLineEdit("Vendite");         // solo uint
    cstSalesEdit->setDisabled(true);

    spoListenersEdit = new QLineEdit("Ascolti");     // solo uint
    spoListenersEdit->setDisabled(true);

    appMListenersEdit = new QLineEdit("Ascolti");    // solo uint
    appMListenersEdit->setDisabled(true);

    tidListenersEdit = new QLineEdit("Ascolti");     // solo uint
    tidListenersEdit->setDisabled(true);

    deeListenersEdit = new QLineEdit("Ascolti");     // solo uint
    deeListenersEdit->setDisabled(true);

    youListenersEdit = new QLineEdit("Ascolti");     // solo uint
    youListenersEdit->setDisabled(true);

    AmListenersEdit = new QLineEdit("Ascolti");      // solo uint
    AmListenersEdit->setDisabled(true);
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
    // checkbox signal & slot
    connect(cdCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(vnlCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(cstCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));

    connect(spotifyCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(appMusicCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(tidalCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(deezerCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(youMusicCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(amMusicCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
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

void Viewer::showEditLine() {
    if (cdCKB->isChecked())
        cdSalesEdit->setDisabled(false);
    else
        cdSalesEdit->setDisabled(true);

    if (vnlCKB->isChecked())
        vnlSalesEdit->setDisabled(false);
    else
        vnlSalesEdit->setDisabled(true);

    if(cstCKB->isChecked())
        cstSalesEdit->setDisabled(false);
    else
        cstSalesEdit->setDisabled(true);

    if(spotifyCKB->isChecked())
        spoListenersEdit->setDisabled(false);
    else
        spoListenersEdit->setDisabled(true);

    if(appMusicCKB->isChecked())
        appMListenersEdit->setDisabled(false);
    else
        appMListenersEdit->setDisabled(true);

    if(tidalCKB->isChecked())
        tidListenersEdit->setDisabled(false);
    else
        tidListenersEdit->setDisabled(true);

    if(deezerCKB->isChecked())
        deeListenersEdit->setDisabled(false);
    else
        deeListenersEdit->setDisabled(true);

    if(youMusicCKB->isChecked())
        youListenersEdit->setDisabled(false);
    else
        youListenersEdit->setDisabled(true);

    if(amMusicCKB->isChecked())
        AmListenersEdit->setDisabled(false);
    else
        AmListenersEdit->setDisabled(true);
}

