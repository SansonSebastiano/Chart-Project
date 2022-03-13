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

    // TODO : da sistemare

    QValueAxis *axisX = new QValueAxis;
    axisX->setLabelFormat("%.0f");
    axisX->setTickCount(x_data.size());
    axisX->setTitleText("Intervallo anni");
   // addAxis(axisX, Qt::AlignBottom);
    setAxisX(axisX, mySeries);
    //mySeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setMin(0);
    axisY->setLabelFormat("%.2f");
    axisY->setTickCount(y_data.size());
    axisY->setTitleText("Profitto (in €)");
    //addAxis(axisY, Qt::AlignLeft);
    setAxisY(axisY, mySeries);
    //mySeries->attachAxis(axisY);

    legend()->hide();
    setTitle(getTitle());
    setAnimationOptions(QChart::SeriesAnimations);
    // ...
}
