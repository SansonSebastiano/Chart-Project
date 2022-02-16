#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

#include <phisycalmedium.h>
#include <digitalmedium.h>

const int COLS = 9;

class TableModel : public QAbstractTableModel{
    Q_OBJECT
public:
    TableModel(QObject *parent = nullptr);
    TableModel(const QVector<const Music*> &_catalog, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
private:
    QVector<const Music*> catalog;
};

#endif // TABLEMODEL_H
