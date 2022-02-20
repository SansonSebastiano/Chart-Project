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

class CustomFormDialog : public QDialog{
private:
    // components
    // music info
    QLineEdit *nameEdit, *artistEdit, *genreEdit;
    // to public?
    QRadioButton *publicRB;
    // release info
    QDateEdit *releaseDE;
    // phisycal medium info
    QCheckBox *cdCKB, *vnlCKB, *cstCKB;
    QLineEdit *cdEdit, *vnlEdit, *cstEdit;
    // digital medium info
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

    void createDialogLayout();
    
public:
    CustomFormDialog();

    const QPushButton* getAddbtn() const;
    const QPushButton* getCancbtn() const;

    const QCheckBox* getcdCKB() const;
    const QCheckBox* getvnlCKB() const;
    const QCheckBox* getcstCKB() const;

    const QCheckBox* getsptfCKB() const;
    const QCheckBox* getapplmCKB() const;
    const QCheckBox* gettdlCKB() const;
    const QCheckBox* getdzrCKB() const;
    const QCheckBox* getytmCKB() const;
    const QCheckBox* getamzCKB() const;

    void enableComponents();
};

#endif // CUSTOMFORMDIALOG_H
