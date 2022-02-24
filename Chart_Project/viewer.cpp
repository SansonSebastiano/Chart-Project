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
    file->addAction(new QAction("Salva dati", file));   // DA IMPLEMENTARE
    file->addAction(new QAction("Chiudi", file));       // DA IMPLEMENTARE

    edit->addAction(new QAction("Aggiungi nuova musica", edit));    // DA IMPLEMENTARE
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
    resize(QSize(1920, 720));
}

void Viewer::setController(Controller *c) {
    controller = c;

    // IMPLEMENTAZIONE SEGNALI E SLOT
    connect(btn_saveData, SIGNAL(clicked()), controller, SLOT(saveToFile()));

    connect(btn_uploadData, SIGNAL(clicked()), controller, SLOT(showTable()));
        // to show/close Music custom form dialog
    connect(btn_addItem, &QPushButton::clicked, controller, &Controller::showMusicDialog);
    //connect(btn_addItem, SIGNAL(clicked()), controller, SLOT(showMusicDialog()));
    //connect(md->getCancBtn(), SIGNAL(clicked()), controller, SLOT(closeDialog(FormDialog*)));
    connect(md->getAddBtn(), SIGNAL(clicked()), controller, SLOT(addNewMusic()));
        // to show/close Release custo form dialog and checkbox's signal
    connect(btn_release, SIGNAL(clicked()), controller, SLOT(showReleaseDialog()));
    //connect(rd->getCancBtn(), SIGNAL(clicked()), controller, SLOT(closeDialog(FormDialog*)));
    connect(rd->getAddBtn(), SIGNAL(clicked()), controller, SLOT(releaseMusic()));

    connect(rd->getcdCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableRDComponents()));
    connect(rd->getvnlCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableRDComponents()));
    connect(rd->getcstCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableRDComponents()));

    connect(rd->getsptfCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableRDComponents()));
    connect(rd->getapplmCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableRDComponents()));
    connect(rd->gettdlCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableRDComponents()));
    connect(rd->getdzrCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableRDComponents()));
    connect(rd->getytmCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableRDComponents()));
    connect(rd->getamzCKB(), SIGNAL(stateChanged(int)), controller, SLOT(enableRDComponents()));
}

void Viewer::setTable() {
    table = new QTableView;

    if (catalog.isEmpty()){
        catalog = controller->initData();       // NON MI CONVINCE MOLTO
        qDebug() << "Is catalog loaded? " << !catalog.isEmpty() << endl;
        myTableModel = new TableModel(catalog);

        table->setModel(myTableModel);
        //table->setWindowTitle();

        table_layout->addWidget(table);
        frame->setLayout(table_layout);
    }else
        showWarning("Dati già caricati");
}

void Viewer::addMusicToTable(const Music* newMusic) {
    // FORSE SAREBBE MEGLIO FARLO FARE AL CONTROLLER??
    toSave.push_back(newMusic);

    myTableModel->addEntry(newMusic);
    qDebug() << QString::fromStdString(newMusic->getInfo()) << " \n ADDED TO TABLE" << endl;
}

void Viewer::removeMusicFromTable(uint index) { myTableModel->removeEntry(index); }

MusicDialog *Viewer::getMusicDialog() const { return md; }
ReleaseDialog *Viewer::getReleaseDialog() const { return rd; }

void Viewer::showDialog(FormDialog *dialog, const QVector<const Music*> &notReleased) {
    auto releaseDialog = dynamic_cast<ReleaseDialog*>(dialog);
    if (releaseDialog)
        releaseDialog->setMusicToPublic(notReleased);

    dialog->show();
}

void Viewer::resetComponents(FormDialog *dialog) { dialog->resetComponents(); }
void Viewer::closeDialog(FormDialog *dialog) {
    resetComponents(dialog);
    dialog->close();
}

void Viewer::enableReleaseDialogComponents() { rd->enableComponents(); }

void Viewer::showWarning(const QString &message) { QMessageBox::warning(this, tr("Campi vuoti"), message, QMessageBox::Ok); }
QMessageBox::StandardButton Viewer::showQuestion(const QString &message) { return QMessageBox::question(this, " ", message, QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes); }

QVector<const Music*> Viewer::getToSave() const{ return toSave; }

void Viewer::clearToSave() { toSave.clear(); }
