#ifndef CHARTSCREEN_H
#define CHARTSCREEN_H

#include <QDialog>
#include <QTableView>
#include <QtCharts/QChartView>
using QtCharts::QChartView;
#include <QHBoxLayout>
#include <QVector>

#include "tablemodel.h"
#include "piechart.h"
#include "linechart.h"
#include "barchart.h"
#include "phisycalmedium.h"
#include "digitalmedium.h"

class ChartScreen : public QDialog {
private:
    TableModel *myTableModel;
    QTableView *tableView;

    AbstractChart *myChartModel;
    QChartView *chartView;

    QHBoxLayout *mainLayout;
public:
    ChartScreen(QWidget* parent = Q_NULLPTR);
    ~ChartScreen();
    // imposta la tabella con i dati necessari per il grafico che lo necessita
    void setTableView(const QVector<const Music*> &v);
    // imposta la schermata per visualizzare un grafico
    void setChartView(AbstractChart* ac);
};

#endif // CHARTSCREEN_H
