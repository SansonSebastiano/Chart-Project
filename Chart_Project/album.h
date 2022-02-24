#ifndef ALBUM_H
#define ALBUM_H

#include "music.h"

class Album : public Music{
private:
    string name;    // nome dell'album
    string artist;  // artista dell'album
public:
    Album(const string& _genre = "", const string& _name = "", const string& _artist = "");
    virtual ~Album() = default;
    /*
     * @brief   restituisce il nome di un album
     * @return  string
     */
     string getName() const override;
    /*
     * @brief   restituisce l'artista di un album
     * @return  string
     */
     string getArtist() const override;
     /*
      * @brief   restituisce informazioni riguardante il prodotto musicale
      * @return  string
      */
     virtual string getInfo() const override;
};

#endif // ALBUM_H
