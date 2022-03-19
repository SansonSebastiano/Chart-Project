#include "barchartdialog.h"

const QString BarChartDialog::option2("Profitto Medium Digitali");
const QString BarChartDialog::option1("Profitto Medium Fisici");

const QString BarChartDialog::desc_option2("Questo grafico permette di confrontare le vendite della musica su piattaforme digitali in un anno dato in input");
const QString BarChartDialog::desc_option1("Questo grafico permette di confrontare le vendite della musica su supporti fisici in un anno dato in input");

BarChartDialog::BarChartDialog(QWidget* parent)
    : ChartDialog(parent),
      artistsCB(new QComboBox(parent)),
      dateQE(new QDateEdit(parent))
{
    dateQE->setDisplayFormat("yyyy");
    dateQE->setMaximumDate(QDate::currentDate());
}

void BarChartDialog::setOptions() { optionsCB->addItems({option1, option2}); }

uint BarChartDialog::getSelectedYear() const {
    return dateQE->date().year();
}

void BarChartDialog::createFormDialogLayout(QWidget *parent) {
    QVBoxLayout *dialogLayout = new QVBoxLayout(parent);

    setOptions();

    createOptionsQCBBox(dialogLayout, parent);
    // must setted artistCB before
    createDescriptionBox(dialogLayout, desc_option1);
    createFormLayout("Seleziona anno: ", dateQE, dialogLayout);

    // button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout(parent);
    buttonLayout->addWidget(getAddBtn());
    buttonLayout->setAlignment(Qt::AlignRight);

    dialogLayout->addLayout(buttonLayout);

    setLayout(dialogLayout);
}

// NB. c'e' anche su piechartdialog => polimorfismo??
void BarChartDialog::switchDescriptions() {
    switch (getOptionsIndex()) {
    case 0:
        changeTextDescription(desc_option1);
        break;
    case 1:
        changeTextDescription(desc_option2);
        break;
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

void BarChartDialog::setArtistCB(const std::vector<string> &artists) {
    QStringList list;
    artistsCB->clear();

    for (auto it = artists.begin(); it != artists.end(); ++it)
        list.push_back(QString::fromStdString(*it));

    artistsCB->addItems(list);
}
