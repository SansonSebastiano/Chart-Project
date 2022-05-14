#ifndef MODEL_H
#define MODEL_H

#include <algorithm>
#include "recordlabel.h"

class Model{
private:
    RecordLabel *rl;
public:
    Model();
    ~Model() = default;   // DA IMPLEMENTARE : *rl nello heap !!
    /*
     * @brief   inserisce nuova musica nel catalogo dell'etichetta discografica
     * @param   const Music*
     * @return  void
     */
    void insertMusic(const Music* music);
    /*
     * @brief   rimuove musica non pubblicata (NB: che e' stata pero' pubblicata appena prima dell'invocazione di questa funzione) dal catalogo dell'etichetta discografica
     * @param   const Music*
     * @return  void
     */
    void removeMusic(const Music* music);
    // DA ELIMINARE ?
    void getCatalogInfo() const;
    /*
     * @brief   ritorna l'intero catalogo dell'etichetta discografica
     *          (NB: della musica pubblicata, viene prevelata soltanto se dalla data della sua pubblicazione e' passato almeno un anno)
     * @return  vector<const Music*>
     */
    vector<const Music*> getCatalog() const;
    /*
     * @brief   ritorna tutta la musica non pubblicata dell'etichetta discografica
     * @return  vector<const Music*>
     */
    vector<const Music*> getNotReleasedMusic() const;
    /*
     * @brief   controlla se nel catalogo e' presente la musica passata in input
     * @param   const Music*
     * @return  bool
     */
    bool isPresent(const Music*) const;
    // vedi 'areSame' in 'recordlabel.h'
    bool areEquals(const Music* m1, const Music *m2) const;
    // vedi 'isElapsed1Year' in 'recordlabel.h'
    bool isElapsed1Year(const Release *release) const;
    /*
     * @brief   ritorna tutti gli artisti dell'etichetta discografica
     * @return  vector<string>
     */
    vector<string> getArtists() const;
    /*
     * @brief   ritorna tutti i generi musicali dell'etichetta discografica
     * @return  vector<string>
     */
    vector<string> getGenres() const;

    // opzioni grafici:
    // - LINE CHART :
    /*
     * @brief   preleva musica di genere x, pubblicata in un range di anni, calcola infine il profitto per ogni anno compreso nel range
     * @param   const string &
     * @param   unsigned int
     * @param   unsigned int
     * @param   vector<const Music*> &
     * @return vector<unsigned int>
     */
    vector<uint> lineChartOp1(const string &genre, uint from, uint to, vector<const Music*> &data);
    // - PIE CHART :
    /*
     * @brief   preleva un numero x (per ora 5, senza possibilita' di scelta) di artisti migliori in assoluto della label, in base al profitto
     * @return  vector<std::pair<double, string>>
     */
    vector<std::pair<double, string>> pieChartOp1();
    /*
     * @brief   ritorna la quantita' di musica pubblicata e non
     * @return  vector<std::pair<double, double>>
     */
    std::pair<double, double> pieChartOp2();
    /*
     * @brief   confronta gli incassi tra medium fisici e digitali
     * @return  vector<std::pair<double, double>>
     */
    std::pair<double, double> pieChartOp3();
    // - BAR CHART :
    /*
     * @brief   dato un anno x, confronta le vendite su supporti fisici
     * @param   unsigned int
     * @return  vector<std::pair<string, double>>
     */
    vector<std::pair<string, double>> barChartOp1(uint year);
    /*
     * @brief   dato un anno x, confronta gli ascolti su piattaforme digitali
     * @param   unsigned int
     * @return  vector<std::pair<string, double>>
     */
    vector<std::pair<string, double>> barChartOp2(uint year);
};

#endif // MODEL_H
