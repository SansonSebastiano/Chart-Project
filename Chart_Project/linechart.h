#ifndef LINECHART_H
#define LINECHART_H

#include <QLineSeries>

#include "abstractchart.h"

class LineChart : public AbstractChart {
private:
    QList<qreal*> x_data;
    QList<qreal*> y_data;
    QList<QPointF> points;

    void setPoints();
    void setSeries() override;
public:
    LineChart(const QString &_title, const QList<qreal*> &_xData, const QList<qreal*> &_yData );
    ~LineChart() = default;     // DA IMPLEMENTARE

    void setChart() override;
};

#endif // LINECHART_H
