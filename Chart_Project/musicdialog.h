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
    ~MusicDialog() = default;

    std::string getInputName() const;
    std::string getInputArtist() const;
    std::string getInputGenre() const;

    void createAddMusicLayout(QWidget* parent = Q_NULLPTR);

    bool checkMusicInput() const;

    string capitalizeInput(string input);

    const Music* getInput();

    void resetComponents() override;
};

#endif // MUSICDIALOG_H
