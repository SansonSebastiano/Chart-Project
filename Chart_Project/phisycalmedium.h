#ifndef PHISYCALMEDIUM_H
#define PHISYCALMEDIUM_H

#include "release.h"

// macro:
// - definisco gli elementi per l'enumerazione di supporti fisici
#define FOREACH_SUPPORTS(S) \
    S(CD)                   \
    S(Vinile)               \
    S(Cassetta)             \
    S(None_Support)         \
// - generazione enumerazione
#define GENERATE_ENUM(ENUM) ENUM,
// - generazione stringhe dall'enumerazione
#define GENERATE_STRING(STRING) #STRING,

// dichiarazione enumerazione di supporti fisici
enum Support { FOREACH_SUPPORTS(GENERATE_ENUM) };

class PhisycalMedium : public Release{
private:
    Support support;    // tipo di supporto fisico utilizzato per la vendita di un prodotto musicale
    uint num_sales;     // numero di copie vendute in media ogni anno

    static const double cd_price;   // costo per copia CD in € di default
    static const double vnl_price;  // costo per copia Vinile in € di default
    static const double cst_price;  // costo per copia Cassetta in € di default
    /*
     * @brief   calcola il guadagno di un prodotto musicale: prodotto tra #copie vendute (in media annualmente) e il prezzo per copia
     * @return  void
     */
    void calcProfit() override;
public:
    static const string support_names[];    // contiene i nomi dei supporti fisici
    static const uint MAX_PM_VALUES;        // contiene il valore massimo dell'enumerazione

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
