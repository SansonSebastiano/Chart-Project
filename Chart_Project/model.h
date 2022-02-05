#ifndef MODEL_H
#define MODEL_H

#include "recordlabel.h"

class Model{
private:
    RecordLabel *rl;
public:
    Model() = default;
    ~Model();   // ??

    // DA COMMENTARE
    // DA DEFINIRE SE CONST

    void newRL(string rl_name);

    void insertAlbum(const Album* album);

    void releaseAlbum(const Album* album);

    void getInfo(/*parametri da definire*/);
};

#endif // MODEL_H
