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
    virtual ~ReleaseDialog() = default;

    const QStringList getMusicToPublic() const;
    void setMusicToPublic(const QVector<const Music*> &notReleased);

    void createReleaseMusicLayout(QWidget* parent = Q_NULLPTR);

    // forse dovrei ritornare direttamente quello che mi serve e non i componenti

    uint getToPublicIndexItem() const;

    const QDate getReleaseDate() const;

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
    bool checkLine(const QCheckBox *cb, const QLineEdit *le, const QString &message) const;
    bool checkLineEdit(const QLineEdit *le) const;

    //bool checkPMInput() const;
    //bool checkDMInput() const;

    void resetComponents() override;

    bool isAllUnchecked() const;
    bool isAllEmpty() const;

    std::vector<const Release*> getInput(const std::vector<const Music*> &not_released);
};
#endif // RELEASEDIALOG_H
