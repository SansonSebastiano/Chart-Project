#include "linechart.h"

LineChart::LineChart(const QString &_title, const std::vector<uint> &profits, const uint from, const uint to) : AbstractChart(_title) {
    mySeries = new QLineSeries();
    setChartData(profits, from, to);
}

void LineChart::setChartData(const std::vector<uint> &profit, const uint from, const uint to) {
    x_data = profit;

    for (uint year = from; year <= to; ++year)
        y_data.push_back(year);
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

    QValueAxis *axisX = new QValueAxis;
    axisX->setLabelFormat("%i");
    axisX->setTickCount(x_data.size());
    axisX->setTitleText("Intervallo anni");
    setAxisX(axisX, mySeries);

    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%.2f");
    axisY->setTickCount(y_data.size());
    axisY->setTitleText("Profitto (in €)");
    setAxisY(axisY, mySeries);

    legend()->hide();
    setTitle(getTitle());
    setAnimationOptions(QChart::SeriesAnimations);
    // ...
}
