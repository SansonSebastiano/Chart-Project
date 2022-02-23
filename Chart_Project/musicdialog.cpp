#include "musicdialog.h"

MusicDialog::MusicDialog(QWidget* parent) :     FormDialog(parent),
                                                nameEdit(new QLineEdit(parent)),
                                                artistEdit(new QLineEdit(parent)),
                                                genreEdit(new QLineEdit(parent))
{
    setAddBtn("Aggiungi");
}

const QLineEdit *MusicDialog::getNameEdit() const { return nameEdit; }
const QLineEdit *MusicDialog::getArtistEdit() const { return artistEdit; }
const QLineEdit *MusicDialog::getGenreEdit() const { return  genreEdit; }

void MusicDialog::createMusicBox(QVBoxLayout *vbl, QWidget* parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);

    createFormLayout("Nome: ", nameEdit, boxLayout);
    createFormLayout("Artista: ", artistEdit, boxLayout);
    createFormLayout("Genere: ", genreEdit, boxLayout);

    QGroupBox *groupBox = new QGroupBox("Info Musica", parent);
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
}

void MusicDialog::createAddMusicLayout(QWidget* parent) {
    QVBoxLayout *dialogLayout = new QVBoxLayout(parent);

    // add Music Box
    createMusicBox(dialogLayout, parent);

    // button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout(parent);
    buttonLayout->addWidget(getAddBtn());
    buttonLayout->addWidget(getCancBtn());
    buttonLayout->setAlignment(Qt::AlignRight);

    dialogLayout->addLayout(buttonLayout);

    setLayout(dialogLayout);
}

bool MusicDialog::checkMusicInput() const {
    return  !nameEdit->text().isEmpty() &&
            !artistEdit->text().isEmpty() &&
            !genreEdit->text().isEmpty();
}

void MusicDialog::resetComponents() {
    nameEdit->clear();
    artistEdit->clear();
    genreEdit->clear();
}
