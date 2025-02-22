#include "viewer.h"
#include "controller.h"

void Viewer::closeEvent(QCloseEvent *event) {
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

    // Aggiungere proprieta se necessario...

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

    edit->addAction(AC_add);
    edit->addAction(AC_release);

    chart->addAction(AC_lineChart);
    chart->addAction(AC_pieChart);
    chart->addAction(AC_barChart);

    mainLayout->addWidget(menuBar);
}

void Viewer::addControll_1(QVBoxLayout *mainLayout)
{
    // QGROUPBUTTONS
    QHBoxLayout *buttonLayout_1 = new QHBoxLayout;
    QHBoxLayout *dataBtnLayout = new QHBoxLayout;
    QHBoxLayout *chartBtnLayout = new QHBoxLayout;

    btn_saveData = createButton("Salva dati");
    btn_uploadData = createButton("Carica dati");

    dataBtnLayout->addWidget(btn_saveData);
    dataBtnLayout->addWidget(btn_uploadData);

    dataBtnLayout->setSpacing(10);
    dataBtnLayout->setContentsMargins(160, 0, 400 ,0);

    btn_lineChart = createButton("Line Chart");
    btn_pieChart = createButton("Pie Chart");
    btn_barChart = createButton("Bar Chart");

    chartBtnLayout->addWidget(btn_lineChart);
    chartBtnLayout->addWidget(btn_pieChart);
    chartBtnLayout->addWidget(btn_barChart);

    chartBtnLayout->setSpacing(50);

    buttonLayout_1->addLayout(dataBtnLayout);
    buttonLayout_1->addLayout(chartBtnLayout);

    mainLayout->addLayout(buttonLayout_1);
}

void Viewer::addControll_2(QHBoxLayout *screenLayout){
    // QGROUPBUTTONS
    QVBoxLayout *buttonLayout_2 = new QVBoxLayout;

    btn_addItem = createButton("Aggiungi musica");
    btn_release = createButton("Pubblica");

    buttonLayout_2->addWidget(btn_addItem);
    buttonLayout_2->addWidget(btn_release);

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

    screenLayout->addWidget(frame);
    mainLayout->addLayout(screenLayout);
}

Viewer::Viewer(QWidget *parent) : QDialog(parent), controller(new Controller) {
    mainLayout = new QVBoxLayout;

    // init Custom-Dialog-Form
    md = new MusicDialog(parent);
    md->createFormDialogLayout(parent);

    rd = new ReleaseDialog(parent);
    rd->createFormDialogLayout(parent);

    ld = new LineChartDialog(parent);
    ld->createFormDialogLayout(parent);

    pd = new PieChartDialog(parent);
    pd->createFormDialogLayout(parent);

    bd = new BarChartDialog(parent);
    bd->createFormDialogLayout(parent);

    // Add menu bar
    addMenus(mainLayout);

    // Add main buttons
    addControll_1(mainLayout);

    // add main screen
    addScreen(mainLayout);

    //mainLayout->setSpacing(0);
    setLayout(mainLayout);
    resize(QSize(600, 600));
}

Viewer::~Viewer() {
    delete controller;
    delete mainLayout;
    delete screenLayout;
    delete table_layout;
    delete frame;
    delete file;
    delete edit;
    delete chart;
    delete AC_upload;
    delete AC_save;
    delete AC_add;
    delete AC_release;
    delete AC_lineChart;
    delete AC_pieChart;

    delete btn_saveData;
    delete btn_uploadData;
    delete btn_lineChart;
    delete btn_pieChart;
    delete btn_release;
    delete btn_add;
    delete btn_cancel;
    delete tableView;
    delete myTableModel;
    delete md;
    delete rd;
    delete ld;
    delete pd;
    delete bd;
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
    // to handle line chart
    connect(AC_lineChart, &QAction::triggered, controller, &Controller::showLineChartDialog);
    connect(btn_lineChart, &QPushButton::clicked, controller, &Controller::showLineChartDialog);
    connect(ld->getGenreRB(), &QRadioButton::clicked, controller, &Controller::enableLDComponents);
    connect(ld->getAddBtn(), &QPushButton::clicked, controller, &Controller::showLineChartWindow);
    // to handle pie chart
    connect(AC_pieChart, &QAction::triggered, controller, &Controller::showPieChartDialog);
    connect(btn_pieChart, &QPushButton::clicked, controller, &Controller::showPieChartDialog);
    connect(pd->getOptionsCB(), static_cast<void(QComboBox::*)(int)>(&QComboBox::activated),
            [=](int index){
        Q_UNUSED(index);
        controller->changeDescription();
    });
    connect(pd->getAddBtn(), &QPushButton::clicked, controller, &Controller::showPieChartWindow);
    // to handle bar chart
    connect(btn_barChart, &QPushButton::clicked, controller, &Controller::showBarChartDialog);
    connect(AC_barChart, &QAction::triggered, controller, &Controller::showBarChartDialog);
    connect(bd->getAddBtn(), &QPushButton::clicked, controller, &Controller::showBarChartWindow);

}

void Viewer::setTable(const QVector<const Music*> &catalog) {
    tableView = new QTableView;
    myTableModel = new TableModel(catalog);

    tableView->setModel(myTableModel);

    table_layout->addWidget(tableView);
    frame->setLayout(table_layout);
}

void Viewer::addMusicToTable(const Music* newMusic) {
    myTableModel->addEntry(newMusic);
    qDebug() << QString::fromStdString(newMusic->getInfo()) << " \n ADDED TO TABLE" << endl;
}

void Viewer::removeMusicFromTable(uint index) { myTableModel->removeEntry(index); }

MusicDialog *Viewer::getMusicDialog() const { return md; }
ReleaseDialog *Viewer::getReleaseDialog() const { return rd; }
LineChartDialog *Viewer::getLineChartDialog() const { return ld; }
PieChartDialog *Viewer::getPieChartDialog() const { return pd; }
BarChartDialog *Viewer::getBarChartDialog() const { return bd; }

void Viewer::showDialog(FormDialog *dialog) { dialog->show(); }

void Viewer::resetComponents(FormDialog *dialog) { dialog->resetComponents(); }

void Viewer::closeDialog(FormDialog *dialog) {
    resetComponents(dialog);
    dialog->close();
}

void Viewer::showWarning(const QString &message) { QMessageBox::warning(this, tr("Campi vuoti"), message, QMessageBox::Ok); }

QMessageBox::StandardButton Viewer::showQuestion(const QString &message) { return QMessageBox::question(this, " ", message, QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes); }
