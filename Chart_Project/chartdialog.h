#ifndef CHARTDIALOG_H
#define CHARTDIALOG_H

#include <QLabel>
#include <QPlainTextEdit>
#include "formdialog.h"

class ChartDialog : public FormDialog {
protected:      // CORRETTO????
    QComboBox *optionsCB;
public:
    ChartDialog(QWidget* parent = Q_NULLPTR);
    virtual ~ChartDialog() = default;

    uint getOptionsIndex() const;
    //QComboBox* getOptions() const;

    virtual void setOptions() = 0;
    virtual void createDescriptionBox(QVBoxLayout *vbl, const QString &label, QWidget* parent = Q_NULLPTR);
    void createOptionsQCBBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);

    void resetComponents() override;
};

#endif // CHARTDIALOG_H
