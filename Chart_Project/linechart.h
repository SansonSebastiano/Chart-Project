#ifndef LINECHART_H
#define LINECHART_H

#include <QLineSeries>
#include <QDateTimeAxis>

#include "abstractchart.h"

class LineChart : public AbstractChart {
private:
    std::vector<uint> x_data;       // contiene i valori delle ascisse
    std::vector<uint> y_data;       // contiene i valori delle ordinate
    QList<QPointF> points;

    void setPoints();               // crea una lista con coppia di coordinate (x, y)
    void setSeries() override;
public:
    LineChart(const QString &_title, const std::vector<uint> &profits, const uint from, const uint to);
    virtual ~LineChart() = default;
    // imposta profitto e anni nei rispettivi container
    void setChartData(const std::vector<uint> &profit, const uint from, const uint to);
    void setChart() override;
};

#endif // LINECHART_H
