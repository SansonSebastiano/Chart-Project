#ifndef BARCHARTDIALOG_H
#define BARCHARTDIALOG_H

#include "chartdialog.h"

class BarChartDialog : public ChartDialog {
private:
    QVBoxLayout *dialogLayout;
    QComboBox *artistsCB, *releaseCB;
    QDateEdit *date;

    void setOptions() override;

    static const QString option1, option2, option3,
                         desc_option1, desc_option2, desc_option3;
public:
    BarChartDialog(QWidget* parent = Q_NULLPTR);
    ~BarChartDialog() = default;  // nb: memory leak

    void createFormDialogLayout(QWidget* parent = Q_NULLPTR) override;
    void resetComponents() override;

    // se necessario renderla astratta nella classe base 'ChartDialog'
    void showDescription();
    void enableComponents();
};

#endif // BARCHARTDIALOG_H
