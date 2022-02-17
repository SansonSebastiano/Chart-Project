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

QHBoxLayout *Viewer::createHEditLine(QLabel *l, QWidget *w) {
    QHBoxLayout *layout = new QHBoxLayout();

    layout->addWidget(l);
    layout->addWidget(w);

    return layout;
}

QVBoxLayout *Viewer::createVEditLine(QLabel *l, QList<QWidget*> *lw) {
    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(l);

    for (auto it = lw->begin(); it != lw->end(); ++it)
        layout->addWidget(*it);

    return layout;
}

QVBoxLayout *Viewer::createLineLayout(QList<QBoxLayout*> *vbl, int leftMargin, int topMargin, int rightMargin, int bottomMargin){
    QVBoxLayout *layout = new QVBoxLayout();

    layout->setContentsMargins(leftMargin, topMargin, rightMargin, bottomMargin);

    for (auto it = vbl->begin(); it != vbl->end(); ++it)
        layout->addLayout(*it);

    return layout;
}

void Viewer::createCustomDialog() {
    formDialog = new QDialog();

    // add QGroupBox
    QList<QWidget*> *lineEdit = new QList<QWidget*>();
    QList<QBoxLayout*> *layoutList = new QList<QBoxLayout*>();    

    // Music info
    QGroupBox *musicGB = new QGroupBox("Info Musica");
    // name line
    QLabel *nameLabel = new QLabel("Nome: ");
    // da dichiarare come campi dati in realta
    QLineEdit *nameEdit = new QLineEdit();      // solo string
    QHBoxLayout *nameLine = createHEditLine(nameLabel, nameEdit);

    // artist line
    QLabel *artistLabel = new QLabel("Artista: ");
    // da dichiarare come campi dati in realta
    QLineEdit *artistEdit = new QLineEdit();    // solo string
    QHBoxLayout *artistLine = createHEditLine(artistLabel, artistEdit);

    // genre line
    QLabel *genreLabel = new QLabel("Genere: ");
    // da dichiarare come campi dati in realta
    QLineEdit *genreEdit = new QLineEdit();     // solo string
    QHBoxLayout *genreLine = createHEditLine(genreLabel, genreEdit);

    // adding music info layout
    layoutList->push_back(nameLine);
    layoutList->push_back(artistLine);
    layoutList->push_back(genreLine);
    QVBoxLayout *musicInfoLayout = createLineLayout(layoutList, 10, 10 ,10, 20);
    //musicGB->setLayout(musicInfoLayout);

    // ADD to release or not possibility

    // Release info
    // release line
    QLabel *releaseLabel = new QLabel("Data Pubblicazione: ");
    // da dichiarare come campi dati in realta
    QDateEdit *releaseDE = new QDateEdit();

    releaseDE->setMaximumDate(QDate::currentDate());

    QHBoxLayout *releaseLine = createHEditLine(releaseLabel, releaseDE);
    // adding release info layout
    layoutList->clear();
    layoutList->push_back(releaseLine);
    QVBoxLayout *releaseInfoLayout = createLineLayout(layoutList, 10, 10 ,10, 20);

    // PhisycalMedium info
    // support line
    QLabel *supportLabel = new QLabel("Supporti: ");
    // da dichiarare come campi dati in realta
    lineEdit->push_back(new QCheckBox("CD"));
    lineEdit->push_back(new QCheckBox("Vinile"));
    lineEdit->push_back(new QCheckBox("Cassetta"));

    QVBoxLayout *supportLine = createVEditLine(supportLabel, lineEdit);

    // sales line
    QLabel *salesLabel = new QLabel("Vendite: ");
    // da dichiarare come campi dati in realta
    QLineEdit *salesEdit = new QLineEdit();     // solo uint
    QHBoxLayout *salesLine = createHEditLine(salesLabel, salesEdit);
    // adding pm info layout
    layoutList->clear();
    layoutList->push_back(supportLine);
    layoutList->push_back(salesLine);
    QVBoxLayout *pmLayout = createLineLayout(layoutList, 10, 10, 10, 20);

    // DigitalMedium info
    // platform line
    lineEdit->clear();
    QLabel *platformLabel = new QLabel("Piattaforme: ");
    // da dichiarare come campi dati in realta
    lineEdit->push_back(new QCheckBox("Spotify"));
    lineEdit->push_back(new QCheckBox("Apple Music"));
    lineEdit->push_back(new QCheckBox("Tidal"));
    lineEdit->push_back(new QCheckBox("Deezer"));
    lineEdit->push_back(new QCheckBox("YouTube Music"));
    lineEdit->push_back(new QCheckBox("Amazon Music"));

    QVBoxLayout *platformLine = createVEditLine(platformLabel, lineEdit);

    // listeners line
    QLabel *listenersLabel = new QLabel("Ascolti: ");
    // da dichiarare come campi dati in realta
    QLineEdit *listenersEdit = new QLineEdit();     // solo uint
    QHBoxLayout *listenersLine = createHEditLine(listenersLabel, listenersEdit);
    // adding dm info lauout
    layoutList->clear();
    layoutList->push_back(platformLine);
    layoutList->push_back(listenersLine);
    QVBoxLayout *dmLayout = createLineLayout(layoutList, 10, 10, 10, 20);

    // adding buttons layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(btn_add);
    buttonLayout->addWidget(btn_cancel);
    buttonLayout->setContentsMargins(500, 10, 20, 20);

    // compose layout
    layoutList->clear();
    layoutList->push_back(musicInfoLayout);
    layoutList->push_back(releaseInfoLayout);
    layoutList->push_back(pmLayout);
    layoutList->push_back(dmLayout);
    layoutList->push_back(buttonLayout);
    QVBoxLayout *formLayout = createLineLayout(layoutList, 0, 0, 0 ,0);

    formDialog->resize(QSize(720, 360));
    formDialog->setLayout(formLayout);
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
        createCustomDialog();

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

void Viewer::addNewMusic() {
    // get all attribute to create new music -> to invoke constructor

    // ATTENZIONE : aggiornare anche su file e su RecordLabel per evitare inconsistenza
    DigitalMedium *example = new DigitalMedium("Genre", "Name", "Artist", Date(2, 5, 1983), AppleMusic, 1000);

    myModel->addEntry(example);
}
