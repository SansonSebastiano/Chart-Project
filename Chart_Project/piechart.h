#ifndef PIECHART_H
#define PIECHART_H

#include <QtCharts/QPieSeries>
using QtCharts::QPieSeries;
#include <QtCharts/QPieSlice>
using QtCharts::QPieSlice;

#include "abstractchart.h"

class PieChart : public AbstractChart{
private:
    QStringList x_data;
    //QList<QString*> x_data;
    QList<qreal*> y_data;
    QList<QPieSlice*> slices;

    void setSlices ();
    void setSeries() override;
public:
    PieChart(const QString &_title, const QStringList &_xData, const QList<qreal*> &_yData);
    virtual ~PieChart() = default;      // DA IMPLEMENTARE

    void setChart() override;
};

#endif // PIECHART_H
