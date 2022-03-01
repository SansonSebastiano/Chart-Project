#include "barchart.h"

BarChart::BarChart(const QString& _title, const QList<QString*> &_xData, const QList<qreal> &_yData) : AbstractChart(_title), x_data(_xData), y_data(_yData) {
    mySeries = new QBarSeries();
}

void BarChart::setBars() {

    for(auto xit = x_data.begin(); xit != x_data.end(); ++xit)
        bars.push_back(new QBarSet(**xit));

    auto bit = bars.begin();
    auto yit = y_data.begin();

    while (bit != bars.end() && yit != y_data.end()) {
        (*bit)->append(*yit);   // DA TESTARE, NON SO COSA COMBINA

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
    /*
    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
     */

    QValueAxis *axisY = new QValueAxis();
    //axisY->setRange(0,15);    // prelevare il massimo valore in y_data
    addAxis(axisY, Qt::AlignLeft);
    mySeries->attachAxis(axisY);

    legend()->setVisible(true);
    legend()->setAlignment(Qt::AlignBottom);
}
