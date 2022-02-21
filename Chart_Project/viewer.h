#ifndef VIEWER_H
#define VIEWER_H

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
#include <QPair>

#include <phisycalmedium.h>
#include <digitalmedium.h>
#include "tablemodel.h"
#include "customformdialog.h"

class Controller;

class Viewer : public QWidget{
    Q_OBJECT
private:
    Controller *controller;

    QVector<const Music*> catalog;
    QVector<const Music*> toSave;

    // Components' layout
    // Menu
    QMenu *file;
    QMenu *edit;
    QMenu *chart;
    // Buttons controlls_1
    QPushButton *btn_uploadData;
    QPushButton *btn_saveData;

    QPushButton *btn_lineChart;
    QPushButton *btn_pieChart;
    QPushButton *btn_histogram;
    // Buttons controlls_2
    QPushButton *btn_addItem;
    QPushButton *btn_release;
    QPushButton *btn_filter;
    // Buttons dialog
    QPushButton *btn_add;
    QPushButton *btn_cancel;

    QTableView *table;
    TableModel *myTableModel;

    CustomFormDialog *cfd;

    void addMenus(QVBoxLayout *mainLayout);
    void addControll_1(QVBoxLayout *mainLayout);
    void addScreen(QVBoxLayout *mainLayout);
    void addControll_2(QHBoxLayout *screenLayout);

    QPushButton *createButton(const QString& title);

    void capitalizeInput(string& input);

public:
    explicit Viewer(QWidget *parent = nullptr);
    ~Viewer() = default;

    void setController(Controller *c);

    void showFormDialog();
    void closeFormDialog();
    void enableFormDialogComponents();
    void showWarning(const QString &message);
    Music *getMusicInput();
    void getReleaseInput();
    void addNewMusic(const Music* newMusic);
};

#endif // VIEWER_H
