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

    QPieSeries *series;
    QList<QPieSlice*> slices;

    void setSlices (const QList<QString*> &x_data, const QList<qreal*> &y_data);
public:
    PieChart(const QString &_title, const QList<qreal*> &_y_data, const QList<QString*> &_x_data);
    ~PieChart() = default;      // default un CAZZO, E' DA IMPLEMENTARE

    void setSeries(const QList<QString*> &x_data, const QList<qreal*> &y_data);
};

#endif // PIECHART_H
