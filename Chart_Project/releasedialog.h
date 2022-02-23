#ifndef RELEASEDIALOG_H
#define RELEASEDIALOG_H

#include "formdialog.h"

class ReleaseDialog : public FormDialog {
private:
    // release info
    QComboBox *toPublicCB;
    QDateEdit *releaseDE;
    // phisycal medium info
    QCheckBox *cdCKB, *vnlCKB, *cstCKB;
    QLineEdit *cdEdit, *vnlEdit, *cstEdit;
    // digital medium info
    QCheckBox *sptfCKB, *applmCKB, *tdlCKB, *dzrCKB, *ytmCKB, *amzCKB;
    QLineEdit *sptfEdit, *applmEdit, *tdlEdit, *dzrEdit, *ytmEdit, *amzEdit;

    QStringList musicToPublic;

    void createLine(QWidget *ckb, QWidget *lineEdit, QFormLayout *fl, QWidget* parent = Q_NULLPTR);
    void createMediumLine(QWidget *ckb, QWidget *lineEdit, QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);

    void createReleaseBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);
    void createPMBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);
    void createDMBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);

public:
    ReleaseDialog(QWidget* parent = Q_NULLPTR);
    ~ReleaseDialog() = default;

    const QStringList getMusicToPublic() const;
    void setMusicToPublic(const QVector<const Music*> &notReleased);

    void createReleaseMusicLayout(/*const QVector<const Music*> &notReleased,*/ QWidget* parent = Q_NULLPTR);

    const QComboBox* getToPubliCB() const;

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

    void enableComponents();

    bool checkPMInput() const;
    bool checkDMInput() const;

    void resetComponents() override;
};
#endif // RELEASEDIALOG_H
