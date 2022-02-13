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

class Viewer : public QWidget{
    Q_OBJECT
private:
    void addMenus(QVBoxLayout *mainLayout);
    void addScreen(QVBoxLayout *mainLayout, QHBoxLayout *screen);
    void addButtons(QVBoxLayout *mainLayout);

    void addBtn(QVBoxLayout *mainLayout, QHBoxLayout *screen);

public:
    explicit Viewer(QWidget *parent = nullptr);

signals:
};

#endif // VIEWER_H
