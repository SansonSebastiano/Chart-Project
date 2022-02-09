#ifndef MODEL_H
#define MODEL_H

#include "recordlabel.h"

// CONTROLLARE IL POLIMORFISMO:
    // - RecordLabel *rl

class Model{
private:
    RecordLabel rl;
public:
    Model() = default;
    ~Model() = default;   // ??

    // DA COMMENTARE
    // DA DEFINIRE SE CONST

    void newRL(string rl_name);

    void insertAlbum(const Album* album);

    void releaseAlbum(const Release* album);

    void getAllInfo() const;
};

#endif // MODEL_H
