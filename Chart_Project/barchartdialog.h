#ifndef BARCHARTDIALOG_H
#define BARCHARTDIALOG_H

#include "chartdialog.h"

class BarChartDialog : public ChartDialog {
private:
    //QVBoxLayout *dialogLayout;
    QComboBox *artistsCB;
    QDateEdit *dateQE;

    void setOptions() override;

    static const QString option1, option2,
                         desc_option1, desc_option2;
public:
    BarChartDialog(QWidget* parent = Q_NULLPTR);
    ~BarChartDialog();

    uint getSelectedYear() const;

    void createFormDialogLayout(QWidget* parent = Q_NULLPTR) override;
    void resetComponents() override;

    // se necessario renderla astratta nella classe base 'ChartDialog'
    void switchDescriptions();
    void enableComponents();    // forse non serve

    void setArtistCB(const std::vector<string> &artists);
};

#endif // BARCHARTDIALOG_H
