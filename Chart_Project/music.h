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
    virtual ~Music() = 0;
    /*
     * @brief   restituisce un genere musicale
     * @return  string
     */
    string getGenre() const;
    /*
     * @brief   restituisce informazioni riguardante il prodotto musicale
     * @return  void
     */
    virtual string getInfo() const;

    // EVENTUALE OVERLOADING DELL'OPERATORE DI OUTPUT
};

#endif // MUSIC_H
