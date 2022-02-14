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

#include <phisycalmedium.h>
#include <digitalmedium.h>
#include "tablemodel.h"

class Controller;

class Viewer : public QWidget{
    Q_OBJECT
private:
    Controller *controller;

    QList<const Music*> list;

    // Components' layout
    // Menu
    QMenu *file;
    QMenu *edit;
    QMenu *chart;
    // Buttons
    QPushButton *btn_uploadData;
    QPushButton *btn_saveData;

    QPushButton *btn_lineChart;
    QPushButton *btn_pieChart;
    QPushButton *btn_histogram;

    QPushButton *btn_addItem;
    QPushButton *btn_filter;

    TableModel *myModel;

    QPushButton *createButton(const QString& title);

    void addMenus(QVBoxLayout *mainLayout);
    void addControll_1(QVBoxLayout *mainLayout);
    void addScreen(QVBoxLayout *mainLayout);

    void addControll_2(QHBoxLayout *screenLayout);

public:
    explicit Viewer(QWidget *parent = nullptr);

    void setController(Controller *c);
    void setList(QList<const Music*> l);

    void showCatalog();
};

#endif // VIEWER_H
