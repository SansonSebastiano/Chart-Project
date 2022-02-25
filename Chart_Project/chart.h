#ifndef CHART_H
#define CHART_H

#include <QString>
#include <QList>

//QList<T> myList = QList<T>::fromVector(QVector<T>::fromStdVector(myVector));

template<class x_dataType = QString>    // x_dataType = { QString, qreal }
class Chart {
    QString title;
    QList<x_dataType> x_data;
    QList<qreal> y_data;
public:
    Chart();    // DA DEFINIRE/IMPLEMENTARE
    ~Chart();   // DA DEFINIRE/IMPLEMENTARE

    void setTitle(const QString &_title);
    void setXdata(const QList<x_dataType> &_x);
    void setYdata(const QList<qreal> &_y);

    QString getTitle() const;
    QList<x_dataType> getXdata() const;
    QList<qreal> getYdata() const;
};

#endif // CHART_H
