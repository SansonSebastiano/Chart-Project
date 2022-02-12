#include "recordlabel.h"

RecordLabel::RecordLabel(const string& _name) : RL_name(_name) {}

RecordLabel::~RecordLabel() {
    for(auto r : released) delete r;
    for(auto nr : not_released) delete nr;
}

string RecordLabel::getRLName() const { return RL_name; }

void RecordLabel::insert(const Music* music) {
    //if(!music) throw string("NoInsert");        // DEFINIRE UNA CLASSE DI ECCEZIONI

    if (dynamic_cast<const Release*>(music))     // se e' un album che e' stato pubblicato
        released.push_back(static_cast<const Release*>(music));
    else not_released.push_back(music);         // altrimenti
}

// DA TESTARE

vector<const Music*> RecordLabel::getByName(vector<const Music *> v, const string &album_name) const {
    //controllo se 'v' e' vuoto?
    vector<const Music*> result;
    for(auto it = v.begin(); it != v.end(); ++it)
        if((*it)->getName() == album_name)
            result.push_back(*it);

    //if(result.empty()) throw string("NameNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
    return result;
}

vector<const Music*> RecordLabel::getByGenre(vector<const Music *> v, const string &genre) const {
    vector<const Music*> result;
    for(auto it = v.begin(); it != v.end(); ++it)
        if((*it)->getGenre() == genre)
            result.push_back((*it));

    //if(result.empty()) throw string("GenreNotFound"); // DEFINIRE UNA CLASSE DI ECCEZIONI
                                                        // VEDERE UN ESERCIZIO DEGLI APPELLI CHE LO FA
    return result;
}

vector<const Music*> RecordLabel::getByArtist(vector<const Music *> v, const string &artist) const{
    vector<const Music*> result;
    for(auto it = v.begin(); it != v.end(); ++it)
        if((*it)->getArtist() == artist)
            result.push_back((*it));

    //if(result.empty()) throw string("ArtistNotFound");    // DEFINIRE UNA CLASSE DI ECCEZIONI
    return result;
}

vector<const Music*> RecordLabel::getByYear(vector<const Music *> v, uint year) const {
    vector<const Music*> result;
    for(auto it = v.begin(); it != v.end(); ++it)
        if(dynamic_cast<const Release*>(*it)->getReleaseDate().getYear() == year)
            result.push_back(static_cast<const Release*>(*it));

    //if(result.empty()) throw string("YearNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
    return result;
}

vector<const Release*> RecordLabel::getByPlatform(Platform platform) const{
    vector<const Release*> result;
    const DM* pdm = nullptr;

    for(auto it = released.begin(); it != released.end(); ++it){
        pdm = dynamic_cast<const DM*>(*it);
        if(pdm && pdm->getPlatform() == platform)
            result.push_back(pdm);
    }
    //if(result.empty()) throw string("PlatformNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
    return result;
}

vector<const Release*> RecordLabel::getBySupport(Support support) const{
    vector<const Release*> result;
    const PM *ppm = nullptr;

    for(auto it = released.begin(); it != released.end(); ++it){
        ppm = dynamic_cast<const PM*>(*it);
        if(ppm && ppm->getSupport() == support)
            result.push_back(ppm);
    }
    //if(result.empty()) throw string("SupportNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
    return result;
}

vector<const Release*> RecordLabel::getBetweenYears(vector<const Release*> v, const Date& from, const Date& to) const{
    vector<const Release*> result;
    const Release* pr = nullptr;
    for(auto it = v.begin(); it != v.end(); ++it){
        pr = dynamic_cast<const Release*>(*it);
        if(pr && (pr->getReleaseDate() >= from && pr->getReleaseDate() <= to))
            result.push_back(pr);
    }
    //if(result.empty()) throw string("RangeOfYearsNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
    return result;
}

double RecordLabel::getTotProfit(vector<const Release*> r) const {
    double tot_profit = 0.0;
    for(auto it = r.begin(); it != r.end(); ++it)
        tot_profit += (*it)->getProfit();
    return tot_profit;
}

// DA TESTARE
uint RecordLabel::getTotNumbers(vector<const Release *> r) const{
    uint tot_sales = 0;
    for(auto it = r.begin(); it != r.end(); ++it)
        tot_sales += (*it)->getNumbers();
    return tot_sales;
}

void RecordLabel::release(const Release *album){
    bool found = false;

    for (auto it = not_released.begin(); it != not_released.end() && !found; ++it)
        if((*it)->getName() == album->getName() && isElapsed1Year(album)) {
            insert(album);
            found = true;
     }
    // DA TESTARE
    //if(!isElapsed1Year(album)) throw string("NotOneYearElapsed"); // DEFINIRE UNA CLASSE DI ECCEZIONI
    //if(!found) throw string("NameNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
}

bool RecordLabel::isElapsed1Year(const Release *album) const{
    if(album->getElapsedYears() >= 1) return true;
    else return false;
}

vector<const Music*> RecordLabel::getReleased() const{ return released; }

vector<const Music*> RecordLabel::getNotReleased() const{ return not_released; }

void RecordLabel::removeFromNotReleased(const Music *music) {
    bool found = false;

    for(auto it = not_released.begin(); it != not_released.end() && !found; ++it)
        if((*it)->getName() == music->getName()){
            delete (*it);
            it = not_released.erase(it);
            it--;
            found = true;
        }
    // DA TESTARE
    //if(!found) throw string("NameNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
}
