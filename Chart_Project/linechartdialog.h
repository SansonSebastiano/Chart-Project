#ifndef LINECHARTDIALOG_H
#define LINECHARTDIALOG_H

#include "chartdialog.h"

// DA COMMENTARE

class LineChartDialog : public ChartDialog {
private:
    QRadioButton *genreRB;
    QComboBox *genreCB;     // get genre in input
    QDateEdit *from, *to;   // get date range

    void setOptions() override; // non fa nulla
    static const QString desc_option1;
public:
    LineChartDialog(QWidget* parent = Q_NULLPTR);
    ~LineChartDialog();

    void createFormDialogLayout(QWidget* parent = Q_NULLPTR) override;
    void resetComponents() override;
    // imposta una combobox con la lista di generi musicali presenti nell'etichetta discografica
    void setGenreCB(const std::vector<string> &genres);

    // groupboxes
    void createGenreQCBBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);
    void createYearBox(QVBoxLayout *vbl, QWidget *parent = Q_NULLPTR);
    //
    QRadioButton *getGenreRB() const;

    void enableComponents();
    // ritorna l'anno in cui inizia l'intervallo
    uint getYearFrom() const;
    // ritorna l'anno in cui termina l'intervallo
    uint getYearTo() const;
    // ritorna il genere selezionato
    std::string getGenreSelected() const;
};

#endif // LINECHARTDIALOG_H
