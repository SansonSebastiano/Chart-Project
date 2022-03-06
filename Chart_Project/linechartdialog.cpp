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
    to->setMaximumDate(QDate::currentDate());   // accetta come data massima: esattamente oggi
}

void LineChartDialog::setOptions() { }

void LineChartDialog::setGenreCB(const QStringList &genres) { genreCB->addItems(genres); }

void LineChartDialog::createGenreQCBBox(QVBoxLayout *vbl, QWidget *parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);

    // PRE: set genreCB
    createFormLayout(genreRB, genreCB, boxLayout, parent);
    // other rb buttons

    QGroupBox *groupBox = new QGroupBox("Scegli un opzione:", parent);
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
}

void LineChartDialog::createFormDialogLayout(QWidget *parent) {
    QVBoxLayout *dialogLayout = new QVBoxLayout(parent);

    createDescriptionBox(dialogLayout, desc_option1, parent);

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

void LineChartDialog::enableComponents() {
    if (genreRB->isChecked())
        genreCB->setEnabled(true);
    else
        genreCB->setEnabled(true);
}
