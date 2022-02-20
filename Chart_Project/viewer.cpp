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

    // init Dialog-Form
    cfd = new CustomFormDialog();

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


}

void Viewer::showFormDialog() { cfd->show(); }
void Viewer::closeFormDialog() { cfd->close(); }
void Viewer::enableFormDialogComponents() { cfd->enableComponents(); }

void Viewer::addNewMusic() {
    // get all attribute to create new music -> to invoke constructor

    // ATTENZIONE : aggiornare anche su file e su RecordLabel per evitare inconsistenza
    DigitalMedium *example = new DigitalMedium("Genre", "Name", "Artist", Date(2, 5, 1983), AppleMusic, 1000);

    myModel->addEntry(example);
}

