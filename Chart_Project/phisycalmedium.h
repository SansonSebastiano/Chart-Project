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
    // tipo di supporto fisico utilizzato per la vendita di un prodotto musicale
    Support support;
    // numero di copie vendute in media ogni anno
    uint num_sales;
    // DA RIVEDERE QUESTE 3 VARIABILI E METTERLE PUBBLICHE ??
    // costo per copia CD in € di default
    static const double cd_price;
    // costo per copia Vinile in € di default
    static const double vnl_price;
    // costo per copia Cassetta in € di default
    static const double cst_price;
    /*
     * @brief   imposta il guadagno di un prodotto musicale: prodotto tra #copie vendute (in media in un anno) e il prezzo per copia
     * @return  void
     */
     void setProfit() override;
public:
    // contiene i nomi dei supporti fisici
    static const string support_names[];
    // contiene il valore massimo dell'enumerazione
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
