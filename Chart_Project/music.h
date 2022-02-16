#ifndef MUSIC_H
#define MUSIC_H

#pragma once
#include<string>
using std::string;

class Music{
private:
    string genre;
public:
    Music(const string& _genre);
    virtual ~Music() = default;
    /*
     * @brief   restituisce un genere musicale
     * @return  string
     */
    string getGenre() const;
    virtual string getName() const = 0;
    virtual string getArtist() const = 0;
    /*
     * @brief   restituisce informazioni riguardante il prodotto musicale
     * @return  void
     */
    virtual string getInfo() const;
};

#endif // MUSIC_H
