#include "barchart.h"

BarChart::BarChart(const QString& _title, const std::vector<std::pair<std::string, double>>& data, const QString &_year) : AbstractChart(_title), year(_year) {
    mySeries = new QBarSeries();
    setChartData(data);
}

void BarChart::setChartData(const std::vector<std::pair<std::string, double>> &data) {
    for (auto it = data.begin(); it != data.end(); ++it){
        x_data.push_back(QString::fromStdString((*it).first));
        auto x = (*it).second;
        y_data.push_back(&x);
    }
}

void BarChart::setBars() {

    for(auto xit = x_data.begin(); xit != x_data.end(); ++xit)
        bars.push_back(new QBarSet(*xit));

    auto bit = bars.begin();
    auto yit = y_data.begin();

    while (bit != bars.end() && yit != y_data.end()) {
        (*bit)->append(**yit);   // DA TESTARE, NON SO COSA COMBINA

        ++bit;
        ++yit;
    }
}

void BarChart::setSeries() {
    setBars();
    dynamic_cast<QBarSeries*>(mySeries)->append(bars);
}

void BarChart::setChart() {
    setSeries();

    addSeries(mySeries);
    setTitle(getTitle());
    setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(year);
    axisX->setTitleText("Anno");
    addAxis(axisX, Qt::AlignBottom);
    mySeries->attachAxis(axisX);


    QValueAxis *axisY = new QValueAxis();
    axisY->setTickCount(y_data.size());
    axisY->setTitleText("Profitto (in €)");
    //axisY->setRange(0,15);    // prelevare il massimo valore in y_data
    addAxis(axisY, Qt::AlignLeft);
    mySeries->attachAxis(axisY);


    legend()->setVisible(true);
    legend()->setAlignment(Qt::AlignBottom);
}
