#ifndef DIGITALMEDIUM_H
#define DIGITALMEDIUM_H

#include "release.h"

#define FOREACH_PLATFORMS(P) \
    P(Spotify)               \
    P(AppleMusic)            \
    P(Tidal)                 \
    P(Deezer)                \
    P(YoutubeMusic)          \
    P(AmazonMusic)           \
    P(None_Platform)         \

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

// nome del servizio di streaming musicale
enum Platform { FOREACH_PLATFORMS(GENERATE_ENUM) };
// @brief  converte enum to string
static const string platform_names[]  = { FOREACH_PLATFORMS(GENERATE_STRING) };
static const int MAX_SVALUES = None_Platform + 1;

class DigitalMedium : public Release{
private:
    // nome della piattaforma
   Platform platform;
   // ascoltatori annui, relativo all'anno di pubblicazione
   uint listeners;
   // costo per ascolto in €
   static const double price;
   /*
    * @brief   imposta il guadagno di una album: prodotto tra #copie vendute e il prezzo per copia
    * @return  void
    */
    void setProfit() override;
public:
    DigitalMedium(string _genre, string _album_name, string _album_artist, const Date& _rd, Platform _platform, uint _listeners);
    virtual ~DigitalMedium() = default;
    /*
     * @brief   restituisce il nome del servizio digitale
     * @return  Platform
     */
    Platform getPlatform() const;
    /*
     * @brief   restituisce il numero di ascoltatori di un album
     * @return  unsigned int
     */
    uint getListeners() const;
    /*
     * @brief   restituisce informazioni riguardante il prodotto musicale
     * @return  void
     */
    virtual string getInfo() const override;
};

#endif // DIGITALMEDIUM_H
