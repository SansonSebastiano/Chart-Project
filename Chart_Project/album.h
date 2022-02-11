#ifndef ALBUM_H
#define ALBUM_H

#include "music.h"

class Album : public Music{
private:
    string name;
    string artist;
public:
    Album(const string& _genre, const string& _name, const string& _artist);
    virtual ~Album() = default;
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
     /*
      * @brief   restituisce informazioni riguardante il prodotto musicale
      * @return  void
      */
     virtual string getInfo() const override;
};

#endif // ALBUM_H
