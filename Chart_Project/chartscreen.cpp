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
    // DA RIDEFINIRE L'ALGORITMO DI IMPOSTAZIONE DI CHART (ANCHE SULLA GERARCHIA DEI MODELLI) => FORSE NON SERVE
        // nel controller dichiarare un abstractchart e inizializzarlo secondo la scelta
        // poi invocare setChart()
        // infine passare l'oggetto abstractchart qui
    myChartModel = ac; // metodo clone ??
    chartView = new QChartView(myChartModel);
    chartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addWidget(chartView);
    resize(QSize(1080, 720));
}
