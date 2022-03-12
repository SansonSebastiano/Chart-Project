#include "piechart.h"

PieChart::PieChart(const QString& _title, const QStringList &_xData, const QList<qreal*> &_yData) : AbstractChart(_title), x_data(_xData), y_data(_yData) {
    mySeries = new QPieSeries();
}


void PieChart::setSlices() {
    auto xit = x_data.begin();
    auto yit = y_data.begin();

    while (xit != x_data.end() && yit != y_data.end()) {
        slices.push_back(new QPieSlice(*xit,**yit));

        ++xit;
        ++yit;
    }
    // another slices' configurations ... MAYBE
}

void PieChart::setSeries() {
    setSlices();
    dynamic_cast<QPieSeries*>(mySeries)->append(slices);
}

void PieChart::setChart() {
    setSeries();
    addSeries(mySeries);

    setTitle(getTitle());
    legend()->show();
    // ...
}
