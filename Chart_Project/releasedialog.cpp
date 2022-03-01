#include "releasedialog.h"

ReleaseDialog::ReleaseDialog(QWidget* parent) : FormDialog(parent),
                                                toPublicCB(new QComboBox(parent)),
                                                //releaseBox(new QGroupBox("Info Pubblicazione")),
                                                releaseDE(new QDateEdit(parent)),

                                                // INT VALIDATOR
                                                // MOSTRARE I PREZZI
                                                cdCKB(new QCheckBox("CD", parent)),
                                                vnlCKB(new QCheckBox("Vinile", parent)),
                                                cstCKB(new QCheckBox("Cassetta",parent)),
                                                cdEdit(new QLineEdit(parent)),
                                                vnlEdit(new QLineEdit(parent)),
                                                cstEdit(new QLineEdit(parent)),

                                                sptfCKB(new QCheckBox("Spotify", parent)),
                                                applmCKB(new QCheckBox("Apple Music", parent)),
                                                tdlCKB(new QCheckBox("Tidal", parent)),
                                                dzrCKB(new QCheckBox("Deezer", parent)),
                                                ytmCKB(new QCheckBox("YouTube Music", parent)),
                                                amzCKB(new QCheckBox("Amazon Music", parent)),
                                                sptfEdit(new QLineEdit(parent)),
                                                applmEdit(new QLineEdit(parent)),
                                                tdlEdit(new QLineEdit(parent)),
                                                dzrEdit(new QLineEdit(parent)),
                                                ytmEdit(new QLineEdit(parent)),
                                                amzEdit(new QLineEdit(parent)),

                                                musicToPublic(QStringList())
{
    setAddBtn("Pubblica");

    releaseDE->setMaximumDate(QDate::currentDate());

    cdEdit->setDisabled(true);
    cdEdit->setValidator(new QIntValidator(parent));

    vnlEdit->setDisabled(true);
    vnlEdit->setValidator(new QIntValidator(parent));

    cstEdit->setDisabled(true);
    cstEdit->setValidator(new QIntValidator(parent));

    sptfEdit->setDisabled(true);
    sptfEdit->setValidator(new QIntValidator(parent));

    applmEdit->setDisabled(true);
    applmEdit->setValidator(new QIntValidator(parent));

    tdlEdit->setDisabled(true);
    tdlEdit->setValidator(new QIntValidator(parent));

    dzrEdit->setDisabled(true);
    dzrEdit->setValidator(new QIntValidator(parent));

    ytmEdit->setDisabled(true);
    ytmEdit->setValidator(new QIntValidator(parent));

    amzEdit->setDisabled(true);
    amzEdit->setValidator(new QIntValidator(parent));
}

uint ReleaseDialog::getToPublicIndexItem() const { return toPublicCB->currentIndex(); }

const QDate ReleaseDialog::getReleaseDate() const { return releaseDE->date(); }

const QCheckBox *ReleaseDialog::getcdCKB() const { return cdCKB; }
const QCheckBox *ReleaseDialog::getvnlCKB() const { return vnlCKB; }
const QCheckBox *ReleaseDialog::getcstCKB() const { return cstCKB; }

const QCheckBox *ReleaseDialog::getsptfCKB() const { return sptfCKB; }
const QCheckBox *ReleaseDialog::getapplmCKB() const { return applmCKB; }
const QCheckBox *ReleaseDialog::gettdlCKB() const { return tdlCKB; }
const QCheckBox *ReleaseDialog::getdzrCKB() const { return dzrCKB; }
const QCheckBox *ReleaseDialog::getytmCKB() const { return ytmCKB; }
const QCheckBox *ReleaseDialog::getamzCKB() const { return amzCKB; }

void ReleaseDialog::createLine(QWidget *ckb, QWidget *lineEdit, QFormLayout *fl, QWidget* parent) {
    QHBoxLayout *line = new QHBoxLayout(parent);

    line->addWidget(ckb);
    line->addWidget(lineEdit);
    line->setSpacing(50);
    //line->setAlignment(ckb, Qt::AlignLeft);
    //line->setAlignment(lineEdit, Qt::AlignRight);

    fl->addItem(line);
}

void ReleaseDialog::createMediumLine(QWidget *ckb, QWidget *lineEdit, QVBoxLayout *vbl, QWidget* parent) {
    QFormLayout *formLayout = new QFormLayout(parent);
    formLayout->setFormAlignment(Qt::AlignAbsolute);
    createLine(ckb, lineEdit, formLayout);

    vbl->addLayout(formLayout);
}

void ReleaseDialog::createReleaseBox(QVBoxLayout *vbl, QWidget* parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);

   createFormLayout("Data Pubblicazione: ", releaseDE, boxLayout);

   QGroupBox *groupBox = new QGroupBox("Info Pubblicazione", parent);
   groupBox->setLayout(boxLayout);

   vbl->addWidget(groupBox);
}

void ReleaseDialog::createPMBox(QVBoxLayout *vbl, QWidget* parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);
    // cd line
    createMediumLine(cdCKB, cdEdit, boxLayout, parent);
    // vinyl line
    createMediumLine(vnlCKB, vnlEdit, boxLayout, parent);
    // cassette line
    createMediumLine(cstCKB, cstEdit, boxLayout, parent);

    QGroupBox *groupBox = new QGroupBox("Supporti Fisici", parent);
    groupBox->setLayout(boxLayout);
    //groupBox->setDisabled(true);

    vbl->addWidget(groupBox);
}

void ReleaseDialog::createDMBox(QVBoxLayout *vbl, QWidget* parent) {
    QVBoxLayout *boxLayout = new QVBoxLayout(parent);
    // spotify line
    createMediumLine(sptfCKB, sptfEdit, boxLayout, parent);
    // apple music line
    createMediumLine(applmCKB, applmEdit, boxLayout, parent);
    // tidal line
    createMediumLine(tdlCKB, tdlEdit, boxLayout, parent);
    // deezer line
    createMediumLine(dzrCKB, dzrEdit, boxLayout, parent);
    // youtube music line
    createMediumLine(ytmCKB, ytmEdit, boxLayout, parent);
    // amazon music line
    createMediumLine(amzCKB, amzEdit, boxLayout, parent);

    QGroupBox *groupBox = new QGroupBox("Piattaforme Digitali", parent);
    groupBox->setLayout(boxLayout);
    //groupBox->setDisabled(true);

    vbl->addWidget(groupBox);
}

void ReleaseDialog::setMusicToPublic(const QVector<const Music *> &notReleased) {
    musicToPublic.clear();
    toPublicCB->clear();
    for (auto it = notReleased.begin(); it != notReleased.end(); ++it)
        musicToPublic.push_back(QString::fromStdString((*it)->getInfo()));  // DA SISTEMARE

    toPublicCB->addItems(musicToPublic);
}

void ReleaseDialog::createFormDialogLayout(QWidget* parent) {
    QVBoxLayout *dialogLayout = new QVBoxLayout(parent);

    dialogLayout->addWidget(toPublicCB);
    // add Release Box
    createReleaseBox(dialogLayout, parent);
    // add PhisycalMedium Box
    createPMBox(dialogLayout, parent);
    // add DigitalMedium Box
    createDMBox(dialogLayout, parent);

    // button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout(parent);
    buttonLayout->addWidget(getAddBtn());
    //buttonLayout->addWidget(getCancBtn());
    buttonLayout->setAlignment(Qt::AlignRight);

    dialogLayout->addLayout(buttonLayout);

    setLayout(dialogLayout);
}

void ReleaseDialog::enableComponents() {
    if (cdCKB->isChecked())
        cdEdit->setDisabled(false);
    else
        cdEdit->setDisabled(true);

    if (vnlCKB->isChecked())
        vnlEdit->setDisabled(false);
    else
        vnlEdit->setDisabled(true);

    if(cstCKB->isChecked())
        cstEdit->setDisabled(false);
    else
        cstEdit->setDisabled(true);

    if(sptfCKB->isChecked())
        sptfEdit->setDisabled(false);
    else
        sptfEdit->setDisabled(true);

    if(applmCKB->isChecked())
        applmEdit->setDisabled(false);
    else
        applmEdit->setDisabled(true);

    if(tdlCKB->isChecked())
        tdlEdit->setDisabled(false);
    else
        tdlEdit->setDisabled(true);

    if(dzrCKB->isChecked())
        dzrEdit->setDisabled(false);
    else
        dzrEdit->setDisabled(true);

    if(ytmCKB->isChecked())
        ytmEdit->setDisabled(false);
    else
        ytmEdit->setDisabled(true);

    if(amzCKB->isChecked())
        amzEdit->setDisabled(false);
    else
        amzEdit->setDisabled(true);
}

bool ReleaseDialog::checkLine(const QCheckBox *cb, const QLineEdit *le, const QString &message) const {
    if (cb->isChecked()) {
        if (!le->text().isEmpty())
            return true;
        else {
            QMessageBox::warning(const_cast<QLineEdit*>(le), tr("Campi vuoti"), "Campo " + message + " necessario", QMessageBox::Ok);
            return false;
        }
    }
    return false;
}

bool ReleaseDialog::checkLineEdit(const QLineEdit *le) const {
    return le->isEnabled() && !le->text().isEmpty();
}

/*
bool ReleaseDialog::checkPMInput() const {
    return  checkLine(cdCKB, cdEdit, "vendite") ||
            checkLine(vnlCKB, vnlEdit, "vendite") ||
            checkLine(cstCKB, cstEdit, "vendite");
}

bool ReleaseDialog::checkDMInput() const {
    return  checkLine(sptfCKB, sptfEdit, "ascolti") ||
            checkLine(applmCKB, applmEdit, "ascolti") ||
            checkLine(tdlCKB, tdlEdit, "ascolti") ||
            checkLine(dzrCKB, dzrEdit, "ascolti") ||
            checkLine(ytmCKB, ytmEdit, "ascolti") ||
            checkLine(amzCKB, amzEdit, "ascolti");
}
*/
void ReleaseDialog::resetComponents() {
    releaseDE->clear();

    cdCKB->setChecked(false);
    vnlCKB->setChecked(false);
    cstCKB->setChecked(false);

    cdEdit->clear();
    vnlEdit->clear();
    cstEdit->clear();

    sptfCKB->setChecked(false);;
    applmCKB->setChecked(false);
    tdlCKB->setChecked(false);
    dzrCKB->setChecked(false);
    ytmCKB->setChecked(false);
    amzCKB->setChecked(false);

    sptfEdit->clear();
    applmEdit->clear();
    tdlEdit->clear();
    dzrEdit->clear();
    ytmEdit->clear();
    amzEdit->clear();
}

bool  ReleaseDialog::isAllUnchecked() const{
    return  !cdCKB->isChecked() &&
            !vnlCKB->isChecked() &&
            !cstCKB->isChecked() &&
            !sptfCKB->isChecked() &&
            !applmCKB->isChecked() &&
            !tdlCKB->isChecked() &&
            !dzrCKB->isChecked() &&
            !amzCKB->isChecked();
}

bool ReleaseDialog::isAllEmpty() const {
    return  cdEdit->text().isEmpty() &&
            vnlEdit->text().isEmpty() &&
            cstEdit->text().isEmpty() &&
            sptfEdit->text().isEmpty() &&
            applmEdit->text().isEmpty() &&
            tdlEdit->text().isEmpty() &&
            dzrEdit->text().isEmpty() &&
            amzEdit->text().isEmpty();
}

// PRE : almeno una edit line non vuota
std::vector<const Release*> ReleaseDialog::getInput(const std::vector<const Music*> &not_released) {
    std::vector<const Release*> result;

    auto selectedMusic = not_released.at(getToPublicIndexItem());
    cout << "SELECTED ITEM : " << selectedMusic->getInfo() << endl;

    // controllo validita' della data di pubblicazione delegata a RecordLabel
    // ricorda infatti di implementare le eccezioni e catturarle
    uint day(getReleaseDate().day());
    uint month(getReleaseDate().month());
    uint year(getReleaseDate().year());

    uint numbers(0);

    if (checkLineEdit(cdEdit)){
        cout << "cd line" << endl;
        numbers = cdEdit->text().toUInt();
        result.push_back(new PhisycalMedium(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), CD, numbers));
    }
    if (checkLineEdit(vnlEdit)) {
        cout << "vinile line" << endl;
        numbers = vnlEdit->text().toUInt();
        result.push_back(new PhisycalMedium(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Vinile, numbers));
    }
    if (checkLineEdit(cstEdit)) {
        cout << "cassetta line" << endl;
        numbers = cstEdit->text().toUInt();
        result.push_back(new PhisycalMedium(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Cassetta, numbers));
    }
    // DM
    if(checkLineEdit(sptfEdit)){
        cout << "spotify line" << endl;
        numbers = sptfEdit->text().toUInt();
        result.push_back(new DigitalMedium(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Spotify, numbers));
    }
    if(checkLineEdit(applmEdit)){
        cout << "apple music line" << endl;
        numbers = applmEdit->text().toUInt();
        result.push_back(new DigitalMedium(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), AppleMusic, numbers));
    }
    if(checkLineEdit(tdlEdit)){
        cout << "tidal line" << endl;
        numbers = tdlEdit->text().toUInt();
        result.push_back(new DigitalMedium(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Tidal, numbers));
    }
    if(checkLineEdit(dzrEdit)){
        cout << "deezer line" << endl;
        numbers = dzrEdit->text().toUInt();
        result.push_back(new DigitalMedium(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), Deezer, numbers));
    }
    if(checkLineEdit(ytmEdit)){
        cout << "youtube music line" << endl;
        numbers = ytmEdit->text().toUInt();
        result.push_back(new DigitalMedium(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), YoutubeMusic, numbers));
    }
    if(checkLineEdit(amzEdit)){
        cout << "amazon music line" << endl;
        numbers = amzEdit->text().toUInt();
        result.push_back(new DigitalMedium(selectedMusic->getGenre(), selectedMusic->getName(), selectedMusic->getArtist(), Date(day, month, year), AmazonMusic, numbers));
    }
    return result;
}
// POST : ritorno result non vuoto
