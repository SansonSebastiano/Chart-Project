#include "tablemodel.h"

TableModel::TableModel(QObject *parent) : QAbstractTableModel(parent) { }

int TableModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 0;
}
int TableModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    // come far si che si estendibile, in base alla gerarchia dei dati nel modello?
    return COLS;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= list.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole){
        return QVariant();
        /*
        if(index.column() == 0)
            return QString::fromStdString(list.at(index.row())->getName());
        if(index.column() == 1)
            return QString::fromStdString(list.at(index.row())->getArtist());
        if(index.column() == 2)
            return QString::fromStdString(list.at(index.row())->getGenre());
        auto release = dynamic_cast<const Release*>(list.at(index.row()));
        if(index.column() == 3 && release)
            return QString::fromStdString(release->getReleaseDate().getDate());
        if(index.column() == 4 && release)
            return QString::fromStdString(release->double_to_string(release->getProfit()));
        auto pm = dynamic_cast<const PhisycalMedium*>(list.at(index.row()));
        if(index.column() == 5 && pm)
            return QString::fromStdString(pm->PhisycalMedium::support_names[pm->getSupport()]);
        if(index.column() == 6 && pm)
            return QString::fromStdString(pm->double_to_string(pm->getNumbers()));
        auto dm = dynamic_cast<const DigitalMedium*>(list.at(index.row()));
        if(index.column() == 7 && dm)
            return QString::fromStdString(dm->DigitalMedium::platform_names[dm->getPlatform()]);
        if(index.column() == 8 && dm)
            return QString::fromStdString(dm->double_to_string(dm->getNumbers()));
            */
    }

    return QVariant();
}

// DA RENDERE VARIABILE IN BASE ALLA GERARCHIA ESTENDIBILE DEL MODELLO -> IN CHE MODO?
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    // ATTENZIONE : DM vs PM !
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section) {
        case 0:
            return QString("Musica");
        case 1:
            return QString("Artista");
        case 2:
            return QString("Genere");
        case 3:
            return QString("Data Pubblicazione");
        case 4:
            return QString("Profitto");
        case 5:
            return QString("Supporto");
        case 6:
            return QString("Vendite");
        case 7:
            return QString("Piattaforma");
        case 8:
            return QString("Ascolti");
        }
    }
    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    Q_UNUSED(value);

    emit dataChanged(index, index);

    return true;
}

bool TableModel::insertRows(int position, int rows, const QModelIndex &index) {
    //Q_UNUSED(index);
    int colums = columnCount();
    beginInsertRows(index, position, position + rows - 1);

    //cout << "rows: " << rows << endl << "columns: " << colums << endl;

    for(int row = 0; row < rows; row++){
        for (int column = 0; column < colums; column++){

        }
    }

    /*
    for (int row = 0; row < rows; ++row){
        const Music* items;
        for(int column = 0; column < colums; ++column)
            items = list.at(row);
        list.insert(position, items);

        cout << list.at(row)->getInfo() << endl << endl;
    }
*/
    endInsertRows();
    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex &index) {
    //Q_UNUSED(index);
    beginRemoveRows(index, position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        list.removeAt(position);

    endRemoveRows();
    return true;
}

void TableModel::setCatalog(QList<const Music *> l) { list = l; }
