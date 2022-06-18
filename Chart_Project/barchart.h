#ifndef BARCHART_H
#define BARCHART_H

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
using QtCharts::QBarSet;
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include "abstractchart.h"

class BarChart : public AbstractChart {
private:
    QStringList x_data;     // lista di piattaforme o supporti
    QList<qreal> y_data;    // guadagno di ciascuna piattaforma/supporto dato un anno
    QList<QBarSet*> bars;   // contiene una lista di coppia di valori (x_data, y_data)
    QString year;           // anno scelto
    /*
     * @brief   imposta i valori di x_data e y_data rispettivamente nell'ascissa e ordinata
     * @return  void
     */
    void setBars();
    /*
     * @brief   inserisce la lista di dati (bars) in mySeries
     * @return  void
     */
    void setSeries() override;
public:
    BarChart(const QString &_title, const std::vector<std::pair<std::string, double>>& data, const QString &_year);
    virtual ~BarChart();
    /*
     * @brief   inserisce i dati ricevuti in input rispettivamente in x_data e y_data
     * @return  void
     */
    void setChartData(const std::vector<std::pair<std::string, double>> &data);
    /*
     * @brief   imposta i dati contenuti in mySeries e li formatta a seconda del tipo di grafico
     * @return  void
     */
    void setChart() override;
};

#endif // BARCHART_H
