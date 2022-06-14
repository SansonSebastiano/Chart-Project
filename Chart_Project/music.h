#ifndef MUSIC_H
#define MUSIC_H

#include <QMetaType>
#include<string>
using std::string;

class Music{
private:
    string genre;   // genere musicale
public:
    Music(const string& _genre = "");
    virtual ~Music() = default;
    /*
     * @brief   ritorna un genere musicale
     * @return  string
     */
    string getGenre() const;
    /*
     * @brief   restituisce il nome prodotto musicale
     * @return  string
     */
    virtual string getName() const = 0;
    /*
     * @brief   restituisce l'artista del prodotto musicale
     * @return  string
     */
    virtual string getArtist() const = 0;
    /*
     * @brief   restituisce informazioni riguardante il prodotto musicale
     * @return  void
     */
    virtual string getInfo() const;
};

// permette il casting attraverso QVariant
// necessario in tableModel.h /.cpp
Q_DECLARE_METATYPE(const Music*)

#endif // MUSIC_H
