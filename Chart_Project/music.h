#ifndef MUSIC_H
#define MUSIC_H

#include<string>
using std::string;

class Music{
private:
    string genre;
public:
    Music() = default;
    Music(string _genre);
    virtual ~Music() = default;
    /*
     * @brief   restituisce un genere musicale
     * @return  string
     */
    string getGenre() const;
    /*
     * @brief   restituira' il nome di una canzone/album
     * @return  string
     */
    virtual string getName() const = 0;
    /*
     * @brief   restituira' l'artista di una canzone/album
     * @return  string
     */
    virtual string getArtist() const = 0;
};

#endif // MUSIC_H
