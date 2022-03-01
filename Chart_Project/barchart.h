#ifndef BARCHART_H
#define BARCHART_H

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
using QtCharts::QBarSet;
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include "abstractchart.h"

class BarChart : public AbstractChart {
private:
    QList<QString*> x_data;
    QList<qreal> y_data;
    QList<QBarSet*> bars;

    void setBars();
    void setSeries() override;
public:
    BarChart(const QString &_title, const QList<QString*> &_xData, const QList<qreal> &_yData);
    ~BarChart() = default;  // DA IMPLEMENTARE

    void setCategories();   // FORSE NON SERVE
    void setChart() override;
};

#endif // BARCHART_H
