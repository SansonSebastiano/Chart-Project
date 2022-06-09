#include "abstractchart.h"

AbstractChart::AbstractChart(const QString &_title) : _title(_title) { }

AbstractChart::~AbstractChart() {
    delete mySeries;
}

QString AbstractChart::getTitle() const { return _title; }
