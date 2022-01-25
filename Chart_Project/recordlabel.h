#ifndef RECORDLABEL_H
#define RECORDLABEL_H

#include "phisycalmedium.h"
typedef PhisycalMedium PM;

#include "digitalmedium.h"
typedef DigitalMedium DM;

#include "exceptions.h"

#include <vector>
using std::vector;

class RecordLabel{
private:
    // tipologie di supporto fisico
    //enum pm_type {CD, Vinile, Cassetta};
    // tipologie di supporto digitale
    //enum dm_name {Spotify, AppleMusic, Tidal, AmazonMusic, Deezer, YouTubeMusic};

    // raccolta di tutta la musica prodotta appartenente all'etichetta discografica:
    //  - pubblicata
    //  NB: un album pubblicato, lo e' via supporto fisico che digitale !
    vector<const Music*> released;
    // - non ancora pubblicata
    vector<const Music*> not_released;
public:
    RecordLabel() = default;
    /*
     * @brief   pensa a come fare la insert:
     *          - PER GLI ALBUM PUBBLICATI (ovvero che andranno nel vettore 'released'
     *              - in ordine cronologico? (ovviamente per gli album pubblicati)
     *              -
     *          - PER GLI ALBUM ANCORA NON PUBBLICATI (ovvero che andranno nel vettore 'not_released'
     *              -
     * @param   Album
     * @ ECCEZIONI
     * @return  void
     */
    void insert(const Music*);
    /*
     * @brief   calcola e ritorna l'incasso totale di un album dato in input
     * @pre     l'album passato per parametro deve essere pubblicato sia su supporto fisico che digitale
     * @param   Release
     * @ ECCEZIONI  nel caso album non sia pubblicato su supporto o fisico o digitale
     * @return  double
     */
    double getTotProfit(const Music*) const;
};

#endif // RECORDLABEL_H
