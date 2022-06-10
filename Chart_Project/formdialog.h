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

    void createFormLayout(const QString &label, QWidget *w, QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);
    void createFormLayout(QWidget *w1, QWidget *w2, QVBoxLayout *vbl, QWidget *parent = Q_NULLPTR);

    void setAddBtn(const QString &buttonLabel);
    QPushButton* getAddBtn() const;

    virtual void createFormDialogLayout(QWidget* parent = Q_NULLPTR) = 0;
    virtual void resetComponents() = 0;
};

#endif // FORMDIALOG_H
