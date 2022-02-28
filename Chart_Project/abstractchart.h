#ifndef ABSTRACTCHART_H
#define ABSTRACTCHART_H

#include <QString>
#include <QList>
#include <QChart>
QT_CHARTS_USE_NAMESPACE

//template<class x_dataType = QString>    // x_dataType = { QString, qreal }
class AbstractChart : public QChart {
private:
    //QList<x_dataType*> x_data;
    QString _title;
    QAbstractSeries *series;
    QList<qreal*> y_data;
public:
    AbstractChart(const QString &_title, const QList<qreal*> &_y_data);
    virtual ~AbstractChart() = 0;

    //QList<x_dataType*> getXdata() const;
    QList<qreal*> getYdata() const;

    //void setXdata(const QList<x_dataType*> &_x_data);
    void setYdata(const QList<qreal*> &_y_data);

    //virtual void setChartData() = 0;
};

#endif // ABSTRACTCHART_H
