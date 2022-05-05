#include "piechart.h"

PieChart::PieChart(const QString &_title, const std::vector<std::pair<double, std::string>> &data) : AbstractChart(_title) {
    setChartData(data);
    mySeries = new QPieSeries();
}

PieChart::PieChart(const QString& _title, const QStringList &_xData, const QList<qreal> &_yData) : AbstractChart(_title), x_data(_xData), y_data(_yData) {
    mySeries = new QPieSeries();
}

void PieChart::setChartData(const std::vector<std::pair<double, std::string>> &data) {
    for(auto it = data.begin(); it != data.end(); ++it){
        x_data.push_back(QString::fromStdString((*it).second));  // artist's name
        auto tot_profit = (*it).first;                          // artist's tot profit
        y_data.push_back(tot_profit);
    }
}

void PieChart::setSlices() {
    auto xit = x_data.begin();
    auto yit = y_data.begin();

    while (xit != x_data.end() && yit != y_data.end()) {
        slices.push_back(new QPieSlice(*xit, *yit));

        ++xit;
        ++yit;
    }
    // another slices' configurations ... MAYBE
}

void PieChart::setSeries() {
    setSlices();

    auto pieSeries = dynamic_cast<QPieSeries*>(mySeries);

    pieSeries->append(slices);

    pieSeries->setLabelsVisible();
    pieSeries->setLabelsPosition(QPieSlice::LabelInsideHorizontal);

    //VISUALIZZARE LA PERCENTUALE

    //slices[0]->setLabel(QString("%1%").arg(100 * slices[0]->percentage(), 0, 'f', 1));
    //slices[1]->setLabel(QString("%1%").arg(100 * slices[1]->percentage(), 0, 'f', 1));
;
}

void PieChart::setChart() {
    setSeries();
    addSeries(mySeries);

    setTitle(getTitle());
    legend()->show();
    setAnimationOptions(QChart::SeriesAnimations);
    // ...
}
