#ifndef ALBUM_H
#define ALBUM_H

#include "music.h"

class Album : virtual public Music{
private:
    string name;
    string artist;
public:
    Album() = default;
    Album(string _genre, string _name, string _artist);
    ~Album() = default;
    /*
     * @brief   restituisce il nome di una album
     * @return  string
     */
     string getAlbumName() const;
    /*
     * @brief   restituisce l'artista di una album
     * @return  string
     */
     string getAlbumArtist() const;
};

#endif // ALBUM_H
