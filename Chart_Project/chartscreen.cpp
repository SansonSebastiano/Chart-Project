#include "chartscreen.h"

ChartScreen::ChartScreen(const QVector<const Music*> &v, AbstractChart* ac, QWidget* parent) : QDialog(parent) {
    setModal(false);

    mainLayout = new QHBoxLayout();

    setTableView(v);
    setChartView(ac);

    setLayout(mainLayout);
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
    chartView->setRenderHint(QPainter::Antialiasing);


    mainLayout->addWidget(chartView);
    resize(QSize(1920, 1080));
}
