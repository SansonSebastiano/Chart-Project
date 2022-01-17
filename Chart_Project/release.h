#ifndef RELEASE_H
#define RELEASE_H

#include "album.h"
#include "date.h"

class Release : public Album{
private:
    Date release_date;
protected:
    double profit;  // in €
public:
    Release () = default;
    Release(string _genre, string _album_name, string _artist_name, Date _rd);
    virtual ~Release() = default;
    /*
     * @brief   imposta il guadagno di una album
     * @return  void
     */
    virtual void setProfit() = 0;
    /*
     * @brief   restituisce il guadagno di una album
     * @return  double
     */
    virtual double getProfit() const;
    /*
     * @brief   restituisce la data di uscita di una album
     * @return  string
     */
    Date getReleaseDate() const;
};

#endif // RELEASE_H
