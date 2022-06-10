#ifndef VIEWER_H
#define VIEWER_H

#include <QApplication>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QPushButton>
#include <QTableView>
#include <QStandardItemModel>
#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QComboBox>
#include <QDateEdit>
#include <QCheckBox>
#include <QGroupBox>
#include<QFormLayout>
#include <QRadioButton>
#include <QMessageBox>

#include "phisycalmedium.h"
#include "digitalmedium.h"

#include "tablemodel.h"

#include "musicdialog.h"
#include "releasedialog.h"

#include "linechartdialog.h"
#include "piechartdialog.h"
#include "barchartdialog.h"

class Controller;

class Viewer : public QDialog{
    Q_OBJECT
private:
    Controller *controller;

    // Components' layout
    QVBoxLayout *mainLayout;
    QHBoxLayout *screenLayout,
                *table_layout;                  // contiene la tabella
    QFrame *frame;
    // Menu
    QMenu *file,
          *edit,
          *chart;
    // menu's actions
    QAction *AC_upload,
            *AC_save,
            *AC_add,
            *AC_release,
            *AC_lineChart,
            *AC_pieChart,
            *AC_barChart;

    // Buttons controlls_1
    QPushButton *btn_saveData,
                *btn_uploadData;

    QPushButton *btn_lineChart, *btn_pieChart, *btn_barChart;
    // Buttons controlls_2
    QPushButton *btn_addItem, *btn_release;
    // Buttons dialog
    QPushButton *btn_add, *btn_cancel;

    QTableView *tableView;
    TableModel *myTableModel;

    // custom dialog for adding and releasing music
    MusicDialog *md;
    ReleaseDialog *rd;

    // custom dialog for visualize charts
    LineChartDialog *ld;
    PieChartDialog *pd;
    BarChartDialog *bd;

    // overloading
    void closeEvent(QCloseEvent *event);

    void addMenus(QVBoxLayout *mainLayout);
    void addControll_1(QVBoxLayout *mainLayout);
    void addScreen(QVBoxLayout *mainLayout);
    void addControll_2(QHBoxLayout *screenLayout);

    QPushButton *createButton(const QString& title);

public:
    explicit Viewer(QWidget *parent = nullptr);
    ~Viewer();

    void setController(Controller *c);
    void setTable(const QVector<const Music*> &catalog);
    void addMusicToTable(const Music *newMusic);
    void removeMusicFromTable(uint index);

    MusicDialog *getMusicDialog() const;
    ReleaseDialog *getReleaseDialog() const;
    LineChartDialog *getLineChartDialog() const;
    PieChartDialog *getPieChartDialog() const;
    BarChartDialog *getBarChartDialog() const;

    // manage custom form dialog
    void showDialog(FormDialog *dialog);
    void resetComponents(FormDialog *dialog);
    void closeDialog(FormDialog *dialog);

    // dialog to release music
    bool getReleaseInput(std::vector<const Release*>& result);
    std::vector<const Release*> test();
    // display warning dialog
    void showWarning(const QString &message);
    QMessageBox::StandardButton showQuestion(const QString &message);
};

#endif // VIEWER_H
