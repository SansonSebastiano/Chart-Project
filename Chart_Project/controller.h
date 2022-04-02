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

#include "linechart.h"
#include "piechart.h"
#include "barchart.h"

#include "chartscreen.h"

class Controller : public QObject{
    Q_OBJECT
private:
    Viewer *view;   // per gestire la GUI
    Model *model;   // per gestire i dati

    // per gestire I/O su file
    xml_IO *xmlio;

    AbstractChart *chart;       // per creare i vari tipi di charts
    ChartScreen *chartWindow;   // per visualizzare i chart

    QVector<const Music*> catalog;  // preleva tutti i dati da file e caricarli nella tabella
    QVector<const Music*> toSave;   // memorizza i dati da salvare su file

    static const QDir project_path;     // percorso della directory del progetto
    static const QString dataSetDir;    // percorso del file .xml dove sono memorizzari i file
    /*
     * @brief   scrive su file nominato 'label' il contenuto 'document'
     * @param   const QString&
     * @param   const QDomDocument &
     * @return  void
     */
    void writeOnFile(const QString& label, const QDomDocument& document);
    /*
     * @brief   legge dal file nominato 'label' il contenuto 'document'
     * @param   const QString&
     * @param   const QDomDocument &
     * @return  void
     */
    void readFromFile(const QString& label, QDomDocument& document);

    // pie chart options
    // vengono impostati i dati per la visualizzazione delle varie opzioni di pie chart
    /*
     * @brief   artista X profitto
     * @return  void
     */
    void setPieOp1();
    /*
     * @brief   musica pubblicata X musica non pubblicata
     * @return  void
     */
    void setPieOp2();
    /*
     * @brief   profitto piattaforma X profitto supporti
     * @return  void
     */
    void setPieOp3();

    // bar chart options
    // vengono impostati i dati per la visualizzazione delle varie opzioni di bar chart
    /*
     * @brief   vendite (supporti) per anno dato in input
     * @param   uint
     * @return  void
     */
    void setBarOp1(uint year);
    /*
     * @brief   ascolti (piattaforme) per anno dato in input
     * @param   uint
     * @return  void
     */
    void setBarOp2(uint year);
public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller() = default; // da implementare

    void setModel(Model* m);
    void setViewer(Viewer *v);

    // pensare alle funzioni di parsing: dati in input e convertirli (in Date, uint, Support e Platform)
        // GENERE, ARTISTA, NOME ALBUM: scegliere convenzione

    // da mettere private?

    /*
     * @brief   legge i dati da file 'project_path/dataSetDir/"label".xml' e li carica sul catalogo di RecordLabel
     * @param   const QString&
     * @return  void
     */
    void loadDataFrom(const QString& label);
    /*
     * @brief   controlla l'esistenza del file 'label'.xml
     * @param   const QString&
     * @param   const Music*
     * @return  void
     */
    void isExists(const QString& label, const Music* music);
    /*
     * @brief   nel caso non esista il file 'label'.xml (controllato da 'isExists') si effettua un nuovo salvataggio,
     *          scrivendo per la prima volta su file i dati di 'music'
     * @param   const QString&
     * @param   const Music*
     * @return  void
     */
    void newSave(const QString& label, const Music* music);
    /*
     * @brief   nel caso esista il file 'label'.xml (controllato da 'isExists') si scrive in coda su file i dati di 'music'
     * @param   const QString&
     * @param   const Music*
     * @return  void
     */
    void appendTo(const QString& label, const Music* music);
    /*
     * @brief   scrive su file 'label'.xml la versione pubblicata di 'album' su supporto fisico
     * @param   const QString&
     * @param   const Album*
     * @param   const Date&
     * @param   uint
     * @param   Support
     * @return  void
     */
    void releasePMToFile(const QString& label, const Album* album, const Date& date, uint num, Support support);
    /*
     * @brief   scrive su file 'label'.xml la versione pubblicata di 'album' su piattaforma digitale
     * @param   const QString&
     * @param   const Album*
     * @param   const Date&
     * @param   uint
     * @param   Platform
     * @return  void
     */
    void releaseDMToFile(const QString& label, const Album* album, const Date& date, uint num, Platform platform);
    /*
     * @brief   rimuove da file 'label'.xml, dopo essere stata pubblicata, la versione non pubblicata di 'music'
     * @param   const QString&
     * @const   Music*
     */
    void removeFromFile(const QString& label, const Music* music, const QString& music_type);
    /*
     * @brief   legge e carica i dati da file
     * return   QVector<const Music*>
     */
    QVector<const Music*> initData();
    /*
     * @brief   ritorna i dati che non sono stati salvati su file
     * @return  const QVector<const Music*>
     */
    const QVector<const Music*> getToSave() const;

public slots:
    /*
     * @brief   imposta e visualizza i dati caricati su una tabella
     * return   void
     */
    void showTable();
    /*
     * @brief   chiude una finestra di dialogo
     * @param   FormDialog*
     * return   void
     */
    void closeDialog(FormDialog *dialog);
    /*
     * @brief   rimuove dal vettore 'toSave' (contiene i dati da salvare) 'music' non pubblicato
     * @param   const Music*
     * return   void
     */
    void removeFromToSave(const Music* music);
    /* BUG: vedi Issue #7
     * @brief   salva su file i dati aggiunti dall'utente
     * return   void
     */
    void saveToFile();

    //---------------------------------------------------------
    //  IMPLEMENTRE POLIMORFISMO
    //---------------------------------------------------------

    // music dialog

    /*
     * @brief   mostra una finestra che permette di inserire i dati di un prodotto musicale
     * return   void
     */
    void showMusicDialog();
    /*
     * @brief   aggiunge il prodotto musicale al catalogo di 'RecordLabel', alla tabella e sul vettore dei dati da salvare
     * @return  void
     */
    void addNewMusic();

    // release dialog

    /*
     * @brief   mostra una finestra che permette di pubblicare un prodotto musicale
     * return   void
     */
    void showReleaseDialog();
    /*
     * @brief   abilita/disabilita i componenti della finestra di dialogo in base alle interazioni dell'utente
     * @return  void
     */
    void enableRDComponents();
    /*  NON VA SU SLOT => DA METTERE PRIVATE?
     * @brief   preleva l'indice del prodotto musicale 'music' (non pubblicato) dal catalogo
     * @param   const Music*
     * @return  int
     */
    int getIndex(const Music* music);
    /*
     * @brief   pubblica il prodotto musicale
     * @return  void
     */
    void releaseMusic();

    // line chart

    /*
     * @brief   mostra una finestra che permette di visualizzare un line chart
     * return void
     */
    void showLineChartDialog();
    /*
     * @brief   abilita/disabilita i componenti della finestra di dialogo in base alle interazioni dell'utente
     * @return  void
     */
    void enableLDComponents();
    /*
     * @brief   mostra un line chart in una nuova finestra
     * @return  void
     */
    void showLineChartWindow();

    // pie chart
    /*
     * @brief   mostra una finestra che permette di scegliere un opzione e visualizzare un pie chart
     * return void
     */
    void showPieChartDialog();
    /*
     * @brief   visualizza una descrizione in base all'opzione selezionata
     * @return  void
     */
    void changeDescription();
    /*
     * @brief   mostra un pie chart in una nuova finestra
     * @return  void
     */
    void showPieChartWindow();

    // bar chart
    /*
     * @brief   mostra una finestra che permette di scegliere un opzione e visualizzare un bar chart
     * return void
     */
    void showBarChartDialog();
    //void changeDescription();
    /*
     * @brief   mostra un bar chart in una nuova finestra
     * @return  void
     */
    void showBarChartWindow();
};

#endif // CONTROLLER_H
