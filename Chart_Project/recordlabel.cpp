#include "recordlabel.h"

RecordLabel::RecordLabel(string _name) : RL_name(_name) {}

RecordLabel::~RecordLabel() {
    for(auto r : released) delete r;
    for(auto nr : not_released) delete nr;
}

string RecordLabel::getRLName() const { return RL_name; }

void RecordLabel::insert(const Album* album) {
    if (dynamic_cast<const Release*>(album))    // se '*album' e' un album che e' stato pubblicato
        released.push_back(album);
    else not_released.push_back(album);
}

vector<const Release*> RecordLabel::getReleasedByName(string album_name) const{
    vector<const Release*> result;
    const Release* pr = nullptr;
    for(auto it = released.begin(); it != released.end(); ++it){
        pr = dynamic_cast<const Release*>(*it);
        if (pr && pr->getAlbumName() == album_name)
            result.push_back(pr);
    }
    return result;
}

vector<const Release*> RecordLabel::getReleasedByGenre(string genre) const{
    vector<const Release*> result;
    const Release* pr = nullptr;
    for(auto it = released.begin(); it != released.end(); ++it){
        pr = dynamic_cast<const Release*>(*it);
        if (pr && pr->getGenre() == genre)
            result.push_back(pr);
    }
    return result;
}

vector<const Release*> RecordLabel::getReleasedByArtist(string artist) const{
    vector<const Release*> result;
    const Release* pr = nullptr;
    for(auto it = released.begin(); it != released.end(); ++it){
        pr = dynamic_cast<const Release*>(*it);
        if(pr && pr->getAlbumArtist() == artist)
            result.push_back(pr);
    }
    return result;
}

// DA TESTARE
vector<const Release*> RecordLabel::getReleasedByYear(Date date) const{
    vector<const Release*> result;
    const Release* pr = nullptr;
    for(auto it = released.begin(); it != released.end(); ++it){
        pr = dynamic_cast<const Release*>(*it);
        if(pr && pr->getReleaseDate().getYear() == date.getYear())
            result.push_back(pr);
    }
    return result;
}

vector<const DigitalMedium*> RecordLabel::getReleasedByPlatform(Platform platform) const{
    vector<const DigitalMedium*> result;
    const DigitalMedium* pdm = nullptr;
    for(auto it = released.begin(); it != released.end(); ++it){
        pdm = dynamic_cast<const DigitalMedium*>(*it);
        if(pdm && pdm->getPlatform() == platform)
            result.push_back(pdm);
    }
    return result;
}

vector<const PhisycalMedium*> RecordLabel::getReleasedBySupport(Support support) const{
    vector<const PhisycalMedium*> result;
    const PhisycalMedium *ppm = nullptr;
    for(auto it = released.begin(); it != released.end(); ++it){
        ppm = dynamic_cast<const PhisycalMedium*>(*it);
        if(ppm && ppm->getSupport() == support)
            result.push_back(ppm);
    }
    return result;
}

vector<const Release*> RecordLabel::getBetweenYears(vector<const Release*> v, Date from, Date to) const{
    vector<const Release*> result;
    const Release* pr = nullptr;
    for(auto it = v.begin(); it != v.end(); ++it){
        pr = dynamic_cast<const Release*>(*it);
        if(pr && (pr->getReleaseDate() >= from && pr->getReleaseDate() <= to))
            result.push_back(pr);
    }
    return result;
}

double RecordLabel::getTotProfit(vector<const Release*> r) const {
    double tot_profit = 0.0;
    for(auto it = r.begin(); it != r.end(); ++it)
        tot_profit += (*it)->getProfit();
    return tot_profit;
}

// DA TESTARE
uint RecordLabel::getTotSales(vector<const Release *> r) const{
    uint tot_sales = 0;
    for(auto it = r.begin(); it != r.end(); ++it)
        if(dynamic_cast<const PM*>(*it))
            tot_sales += dynamic_cast<const PM*>(*it)->getNumSales();
    return tot_sales;
}

// DA TESTARE
uint RecordLabel::getTotListeners(vector<const Release *> r) const{
    uint tot_listeners = 0;
    for(auto it = r.begin(); it != r.end(); ++it)
        if(dynamic_cast<const DM*>(*it))
            tot_listeners += dynamic_cast<const DM*>(*it)->getListeners();
    return tot_listeners;
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

vector<const Music*> RecordLabel::getReleased() const{ return released; }

vector<const Music*> RecordLabel::getNotReleased() const{ return not_released; }

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
