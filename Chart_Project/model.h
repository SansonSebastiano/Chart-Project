#ifndef MODEL_H
#define MODEL_H

#include "recordlabel.h"

class Model{
private:
    RecordLabel *rl;
public:
    Model(const string& label = "");
    ~Model() = default;   // ??

    // DA COMMENTARE
    // DA DEFINIRE SE CONST

    //void newRL(string rl_name);

    void insertMusic(const Music* album);

    void releaseMusic(const Release* album);

    void getAllInfo() const;

    bool isPresent(const Music*) const;

    vector<const Music*> getData() const;
};

#endif // MODEL_H
