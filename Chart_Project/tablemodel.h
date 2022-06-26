#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QMessageBox>

#include <phisycalmedium.h>
#include <digitalmedium.h>

const int COLS = 9;

class TableModel : public QAbstractTableModel{
    Q_OBJECT
private:
    // imposta il numero di righe
    int rowCount(const QModelIndex &parent) const override;
    // imposta il numero di colonne
    int columnCount(const QModelIndex &parent) const override;
    // imposta i dati nelle righe, con ciascuno attributo nella rispettiva colonna
    QVariant data(const QModelIndex &index, int role) const override;
    // imposta il titolo di ogni colonna
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    // aggiunge le righe
    bool insertRows(int position, int rows, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &parent = QModelIndex()) override;
    // rimuove le righe

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    const QVector<const Music*> &getMusics() const;
public:
    TableModel(QObject *parent = nullptr);
    TableModel(const QVector<const Music*> &_catalog, QObject *parent = nullptr);

    // aggiunge una riga nella tabella con un nuovo album
    void addEntry(const Music* m);
    // rimuove una riga dalla tabella
    void removeEntry(uint index);
private:
    QVector<const Music*> catalog;
};

#endif // TABLEMODEL_H
