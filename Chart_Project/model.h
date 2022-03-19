#ifndef MODEL_H
#define MODEL_H

#include <algorithm>
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

    vector<string> getArtists() const;
    vector<string> getGenre() const;

    // opzioni grafici:
        // - linechart :
            // -> prendere musica di genere x, pubblicata in un range di anni, prelevare infine profitto (o vendite o costi?) per ogni anno compreso nel range
    vector<uint> lineChartOp1(const string &genre, uint from, uint to, vector<const Music*> &data);
        // - piechart :
            // -> prelevare un numero x (per ora 5, senza possibilita' di scelta) di artisti migliori in assoluto della label, in base al profitto (o vendite o ascolti?)
    vector<std::pair<double, string>> pieChartOp1();
            // -> percentuale musica pubblicata e non
    std::pair<double, double> pieChartOp2();
            // -> confrontare incassi medium fisici vs digitali
    std::pair<double, double> pieChartOp3();
        // - bar chart :
            // -> dato un artista x, confrontare i profitti tra i vari medium su cui e' pubblicata la sua musica
            // -> dato un anno x, confrontare vendite supporti fisici vs digitali
    void barChartOp2();
};

#endif // MODEL_H
