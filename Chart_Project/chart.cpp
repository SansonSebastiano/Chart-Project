#include "chart.h"

template<class T>
void Chart<T>::setTitle(const QString &_title) { title = _title; }

template<class T>
void Chart<T>::setXdata(const QList<T> &_x) { x_data = _x; }

template<class T>
void Chart<T>::setYdata(const QList<qreal> &_y) { y_data = _y; }

template <class T>
QString Chart<T>::getTitle() const { return title; }

template<class T>
QList<T> Chart<T>::getXdata() const { return x_data; }


