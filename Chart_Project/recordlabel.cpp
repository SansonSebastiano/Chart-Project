#include "recordlabel.h"

RecordLabel::~RecordLabel() { for(auto c : catalog) delete c; }

void RecordLabel::insert(const Music* music) {
    //if(!music) throw string("NoInsert");        // DEFINIRE UNA CLASSE DI ECCEZIONI

    catalog.push_back(music);
    cout << music->getInfo() << " \nINSERTED TO RECORD LABEL" << endl << endl;
}

// DA TESTARE

vector<const Music*> RecordLabel::getByName(const vector<const Music *> &v, const string &name) const {
    //controllo se
        // - 'v' e' vuoto?
        // - name nullo

    vector<const Music*> result;
    for(auto it = v.begin(); it != v.end(); ++it)
        if((*it)->getName() == name)
            result.push_back(*it);

    //if(result.empty()) throw string("NameNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
    return result;
}

vector<const Music*> RecordLabel::getByGenre(const vector<const Music *> &v, const string &genre) const {
    //controllo se
        // - 'v' e' vuoto?
        // - genre nullo

    vector<const Music*> result;
    for(auto it = v.begin(); it != v.end(); ++it)
        if((*it)->getGenre() == genre)
            result.push_back((*it));

    //if(result.empty()) throw string("GenreNotFound"); // DEFINIRE UNA CLASSE DI ECCEZIONI
                                                        // VEDERE UN ESERCIZIO DEGLI APPELLI CHE LO FA
    return result;
}

vector<const Music*> RecordLabel::getByArtist(const vector<const Music *> &v, const string &artist) const {
    //controllo se
        // - 'v' e' vuoto?
        // - artist nullo

    vector<const Music*> result;
    for(auto it = v.begin(); it != v.end(); ++it)
        if((*it)->getArtist() == artist)
            result.push_back((*it));

    //if(result.empty()) throw string("ArtistNotFound");    // DEFINIRE UNA CLASSE DI ECCEZIONI
    return result;
}

vector<const Music*> RecordLabel::getByYear(const vector<const Music *> &v, uint year) const {
    //controllo se
        // - 'v' e' vuoto?

    vector<const Music*> result;

    for(auto it = v.begin(); it != v.end(); ++it) {
        auto pr = dynamic_cast<const Release*>(*it);
        if(pr && pr->getReleaseDate().getYear() == year)
            result.push_back(static_cast<const Release*>(*it));
    }

    //if(result.empty()) throw string("YearNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
    return result;
}

vector<const Music*> RecordLabel::getByPlatform(const vector<const Music*> &v, Platform platform) const{
    //controllo se
        // - 'v' e' vuoto?
        // - platform == None_Platform

    vector<const Music*> result;

    for(auto it = v.begin(); it != v.end(); ++it){
        auto pdm = dynamic_cast<const DM*>(*it);
        if(pdm && pdm->getPlatform() == platform)
            result.push_back(static_cast<const DM*>(*it));
    }
    //if(result.empty()) throw string("PlatformNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
    return result;
}

vector<const Music*> RecordLabel::getBySupport(const vector<const Music*> &v, Support support) const{
    //controllo se
        // - 'v' e' vuoto?
        // - support = None_Support
    vector<const Music*> result;

    for(auto it = v.begin(); it != v.end(); ++it){
        auto ppm = dynamic_cast<const PM*>(*it);
        if(ppm && ppm->getSupport() == support)
            result.push_back(static_cast<const PM*>(*it));
    }
    //if(result.empty()) throw string("SupportNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
    return result;
}

double RecordLabel::getTotProfit(const vector<const Music*> &r) const {
    // controllo se r è vuoto ??

    double tot_profit = 0.0;
    for(auto it = r.begin(); it != r.end(); ++it) {
        auto pr = dynamic_cast<const Release*>(*it);
        if(pr)
            tot_profit += pr->getProfit();
    }

    return tot_profit;
}

uint RecordLabel::getTotNumbers(const vector<const Music *> &r) const {
    // controllo se r è vuoto ??

    uint tot_numbers = 0;
    for(auto it = r.begin(); it != r.end(); ++it) {
        auto pr = dynamic_cast<const Release*>(*it);
        if(pr)
            tot_numbers += pr->getNumbers();
    }

    return tot_numbers;
}

bool RecordLabel::isElapsed1Year(const Release *release) const{
    // controllo se album vuoto

    return release->getElapsedYears() >= 1;
}

vector<const Music*> RecordLabel::getAll() const {
    vector<const Music*> result;
    const Release* r;

    for (auto it = catalog.begin(); it != catalog.end(); ++it) {
        r = dynamic_cast<const Release*>(*it);
        if (!r || (r && isElapsed1Year(r)))
            result.push_back(*it);
    }

    return result;
}

vector<const Music*> RecordLabel::getReleased() const {
    vector<const Music*> released;
    const Release* r;

    for (auto it = catalog.begin(); it != catalog.end(); ++it){
        r = dynamic_cast<const Release*>(*it);
        if (r && isElapsed1Year(r))
            released.push_back(*it);
    }

    return released;
}

vector<const Music*> RecordLabel::getNotReleased() const {
    vector<const Music*> not_released;

    for (auto it = catalog.begin(); it != catalog.end(); ++it)
        if(!dynamic_cast<const Release*>(*it))
            not_released.push_back(*it);

    return not_released;
}

vector<const Music*> RecordLabel::getReleaseOnSupport() const {
    vector<const Music*> result;
    auto data(getReleased());

    for(auto it = data.begin(); it != data.end(); ++it)
        if(dynamic_cast<const PM*>(*it))
            result.push_back(*it);

    return result;
}

vector<const Music*> RecordLabel::getReleaseOnPlatform() const {
    vector<const Music*> result;
    auto data(getReleased());

    for(auto it = data.begin(); it != data.end(); ++it)
        if(dynamic_cast<const DM*>(*it))
            result.push_back(*it);

    return result;
}

void RecordLabel::removeNotReleased(const Music *music) {
    // controllo se music vuoto

    bool found(false);

    for(auto it = catalog.begin(); it != catalog.end() && !found; ++it)
        if(!dynamic_cast<const Release*>(*it) && areSame((*it), music)){
            cout << (*it)->getInfo();
            delete (*it);
            it = catalog.erase(it);
            it--;
            found = true;
            cout << "\tDELETED FROM RECORD LABEL" << endl << endl;
        }
    // DA TESTARE
    //if(!found) throw string("NameNotFound");  // DEFINIRE UNA CLASSE DI ECCEZIONI
}

bool RecordLabel::areSame(const Music *m1, const Music *m2) const {
    return (m1->getName() == m2->getName() && m1->getArtist() == m2->getArtist() && m1->getGenre() == m2->getGenre());

}
