#ifndef SONG_H
#define SONG_H

#include "music.h"

//  ???

class Song : public Music{
private:
    string name;
    string artist;
public:
    Song(string _genre, string _name, string _artist);
    ~Song() = default;
    /*
     * @brief   restituisce il nome di una canzone
     * @return  string
     */
     string getSongName() const;
    /*
     * @brief   restituisce l'artista di una canzone
     * @return  string
     */
     string getSongArtist() const;
};

#endif // SONG_H
