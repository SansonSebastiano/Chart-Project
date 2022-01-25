#ifndef DIGITALMEDIUM_H
#define DIGITALMEDIUM_H

#include<sstream>
#include<iomanip>

#include "release.h"

// nome del servizio di streaming musicale
enum Platform {Spotify, AppleMusic, Tidal, AmazonMusic, Deezer, YouTubeMusic};

class DigitalMedium : public Release{
private:
    // nome della piattaforma
   Platform platform;
   // ascoltatori annui
   uint listeners;
   // costo per ascolto in €
   static const double price;
   /*
    * @brief   imposta il guadagno di una album: prodotto tra #copie vendute e il prezzo per copia
    * @return  void
    */
    void setProfit() override;
    // @brief  converte enum to string
    static const char* platform_str[];
public:
    DigitalMedium(string _genre, string _album_name, string _album_artist, Date _rd, Platform _platform, uint _listeners);
    virtual ~DigitalMedium() = default;
    /*
     * @brief   restituisce il nome del servizio digitale
     * @return  string
     */
    string getPlatform() const;
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
