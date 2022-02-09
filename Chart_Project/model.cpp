#include "model.h"

void Model::insertAlbum(const Album *album){
    rl.insert(album);
}

void Model::releaseAlbum(const Release *album){
    rl.release(album);
    // NON RIMUOVERE : CI POSSONO ESSERE PIU' PUBBLICAZIONI
    //rl.removeFromNotReleased(album);
}

void Model::getAllInfo() const{
    auto r  = rl.getReleased();
    auto nr = rl.getNotReleased();

    for(auto it = r.begin(); it != r.end(); ++it)
        cout << (*it)->getInfo() << endl << endl;

    for(auto it = nr.begin(); it != nr.end(); ++it)
         cout << (*it)->getInfo() << endl << endl;
}
