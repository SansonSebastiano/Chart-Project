#include "releasedialog.h"

ReleaseDialog::ReleaseDialog(QWidget* parent) : FormDialog(parent),
                                                toPublicCB(new QComboBox()),
                                                //releaseBox(new QGroupBox("Info Pubblicazione")),
                                                releaseDE(new QDateEdit()),

                                                // INT VALIDATOR
                                                // MOSTRARE I PREZZI
                                                cdCKB(new QCheckBox("CD")),
                                                vnlCKB(new QCheckBox("Vinile")),
                                                cstCKB(new QCheckBox("Cassetta")),
                                                cdEdit(new QLineEdit()),
                                                vnlEdit(new QLineEdit()),
                                                cstEdit(new QLineEdit()),

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

                                                musicToPublic(QStringList())
{
    setAddBtn("Pubblica");

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
}

const QComboBox *ReleaseDialog::getToPubliCB() const { return toPublicCB; }

const QDateEdit *ReleaseDialog::getReleaseDE() const { return releaseDE; }

const QCheckBox *ReleaseDialog::getcdCKB() const { return cdCKB; }
const QCheckBox *ReleaseDialog::getvnlCKB() const { return vnlCKB; }
const QCheckBox *ReleaseDialog::getcstCKB() const { return cstCKB; }

const QLineEdit *ReleaseDialog::getCdEdit() const { return  cdEdit; }
const QLineEdit *ReleaseDialog::getVnlEdit() const { return vnlEdit; }
const QLineEdit *ReleaseDialog::getCstEdit() const { return cstEdit; }

const QCheckBox *ReleaseDialog::getsptfCKB() const { return sptfCKB; }
const QCheckBox *ReleaseDialog::getapplmCKB() const { return applmCKB; }
const QCheckBox *ReleaseDialog::gettdlCKB() const { return tdlCKB; }
const QCheckBox *ReleaseDialog::getdzrCKB() const { return dzrCKB; }
const QCheckBox *ReleaseDialog::getytmCKB() const { return ytmCKB; }
const QCheckBox *ReleaseDialog::getamzCKB() const { return amzCKB; }

const QLineEdit *ReleaseDialog::getSptfEdit() const { return sptfEdit; }
const QLineEdit *ReleaseDialog::getApplmEdit() const { return applmEdit; }
const QLineEdit *ReleaseDialog::getTdlEdit() const { return tdlEdit; }
const QLineEdit *ReleaseDialog::getDzrEdit() const { return dzrEdit; }
const QLineEdit *ReleaseDialog::getYtmEdit() const { return ytmEdit; }
const QLineEdit *ReleaseDialog::getAmzEdit() const { return amzEdit; }


void ReleaseDialog::createLine(QWidget *ckb, QWidget *lineEdit, QFormLayout *fl) {
    QHBoxLayout *line = new QHBoxLayout();

    line->addWidget(ckb);
    line->addWidget(lineEdit);
    line->setSpacing(50);
    //line->setAlignment(ckb, Qt::AlignLeft);
    //line->setAlignment(lineEdit, Qt::AlignRight);

    fl->addItem(line);
}

void ReleaseDialog::createMediumLine(QWidget *ckb, QWidget *lineEdit, QVBoxLayout *vbl) {
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setFormAlignment(Qt::AlignAbsolute);
    createLine(ckb, lineEdit, formLayout);

    vbl->addLayout(formLayout);
}

void ReleaseDialog::createReleaseBox(QVBoxLayout *vbl) {
    QVBoxLayout *boxLayout = new QVBoxLayout();

   createFormLayout("Data Pubblicazione: ", releaseDE, boxLayout);

   QGroupBox *groupBox = new QGroupBox("Info Pubblicazione");
   groupBox->setLayout(boxLayout);

   vbl->addWidget(groupBox);
}

void ReleaseDialog::createPMBox(QVBoxLayout *vbl) {
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

void ReleaseDialog::createDMBox(QVBoxLayout *vbl) {
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

const QStringList ReleaseDialog::getMusicToPublic() const { return musicToPublic; }

void ReleaseDialog::setMusicToPublic(const QVector<const Music *> &notReleased) {
    for (auto it = notReleased.begin(); it != notReleased.end(); ++it)
        musicToPublic.push_back(QString::fromStdString((*it)->getInfo()));
}

void ReleaseDialog::createReleaseMusicLayout(const QVector<const Music*> &notReleased) {
    QVBoxLayout *dialogLayout = new QVBoxLayout();

    // add combobox with not releases music
    setMusicToPublic(notReleased);
    toPublicCB->addItems(getMusicToPublic());
    dialogLayout->addWidget(toPublicCB);
    // add Release Box
    createReleaseBox(dialogLayout);
    // add PhisycalMedium Box
    createPMBox(dialogLayout);
    // add DigitalMedium Box
    createDMBox(dialogLayout);

    // button layout
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(getAddBtn());
    buttonLayout->addWidget(getCancBtn());
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
