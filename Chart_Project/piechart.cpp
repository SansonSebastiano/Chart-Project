#include "piechart.h"

void PieChart::setSlices(const QList<QString *> &x_data, const QList<qreal *> &y_data) {
    auto xit = x_data.begin();
    auto yit = y_data.begin();

    while (xit != x_data.end() && yit != y_data.end()) {
        slices.push_back(new QPieSlice(**xit,**yit));

        ++xit;
        ++yit;
    }
}

void PieChart::setSeries(const QList<QString *> &x_data, const QList<qreal *> &y_data) {
    setSlices(x_data, y_data);

    series->append(slices);
}

