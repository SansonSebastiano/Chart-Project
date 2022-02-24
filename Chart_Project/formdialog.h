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
    QPushButton *btn_add /**btn_cancel*/;
public:
    FormDialog(QWidget* parent = Q_NULLPTR);
    ~FormDialog() = default;

    void createFormLayout(const QString &label, QWidget *w, QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);

    void setAddBtn(const QString &buttonLabel);
    QPushButton* getAddBtn() const;
    //QPushButton* getCancBtn() const;

    virtual void resetComponents() = 0;
};

#endif // FORMDIALOG_H
