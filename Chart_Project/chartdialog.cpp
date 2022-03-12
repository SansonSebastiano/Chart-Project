#include "chartdialog.h"

ChartDialog::ChartDialog (QWidget* parent) : FormDialog(parent), optionsCB(new QComboBox(parent)), description(new QPlainTextEdit()) {
    setAddBtn("Visualizza");
}

uint ChartDialog::getOptionsIndex() const { return optionsCB->currentIndex(); }

QComboBox *ChartDialog::getOptionsCB() const { return optionsCB; }

//void ChartDialog::setOptions(const QStringList &optionsList) { options->addItems(optionsList); }

void ChartDialog::changeTextDescription(const QString &text) {
    description->clear();
    description->setPlainText(text);
}

void ChartDialog::createDescriptionBox(QVBoxLayout *vbl, const QString &text, QWidget *parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);

    description->setPlainText(text);
    description->setReadOnly(true);

    boxLayout->addWidget(description);

    QGroupBox *groupBox = new QGroupBox("Info: ", parent);
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
}

// PRE : setOptions() must be invocated before
void ChartDialog::createOptionsQCBBox(QVBoxLayout *vbl, QWidget* parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);

    createFormLayout("", optionsCB, boxLayout, parent);

    QGroupBox *groupBox = new QGroupBox("Scegli un'opzione: ");
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
}

void ChartDialog::resetComponents() { optionsCB->setCurrentIndex(0); }
