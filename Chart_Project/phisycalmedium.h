#ifndef PHISYCALMEDIUM_H
#define PHISYCALMEDIUM_H

#include "release.h"

class PhisycalMedium : public Release{
private:
    // tipo di supporto fisico
    string type;
    // numero di copie vendute all'anno
    uint num_sales;
    // costo per copia in €
    static const double price;
    /*
     * @brief   imposta il guadagno di una album: prodotto tra #copie vendute e il prezzo per copia
     * @return  void
     */
     void setProfit();
public:
    PhisycalMedium(string _genre,
                   string _album_name,
                   string _album_artist,
                   Date _rd,
                   string _type,
                   uint _ns);
    virtual ~PhisycalMedium() = default;
    /*
     * @brief   restituisce il numero di copie vendute
     * @return  unsigned int
     */
    uint getNumSales() const;
    /*
     * @brief   restituisce la tipologia del supporto fisico = {CD, Vinile, Cassetta}
     * @return  string
     */
    string getType() const;
};

#endif // PHISYCALMEDIUM_H
