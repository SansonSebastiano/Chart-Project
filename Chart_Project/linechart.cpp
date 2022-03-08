#include "linechart.h"

LineChart::LineChart(const QString &_title, const std::vector<uint> &_xData, const std::vector<uint> &_yData) : AbstractChart(_title), x_data(_xData), y_data(_yData) {
    mySeries = new QLineSeries();
}

void LineChart::setPoints() {
    auto xit = x_data.begin();
    auto yit = y_data.begin();

    while (xit != x_data.end() && yit != y_data.end()) {
        points.push_back(QPointF(*yit, *xit));

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
    legend()->hide();
    createDefaultAxes();
    setTitle(getTitle());
    // ...
}
