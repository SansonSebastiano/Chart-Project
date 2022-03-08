#include "linechartdialog.h"

const QString LineChartDialog::desc_option1("Questo grafico permette di visualizzare l'andamento dei profitti in un certo intervallo di anni, dato un parametro a scelta tra le seguenti opzioni");

LineChartDialog::LineChartDialog(QWidget *parent)
    : ChartDialog(parent),
      genreRB(new QRadioButton("Genere Musicale")),
      genreCB(new QComboBox()),
      from(new QDateEdit()),
      to(new QDateEdit())
{
    genreRB->setChecked(false);
    genreCB->setEnabled(false);

    from->setMaximumDate(QDate(QDate::currentDate().year() - 1, QDate::currentDate().month(), QDate::currentDate().day())); // accetta come data massima: esattamente un anno fa
    from->setDisplayFormat("yyyy");
    to->setMaximumDate(QDate::currentDate());   // accetta come data massima: esattamente oggi
    to->setDisplayFormat("yyyy");
}

void LineChartDialog::setOptions() { }

void LineChartDialog::setGenreCB(const std::vector<string> &genres) {
    QStringList list;
    genreCB->clear();
    for (auto it = genres.begin(); it != genres.end(); ++it)
        list.push_back(QString::fromStdString(*it));

    genreCB->addItems(list);
}

void LineChartDialog::createGenreQCBBox(QVBoxLayout *vbl, QWidget *parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);

    // PRE: set genreCB
    createFormLayout(genreRB, genreCB, boxLayout, parent);
    // other rb buttons

    QGroupBox *groupBox = new QGroupBox("Scegli un opzione:", parent);
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
}

void LineChartDialog::createYearBox(QVBoxLayout *vbl, QWidget *parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);

    createFormLayout("Da: ", from, boxLayout, parent);
    createFormLayout("A: ", to, boxLayout, parent);

    QGroupBox *groupBox = new QGroupBox("Seleziona l'intervallo di anni:", parent);
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
}

void LineChartDialog::createFormDialogLayout(QWidget *parent) {
    QVBoxLayout *dialogLayout = new QVBoxLayout(parent);

    createDescriptionBox(dialogLayout, desc_option1, parent);

    createYearBox(dialogLayout, parent);
    createGenreQCBBox(dialogLayout, parent);

    // button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout(parent);
    buttonLayout->addWidget(getAddBtn());
    buttonLayout->setAlignment(Qt::AlignRight);

    dialogLayout->addLayout(buttonLayout);

    setLayout(dialogLayout);
}

void LineChartDialog::resetComponents() {
    ChartDialog::resetComponents();

    genreRB->setChecked(false);
    genreCB->setEnabled(false);
}

QRadioButton *LineChartDialog::getGenreRB() const { return genreRB; }

void LineChartDialog::enableComponents() {
    if (genreRB->isChecked())
        genreCB->setEnabled(true);
    else
        genreCB->setEnabled(false);
}

uint LineChartDialog::getYearFrom() const { return from->date().year(); }
uint LineChartDialog::getYearTo() const { return to->date().year(); }

std::string LineChartDialog::getGenreSelected() const { return genreCB->currentText().toStdString(); }
