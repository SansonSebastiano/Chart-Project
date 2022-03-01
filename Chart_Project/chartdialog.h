#ifndef CHARTDIALOG_H
#define CHARTDIALOG_H

#include "formdialog.h"

class ChartDialog : public FormDialog {
private:
    QComboBox *options;
    QStringList optionsList;
public:
    ChartDialog(QWidget* parent = Q_NULLPTR);
    virtual ~ChartDialog() = default;

    uint getOptionsIndex() const;

    void setOptionsList(const QStringList &_optionsList);

    virtual void setOptions() = 0;
};

#endif // CHARTDIALOG_H
