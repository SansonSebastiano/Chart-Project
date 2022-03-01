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
    QTableView *myTable;

    AbstractChart *myChartModel;
    QChartView *chartView;

    QHBoxLayout *mainLayout;
public:
    ChartScreen(const QVector<const Music*> &v, AbstractChart* ac, QWidget* parent = Q_NULLPTR);
    ~ChartScreen() = default;   // DA IMPLEMENTARE

    void setTableView(const QVector<const Music*> &v);
    void setChartView(AbstractChart* ac);
};

#endif // CHARTSCREEN_H
