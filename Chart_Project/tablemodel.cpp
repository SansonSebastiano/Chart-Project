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
            return QString::fromStdString(release->double_to_string(release->getProfit()));

        const auto pm = dynamic_cast<const PhisycalMedium*>(music);
        const auto dm = dynamic_cast<const DigitalMedium*>(music);

        if (index.column() == 5 && pm)
            return QString::fromStdString(pm->support_names[pm->getSupport()]);
        if (index.column() == 6 && pm)
            return QString::fromStdString(pm->double_to_string(pm->getNumbers()));

        if (index.column() == 7 && dm)
            return QString::fromStdString(dm->platform_names[dm->getPlatform()]);
        if (index.column() == 8 && dm)
            return QString::fromStdString(dm->double_to_string(dm->getNumbers()));
    }
    return QVariant();
}
