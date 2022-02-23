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

#include <phisycalmedium.h>
#include <digitalmedium.h>
#include "tablemodel.h"
#include "musicdialog.h"
#include "releasedialog.h"

class Controller;

class Viewer : public QDialog{
    Q_OBJECT
private:
    Controller *controller;

    QVector<const Music*> catalog;
    QVector<const Music*> toSave;

    // Components' layout
    QVBoxLayout *mainLayout;
    QHBoxLayout *screenLayout;
    QHBoxLayout *table_layout;
    QFrame *frame;
    // Menu
    QMenu *file;
    QMenu *edit;
    QMenu *chart;
    // Buttons controlls_1
    QPushButton *btn_saveData;
    QPushButton *btn_uploadData;

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

    MusicDialog *md;
    ReleaseDialog *rd;

    // overloading
    void closeEvent(QCloseEvent *event);

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

    void setTable();
    void addMusic(const Music *newMusic);
    void removeMusic(uint index);
    // manage custom form dialog
    void resetComponent();
    void closeDialog();
    // dialog to add new music
    void showMusicDialog();
    const Music *getMusicInput();
    // dialog to release music
    void showReleaseDialog(const QVector<const Music*> &notReleased);
    std::vector<const Release*> getReleaseInput();
    void enableReleaseDialogComponents();
    // display warning dialog
    void showWarning(const QString &message);

    QVector<const Music*> getToSave() const;
    void clearToSave();
};

#endif // VIEWER_H
