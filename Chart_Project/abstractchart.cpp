#include "abstractchart.h"

AbstractChart::AbstractChart(const QString &_title, const QList<qreal*> &_y_data) : _title(_title), y_data(_y_data) { }
AbstractChart::~AbstractChart() { }

//template<class x_dataType>
//QString AbstractChart::getTitle() const { return title; }

/*
template<class x_dataType>
QList<x_dataType*> AbstractChart<x_dataType>::getXdata() const { return x_data; }
*/
//template<class x_dataType>
QList<qreal*> AbstractChart::getYdata() const { return y_data; }

//template<class x_dataType>
//void AbstractChart::setTitle(const QString &_title) { title = _title; }

//template<class x_dataType>
//void AbstractChart<x_dataType>::setXdata(const QList<x_dataType*> &_x_data) { x_data = _x_data; }

//template<class x_dataType>
void AbstractChart::setYdata(const QList<qreal*> &_y_data) { y_data = _y_data; }
