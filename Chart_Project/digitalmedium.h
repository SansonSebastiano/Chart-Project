#ifndef DIGITALMEDIUM_H
#define DIGITALMEDIUM_H

#include<sstream>
#include<iomanip>

#include "release.h"

class DigitalMedium : public Release{
private:
    // nome della servizio {Spotify, Tidal, Apple Music, ...}
   string service_name;
   // ascoltatori annui
   uint listeners;
   // costo per ascolto in €
   static const double price;
   /*
    * @brief   imposta il guadagno di una album: prodotto tra #copie vendute e il prezzo per copia
    * @return  void
    */
    void setProfit() override;
public:
    DigitalMedium(string _genre,
                  string _album_name,
                  string _album_artist,
                  Date _rd,
                  string _sn,
                  uint _listeners);
    virtual ~DigitalMedium() = default;
    /*
     * @brief   restituisce il nome del servizio digitale
     * @return  string
     */
    string getServiceName() const;
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
