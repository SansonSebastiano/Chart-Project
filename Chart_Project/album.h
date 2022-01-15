#ifndef ALBUM_H
#define ALBUM_H

#include "music.h"

class Album : virtual public Music{
private:
    string album_name;
    string album_artist;
public:
    Album() = default;
    Album(string _genre, string _name, string _artist);
    ~Album() = default;
    /*
     * @brief   restituisce il nome di una album
     * @return  string
     */
     string getName() const override;
    /*
     * @brief   restituisce l'artista di una album
     * @return  string
     */
     string getArtist() const override;
};

#endif // ALBUM_H
