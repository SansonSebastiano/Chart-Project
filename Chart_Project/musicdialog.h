#ifndef MUSICDIALOG_H
#define MUSICDIALOG_H

#include "formdialog.h"

class MusicDialog : public FormDialog{
private:
    // music info
    QLineEdit *nameEdit, *artistEdit, *genreEdit;

    void createMusicBox(QVBoxLayout *vbl, QWidget* parent = Q_NULLPTR);
public:
    MusicDialog(QWidget* parent = Q_NULLPTR);
    virtual ~MusicDialog();

    std::string getInputName() const;
    std::string getInputArtist() const;
    std::string getInputGenre() const;

    void createFormDialogLayout(QWidget* parent = Q_NULLPTR) override;

    bool checkMusicInput() const;

    string capitalizeInput(string input);

    const Music* getInput();

    void resetComponents() override;
};

#endif // MUSICDIALOG_H
