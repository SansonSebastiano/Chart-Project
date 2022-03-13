#include "piechartdialog.h"

const QString PieChartDialog::option1("Top 5 artisti");
const QString PieChartDialog::option2("Percentuale musica pubblicata");
const QString PieChartDialog::option3("Confronto incassi tra supporti fisici e digitali");

const QString PieChartDialog::desc_option1("Questo grafico permette di visualizzare i 5 con maggior profitto");
const QString PieChartDialog::desc_option2("Questo grafico permette di visualizzare la differenza, in termini di percentuale, tra la musica pubblicata e non dell'intero catalogo");
const QString PieChartDialog::desc_option3("Questo grafico permette di confrontare gli incassi totali, in termini di percentuale, tra la musica pubblicata sui supporti fisici e digitali");

PieChartDialog::PieChartDialog(QWidget *parent) : ChartDialog(parent), dialogLayout(new QVBoxLayout(parent)) { }

void PieChartDialog::setOptions() { optionsCB->addItems({option1, option2, option3}); }

void PieChartDialog::createFormDialogLayout(QWidget *parent) {
    // set options' combobox
    setOptions();
    // add options' combobox to dialog
    createOptionsQCBBox(dialogLayout, parent);
    // add a detailed description of option selected
    createDescriptionBox(dialogLayout, desc_option1);

    // button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout(parent);
    buttonLayout->addWidget(getAddBtn());
    buttonLayout->setAlignment(Qt::AlignRight);

    dialogLayout->addLayout(buttonLayout);

    setLayout(dialogLayout);
}

void PieChartDialog::resetComponents() {
    ChartDialog::resetComponents();
}


void PieChartDialog::switchDescription() {
    switch (getOptionsIndex()) {
    case 0:
        changeTextDescription(desc_option1);
        break;
    case 1:
        changeTextDescription(desc_option2);
        break;
    case 2:
        changeTextDescription(desc_option3);
        break;
    default:
        break;
    }
}

