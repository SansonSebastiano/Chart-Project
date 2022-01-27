#ifndef RELEASE_H
#define RELEASE_H

#include<sstream>
#include<iomanip>

#include "album.h"
#include "date.h"

class Release : public Album{
private:
    Date release_date;
protected:
    double profit;  // annuo in €: relativo all'anno della data di pubblicazione
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
    /*
     * @brief   converte un double in un stringa e lo "formatta in euro"
     * @param   double profit
     * @return  string
     */
    static string profit_to_string(double profit);
};

#endif // RELEASE_H
