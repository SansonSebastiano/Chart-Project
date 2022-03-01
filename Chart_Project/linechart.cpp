#include "linechart.h"

LineChart::LineChart(const QString &_title, const QList<qreal*> &_xData, const QList<qreal*> &_yData) : AbstractChart(_title), x_data(_xData), y_data(_yData) {
    mySeries = new QLineSeries();
}

void LineChart::setPoints() {
    auto xit = x_data.begin();
    auto yit = y_data.end();

    while (xit != x_data.end() && yit != y_data.end()) {
        points.push_back(QPointF(**xit, **yit));

        ++xit;
        ++yit;
    }
}

void LineChart::setSeries() {
    setPoints();
    dynamic_cast<QLineSeries*>(mySeries)->append(points);
}

void LineChart::setChart() {
    setSeries();

    addSeries(mySeries);
    setTitle(getTitle());
    // ...
}
