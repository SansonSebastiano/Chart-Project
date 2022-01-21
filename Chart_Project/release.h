#ifndef RELEASE_H
#define RELEASE_H

#include "album.h"
#include "date.h"

class Release : public Album{
private:
    Date release_date;
protected:
    double profit;  // in €
    /*
     * @brief   imposta il guadagno di una album
     * @return  void
     */
    virtual void setProfit() = 0;
public:
    Release(string _genre, string _album_name, string _artist_name, Date _rd);
    virtual ~Release() = default;
    /*
     * @brief   restituisce il guadagno di una album
     * @return  double
     */
    double getProfit() const;
    /*
     * @brief   restituisce la data di uscita di una album
     * @return  Date
     */
    Date getReleaseDate() const;
    /*
     * @brief   restituisce informazioni riguardante il prodotto musicale
     * @return  void
     */
    virtual string getInfo() const override;
};

#endif // RELEASE_H
