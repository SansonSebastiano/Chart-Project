#ifndef LINECHARTDIALOG_H
#define LINECHARTDIALOG_H

#include "chartdialog.h"

class LineChartDialog : public ChartDialog {
private:
    QRadioButton *genreRB;
    QComboBox *genreCB;     // get genre in input
    QDateEdit *from, *to;   // get date range

    void setOptions() override; // non fa nulla
    static const QString desc_option1;
public:
    LineChartDialog(QWidget* parent = Q_NULLPTR);
    ~LineChartDialog() = default;   // nb memory leak

    void createFormDialogLayout(QWidget* parent = Q_NULLPTR) override;
    void resetComponents() override;

    void setGenreCB(const std::vector<const string> &genres);

    // groupboxes
    void createGenreQCBBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);

    void enableComponents();
};

#endif // LINECHARTDIALOG_H
