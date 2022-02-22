#ifndef MUSICDIALOG_H
#define MUSICDIALOG_H

#include "formdialog.h"

class MusicDialog : public FormDialog{
private:
    // music info
    QLineEdit *nameEdit, *artistEdit, *genreEdit;

    void createMusicBox(QVBoxLayout *vbl);
public:
    MusicDialog(QWidget* parent = Q_NULLPTR);
    ~MusicDialog() = default;

    const QLineEdit *getNameEdit() const;
    const QLineEdit *getArtistEdit() const;
    const QLineEdit *getGenreEdit() const;

    void createAddMusicLayout();

    bool checkMusicInput() const;

    void resetComponents() override;
};

#endif // MUSICDIALOG_H
