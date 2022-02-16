#include "model.h"

Model::Model(const string& label) : rl(new RecordLabel(label)) { }

void Model::insertMusic(const Music *album){ rl->insert(album); }

void Model::releaseMusic(const Release *album){
    rl->release(album);
    // NON RIMUOVERE : CI POSSONO ESSERE PIU' PUBBLICAZIONI
    //rl.removeFromNotReleased(album);
}

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
    auto released = rl->getReleased();
    auto not_released = rl->getNotReleased();
    vector<const Music*> catalog;
    catalog.reserve(released.size() + not_released.size());
    catalog.insert(catalog.end(), released.begin(), released.end());
    catalog.insert(catalog.end(), not_released.begin(), not_released.end());

    return catalog;
}
