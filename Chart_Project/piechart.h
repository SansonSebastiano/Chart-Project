#ifndef PIECHART_H
#define PIECHART_H

#include <QtCharts/QPieSeries>
using QtCharts::QPieSeries;
#include <QtCharts/QPieSlice>
using QtCharts::QPieSlice;

#include "abstractchart.h"

class PieChart : public AbstractChart{
private:
    QList<QString*> x_data;
    QList<qreal*> y_data;

    QList<QPieSlice*> slices;

    void setSlices ();
public:
    PieChart(const QString &_title, const QList<QString*> &_xData, const QList<qreal*> &_yData);
    ~PieChart() = default;      // DA IMPLEMENTARE

    void setSeries() override;
    void setChart();
};

#endif // PIECHART_H
