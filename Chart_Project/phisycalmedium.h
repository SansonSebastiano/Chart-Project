#ifndef PHISYCALMEDIUM_H
#define PHISYCALMEDIUM_H

#include "release.h"

// definisco gli elementi per una enumerazione
#define FOREACH_SUPPORTS(S) \
    S(CD)                   \
    S(Vinile)               \
    S(Cassetta)             \
    S(None_Support)         \
// generazione enumerazione
#define GENERATE_ENUM(ENUM) ENUM,
// generazione stringhe
#define GENERATE_STRING(STRING) #STRING,

// nome del supporto fisico
enum Support { FOREACH_SUPPORTS(GENERATE_ENUM) };

class PhisycalMedium : public Release{
private:
    // tipo di supporto fisico utilizzato per la vendita dell'album
    Support support;
    // numero di copie vendute in media ogni anno
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
public:
    // contiene i nomi (di tipo string) dei supporti fisici
    static const string support_names[];
    static const uint MAX_PVALUES;

    PhisycalMedium(const string& _genre = "", const string& _album_name = "", const string& _album_artist = "", const Date& _rd = Date(), Support _support = None_Support, uint _ns = 0);
    virtual ~PhisycalMedium() = default;
    /*
     * @brief   restituisce il numero di copie vendute
     * @return  unsigned int
     */
    virtual uint getNumbers() const override;
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
