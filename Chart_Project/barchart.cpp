#include "barchart.h"

BarChart::BarChart(const QString& _title, const std::vector<std::pair<std::string, double>>& data, const QString &_year) : AbstractChart(_title), year(_year) {
    mySeries = new QBarSeries();
    setChartData(data);
}

BarChart::~BarChart() {
    bars.clear();
}

void BarChart::setChartData(const std::vector<std::pair<std::string, double>> &data) {
    for (auto it = data.begin(); it != data.end(); ++it){
        x_data.push_back(QString::fromStdString((*it).first));  // inserisce tutte/i le/i piattaforme/supporti
        auto x = (*it).second;
        y_data.push_back(x);                                    // inserisce i guadagni per ciascuna piattaforma/supporto
    }
}

void BarChart::setBars() {

    for(auto xit = x_data.begin(); xit != x_data.end(); ++xit)
        bars.push_back(new QBarSet(*xit));                  // imnposta le ascisse

    auto bit = bars.begin();
    auto yit = y_data.begin();

    while (bit != bars.end() && yit != y_data.end()) {
        (*bit)->append(*yit);                               // imposta le ordinate

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

    addSeries(mySeries);                                    // aggiunge i dati al grafico
    setTitle(getTitle());                                   // imposta il titolo del grafico
    setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(year);
    axisX->setTitleText("Anno");
    addAxis(axisX, Qt::AlignBottom);
    mySeries->attachAxis(axisX);                            // imposta le/i piattaforme/supporti nell'ascisse


    QValueAxis *axisY = new QValueAxis();
    axisY->setTickCount(y_data.size());
    axisY->setTitleText("Profitto (in €)");
    addAxis(axisY, Qt::AlignLeft);
    mySeries->attachAxis(axisY);                            // imposta il guadagno nell'ordinata


    legend()->setVisible(true);
    legend()->setAlignment(Qt::AlignBottom);
}
