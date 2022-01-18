#ifndef RECORDLABEL_H
#define RECORDLABEL_H

#include "phisycalmedium.h"
#include "digitalmedium.h"
#include <vector>
using std::vector;

class RecordLabel{
private:
    // tipologie di supporto fisico
    enum pm_type {CD, Vinile, Cassetta};
    // tipologie di supporto digitale
    enum dm_name {Spotify, AppleMusic, Tidal, AmazonMusic, Deezer, YouTubeMusic};
    // raccolta di tutta la musica pubblicata fino ad ora dalla etichetta discografica
    vector<const Music*> music;
public:
    RecordLabel();
    /*
     * @brief   pensa a come fare la insert
     * @return  void
     */
};

#endif // RECORDLABEL_H
