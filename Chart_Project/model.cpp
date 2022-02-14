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
    vector<const Music*> catalog(rl->getReleased());
    catalog.insert(catalog.end(), rl->getNotReleased().begin(), rl->getNotReleased().end());

    return catalog;
}
