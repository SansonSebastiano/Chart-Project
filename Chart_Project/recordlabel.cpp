#include "recordlabel.h"

void RecordLabel::insert(const Album* input) {
    if (dynamic_cast<const Release*>(input))    // se m e' un album che e' stato pubblicato
        released.push_back(input);
    else not_released.push_back(input);
}

double RecordLabel::getTotProfit(string album_name) const {
    // estrarre un album, ovvero raccogliere tutte le pubblicazioni di quell'album, che possono essere su piu' supporti fisici/digitali
    // => estrarre dunque da 'released'
    vector<const Release*> allReleases = getReleasedByName(album_name);
    // sommatoria dei vari profitti per ottenere il guadagno complessivo
    double tot_profit = 0.0;
    for(auto it = allReleases.begin(); it != allReleases.end(); ++it)
        tot_profit += (*it)->getProfit();
    return tot_profit;
}


vector<const Release*> RecordLabel::getReleasedByName(string album_name) const{
    vector<const Release*> result;
    const Release* pa = nullptr;
    for(auto it = released.begin(); it != released.end(); ++it){
        pa = dynamic_cast<const Release*>(*it);
        if (pa && pa->getAlbumName() == album_name)
            result.push_back(pa);
    }
    return result;
}

vector<const Release*> RecordLabel::getReleasedByGenre(string genre) const{
    vector<const Release*> result;
    const Release* pa = nullptr;
    for(auto it = released.begin(); it != released.end(); ++it){
        pa = dynamic_cast<const Release*>(*it);
        if (pa && pa->getGenre() == genre)
            result.push_back(pa);
    }
    return result;
}

// DA TESTARE
vector<const Release*> RecordLabel::getBetweenYears(vector<const Release*> v, Date from, Date to) const{
    vector<const Release*> result;
    const Release* pa = nullptr;
    for(auto it = v.begin(); it != v.end(); ++it){
        pa = dynamic_cast<const Release*>(*it);
        if(pa && (pa->getReleaseDate() >= from || pa->getReleaseDate() <= to))
            result.push_back(pa);
    }
    return result;
}

void RecordLabel::release(const Album *album, const Date& date, Support support, uint num_sales){
    bool found = false;
   for (auto it = not_released.begin(); it != not_released.end() && !found; ++it)
       if(dynamic_cast<const Album*>(*it)->getAlbumName() == album->getAlbumName()) {
           insert(new PM(album->getGenre(), album->getAlbumName(), album->getAlbumArtist(), date, support, num_sales));
           found = true;
       }
}

void RecordLabel::release(const Album *album, const Date &date, Platform platform, uint listeners) {
    bool found = false;
    for(auto it = not_released.begin(); it != not_released.end() && !found; ++it)
        if(dynamic_cast<const Album*>(*it)->getAlbumName() == album->getAlbumName()){
            insert(new DM(album->getGenre(), album->getAlbumName(), album->getAlbumArtist(), date, platform, listeners));
            found = true;
        }
}

vector<const Music*> RecordLabel::getReleased() const{
    return released;
}


vector<const Music*> RecordLabel::getNotReleased() const{
    return not_released;
}

void RecordLabel::removeFromNotReleased(const Album *album) {
    bool found = false;
    for(auto it = not_released.begin(); it != not_released.end() && !found; ++it)
        if(dynamic_cast<const Album*>(*it)->getAlbumName() == album->getAlbumName()){
            delete (*it);
            it = not_released.erase(it);
            it--;
            found = true;
        }
}
