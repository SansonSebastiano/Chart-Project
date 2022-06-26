#ifndef PIECHART_H
#define PIECHART_H

#include <QtCharts/QPieSeries>
using QtCharts::QPieSeries;
#include <QtCharts/QPieSlice>
using QtCharts::QPieSlice;

#include "abstractchart.h"

class PieChart : public AbstractChart{
private:
    QStringList x_data;     // contiene la label
    QList<qreal> y_data;    // contiene un valore numerico attribuito ad una label
    QList<QPieSlice*> slices;   // lista di fette, componenti di un pie chart
    // imposta le fette, ciascuna con rispettiva coppia (label, valore numerico)
    void setSlices ();
    void setSeries() override;
public:
    PieChart(const QString &_title, const std::vector<std::pair<double, std::string>> &data);
    PieChart(const QString &_title, const QStringList &_xData, const QList<qreal> &_yData);
    virtual ~PieChart();
    // imposta i container (x_data e y_data) con i rispettivi artisti e profitti
    void setChartData(const std::vector<std::pair<double, std::string>> &data);

    void setChart() override;
};

#endif // PIECHART_H
