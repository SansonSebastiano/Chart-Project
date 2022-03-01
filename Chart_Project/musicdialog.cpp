#include "musicdialog.h"

MusicDialog::MusicDialog(QWidget* parent) :     FormDialog(parent),
                                                nameEdit(new QLineEdit(parent)),
                                                artistEdit(new QLineEdit(parent)),
                                                genreEdit(new QLineEdit(parent))
{
    setAddBtn("Aggiungi");
}

std::string MusicDialog::getInputName() const { return nameEdit->text().toStdString(); }
std::string MusicDialog::getInputArtist() const { return  artistEdit->text().toStdString(); }
std::string MusicDialog::getInputGenre() const { return genreEdit->text().toStdString(); }

void MusicDialog::createMusicBox(QVBoxLayout *vbl, QWidget* parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);

    createFormLayout("Nome: ", nameEdit, boxLayout);
    createFormLayout("Artista: ", artistEdit, boxLayout);
    createFormLayout("Genere: ", genreEdit, boxLayout);

    QGroupBox *groupBox = new QGroupBox("Info Musica", parent);
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
}

void MusicDialog::createFormDialogLayout(QWidget* parent) {
    QVBoxLayout *dialogLayout = new QVBoxLayout(parent);

    // add Music Box
    createMusicBox(dialogLayout, parent);

    // button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout(parent);
    buttonLayout->addWidget(getAddBtn());
    //buttonLayout->addWidget(getCancBtn());
    buttonLayout->setAlignment(Qt::AlignRight);

    dialogLayout->addLayout(buttonLayout);

    setLayout(dialogLayout);
}

bool MusicDialog::checkMusicInput() const {
    return  !nameEdit->text().isEmpty() &&
            !artistEdit->text().isEmpty() &&
            !genreEdit->text().isEmpty();
}

string MusicDialog::capitalizeInput(string input) {
    if (!input.empty()){
        input[0] = std::toupper(input[0]);

        for (uint i = 1; i < input.length(); ++i){
            if (input[i - 1] == ' ' || input[i - 1] == '.' || input[i - 1] == '-')
                input[i] = std::toupper(input[i]);
            else
                input[i] = std::tolower(input[i]);
        }
    }
    return input;
}

const Music* MusicDialog::getInput() {
    string name;
    string artist;
    string genre;

    // validazione
    if (checkMusicInput()){

        name = capitalizeInput(getInputName());
        artist = capitalizeInput(getInputArtist());
        genre = capitalizeInput(getInputGenre());

        return new Album(genre, name, artist);
    }
    return nullptr;
}

void MusicDialog::resetComponents() {
    nameEdit->clear();
    artistEdit->clear();
    genreEdit->clear();
}
