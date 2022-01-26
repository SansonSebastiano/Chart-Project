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
    // raccolta di tutta la musica prodotta, appartenente all'etichetta discografica:
    //  - pubblicata
    //  NB: un album pubblicato, lo e' sia su supporto fisico che digitale !
    //  NB: un album puo' essere in vendita/pubblicato su piu' supporti fisici/digitali
    vector<const Music*> released;
    // - non ancora pubblicata
    vector<const Music*> not_released;
public:
    RecordLabel() = default;

    // DISTRUTTORE

    /*
     * @brief   pensa a come fare la insert:
     *          - PER GLI ALBUM PUBBLICATI (ovvero che andranno nel vettore 'released'
     *              - in ordine cronologico? (ovviamente per gli album pubblicati)
     *              -
     *          - PER GLI ALBUM ANCORA NON PUBBLICATI (ovvero che andranno nel vettore 'not_released'
     *              -
     * @param   const Album*
     * @ ECCEZIONI  da fare
     * @return  void
     */
    void insert(const Album* input);
    /*
     * @brief   calcola e ritorna l'incasso totale di un album dato in input
     * @pre     il nome dell'album passato per parametro deve essere pubblicato sia su supporto fisico che digitale
     * @param   string album_name
     * @ ECCEZIONI ?? nel caso album non sia pubblicato su supporto o fisico o digitale
     * @return  double
     */
    double getTotProfit(string album_name) const;
    /*
     * @brief   scansiona 'released' ed "estrae" tutte le pubblicazioni dell'album il cui nome e' dato in input
     * @param   string album_name
     * @ ECCEZIONI  nel caso il nome dell'album sia errato o non sia stato pubblicato
     * @return  vector<const Album*>
     */
    vector<const Release*> getFromReleased(string album_name) const;
};

#endif // RECORDLABEL_H
