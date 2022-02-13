#include "viewer.h"

void Viewer::addMenus(QVBoxLayout *mainLayout)
{
    QMenuBar *menuBar = new QMenuBar(this);

    QMenu *file = new QMenu ("File", menuBar);
    QMenu *edit = new QMenu ("Edit", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(edit);

    file->addAction(new QAction("Carica dati", file));
    file->addAction(new QAction("Salva dati", file));
    file->addAction(new QAction("Chiudi", file));

    edit->addAction(new QAction("Aggiungi nuova musica", file));

    mainLayout->addWidget(menuBar);
}

void Viewer::addScreen(QVBoxLayout *mainLayout, QHBoxLayout *screen)
{
    QVBoxLayout *screenLayout = new QVBoxLayout;

    QFrame *frame = new QFrame;

    frame->setStyleSheet(".QFrame{background-color: rgb(211, 211, 211); border-radius: 10px}");
    frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    screenLayout->addWidget(frame);
    screenLayout->setSpacing(0);

    screen->addLayout(screenLayout);
    mainLayout->addLayout(screenLayout);
}

void Viewer::addButtons(QVBoxLayout *mainLayout)
{
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QHBoxLayout *dataBtnLayout = new QHBoxLayout;
    QHBoxLayout *chartBtnLayout = new QHBoxLayout;

    //QPushButton *newLabel = new QPushButton("Nuova Label");
    QPushButton *btn_uploadData = new QPushButton("Carica dati");
    QPushButton *btn_saveData = new QPushButton("Salva dati");

    dataBtnLayout->addWidget(btn_uploadData);
    dataBtnLayout->addWidget(btn_saveData);

    dataBtnLayout->setSpacing(10);
    dataBtnLayout->setContentsMargins(100, 0, 20 ,0);

    QPushButton *btn_lineChart = new QPushButton("Line Chart");
    QPushButton *btn_pieChart = new QPushButton("Pie Chart");
    QPushButton *btn_histogram = new QPushButton("Histogram");

    chartBtnLayout->addWidget(btn_lineChart);
    chartBtnLayout->addWidget(btn_pieChart);
    chartBtnLayout->addWidget(btn_histogram);

    chartBtnLayout->setSpacing(10);
    chartBtnLayout->setContentsMargins(20, 0, 20 ,0);

    buttonLayout->addLayout(dataBtnLayout);
    buttonLayout->addLayout(chartBtnLayout);

    mainLayout->addLayout(buttonLayout);
}

void Viewer::addBtn(QVBoxLayout *mainLayout, QHBoxLayout *screen)
{
    QVBoxLayout *buttoLayout = new QVBoxLayout;

    QPushButton *btn_addItem = new QPushButton("+");
    QPushButton *btn_filter = new QPushButton("Filtra");

    buttoLayout->addWidget(btn_addItem);
    buttoLayout->addWidget(btn_filter);

    buttoLayout->setSpacing(5);
    buttoLayout->setContentsMargins(10, 0, 10, 500);

    screen->addLayout(buttoLayout);
    mainLayout->addLayout(buttoLayout);
}

Viewer::Viewer(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // Aggiungere la barra dei menu
    addMenus(mainLayout);

    // Aggiungere i pulsanti
    addButtons(mainLayout);

    // Aggiungere schermo
    QHBoxLayout *tmp = new QHBoxLayout;
    addBtn(mainLayout, tmp);
    addScreen(mainLayout, tmp);
    mainLayout->addLayout(tmp);

    // Aggiungere ...

    //mainLayout->setSpacing(0);
    setLayout(mainLayout);
    resize(QSize(1024, 720));
}
