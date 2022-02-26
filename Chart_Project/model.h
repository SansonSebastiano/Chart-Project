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

    void insertMusic(const Music* music);

    void releaseMusic(const Release* release);

    void removeMusic(const Music* music);

    void getAllInfo() const;

    vector<const Music*> getData() const;
    vector<const Music*> getNotReleased() const;

    bool isPresent(const Music*) const;

    bool areEquals(const Music* m1, const Music *m2) const;

    bool isElapsed1Year(const Release *release) const;
};

#endif // MODEL_H
