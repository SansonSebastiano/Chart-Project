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

    void removeMusic(const Music* music);

    void getAllInfo() const;

    vector<const Music*> getData() const;
    vector<const Music*> getNotReleased() const;

    bool isPresent(const Music*) const;

    bool areEquals(const Music* m1, const Music *m2) const;

    bool isElapsed1Year(const Release *release) const;

    // opzioni grafici:
        // - linechart :
            // -> prendere musica di genere x, pubblicata in un range di anni, prelevare infine profitto (o vendite o costi?) per ogni anno compreso nel range
        // - piechart :
            // -> prelevare un numero x di artisti migliori in assoluto (limite max 10?) della label, in base al profitto (o vendite o costi?)
            // -> percentuale musica pubblicata e non
            // -> confrontare incassi medium fisici vs digitali
        // - bar chart :
            // -> dato un artista x e un suo album y, confrontare i profitti tra i vari medium su cui sono pubblicati l'album y
            // -> dato un anno x, confrontare vendite supporti fisici
            // -> dato un anno x, confrontare ascolti supporti digitali
};

#endif // MODEL_H
