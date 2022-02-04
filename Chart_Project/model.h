#ifndef MODEL_H
#define MODEL_H

#include "recordlabel.h"

class Model{
private:
    RecordLabel *rl;
public:
    Model(string rl_name);
    ~Model();

    void newRL(string rl_name);

    void insertAlbum(RecordLabel _rl);

    void releaseAlbum(RecordLabel _rl);
};

#endif // MODEL_H
