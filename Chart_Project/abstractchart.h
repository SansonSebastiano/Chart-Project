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
protected:
    QAbstractSeries *mySeries;
    //QList<qreal*> y_data;
public:
    AbstractChart(const QString &_title);
    virtual ~AbstractChart() = default; // DA IMPLEMENTARE

    QString getTitle() const;
    virtual void setSeries() = 0;
};

#endif // ABSTRACTCHART_H
