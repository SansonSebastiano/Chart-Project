#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QtXml>
#include <QtDebug>
#include <QTextStream>

#include "io_handler.h"
#include "viewer.h"
#include "model.h"

#include "musicdialog.h"
#include "releasedialog.h"

class Controller : public QObject{
    Q_OBJECT
private:
    Viewer *view;
    Model *model;

    xml_IO xmlio;

    QVector<const Music*> catalog;  // preleva tutti i dati da file e caricarli nella tabella
    QVector<const Music*> toSave;   // memorizza i dati da salvare su file

    static const QDir project_path;
    static const QString dataSetDir;

    void writeOnFile(const QString& label, const QDomDocument& document);
    void readFromFile(const QString& label, QDomDocument& document);
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller() = default; // ??

    void setModel(Model* m);
    void setViewer(Viewer *v);

    // pensare alle funzioni di parsing: dati in input e convertirli (in Date, uint, Support e Platform)
        // GENERE, ARTISTA, NOME ALBUM: scegliere convenzione

    // DA COMMENTARE
    // da mettere private?

    void loadDataFrom(const QString& label);

    void isExists(const QString& label, const Music* music);
    void newSave(const QString& label, const Music* music);
    void appendTo(const QString& label, const Music* music);

    void releasePMToFile(const QString& label, const Album* album, const Date& date, uint num, Support support);
    void releaseDMToFile(const QString& label, const Album* album, const Date& date, uint num, Platform platform);

    void removeFromFile(const QString& label, const Music* music);

    QVector<const Music*> initData();
    const QVector<const Music*> getToSave() const;

public slots:
    void showTable();
    void closeDialog(FormDialog *dialog);

    void removeFromToSave(const Music* music);
    void saveToFile();

    // music dialog
    void showMusicDialog();
    void addNewMusic();

    // release dialog
    void showReleaseDialog();
    void enableRDComponents();
    int getIndex(const Music* music);
    void releaseMusic();

    // line chart dialog
    void showLineChartDialog();
};

#endif // CONTROLLER_H
