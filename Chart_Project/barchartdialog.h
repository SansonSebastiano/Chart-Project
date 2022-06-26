#ifndef BARCHARTDIALOG_H
#define BARCHARTDIALOG_H

#include "chartdialog.h"

class BarChartDialog : public ChartDialog {
private:
    QComboBox *artistsCB;
    QDateEdit *dateQE;

    void setOptions() override;

    static const QString option1, option2,
                         desc_option1, desc_option2;
public:
    BarChartDialog(QWidget* parent = Q_NULLPTR);
    ~BarChartDialog();
    // ritorna l'anno selezionato nel form
    uint getSelectedYear() const;

    void createFormDialogLayout(QWidget* parent = Q_NULLPTR) override;
    void resetComponents() override;
    // imposta una descrizione a seconda dell'opzione scelta
    void switchDescriptions();
};

#endif // BARCHARTDIALOG_H
