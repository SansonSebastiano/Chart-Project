#include "formdialog.h"

FormDialog::FormDialog(QWidget* parent) :  QDialog(parent),
                                           btn_add(new QPushButton(parent))
{
    setModal(true);
}

FormDialog::~FormDialog() {
    delete btn_add;
}

void FormDialog::setAddBtn(const QString &buttonLabel) { btn_add->setText(buttonLabel); }

QPushButton *FormDialog::getAddBtn() const { return btn_add; }


void FormDialog::createFormLayout(const QString &label, QWidget *w, QVBoxLayout *vbl, QWidget* parent) {
    QFormLayout *formLayout = new QFormLayout(parent);

    formLayout->setFormAlignment(Qt::AlignLeading);
    formLayout->setLabelAlignment(Qt::AlignLeft);
    formLayout->setAlignment(w, Qt::AlignRight);

    formLayout->addRow(label, w);
    vbl->addLayout(formLayout);
}

void FormDialog::createFormLayout(QWidget *w1, QWidget *w2, QVBoxLayout *vbl, QWidget *parent) {
    QFormLayout *formLayout = new QFormLayout(parent);

    formLayout->setFormAlignment(Qt::AlignLeading);
    formLayout->setAlignment(w1, Qt::AlignLeft);
    formLayout->setAlignment(w2, Qt::AlignRight);

    formLayout->addRow(w1, w2);
    vbl->addLayout(formLayout);
}
