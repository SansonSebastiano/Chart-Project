#ifndef PHISYCALMEDIUM_H
#define PHISYCALMEDIUM_H

#include "release.h"

// tipologie di supporto fisico
enum Support {CD, Vinile, Cassetta};

class PhisycalMedium : public Release{
private:
    // tipo di supporto fisico utilizzato per la vendita dell'album
    Support support;
    // numero di copie vendute all'anno, relativo all'anno di pubblicazione
    uint num_sales;
    // costo per copia CD in € di default
    static const double cd_price;
    // costo per copia Vinile in € di default
    static const double vnl_price;
    // costo per copia Cassetta in € di default
    static const double cst_price;
    /*
     * @brief   imposta il guadagno di una album: prodotto tra #copie vendute e il prezzo per copia
     * @return  void
     */
     void setProfit() override;
     // @brief  converte enum to string
     static const char *support_str[];
public:
    PhisycalMedium(string _genre, string _album_name, string _album_artist, const Date& _rd, Support _support, uint _ns);
    virtual ~PhisycalMedium() = default;
    /*
     * @brief   restituisce il numero di copie vendute
     * @return  unsigned int
     */
    uint getNumSales() const;
    /*
     * @brief   restituisce la tipologia del supporto fisico
     * @return  Support
     */
    Support getSupport() const;
    /*
     * @brief   restituisce informazioni riguardante il prodotto musicale
     * @return  void
     */
    virtual string getInfo() const override;
};

#endif // PHISYCALMEDIUM_H
