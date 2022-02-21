#ifndef CUSTOMFORMDIALOG_H
#define CUSTOMFORMDIALOG_H

#include <QDialog>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QList>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include <QMessageBox>

#include "release.h"

class CustomFormDialog : public QDialog{
private:
    // components
    // music info
    QLineEdit *nameEdit, *artistEdit, *genreEdit;
    // release info
    // add combobox with not releases music
    //QGroupBox *releaseBox;
    QDateEdit *releaseDE;
    // phisycal medium info
    //QGroupBox *pmBox;
    QCheckBox *cdCKB, *vnlCKB, *cstCKB;
    QLineEdit *cdEdit, *vnlEdit, *cstEdit;
    // digital medium info
    //QGroupBox *dmBox;
    QCheckBox *sptfCKB, *applmCKB, *tdlCKB, *dzrCKB, *ytmCKB, *amzCKB;
    QLineEdit *sptfEdit, *applmEdit, *tdlEdit, *dzrEdit, *ytmEdit, *amzEdit;
    // dialog's buttons
    QPushButton *btn_add, *btn_cancel;

    void createFormLayout(const QString &label, QWidget *w, QVBoxLayout *vbl);
    void createLine(QWidget *ckb, QWidget *lineEdit, QFormLayout *fl);
    void createMediumLine(QWidget *ckb, QWidget *lineEdit, QVBoxLayout *vbl);

    void createMusicBox(QVBoxLayout *vbl);
    void createReleaseBox(QVBoxLayout *vbl);
    void createPMBox(QVBoxLayout *vbl);
    void createDMBox(QVBoxLayout *vbl);
    
public:
    CustomFormDialog();
    ~CustomFormDialog() = default;

    void createAddMusicLayout();
    void createReleaseMusicLayout(const QVector<const Music*> *notReleased);

    const QPushButton* getAddbtn() const;
    const QPushButton* getCancbtn() const;

    const QLineEdit *getNameEdit() const;
    const QLineEdit *getArtistEdit() const;
    const QLineEdit *getGenreEdit() const;

    const QDateEdit *getReleaseDE() const;

    const QCheckBox* getcdCKB() const;
    const QCheckBox* getvnlCKB() const;
    const QCheckBox* getcstCKB() const;

    const QLineEdit *getCdEdit() const;
    const QLineEdit *getVnlEdit() const;
    const QLineEdit *getCstEdit() const;

    const QCheckBox* getsptfCKB() const;
    const QCheckBox* getapplmCKB() const;
    const QCheckBox* gettdlCKB() const;
    const QCheckBox* getdzrCKB() const;
    const QCheckBox* getytmCKB() const;
    const QCheckBox* getamzCKB() const;

    const QLineEdit *getSptfEdit() const;
    const QLineEdit *getApplmEdit() const;
    const QLineEdit *getTdlEdit() const;
    const QLineEdit *getDzrEdit() const;
    const QLineEdit *getYtmEdit() const;
    const QLineEdit *getAmzEdit() const;

    // add get release, pm n dm groupbox

    void enableReleaseComponents();
    void enableAddBtn();
    //void enableReleaseBoxes();

    bool checkLine(const QCheckBox *cb, const QLineEdit *le, const QString &message) const;
    bool checkMusicInput() const;
    bool checkPMInput() const;
    bool checkDMInput() const;

    void resetComponents();
};

#endif // CUSTOMFORMDIALOG_H
