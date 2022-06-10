#ifndef CHARTDIALOG_H
#define CHARTDIALOG_H

#include <QLabel>
#include <QPlainTextEdit>
#include "formdialog.h"

// DA COMMENTARE

class ChartDialog : public FormDialog {
protected:
    QComboBox *optionsCB;
    QPlainTextEdit *description;
public:
    ChartDialog(QWidget* parent = Q_NULLPTR);
    virtual ~ChartDialog();

    uint getOptionsIndex() const;
    QComboBox* getOptionsCB() const;

    void changeTextDescription(const QString &text);

    virtual void setOptions() = 0;
    virtual void createDescriptionBox(QVBoxLayout *vbl, const QString &text, QWidget* parent = Q_NULLPTR);
    void createOptionsQCBBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);

    void resetComponents() override;
};

#endif // CHARTDIALOG_H
