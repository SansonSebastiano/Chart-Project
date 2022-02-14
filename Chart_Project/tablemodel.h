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

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    bool setData(const QModelIndex &index, const QVariant &value,int role) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;

    void setCatalog(QList<const Music*> l);

private:
    // come farli contenere la musica? template?
    QList<const Music*> list;
};

#endif // TABLEMODEL_H
