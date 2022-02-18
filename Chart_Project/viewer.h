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

#include <phisycalmedium.h>
#include <digitalmedium.h>
#include "tablemodel.h"

class Controller;

class Viewer : public QWidget{
    Q_OBJECT
private:
    Controller *controller;

    QVector<const Music*> catalog;

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
    QPushButton *btn_filter;
    // Buttons dialog
    QPushButton *btn_add;
    QPushButton *btn_cancel;

    QTableView *table;
    TableModel *myModel;

    QDialog *formDialog;

    void addMenus(QVBoxLayout *mainLayout);
    void addControll_1(QVBoxLayout *mainLayout);
    void addScreen(QVBoxLayout *mainLayout);
    void addControll_2(QHBoxLayout *screenLayout);

    QPushButton *createButton(const QString& title);

    // FARE UNA CLASSE
    // Dialog Layout
    QVBoxLayout *releaseFormLayout;
    QWidget *container_1;
    QWidget *container_2;
    QWidget *container_3;

    // Dialog Components
    QRadioButton *publicRB;

    QLineEdit *nameEdit;
    QLineEdit *artistEdit;
    QLineEdit *genreEdit;

    QDateEdit *releaseDE;

    QCheckBox *cdCKB;
    QLineEdit *cdSalesEdit;
    QCheckBox *vnlCKB;
    QLineEdit *vnlSalesEdit;
    QCheckBox *cstCKB;
    QLineEdit *cstSalesEdit;

    QCheckBox *spotifyCKB;
    QLineEdit *spoListenersEdit;
    QCheckBox *appMusicCKB;
    QLineEdit *appMListenersEdit;
    QCheckBox *tidalCKB;
    QLineEdit *tidListenersEdit;
    QCheckBox *deezerCKB;
    QLineEdit *deeListenersEdit;
    QCheckBox *youMusicCKB;
    QLineEdit *youListenersEdit;
    QCheckBox *amMusicCKB;
    QLineEdit *AmListenersEdit;

    QFormLayout *createFormLayout(const QString& label, QWidget* w);
    QHBoxLayout *createHEditLine(QList<QWidget*> *lw, QWidget *parent = nullptr);
    QVBoxLayout *createLineLayout(QList<QLayout*> *vbl, int leftMargin = 0, int topMargin = 0, int rightMargin = 0, int bottomMargin = 0, QWidget *parent = nullptr);

    QVBoxLayout * addMusicLine(QList<QLayout*> *layoutList);
    QVBoxLayout * addRelaseLine(QList<QLayout*> *layoutList, QWidget *parent = nullptr);
    QVBoxLayout * addPMLine(QList<QLayout*> *layoutList, QList<QWidget*> *lineEdit, QWidget *parent = nullptr);
    QVBoxLayout * addDMLine(QList<QLayout*> *layoutList, QList<QWidget*> *lineEdit, QWidget *parent = nullptr);

    void initDialogComponets();
    void createCustomDialog();

    // COMBOBOX PER PUBBLICARE GLI ALBUM

public:
    explicit Viewer(QWidget *parent = nullptr);

    void setController(Controller *c);

    void showFormDialog();
    void closeFormDialog();
    void showEditLine();

    void getDataInput();
    void addNewMusic();
};

#endif // VIEWER_H
