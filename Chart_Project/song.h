#ifndef SONG_H
#define SONG_H

#include "music.h"

class Song : virtual public Music{
private:
    string song_name;
    string song_artist;
public:
    Song() = default;
    Song(string _genre, string _name, string _artist);
    ~Song() = default;
    /*
     * @brief   restituisce il nome di una canzone
     * @return  string
     */
     string getName() const override;
    /*
     * @brief   restituisce l'artista di una canzone
     * @return  string
     */
     string getArtist() const override;
};

#endif // SONG_H
