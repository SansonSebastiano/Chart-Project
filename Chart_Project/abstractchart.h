#ifndef ABSTRACTCHART_H
#define ABSTRACTCHART_H

#include <QString>
#include <QList>
#include <QChart>
QT_CHARTS_USE_NAMESPACE
#include <QValueAxis>

class AbstractChart : public QChart {
private:
    QString _title; // titolo del grafico
protected:
    QAbstractSeries *mySeries;  // contiene una serie di dati, specifici per ogni tipo di grafico, da visualizzare
    /*
     * @brief   inserisce la lista di dati in mySeries
     * @return  void
     */
    virtual void setSeries() = 0;
public:
    AbstractChart(const QString &_title);
    virtual ~AbstractChart();
    /*
     * @brief   restituisce il titolo di un grafico
     * @return  QString
     */
    QString getTitle() const;
    /*
     * @brief   imposta i dati contenuti in mySeries e li formatta a seconda del tipo di grafico
     * @return  void
     */
    virtual void setChart() = 0;
};

#endif // ABSTRACTCHART_H

