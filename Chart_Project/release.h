#ifndef RELEASE_H
#define RELEASE_H

#include "song.h"
#include "album.h"

class Release : public Song, public Album{
private:
    string release_date;
    double profit;
public:
    Release(string _genre, string _rd, double _profit, string _sn, string _sa);
    Release(string _an, string _aa, string _genre, string _rd, double _profit);

    virtual ~Release() = default;
    /*
     * @brief   imposta il guadagno di una canzone/album
     * @return  void
     */
    virtual void setProfit() = 0;
    /*
     * @brief   restituisce il guadagno di una canzone/album
     * @return  double
     */
    virtual double getProfit() const = 0;
    /*
     * @brief   restituisce la data di uscita di una canzone/album
     * @return  string
     */
    string getReleaseDate() const;
    // unique final override
    string getName() const;
    string getArtist() const;
};

#endif // RELEASE_H
