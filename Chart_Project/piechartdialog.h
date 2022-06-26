#ifndef PIECHARTDIALOG_H
#define PIECHARTDIALOG_H

#include "chartdialog.h"

class PieChartDialog : public ChartDialog {
private:
    void setOptions() override;

    static const QString option1, option2, option3,
                         desc_option1, desc_option2, desc_option3;
public:
    PieChartDialog(QWidget *parent = Q_NULLPTR);
    ~PieChartDialog() = default;

    void createFormDialogLayout(QWidget* parent = Q_NULLPTR) override;
    void resetComponents() override;
    // visualizza una descrizione in base all'opzione scelta
    void switchDescription();
};

#endif // PIECHARTDIALOG_H
