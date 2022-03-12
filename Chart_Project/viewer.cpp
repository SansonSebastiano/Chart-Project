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
    if(!controller->getToSave().isEmpty())
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

    AC_upload = new QAction("Carica dati", file);
    AC_save = new QAction("Salva dati", file);
    //AC_close = new QAction("Chiudi", file);
    AC_add = new QAction("Aggiungi nuova musica", edit);
    AC_release = new QAction("Pubblica musica", edit);
    AC_lineChart = new QAction("Line Chart", chart);
    AC_pieChart = new QAction("Pie Chart", chart);
    AC_barChart = new QAction("Bar Chart", chart);

    menuBar->addMenu(file);
    menuBar->addMenu(edit);
    menuBar->addMenu(chart);

    file->addAction(AC_upload);
    file->addAction(AC_save);
    //file->addAction(AC_close);       // DA IMPLEMENTARE

    edit->addAction(AC_add);
    edit->addAction(AC_release);

    chart->addAction(AC_lineChart);         // DA IMPLEMENTARE
    chart->addAction(AC_pieChart);          // DA IMPLEMENTARE
    chart->addAction(AC_barChart);    // DA IMPLEMENTARE

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
    //btn_filter = createButton("Filtra");

    buttonLayout_2->addWidget(btn_addItem);
    buttonLayout_2->addWidget(btn_release);
    //buttonLayout_2->addWidget(btn_filter);

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
    // NON MI CONVINCE
    md = new MusicDialog(parent);
    md->createFormDialogLayout();

    rd = new ReleaseDialog(parent);
    rd->createFormDialogLayout();

    ld = new LineChartDialog(parent);
    ld->createFormDialogLayout();

    pd = new PieChartDialog(parent);
    pd->createFormDialogLayout();

    //bd = new BarChartDialog(parent);
    //bd->createFormDialogLayout();

    // Add menu bar
    addMenus(mainLayout);

    // Add main buttons
    addControll_1(mainLayout);

    // add main screen
    addScreen(mainLayout);

    // Aggiungere ...

    //mainLayout->setSpacing(0);
    setLayout(mainLayout);
    resize(QSize(1080, 720));
}

void Viewer::setController(Controller *c) {
    controller = c;

    // IMPLEMENTAZIONE SEGNALI E SLOT
    // save data
    connect(btn_saveData, &QPushButton::clicked, controller, &Controller::saveToFile);
    connect(AC_save, &QAction::triggered, controller, &Controller::saveToFile);
    // upload data
    connect(btn_uploadData, &QPushButton::clicked, controller, &Controller::showTable);
    connect(AC_upload, &QAction::triggered, controller, &Controller::showTable);
    // to handle Music custom form dialog
    connect(btn_addItem, &QPushButton::clicked, controller, &Controller::showMusicDialog);
    connect(AC_add, &QAction::triggered, controller, &Controller::showMusicDialog);
    connect(md->getAddBtn(), &QPushButton::clicked, controller, &Controller::addNewMusic);
    // to handle Release custom form dialog and checkbox's signal
    connect(btn_release, &QPushButton::clicked, controller, &Controller::showReleaseDialog);
    connect(AC_release, &QAction::triggered, controller, &Controller::showReleaseDialog);
    connect(rd->getAddBtn(), &QPushButton::clicked, controller, &Controller::releaseMusic);

    connect(rd->getcdCKB(), &QCheckBox::stateChanged, controller, &Controller::enableRDComponents);
    connect(rd->getvnlCKB(), &QCheckBox::stateChanged, controller, &Controller::enableRDComponents);
    connect(rd->getcstCKB(), &QCheckBox::stateChanged, controller, &Controller::enableRDComponents);

    connect(rd->getsptfCKB(), &QCheckBox::stateChanged, controller, &Controller::enableRDComponents);
    connect(rd->getapplmCKB(), &QCheckBox::stateChanged, controller, &Controller::enableRDComponents);
    connect(rd->gettdlCKB(), &QCheckBox::stateChanged, controller, &Controller::enableRDComponents);
    connect(rd->getdzrCKB(), &QCheckBox::stateChanged, controller, &Controller::enableRDComponents);
    connect(rd->getytmCKB(), &QCheckBox::stateChanged, controller, &Controller::enableRDComponents);
    connect(rd->getamzCKB(), &QCheckBox::stateChanged, controller, &Controller::enableRDComponents);
    // to handle line chart dialog
    connect(AC_lineChart, &QAction::triggered, controller, &Controller::showLineChartDialog);
    connect(btn_lineChart, &QPushButton::clicked, controller, &Controller::showLineChartDialog);
    connect(ld->getGenreRB(), &QRadioButton::clicked, controller, &Controller::enableLDComponents);
    connect(ld->getAddBtn(), &QPushButton::clicked, controller, &Controller::showLineChartWindow);
    // to handle pie chart dialog
    connect(btn_pieChart, &QPushButton::clicked, controller, &Controller::showPieChartDialog);
    connect(pd->getOptionsCB(), static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),
            [=](int index){
        Q_UNUSED(index);
        controller->changeDescription();
    });
}

void Viewer::setTable(const QVector<const Music*> &catalog) {
    tableView = new QTableView;
    myTableModel = new TableModel(catalog);

    tableView->setModel(myTableModel);
    //table->setWindowTitle();

    table_layout->addWidget(tableView);
    frame->setLayout(table_layout);
}

void Viewer::addMusicToTable(const Music* newMusic) {
    // FORSE SAREBBE MEGLIO FARLO FARE AL CONTROLLER??
    //toSave.push_back(newMusic);

    myTableModel->addEntry(newMusic);
    qDebug() << QString::fromStdString(newMusic->getInfo()) << " \n ADDED TO TABLE" << endl;
}

void Viewer::removeMusicFromTable(uint index) { myTableModel->removeEntry(index); }

MusicDialog *Viewer::getMusicDialog() const { return md; }

ReleaseDialog *Viewer::getReleaseDialog() const { return rd; }

LineChartDialog *Viewer::getLineChartDialog() const { return ld; }

PieChartDialog *Viewer::getPieChartDialog() const { return pd; }

void Viewer::showDialog(FormDialog *dialog) { dialog->show(); }

void Viewer::resetComponents(FormDialog *dialog) { dialog->resetComponents(); }

void Viewer::closeDialog(FormDialog *dialog) {
    resetComponents(dialog);
    dialog->close();
}

void Viewer::showWarning(const QString &message) { QMessageBox::warning(this, tr("Campi vuoti"), message, QMessageBox::Ok); }

QMessageBox::StandardButton Viewer::showQuestion(const QString &message) { return QMessageBox::question(this, " ", message, QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes); }
