#ifndef ABSTRACTCHART_H
#define ABSTRACTCHART_H

#include <QString>
#include <QList>
#include <QChart>
QT_CHARTS_USE_NAMESPACE
#include <QValueAxis>

class AbstractChart : public QChart {
private:
    QString _title;
protected:
    QAbstractSeries *mySeries;
    virtual void setSeries() = 0;
public:
    AbstractChart(const QString &_title);
    virtual ~AbstractChart();

    QString getTitle() const;

    //virtual void setChartData() = 0;
    virtual void setChart() = 0;
};

#endif // ABSTRACTCHART_H
