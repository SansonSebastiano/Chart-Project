#include "model.h"

Model::Model() : rl(new RecordLabel()) { }

//Model::Model(const string& label) : rl(new RecordLabel(label)) { }

// inserisce musica nel catalogo dell'etichetta discografica
void Model::insertMusic(const Music *music){ rl->insert(music); }

// rimuove musica non pubblicata dal catalogo dell'etichetta discografica
void Model::removeMusic(const Music *music) { rl->removeNotReleased(music); }

// preleva le informazioni di tutta la musica dell'etichetta discografica
// FORSE DA ELIMINARE
void Model::getCatalogInfo() const{
    auto r(rl->getReleased());
    auto nr(rl->getNotReleased());

    cout << "Musica non rilasciata: " << endl << endl;

    for(auto it = nr.begin(); it != nr.end(); ++it)
         cout << (*it)->getInfo() << endl << endl;

    cout << "Musica rilasciata: " << endl << endl;

    for(auto it = r.begin(); it != r.end(); ++it)
        cout << (*it)->getInfo() << endl << endl;
}

// preleva tutta la musica dal catalogo dell'etichetta discografica
vector<const Music*> Model::getCatalog() const { return rl->getAll(); }

// preleva tutta la musica non pubblicata dal catalogo dell'etichetta discografica
vector<const Music*> Model::getNotReleasedMusic() const { return rl->getNotReleased(); }

bool Model::isPresent(const Music *m) const {
    auto all(getCatalog());     // preleva il catalogo da recordlabel
    bool found(false);

    for (auto it = all.begin(); it != all.end() && !found; ++it)    // per ogni prodotto musicale
        if (areEquals((*it), m))    // controllo esistenza
            found = true;           // se trovato

    return found;
}

bool Model::areEquals(const Music *m1, const Music *m2) const { return rl->areSame(m1, m2); }

bool Model::isElapsed1Year(const Release *release) const { return rl->isElapsed1Year(release); }

// TENTA DI IMPLEMENTARE I PUNTATORI !!!!!!!!!

vector<string> Model::getArtists() const {
    vector<string> result;
    auto v(rl->getAll());   // preleva il catalogo
    string key;             // chiave, ovvero artista, da inserire in result

    for (auto it = v.begin(); it != v.end(); ++it){     // per ogni prodotto musicale
        key = (*it)->getArtist();       // ottiene l'artista del prodotto musicale

        if (std::find(result.begin(), result.end(), key) == result.end())   // se chiave non trovata => l'artista non e' in result
                result.push_back(key);  // inserisce la chiave in result
    }

    return result;
}

vector<string> Model::getGenres() const {
    vector<string> result;
    auto v(rl->getAll());   // preleva il catalogo
    string key;             // chiave, ovvero genere musicale, da inserire in result

    for(auto it = v.begin(); it != v.end(); ++it){  // per ogni prodotto musicale
        key = (*it)->getGenre();    // ottiene genere del prodotto musicale

        if(std::find(result.begin(), result.end(), key) == result.end())    // se chiave non trovata => genere musicale non e' in result
            result.push_back(key);  // inserisce la chiave in result
    }
    return result;
}

vector<uint> Model::lineChartOp1(const string &genre, uint from, uint to, vector<const Music*> &data) {
    auto byGenre(rl->getByGenre(rl->getAll(), genre));  // ottiene tutta la musica di genere 'genre' dal catalogo
    vector<uint> result;

    for(uint year(from); year <= to; year++) {                  // per ogni anno da 'from' a 'to'
        auto byYear(rl->getByYear(byGenre, year));              // ottiene tutta la musica di genere 'genre' pubblicata nell'anno 'year'

        data.reserve(data.size() + byYear.size());              // alloca spazio necessario
        data.insert(data.end(), byYear.begin(), byYear.end());  // inserisce la musica prelevata

        result.push_back(rl->getTotProfit(byYear));             // calcola il profitto di tutta la musica prelevata
    }

    return result;
}

vector<std::pair<double, string>> Model::pieChartOp1() {
    vector<std::pair<double, string>> result;

    vector<const Music*> byArtist;

    // fetch artisti
    auto artists(getArtists());

    // fetch catalogo
    auto all(rl->getReleased());

    // NON MI CONVINCE
    for(auto it = artists.begin(); it != artists.end(); ++it){
        byArtist = rl->getByArtist(all, *it);       // preleva tutta la musica per artista (*it)
        result.push_back(std::make_pair(rl->getTotProfit(byArtist), *it));  // inserisce l'artista e il relativo profitto
    }

    // ordina in modo decrescente rispetto al primo valore, ovvero double profit
    std::sort(result.rbegin(), result.rend());

    // mantengo i 5 migliori, ed elimino i restanti
    result.erase(result.begin() + 5, result.end());

    return result;
}

std::pair<double, double> Model::pieChartOp2() {
    std::pair<double, double> result(rl->getReleased().size(), rl->getNotReleased().size());    // ritorna q.ta' musica pubblicata e non

    return result;
}

std::pair<double, double> Model::pieChartOp3() {
    std::pair<double, double> result(rl->getTotProfit(rl->getReleaseOnSupport()),
                                     rl->getTotProfit(rl->getReleaseOnPlatform()));             // ritorna incasso dei supporti e piattaforme

    return result;
}

vector<std::pair<string, double>> Model::barChartOp1(uint year) {
    auto data(getCatalog());    // ottiene catalogo
    vector<const Music*> bySupport, byYear;
    vector<std::pair<string, double>> result;

    for (int i = CD; i < None_Support; ++i){    // per ogni supporto
        byYear = rl->getByYear(data, year);     // preleva musica in base all'anno
        bySupport = rl->getBySupport(byYear, static_cast<Support>(i));  // li suddivide per supporti
        result.push_back(std::make_pair(PM::support_names[i], rl->getTotProfit(bySupport)));    // inserisce supporto e il relativo profitto
    }

    return result;
}

vector<std::pair<string, double>> Model::barChartOp2(uint year) {
    auto data(getCatalog());    // preleva il catalogo
    vector<const Music*> byPlatform, byYear;
    vector<std::pair<string, double>> result;

    for (int i = Spotify; i < None_Platform; ++i){  // per ogni piattaforma
        byYear = rl->getByYear(data, year);         // preleva musica in base all'anno
        byPlatform = rl->getByPlatform(byYear, static_cast<Platform>(i));   // li suddivide per piattaforme
        result.push_back(std::make_pair(DM::platform_names[i], rl->getTotProfit(byPlatform)));  // inserisce piattaforma e relativo profitto
    }

    return result;
}


