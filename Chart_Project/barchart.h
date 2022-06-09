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
    QStringList x_data;
    QList<qreal> y_data;
    QList<QBarSet*> bars;
    QString year;

    void setBars();
    void setSeries() override;
public:
    BarChart(const QString &_title, const std::vector<std::pair<std::string, double>>& data, const QString &_year);
    //BarChart(const QString &_title, const QStringList &_xData, const QList<qreal*> &_yData, const QString &_year);
    virtual ~BarChart();

    void setChartData(const std::vector<std::pair<std::string, double>> &data);
    void setCategories();   // FORSE NON SERVE
    void setChart() override;
};

#endif // BARCHART_H
