#include "chartdialog.h"

ChartDialog::ChartDialog (QWidget* parent) : FormDialog(parent), options(new QComboBox(parent)), optionsList(QStringList()) {
    setAddBtn("Visualizza");
}

uint ChartDialog::getOptionsIndex() const { return options->currentIndex(); }

void ChartDialog::setOptionsList(const QStringList &_optionsList) { optionsList = _optionsList; }
