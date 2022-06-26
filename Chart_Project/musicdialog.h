#ifndef MUSICDIALOG_H
#define MUSICDIALOG_H

#include "formdialog.h"

class MusicDialog : public FormDialog{
private:
    // music info
    QLineEdit *nameEdit, *artistEdit, *genreEdit;
    /*
     * @brief   crea il layout specifico per il form in cui inserire i dati di un nuovo album
     */
    void createMusicBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);
public:
    MusicDialog(QWidget* parent = Q_NULLPTR);
    virtual ~MusicDialog();

    std::string getInputName() const;
    std::string getInputArtist() const;
    std::string getInputGenre() const;

    void createFormDialogLayout(QWidget* parent = Q_NULLPTR) override;
    /*
     * @brief   controlla se qualche campo di input e' vuoto
     */
    bool checkMusicInput() const;
    /*
     * @brief   rende maiuscola la prima lettere di ogni parola e minuscole le restanti
     */
    string capitalizeInput(string input);
    /*
     * @brief   valida i dati in input e ritorna un album con tali dati
     */
    const Music* getInput();

    void resetComponents() override;
};

#endif // MUSICDIALOG_H
