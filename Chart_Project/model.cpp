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
    auto all(getCatalog());
    bool found(false);

    for (auto it = all.begin(); it != all.end() && !found; ++it)
        if (areEquals((*it), m))
            found = true;

    return found;
}

bool Model::areEquals(const Music *m1, const Music *m2) const { return rl->areSame(m1, m2); }

bool Model::isElapsed1Year(const Release *release) const { return rl->isElapsed1Year(release); }

// TENTA DI IMPLEMENTARE I PUNTATORI !!!!!!!!!

vector<string> Model::getArtists() const {
    vector<string> result;
    auto v(rl->getAll());
    string key;

    for (auto it = v.begin(); it != v.end(); ++it){
        key = (*it)->getArtist();

        if (std::find(result.begin(), result.end(), key) == result.end())
                result.push_back(key);
    }

    return result;
}

vector<string> Model::getGenres() const {
    vector<string> result;
    auto v(rl->getAll());
    string key;

    for(auto it = v.begin(); it != v.end(); ++it){
        key = (*it)->getGenre();

        if(std::find(result.begin(), result.end(), key) == result.end())
            result.push_back(key);
    }
    return result;
}

vector<uint> Model::lineChartOp1(const string &genre, uint from, uint to, vector<const Music*> &data) {
    auto byGenre(rl->getByGenre(rl->getAll(), genre));
    vector<uint> result;

    for(uint year(from); year <= to; year++) {
        auto byYear(rl->getByYear(byGenre, year));

        data.reserve(data.size() + byYear.size());
        data.insert(data.end(), byYear.begin(), byYear.end());

        result.push_back(rl->getTotProfit(byYear));
    }

    return result;
}

vector<std::pair<double, string>> Model::pieChartOp1() {
    vector<std::pair<double, string>> result;

    vector<const Music*> byArtist;

    // fetch artists
    auto artists(getArtists());

    // fetch catalogo
    auto all(rl->getReleased());
    // for cycle to get artist musics
    // NON MI CONVINCE
    for(auto it = artists.begin(); it != artists.end(); ++it){
        byArtist = rl->getByArtist(all, *it);
        result.push_back(std::make_pair(rl->getTotProfit(byArtist), *it));
    }

    // ordina in modo decrescente rispetto al primo valore, ovvero double profit
    std::sort(result.rbegin(), result.rend());

    // mantengo i 5 migliori, ed elimino i restanti
    result.erase(result.begin() + 5, result.end());

    return result;
}

std::pair<double, double> Model::pieChartOp2() {
    std::pair<double, double> result(rl->getReleased().size(), rl->getNotReleased().size());

    return result;
}

std::pair<double, double> Model::pieChartOp3() {
    std::pair<double, double> result(rl->getTotProfit(rl->getReleaseOnSupport()),
                                     rl->getTotProfit(rl->getReleaseOnPlatform()));

    return result;
}

vector<std::pair<string, double>> Model::barChartOp1(uint year) {
    auto data(getCatalog());
    vector<const Music*> bySupport, byYear;
    vector<std::pair<string, double>> result;

    for (int i = CD; i < None_Support; ++i){
        byYear = rl->getByYear(data, year);
        bySupport = rl->getBySupport(byYear, static_cast<Support>(i));
        result.push_back(std::make_pair(PM::support_names[i], rl->getTotProfit(bySupport)));
    }

    return result;
}

vector<std::pair<string, double>> Model::barChartOp2(uint year) {
    auto data(getCatalog());
    vector<const Music*> byPlatform, byYear;
    vector<std::pair<string, double>> result;

    for (int i = Spotify; i < None_Platform; ++i){
        byYear = rl->getByYear(data, year);
        byPlatform = rl->getByPlatform(byYear, static_cast<Platform>(i));
        result.push_back(std::make_pair(DM::platform_names[i], rl->getTotProfit(byPlatform)));
    }

    return result;
}


