#ifndef LINECHART_H
#define LINECHART_H

#include <QLineSeries>
#include <QDateTimeAxis>

#include "abstractchart.h"

class LineChart : public AbstractChart {
private:
    std::vector<uint> x_data;
    std::vector<uint> y_data;
    QList<QPointF> points;

    void setPoints();
    void setSeries() override;
public:
    LineChart(const QString &_title, const std::vector<uint> &_xData, const std::vector<uint> &_yData );
    virtual ~LineChart() = default;     // DA IMPLEMENTARE

    void setChart() override;
};

#endif // LINECHART_H
