#include "customformdialog.h"

CustomFormDialog::CustomFormDialog() : nameEdit(new QLineEdit()),
                                       artistEdit(new QLineEdit()),
                                       genreEdit(new QLineEdit()),

                                       //releaseBox(new QGroupBox("Info Pubblicazione")),
                                       releaseDE(new QDateEdit()),

                                       // INT VALIDATOR
                                       // MOSTRARE I PREZZI
                                       //pmBox(new QGroupBox("Info Supporti Fisici")),
                                       cdCKB(new QCheckBox("CD")),
                                       vnlCKB(new QCheckBox("Vinile")),
                                       cstCKB(new QCheckBox("Cassetta")),
                                       cdEdit(new QLineEdit()),
                                       vnlEdit(new QLineEdit()),
                                       cstEdit(new QLineEdit()),

                                       //dmBox(new QGroupBox("Info Piattaforme Digitali")),
                                       sptfCKB(new QCheckBox("Spotify")),
                                       applmCKB(new QCheckBox("Apple Music")),
                                       tdlCKB(new QCheckBox("Tidal")),
                                       dzrCKB(new QCheckBox("Deezer")),
                                       ytmCKB(new QCheckBox("YouTube Music")),
                                       amzCKB(new QCheckBox("Amazon Music")),
                                       sptfEdit(new QLineEdit()),
                                       applmEdit(new QLineEdit()),
                                       tdlEdit(new QLineEdit()),
                                       dzrEdit(new QLineEdit()),
                                       ytmEdit(new QLineEdit()),
                                       amzEdit(new QLineEdit()),

                                       btn_add(new QPushButton("Aggiungi")),
                                       btn_cancel(new QPushButton("Cancella"))
{
    // init
    releaseDE->setMaximumDate(QDate::currentDate());

    cdEdit->setDisabled(true);
    cdEdit->setValidator(new QIntValidator());

    vnlEdit->setDisabled(true);
    vnlEdit->setValidator(new QIntValidator());

    cstEdit->setDisabled(true);
    cstEdit->setValidator(new QIntValidator());

    sptfEdit->setDisabled(true);
    sptfEdit->setValidator(new QIntValidator());

    applmEdit->setDisabled(true);
    applmEdit->setValidator(new QIntValidator());

    tdlEdit->setDisabled(true);
    tdlEdit->setValidator(new QIntValidator());

    dzrEdit->setDisabled(true);
    dzrEdit->setValidator(new QIntValidator());

    ytmEdit->setDisabled(true);
    ytmEdit->setValidator(new QIntValidator());

    amzEdit->setDisabled(true);
    amzEdit->setValidator(new QIntValidator());

    //btn_add->setDisabled(true);

    //resize(QSize(500, 500));
    setModal(true);
    //createDialogLayout();
}

const QPushButton *CustomFormDialog::getAddbtn() const { return btn_add; }
const QPushButton *CustomFormDialog::getCancbtn() const { return btn_cancel; }

const QLineEdit *CustomFormDialog::getNameEdit() const { return nameEdit; }
const QLineEdit *CustomFormDialog::getArtistEdit() const { return artistEdit; }
const QLineEdit *CustomFormDialog::getGenreEdit() const { return  genreEdit; }

const QDateEdit *CustomFormDialog::getReleaseDE() const { return releaseDE; }

const QCheckBox *CustomFormDialog::getcdCKB() const { return cdCKB; }
const QCheckBox *CustomFormDialog::getvnlCKB() const { return vnlCKB; }
const QCheckBox *CustomFormDialog::getcstCKB() const { return cstCKB; }

const QLineEdit *CustomFormDialog::getCdEdit() const { return  cdEdit; }
const QLineEdit *CustomFormDialog::getVnlEdit() const { return vnlEdit; }
const QLineEdit *CustomFormDialog::getCstEdit() const { return cstEdit; }

const QCheckBox *CustomFormDialog::getsptfCKB() const { return sptfCKB; }
const QCheckBox *CustomFormDialog::getapplmCKB() const { return applmCKB; }
const QCheckBox *CustomFormDialog::gettdlCKB() const { return tdlCKB; }
const QCheckBox *CustomFormDialog::getdzrCKB() const { return dzrCKB; }
const QCheckBox *CustomFormDialog::getytmCKB() const { return ytmCKB; }
const QCheckBox *CustomFormDialog::getamzCKB() const { return amzCKB; }

const QLineEdit *CustomFormDialog::getSptfEdit() const { return sptfEdit; }
const QLineEdit *CustomFormDialog::getApplmEdit() const { return applmEdit; }
const QLineEdit *CustomFormDialog::getTdlEdit() const { return tdlEdit; }
const QLineEdit *CustomFormDialog::getDzrEdit() const { return dzrEdit; }
const QLineEdit *CustomFormDialog::getYtmEdit() const { return ytmEdit; }
const QLineEdit *CustomFormDialog::getAmzEdit() const { return amzEdit; }

void CustomFormDialog::createFormLayout(const QString &label, QWidget *w, QVBoxLayout *vbl) {
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setFormAlignment(Qt::AlignAbsolute);
    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->setAlignment(w, Qt::AlignRight);

    formLayout->addRow(label, w);
    vbl->addLayout(formLayout);
}

void CustomFormDialog::createLine(QWidget *ckb, QWidget *lineEdit, QFormLayout *fl) {
    QHBoxLayout *line = new QHBoxLayout();

    line->addWidget(ckb);
    line->addWidget(lineEdit);
    line->setSpacing(50);
    //line->setAlignment(ckb, Qt::AlignLeft);
    //line->setAlignment(lineEdit, Qt::AlignRight);

    fl->addItem(line);
}

void CustomFormDialog::createMediumLine(QWidget *ckb, QWidget *lineEdit, QVBoxLayout *vbl) {
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setFormAlignment(Qt::AlignAbsolute);
    createLine(ckb, lineEdit, formLayout);

    vbl->addLayout(formLayout);
}

void CustomFormDialog::createMusicBox(QVBoxLayout *vbl) {
    QVBoxLayout *boxLayout = new QVBoxLayout();

    createFormLayout("Nome: ", nameEdit, boxLayout);
    createFormLayout("Artista: ", artistEdit, boxLayout);
    createFormLayout("Genere: ", genreEdit, boxLayout);

    QGroupBox *groupBox = new QGroupBox("Info Musica");
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
}

void CustomFormDialog::createReleaseBox(QVBoxLayout *vbl) {
     QVBoxLayout *boxLayout = new QVBoxLayout();

    createFormLayout("Data Pubblicazione: ", releaseDE, boxLayout);

    //releaseBox->setLayout(boxLayout);
    //releaseBox->setDisabled(true);


    QGroupBox *groupBox = new QGroupBox("Info Pubblicazione");
    groupBox->setLayout(boxLayout);
    //groupBox->setDisabled(true);

    vbl->addWidget(groupBox);

    //vbl->addWidget(releaseBox);
}

void CustomFormDialog::createPMBox(QVBoxLayout *vbl) {
    QVBoxLayout *boxLayout = new QVBoxLayout();
    // cd line
    createMediumLine(cdCKB, cdEdit, boxLayout);
    // vinyl line
    createMediumLine(vnlCKB, vnlEdit, boxLayout);
    // cassette line
    createMediumLine(cstCKB, cstEdit, boxLayout);

    QGroupBox *groupBox = new QGroupBox("Info Supporti Fisici");
    groupBox->setLayout(boxLayout);
    //groupBox->setDisabled(true);

    vbl->addWidget(groupBox);
}

void CustomFormDialog::createDMBox(QVBoxLayout *vbl) {
    QVBoxLayout *boxLayout = new QVBoxLayout();
    // spotify line
    createMediumLine(sptfCKB, sptfEdit, boxLayout);
    // apple music line
    createMediumLine(applmCKB, applmEdit, boxLayout);
    // tidal line
    createMediumLine(tdlCKB, tdlEdit, boxLayout);
    // deezer line
    createMediumLine(dzrCKB, dzrEdit, boxLayout);
    // youtube music line
    createMediumLine(ytmCKB, ytmEdit, boxLayout);
    // amazon music line
    createMediumLine(amzCKB, amzEdit, boxLayout);

    QGroupBox *groupBox = new QGroupBox("Info Piattaforme Digitali");
    groupBox->setLayout(boxLayout);
    //groupBox->setDisabled(true);

    vbl->addWidget(groupBox);
}

void CustomFormDialog::createAddMusicLayout() {
    QVBoxLayout *dialogLayout = new QVBoxLayout();

    // add Music Box
    createMusicBox(dialogLayout);

    // button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(btn_add);
    buttonLayout->addWidget(btn_cancel);
    buttonLayout->setAlignment(Qt::AlignRight);

    dialogLayout->addLayout(buttonLayout);

    setLayout(dialogLayout);
}

void CustomFormDialog::createReleaseMusicLayout(const QVector<const Music*> *notReleased) {
    QVBoxLayout *dialogLayout = new QVBoxLayout();

    // add combobox with not releases music

    // add Release Box
    createReleaseBox(dialogLayout);
    // add PhisycalMedium Box
    createPMBox(dialogLayout);
    // add DigitalMedium Box
    createDMBox(dialogLayout);

    // button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(btn_add);
    buttonLayout->addWidget(btn_cancel);
    buttonLayout->setAlignment(Qt::AlignRight);

    dialogLayout->addLayout(buttonLayout);

    setLayout(dialogLayout);
}

void CustomFormDialog::enableReleaseComponents() {
    //if (publicRB->isChecked())
        // enable release layout
    //else
        // disable release layout

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

void CustomFormDialog::enableAddBtn() {
    // DA RIVEDERE
    /*
    if(checkMusicInput())
        btn_add->setDisabled(false);
    else
        btn_add->setDisabled(true);
        */
}

bool CustomFormDialog::checkLine(const QCheckBox *cb, const QLineEdit *le, const QString &message) const {
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

bool CustomFormDialog::checkMusicInput() const {
    return  !nameEdit->text().isEmpty() &&
            !artistEdit->text().isEmpty() &&
            !genreEdit->text().isEmpty();
}

bool CustomFormDialog::checkPMInput() const {
    return  checkLine(cdCKB, cdEdit, "vendite") ||
            checkLine(vnlCKB, vnlEdit, "vendite") ||
            checkLine(cstCKB, cstEdit, "vendite");
}

bool CustomFormDialog::checkDMInput() const {
    return  checkLine(sptfCKB, sptfEdit, "ascolti") ||
            checkLine(applmCKB, applmEdit, "ascolti") ||
            checkLine(tdlCKB, tdlEdit, "ascolti") ||
            checkLine(dzrCKB, dzrEdit, "ascolti") ||
            checkLine(ytmCKB, ytmEdit, "ascolti") ||
            checkLine(amzCKB, amzEdit, "ascolti");
}

void CustomFormDialog::resetComponents() {
    nameEdit->clear();
    artistEdit->clear();
    genreEdit->clear();

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

/*



void Viewer::getDataInput() {
    string name = nameEdit->text().toStdString();
    string genre = genreEdit->text().toStdString();
    string artist = artistEdit->text().toStdString();

    // prelevare sse selezionato 'to public'
    uint day = releaseDE->date().day();
    uint month = releaseDE->date().month();
    uint year = releaseDE->date().year();

    // prelevare sse selezionato almeno un supporto
    QList<Support> *ls = new QList<Support>();


void Viewer::showEditLine() {
    if (cdCKB->isChecked())
        cdSalesEdit->setDisabled(false);
    else
        cdSalesEdit->setDisabled(true);

    if (vnlCKB->isChecked())
        vnlSalesEdit->setDisabled(false);
    else
        vnlSalesEdit->setDisabled(true);

    if(cstCKB->isChecked())
        cstSalesEdit->setDisabled(false);
    else
        cstSalesEdit->setDisabled(true);

    if(spotifyCKB->isChecked())
        spoListenersEdit->setDisabled(false);
    else
        spoListenersEdit->setDisabled(true);

    if(appMusicCKB->isChecked())
        appMListenersEdit->setDisabled(false);
    else
        appMListenersEdit->setDisabled(true);

    if(tidalCKB->isChecked())
        tidListenersEdit->setDisabled(false);
    else
        tidListenersEdit->setDisabled(true);

    if(deezerCKB->isChecked())
        deeListenersEdit->setDisabled(false);
    else
        deeListenersEdit->setDisabled(true);

    if(youMusicCKB->isChecked())
        youListenersEdit->setDisabled(false);
    else
        youListenersEdit->setDisabled(true);

    if(amMusicCKB->isChecked())
        AmListenersEdit->setDisabled(false);
    else
        AmListenersEdit->setDisabled(true);

}



void Viewer::showFormDialog() { formDialog->show(); }

void Viewer::closeFormDialog() { formDialog->close(); }


}

*/
