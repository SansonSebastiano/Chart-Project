#ifndef PHISYCALMEDIUM_H
#define PHISYCALMEDIUM_H

#include "release.h"

class PhisycalMedium{
private:
    // tipo di supporto fisico
    string type;
    // numero di copie vendute
    unsigned int num_sales;
    // costo per copia
    static double price;
public:
    PhisycalMedium(string _genre,
                   string _name,
                   string _artist,
                   string _rd,
                   string _type,
                   unsigned int _ns);
    virtual ~PhisycalMedium() = default;
    /*
     * @brief   imposta il guadagno di una canzone/album
     * @return  void
     */
    virtual void setProfit();
    /*
     * @brief   restituisce il guadagno di una canzone/album
     * @return  double
     */
    virtual double getProfit() const;
    /*
     * @brief   restituisce il numero di copie vendute
     * @return  unsigned int
     */
    unsigned int getNumSales() const;
    /*
     * @brief   restituisce la tipologia del supporto fisico = {CD, Vinile, Cassetta}
     * @return  string
     */
    string getType() const;
};

#endif // PHISYCALMEDIUM_H
