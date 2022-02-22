#include "musicdialog.h"

MusicDialog::MusicDialog(QWidget* parent) :     FormDialog(parent),
                                                nameEdit(new QLineEdit()),
                                                artistEdit(new QLineEdit()),
                                                genreEdit(new QLineEdit())
{
    setAddBtn("Aggiungi");
}

const QLineEdit *MusicDialog::getNameEdit() const { return nameEdit; }
const QLineEdit *MusicDialog::getArtistEdit() const { return artistEdit; }
const QLineEdit *MusicDialog::getGenreEdit() const { return  genreEdit; }

void MusicDialog::createMusicBox(QVBoxLayout *vbl) {
    QVBoxLayout *boxLayout = new QVBoxLayout();

    createFormLayout("Nome: ", nameEdit, boxLayout);
    createFormLayout("Artista: ", artistEdit, boxLayout);
    createFormLayout("Genere: ", genreEdit, boxLayout);

    QGroupBox *groupBox = new QGroupBox("Info Musica");
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
}

void MusicDialog::createAddMusicLayout() {
    QVBoxLayout *dialogLayout = new QVBoxLayout();

    // add Music Box
    createMusicBox(dialogLayout);

    // button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();
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
