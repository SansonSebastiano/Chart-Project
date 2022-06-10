#include "tablemodel.h"

TableModel::TableModel(QObject *parent) : QAbstractTableModel(parent) { }

TableModel::TableModel(const QVector<const Music*> &_catalog, QObject *parent) : QAbstractTableModel(parent) {
    catalog = _catalog;
}

int TableModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);

    return catalog.size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);

    return COLS;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal){
        switch (section) {
        case 0:
            return tr("Nome");
        case 1:
            return tr("Artista");
        case 2:
            return tr("Genere");
        case 3:
            return tr("Data Pubblicazione");
        case 4:
            return tr("Profitto");
        case 5:
            return tr("Supporto");
        case 6:
            return tr("Vendite");
        case 7:
            return tr("Piattaforma");
        case 8:
            return tr("Ascolti");
        default:
            return QVariant();
        }
    }

    return QVariant();
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= catalog.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const auto &music = catalog.at(index.row());

        if (index.column() == 0)
            return QString::fromStdString(music->getName());
        if (index.column() == 1)
            return QString::fromStdString(music->getArtist());
        if (index.column() == 2)
            return QString::fromStdString(music->getGenre());

        const auto release = dynamic_cast<const Release*>(music);

        if (index.column() == 3 && release)
            return QString::fromStdString(release->getReleaseDate().getDate());
        if (index.column() == 4 && release)
            return QString::fromStdString(release->customProfitFormatting(release->getProfit()) + " €");

        const auto pm = dynamic_cast<const PhisycalMedium*>(music);
        const auto dm = dynamic_cast<const DigitalMedium*>(music);

        if (index.column() == 5 && pm)
            return QString::fromStdString(pm->support_names[pm->getSupport()]);
        if (index.column() == 6 && pm)
            return QVariant(pm->getNumbers()).toString();
        if (index.column() == 7 && dm)
            return QString::fromStdString(dm->platform_names[dm->getPlatform()]);
        if (index.column() == 8 && dm)
            return QVariant(dm->getNumbers()).toString();
    }
    return QVariant();
}

bool TableModel::insertRows(int position, int rows, const QModelIndex &parent) {
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        catalog.push_back(new Album());

    endInsertRows();
    return true;
}

bool TableModel::removeRows(int position, int rows, const QModelIndex &parent) {
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    cout << catalog.at(position)->getInfo();

    for (int row = 0; row < rows; ++row)
        catalog.removeAt(position);

    cout << "\tDELETED FROM TABLE" << endl << endl;

    endRemoveRows();
    return true;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.isValid() && role == Qt::DisplayRole){
        auto newMusic = value.value<const Music*>();
        catalog.replace(index.row(), newMusic);

        emit dataChanged(index, index, {Qt::DisplayRole});
        return true;
    }
    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    Q_UNUSED(index);
    return Qt::ItemIsEnabled;
}

const QVector<const Music*> &TableModel::getMusics() const { return catalog; }

void TableModel::addEntry(const Music* m) {
    insertRows(0, 1, QModelIndex());

    int position = catalog.size() - 1;

    QModelIndex i = index(position, 0, QModelIndex());
    setData(i, QVariant::fromValue<const Music*>(m), Qt::DisplayRole);
}

void TableModel::removeEntry(uint index) {
    removeRows(index, 1, QModelIndex());
}
