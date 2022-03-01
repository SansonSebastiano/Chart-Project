#ifndef ABSTRACTCHART_H
#define ABSTRACTCHART_H

#include <QString>
#include <QList>
#include <QChart>
QT_CHARTS_USE_NAMESPACE

class AbstractChart : public QChart {
private:
    QString _title;
protected:
    QAbstractSeries *mySeries;
    virtual void setSeries() = 0;
public:
    AbstractChart(const QString &_title);
    virtual ~AbstractChart() = default; // DA IMPLEMENTARE

    QString getTitle() const;

    virtual void setChart() = 0;
};

#endif // ABSTRACTCHART_H
