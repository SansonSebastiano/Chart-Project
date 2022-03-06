#include "barchartdialog.h"

const QString BarChartDialog::option1("Confronta i profitti di un artista su vari supporti");
const QString BarChartDialog::option2("Confronta vendite in un certo anno");
const QString BarChartDialog::option3("Confronta ascolti in un certo anno");

const QString BarChartDialog::desc_option1("Questo grafico permette di confrontare i profitti della discografia di un artista in vari supporti");
const QString BarChartDialog::desc_option2("Questo grafico permette di confrontare le vendite su tutti i supporti fisici in un anno dato in input");
const QString BarChartDialog::desc_option3("Questo grafico permette di confrontare gli ascolti su tutti i supporti digitali in un anno dato in input");

BarChartDialog::BarChartDialog(QWidget* parent) : ChartDialog(parent), dialogLayout(new QVBoxLayout(parent)), artistsCB(new QComboBox(parent))
{
    date->setDisplayFormat("yyyy");
}

void BarChartDialog::setOptions() { optionsCB->addItems({option1, option2, option3}); }

void BarChartDialog::createFormDialogLayout(QWidget *parent) {
    setOptions();
    createOptionsQCBBox(dialogLayout, parent);
    // must setted artistCB before
    showDescription();

    // button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout(parent);
    buttonLayout->addWidget(getAddBtn());
    buttonLayout->setAlignment(Qt::AlignRight);

    dialogLayout->addLayout(buttonLayout);

    setLayout(dialogLayout);
}

void BarChartDialog::showDescription() {
    switch (getOptionsIndex()) {
    case 0:
        createDescriptionBox(dialogLayout, desc_option1);
        createFormLayout("Artista: ", artistsCB, dialogLayout);
        break;
    case 1:
        createDescriptionBox(dialogLayout, desc_option2);
        createFormLayout("Seleziona anno: ", date, dialogLayout);
        break;
    case 2:
        createDescriptionBox(dialogLayout, desc_option3);
        createFormLayout("Seleziona anno ", date, dialogLayout);
    default:
        break;
    }
}

void BarChartDialog::enableComponents() {
    // todo
}

void BarChartDialog::resetComponents(){
    ChartDialog::resetComponents();

    artistsCB->setCurrentIndex(0);
}

void BarChartDialog::setArtistCB(const QStringList &artists) { artistsCB->addItems(artists); }
