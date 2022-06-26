#ifndef FORMDIALOG_H
#define FORMDIALOG_H

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
#include <QComboBox>

#include "phisycalmedium.h"
#include "digitalmedium.h"

class FormDialog : public QDialog {
private:
    // dialog's buttons
    QPushButton *btn_add ;
public:
    FormDialog(QWidget* parent = Q_NULLPTR);
    virtual ~FormDialog();
    /*
     * @brief   crea il layout per ricevere in input dei dati, composto da una label e un widget (passati per parametro)
     */
    void createFormLayout(const QString &label, QWidget *w, QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);
    /*
     * @brief   crea il layout per ricevere in input dei dati, composto da due widget (passati per parametro)
     */
    void createFormLayout(QWidget *w1, QWidget *w2, QVBoxLayout *vbl, QWidget *parent = Q_NULLPTR);
    /*
     * @brief   aggiunge il bottone per confermare la ricezione dei dati in input
     */
    void setAddBtn(const QString &buttonLabel);
    QPushButton* getAddBtn() const;
    /*
     * @brief   crea il layout della finestra di dialogo
     */
    virtual void createFormDialogLayout(QWidget* parent = Q_NULLPTR) = 0;
    /*
     * @brief   re-inizializza i componenti della finestra di dialogo
     */
    virtual void resetComponents() = 0;
};

#endif // FORMDIALOG_H
