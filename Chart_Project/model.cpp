#include "model.h"

Model::Model(const string& label) : rl(new RecordLabel(label)) { }

void Model::insertMusic(const Music *music){ rl->insert(music); }

void Model::releaseMusic(const Release *release){ rl->release(release); }

void Model::removeMusic(const Music *music) { rl->removeNotReleased(music); }

void Model::getAllInfo() const{
    auto r  = rl->getReleased();
    auto nr = rl->getNotReleased();

    cout << "Album non rilasciati: " << endl << endl;

    for(auto it = nr.begin(); it != nr.end(); ++it)
         cout << (*it)->getInfo() << endl << endl;

    cout << "Album rilasciati: " << endl << endl;

    for(auto it = r.begin(); it != r.end(); ++it)
        cout << (*it)->getInfo() << endl << endl;
}

vector<const Music*> Model::getData() const {
    auto all = rl->getAll();

    vector<const Music*> catalog;
    catalog.reserve(all.size());
    catalog.insert(catalog.end(), all.begin(), all.end());

    return catalog;
}

vector<const Music*> Model::getNotReleased() const { return rl->getNotReleased(); }

bool Model::isPresent(const Music *m) const {
    auto all = rl->getAll();
    bool found(false);

    for (auto it = all.begin(); it != all.end() && !found; ++it)
        if (rl->areSame((*it), m))
            found = true;

    return found;
}

bool Model::areEquals(const Music *m1, const Music *m2) const {
    return rl->areSame(m1, m2);
}

bool Model::isElapsed1Year(const Release *release) const {
    return rl->isElapsed1Year(release);
}
