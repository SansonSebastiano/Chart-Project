#include "recordlabel.h"

void RecordLabel::insert(const Album* input) {
    if (dynamic_cast<const Release*>(input))    // se m e' un album che e' stato pubblicato
        released.push_back(input);
    else not_released.push_back(input);
}
// FUNZIONA, pero' quando uso il risultato da problemi (vedi test.cpp: da riga 23)
double RecordLabel::getTotProfit(string album_name) const {
    // estrarre un album, ovvero raccogliere tutte le pubblicazioni di quell'album, che possono essere su piu' supporti fisici/digitali
    // => dunque da 'released'
    vector<const Release*> allReleases = getFromReleased(album_name);
    // sommatoria dei vari profitti per ottenere il guadagno complessivo
    double tot_profit = 0.0;
    for(auto it = allReleases.begin(); it != allReleases.end(); ++it)
        tot_profit += (*it)->getProfit();
    // FUNZIONA
    //cout << Release::profit_to_string(tot_profit) << endl;
    return tot_profit;
}

vector<const Release*> RecordLabel::getFromReleased(string album_name) const{
    vector<const Release*> result;
    const Release* pa = nullptr;
    for(auto it = released.begin(); it != released.end(); ++it){
        pa = dynamic_cast<const Release*>(*it);
        if (pa && pa->getAlbumName() == album_name)
            result.push_back(pa);
    }
    return result;
}
