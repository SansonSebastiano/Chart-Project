#include "chartscreen.h"

ChartScreen::ChartScreen(QWidget* parent) : QDialog(parent) {
    setModal(false);

    mainLayout = new QHBoxLayout();

    setLayout(mainLayout);
}

ChartScreen::~ChartScreen() {
    delete myTableModel;
    delete tableView;
    delete myChartModel;
    delete chartView;
    delete mainLayout;
}

void ChartScreen::setTableView(const QVector<const Music *> &v) {
    tableView = new QTableView();
    myTableModel = new TableModel(v);

    tableView->setModel(myTableModel);
    mainLayout->addWidget(tableView);
}

void ChartScreen::setChartView(AbstractChart* ac) {
    myChartModel = ac; // metodo clone ??
    chartView = new QChartView(myChartModel);
    chartView->chart()->setTheme(QChart::ChartThemeDark);
    chartView->setRenderHint(QPainter::Antialiasing);


    mainLayout->addWidget(chartView);
    resize(QSize(1920, 1080));
}
