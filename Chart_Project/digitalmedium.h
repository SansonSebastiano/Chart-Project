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

class DigitalMedium : public Release{
private:
    // nome della piattaforma
   Platform platform;
   // ascoltatori annui in media
   uint listeners;
   // costo per ascolto in €
   static const double price;
   /*
    * @brief   imposta il guadagno di una album: prodotto tra #copie vendute e il prezzo per copia
    * @return  void
    */
    void setProfit() override;
public:
    // contiene in nomi delle piattaforme di streaming
    static const string platform_names[];
    static const uint MAX_SVALUES;

    DigitalMedium(const string& _genre = "", const string& _album_name = "", const string& _album_artist = "", const Date& _rd = Date(), Platform _platform = None_Platform, uint _listeners = 0);
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
    virtual uint getNumbers() const override;
    /*
     * @brief   restituisce informazioni riguardante il prodotto musicale
     * @return  void
     */
    virtual string getInfo() const override;
};

#endif // DIGITALMEDIUM_H
