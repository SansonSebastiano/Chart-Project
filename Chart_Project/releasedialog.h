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
    /*
     * @brief   crea il layout per ricevere in input dei dati, composto da due widget (passati per parametro)
     */
    void createLine(QWidget *ckb, QWidget *lineEdit, QFormLayout *fl, QWidget* parent = Q_NULLPTR);
    /*
     * @brief   crea il layout per ricevere in input i dati riguardanti i media
     */
    void createMediumLine(QWidget *ckb, QWidget *lineEdit, QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);
    /*
     * @brief   crea il layout per ricevere in input la data di pubblicazione
     */
    void createReleaseBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);
    /*
     * @brief   crea il layout per ricevere in input su quale supporto fisico pubblicare e quante vendite
     */
    void createPMBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);
    /*
     * @brief   crea il layout per ricevere in input su quale piattaforma digitale pubblicare e quanti ascolti
     */
    void createDMBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);

public:
    ReleaseDialog(QWidget* parent = Q_NULLPTR);
    virtual ~ReleaseDialog() = default;
    /*
     * @brief   inizializza la combobox con la lista di album ancora non pubblicati
     */
    void setMusicToPublic(const std::vector<const Music*> &notReleased);

    void createFormDialogLayout(QWidget* parent = Q_NULLPTR) override;

    const QCheckBox* getcdCKB() const;
    const QCheckBox* getvnlCKB() const;
    const QCheckBox* getcstCKB() const;

    const QCheckBox* getsptfCKB() const;
    const QCheckBox* getapplmCKB() const;
    const QCheckBox* gettdlCKB() const;
    const QCheckBox* getdzrCKB() const;
    const QCheckBox* getytmCKB() const;
    const QCheckBox* getamzCKB() const;
    /*
     * @brief   abilita il permesso di digitare il numero di vendite/ascolti soltanto se la rispettiva checkbox (di un media) è stata cliccata
     */
    void enableComponents();
    /*
     * @brief   controlla se qualche campo e' vuoto di lineEdit e' vuoto mentre la rispettiva checkbox e' stata cliccata
     */
    bool checkLine(const QCheckBox *cb, const QLineEdit *le, const QString &message) const;
    /*
     * @brief   controlla se line edit e' attivo
     */
    bool checkLineEdit(const QLineEdit *le) const;

    void resetComponents() override;
    /*
     * @brief   controlla se tutte le checkbox sono unchecked
     */
    bool isAllUnchecked() const;
    /*
     * @brief   controlla se tutte le lineEdit sono vuote
     */
    bool isAllEmpty() const;

    std::vector<const Release*> getInput(const std::vector<const Music*> &not_released);
};
#endif // RELEASEDIALOG_H
