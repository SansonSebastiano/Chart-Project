#ifndef DIGITALMEDIUM_H
#define DIGITALMEDIUM_H

#include "release.h"

// macro:
// - definisco gli elementi per l'enumerazione di piattaforme digitali
#define FOREACH_PLATFORMS(P) \
    P(Spotify)               \
    P(AppleMusic)            \
    P(Tidal)                 \
    P(Deezer)                \
    P(YoutubeMusic)          \
    P(AmazonMusic)           \
    P(None_Platform)         \
// - generazione enumerazione
#define GENERATE_ENUM(ENUM) ENUM,
// - generazione stringhe dall'enumerazione
#define GENERATE_STRING(STRING) #STRING,

// nome del servizio di streaming musicale
enum Platform { FOREACH_PLATFORMS(GENERATE_ENUM) };

class DigitalMedium : public Release{
private:
   Platform platform;           // nome della piattaforma
   uint listeners;              // ascoltatori annui in media
   static const double price;   // costo per ascolto in €
   /*
    * @brief   calcola il guadagno di un prodotto musicale: prodotto tra #ascolti (in media all'anno) e il prezzo per ascolto
    * @return  void
    */
    void calcProfit() override;
public:
    static const string platform_names[];   // contiene i nomi delle piattaforme di streaming
    static const uint MAX_DM_VALUES;          // contiene il valore massimo dell'enumerazione

    DigitalMedium(const string& _genre = "", const string& _album_name = "", const string& _album_artist = "", const Date& _rd = Date(), Platform _platform = None_Platform, uint _listeners = 0);
    virtual ~DigitalMedium() = default;
    /*
     * @brief   restituisce il servizio digitale
     * @return  Platform
     */
    Platform getPlatform() const;
    /*
     * @brief   restituisce il numero di ascoltatori di un prodotto musicale
     * @return  unsigned int
     */
    virtual uint getNumbers() const override;
    /*
     * @brief   restituisce informazioni riguardante il prodotto musicale
     * @return  void
     */
    virtual string getInfo() const override;
};

#endif // DIGITALMEDIUM_H
