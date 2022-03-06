#include "chartdialog.h"

ChartDialog::ChartDialog (QWidget* parent) : FormDialog(parent), optionsCB(new QComboBox(parent)) {
    setAddBtn("Visualizza");
}

uint ChartDialog::getOptionsIndex() const { return optionsCB->currentIndex(); }

//void ChartDialog::setOptions(const QStringList &optionsList) { options->addItems(optionsList); }

void ChartDialog::createDescriptionBox(QVBoxLayout *vbl, const QString &label, QWidget *parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);

    QPlainTextEdit *description = new QPlainTextEdit(label, parent);
    description->setReadOnly(true);

    boxLayout->addWidget(description);

    QGroupBox *groupBox = new QGroupBox("Info: ", parent);
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
}

//QComboBox* ChartDialog::getOptions() const { return options; }

// PRE : setOptions() must be invocated before
void ChartDialog::createOptionsQCBBox(QVBoxLayout *vbl, QWidget* parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);

    createFormLayout("", optionsCB, vbl, parent);

    QGroupBox *groupBox = new QGroupBox("Scegli un'opzione: ");
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
}

void ChartDialog::resetComponents() {
    optionsCB->setCurrentIndex(0);
}
