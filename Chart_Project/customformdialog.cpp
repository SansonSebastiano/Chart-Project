#include "customformdialog.h"

CustomFormDialog::CustomFormDialog() : nameEdit(new QLineEdit()),
                                       artistEdit(new QLineEdit()),
                                       genreEdit(new QLineEdit()),

                                       publicRB(new QRadioButton("Pubblica")),

                                       releaseDE(new QDateEdit()),

                                       cdCKB(new QCheckBox("CD")),
                                       vnlCKB(new QCheckBox("Vinile")),
                                       cstCKB(new QCheckBox("Cassetta")),
                                       cdEdit(new QLineEdit("Vendite")),
                                       vnlEdit(new QLineEdit("Vendite")),
                                       cstEdit(new QLineEdit("Vendite")),

                                       sptfCKB(new QCheckBox("Spotify")),
                                       applmCKB(new QCheckBox("Apple Music")),
                                       tdlCKB(new QCheckBox("Tidal")),
                                       dzrCKB(new QCheckBox("Deezer")),
                                       ytmCKB(new QCheckBox("YouTube Music")),
                                       amzCKB(new QCheckBox("Amazon Music")),
                                       sptfEdit(new QLineEdit("Ascolti")),
                                       applmEdit(new QLineEdit("Ascolti")),
                                       tdlEdit(new QLineEdit("Ascolti")),
                                       dzrEdit(new QLineEdit("Ascolti")),
                                       ytmEdit(new QLineEdit("Ascolti")),
                                       amzEdit(new QLineEdit("Ascolti")),

                                       btn_add(new QPushButton("Aggiungi")),
                                       btn_cancel(new QPushButton("Cancella"))
{
    // init
    releaseDE->setMaximumDate(QDate::currentDate());

    cdEdit->setDisabled(true);
    vnlEdit->setDisabled(true);
    cstEdit->setDisabled(true);

    sptfEdit->setDisabled(true);
    applmEdit->setDisabled(true);
    tdlEdit->setDisabled(true);
    dzrEdit->setDisabled(true);
    ytmEdit->setDisabled(true);
    amzEdit->setDisabled(true);

    //btn_add->setDisabled(true);

    //resize(QSize(500, 500));
    setModal(true);
    createDialogLayout();
}

const QPushButton *CustomFormDialog::getAddbtn() const { return btn_add; }
const QPushButton *CustomFormDialog::getCancbtn() const { return btn_cancel; }

const QCheckBox *CustomFormDialog::getcdCKB() const { return cdCKB; }
const QCheckBox *CustomFormDialog::getvnlCKB() const { return vnlCKB; }
const QCheckBox *CustomFormDialog::getcstCKB() const { return cstCKB; }

const QCheckBox *CustomFormDialog::getsptfCKB() const { return sptfCKB; }
const QCheckBox *CustomFormDialog::getapplmCKB() const { return applmCKB; }
const QCheckBox *CustomFormDialog::gettdlCKB() const { return tdlCKB; }
const QCheckBox *CustomFormDialog::getdzrCKB() const { return dzrCKB; }
const QCheckBox *CustomFormDialog::getytmCKB() const { return ytmCKB; }
const QCheckBox *CustomFormDialog::getamzCKB() const { return amzCKB; }

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
    line->setContentsMargins(0, 0, 0, 0);
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

    QGroupBox *groupBox = new QGroupBox("Info Pubblicazione");
    groupBox->setLayout(boxLayout);

    vbl->addWidget(groupBox);
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

    vbl->addWidget(groupBox);
}

void CustomFormDialog::createDialogLayout() {
    QVBoxLayout *dialogLayout = new QVBoxLayout();

    // add Music Box
    createMusicBox(dialogLayout);
    // add to public possibility
    createFormLayout("", publicRB, dialogLayout);
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

void CustomFormDialog::enableComponents() {
    //if (publicRB->isChecked())
        // enable release layout
    //else
        // disable release layout
    /*
    if(!nameEdit->text().isEmpty() && !artistEdit->text().isEmpty() && !genreEdit->text().isEmpty())
        btn_add->setDisabled(false);
    else
        btn_add->setDisabled(true);
        */

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

/*


    // SIGNAL E SLOT
    connect(btn_cancel, SIGNAL(clicked()), controller, SLOT(closeDialog()));
    connect(btn_add, SIGNAL(clicked()), controller, SLOT(addMusic()));
    // checkbox signal & slot
    connect(cdCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(vnlCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(cstCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));

    connect(spotifyCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(appMusicCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(tidalCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(deezerCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(youMusicCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));
    connect(amMusicCKB, SIGNAL(stateChanged(int)), controller, SLOT(showTextEdit()));


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
