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
    double profit;  // in €
    /*
     * @brief   imposta il guadagno di una album
     * @return  void
     */
    virtual void setProfit() = 0;
public:
    Release(const string& _genre = "", const string& _album_name = "", const string& _artist_name = "", const Date& _rd = Date ());
    virtual ~Release() = default;
    /*
     * @brief   restituisce il profitto di un prodotto musicale
     * @return  double
     */
    double getProfit() const;
    /*
     * @brief   restituisce la data di uscita di un prodotto musicale
     * @return  Date
     */
    Date getReleaseDate() const;
    /*
     * @brief   restituisce il numero di anni passati dalla pubblicazione di un prodotto musicale
     * @return  unsigned int
     */
    uint getElapsedYears() const;
    /*
     * @brief   restituisce informazioni riguardante il prodotto musicale
     * @return  void
     */
    virtual string getInfo() const override;
    /*
     * @brief   restituisce il numero riguardante ascolti/vendite di un prodotto musicale
     * @return  unsigned int
     */
    virtual uint getNumbers() const = 0;
    /*
     * @brief   converte un double in un stringa
     * @param   double profit
     * @return  string
     */
    string double_to_string(double profit) const;
};

#endif // RELEASE_H
