#include "formdialog.h"

FormDialog::FormDialog(QWidget* parent) :  QDialog(parent),
                                           btn_add(new QPushButton(parent))
                                           //btn_cancel(new QPushButton("Cancella", parent))
{
    setModal(true);
}

FormDialog::~FormDialog() {
    delete btn_add;
}

void FormDialog::setAddBtn(const QString &buttonLabel) { btn_add->setText(buttonLabel); }

QPushButton *FormDialog::getAddBtn() const { return btn_add; }

//QPushButton *FormDialog::getCancBtn() const { return btn_cancel; }

void FormDialog::createFormLayout(const QString &label, QWidget *w, QVBoxLayout *vbl, QWidget* parent) {
    QFormLayout *formLayout = new QFormLayout(parent);
    formLayout->setFormAlignment(Qt::AlignAbsolute);
    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->setAlignment(w, Qt::AlignRight);

    formLayout->addRow(label, w);
    vbl->addLayout(formLayout);
}

void FormDialog::createFormLayout(QWidget *w1, QWidget *w2, QVBoxLayout *vbl, QWidget *parent) {
    QFormLayout *formLayout = new QFormLayout(parent);
    formLayout->setFormAlignment(Qt::AlignAbsolute);
    formLayout->setLabelAlignment(Qt::AlignLeft);
    //formLayout->setAlignment(w, Qt::AlignRight);

    formLayout->addRow(w1, w2);
    vbl->addLayout(formLayout);
}
