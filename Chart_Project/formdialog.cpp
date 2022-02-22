#include "formdialog.h"

FormDialog::FormDialog(QWidget* parent) :  QDialog(parent),
                                           btn_add(new QPushButton()),
                                           btn_cancel(new QPushButton("Cancella"))
{
    setModal(true);
}

void FormDialog::setAddBtn(const QString &buttonLabel) { btn_add->setText(buttonLabel); }

QPushButton *FormDialog::getAddBtn() const { return btn_add; }

QPushButton *FormDialog::getCancBtn() const { return btn_cancel; }

bool FormDialog::checkLine(const QCheckBox *cb, const QLineEdit *le, const QString &message) const {
    if (cb->isChecked()) {
        if (!le->text().isEmpty())
            return true;
        else {
            QMessageBox::warning(const_cast<QLineEdit*>(le), tr("Campi vuoti"), "Campo " + message + " necessario", QMessageBox::Ok);
            return false;
        }
    }
    return false;
}

void FormDialog::createFormLayout(const QString &label, QWidget *w, QVBoxLayout *vbl) {
    QFormLayout *formLayout = new QFormLayout();
    formLayout->setFormAlignment(Qt::AlignAbsolute);
    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->setAlignment(w, Qt::AlignRight);

    formLayout->addRow(label, w);
    vbl->addLayout(formLayout);
}
