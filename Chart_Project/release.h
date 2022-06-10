#ifndef RELEASE_H
#define RELEASE_H

#include<sstream>
#include<iomanip>

#include "album.h"
#include "date.h"

class Release : public Album{
private:
    Date release_date;  // data di pubblicazione del prodotto musicale
    double profit;      // profitto annuale in €
protected:
    /*
     * @brief   calcola il profitto di un prodotto musicale in base al numero di ascoltatori/vendite medi in un anno (365 giorni)
     */
    virtual void calcProfit() = 0;
public:
    Release(const string& _genre = "", const string& _album_name = "", const string& _artist_name = "", const Date& _rd = Date ());
    virtual ~Release() = default;
    /*
     * @brief   restituisce il profitto di un prodotto musicale
     * @return  double
     */
    double getProfit() const;
    /*
     * @brief   imposta il profitto di un prodotto musicale
     * @param   double
     * @return  void
     */
    virtual void setProfit(double _profit);
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
     * @return  string
     */
    virtual string getInfo() const override;
    /*
     * @brief   restituisce il numero riguardante ascolti/vendite di un prodotto musicale
     * @return  unsigned int
     */
    virtual uint getNumbers() const = 0;
    /*
     * @brief   converte un double in un stringa, applicando una formattazione custom
     * @param   double
     * @return  string
     */
    string customProfitFormatting(double profit) const;
};

#endif // RELEASE_H
