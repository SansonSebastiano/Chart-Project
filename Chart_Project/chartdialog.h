#ifndef CHARTDIALOG_H
#define CHARTDIALOG_H

#include <QLabel>
#include <QPlainTextEdit>
#include "formdialog.h"

class ChartDialog : public FormDialog {
protected:
    QComboBox *optionsCB;           // opzioni di cosa visualizzare nei grafici
    QPlainTextEdit *description;    // descrizione per ogni opzione
public:
    ChartDialog(QWidget* parent = Q_NULLPTR);
    virtual ~ChartDialog();
    /*
     * @brief   ritorna l'indice dell'opzione scelta
     * @return  unsigned int
     */
    uint getOptionsIndex() const;
    /*
     * @brief   ritorna un genere musicale
     * @return  QComboBox
     */
    QComboBox* getOptionsCB() const;
    /*
     * @brief   cambia la descrizione a seconda dell'opzione scelta
     * @param   const Qstring&
     * @return  void
     */
    void changeTextDescription(const QString &text);
    /*
     * @brief   imposta un elenco di opzioni
     * @return  void
     */
    virtual void setOptions() = 0;
    /*
     * @brief   crea la GUI per visualizzare la descrizione
     * @return  void
     */
    virtual void createDescriptionBox(QVBoxLayout *vbl, const QString &text, QWidget* parent = Q_NULLPTR);
    /*
     * @brief   crea la GUI per visualizzare le opzioni
     * @return  void
     */
    void createOptionsQCBBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);
    /*
     * @brief   resetta i valori delle opzioni
     * @return  void
     */
    void resetComponents() override;
};

#endif // CHARTDIALOG_H
