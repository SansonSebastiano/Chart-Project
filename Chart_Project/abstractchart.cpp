#include "abstractchart.h"

AbstractChart::AbstractChart(const QString &_title) : _title(_title) { }

QString AbstractChart::getTitle() const { return _title; }
