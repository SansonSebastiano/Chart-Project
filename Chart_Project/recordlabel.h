#ifndef RECORDLABEL_H
#define RECORDLABEL_H

#include "phisycalmedium.h"
typedef PhisycalMedium PM;

#include "digitalmedium.h"
typedef DigitalMedium DM;

#include "exceptions.h"         // FARE ECCEZIONI

#include <vector>
using std::vector;

class RecordLabel{
private:
    // raccolta di tutta la musica prodotta, appartenente all'etichetta discografica:
    //  - pubblicata
    //  - non pubblicata
    vector<const Music*> catalog;
public:
    RecordLabel() = default;
    ~RecordLabel();
    /*
     * @brief   inserisce un prodotto musicale nel catalogo dell'etichetta discografica
     * @param   const Music*
     * @ECCEZIONI  da fare
     * @return  void
     */
    void insert(const Music* music);
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica il cui nome e' dato in input
     * @param   const string &name
     * @param   const vector<const Release*> &v
     * @ ECCEZIONI  nel caso il nome sia errato ??
     * @return  vector<const Music*>
     */
    vector<const Music*> getByName(const vector<const Music*> &v, const string& name) const;
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica il cui genere e' dato in input
     * @param   const string &genre
     * @param   const vector<const Release*> &v
     * @ ECCEZIONI  nel caso il genere sia errato ??
     * @return  vector<const Music*>
     */
    vector<const Music*> getByGenre(const vector<const Music*> &v, const string& genre) const;
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica il cui artista e' dato in input
     * @param   const string &artist
     * @param   const vector<const Release*> &v
     * @ ECCEZIONI  nel caso l'artista sia errato ??
     * @return  vector<const Music*>
     */
    vector<const Music*> getByArtist(const vector<const Music*> &v, const string& artist) const;
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica il cui anno e' dato in input
     * @param   const Date& year
     * @param   const vector<const Release*> &v
     * @ ECCEZIONI  nel caso l'anno sia errato ??
     * @return  vector<const Release*>
     */
    vector<const Music*> getByYear(const vector<const Music*> &v, uint year) const;
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica pubblicata in una piattaforma data in input
     * @param   Platform platform
     * @param   const vector<const Release*> &v
     * @ ECCEZIONI  ??
     * @return  vector<const Release*>
     */
    vector<const Music*> getByPlatform(const vector<const Music*> &v, Platform platform) const;
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica pubblicata in un supporto fisico dato in input
     * @param   Support support
     * @param   const vector<const Release*> &v
     * @ ECCEZIONI  ??
     * @return  vector<const Release*>
     */
    vector<const Music*> getBySupport(const vector<const Music*> &v, Support support) const;
    /*
     * @brief   somma e ritorna l'incasso totale di un vettore di musica pubblicata data in input
     * @param   vector<const Release*> r
     * @return  double
     */
    double getTotProfit(const vector<const Music*> &r) const;
    /*
     * @brief   somma e ritorna il numero totale di
     *              - vendite, se il vettore contiene PhiscycalMedium
     *              - ascolti, se il vettore contiene DigitalMedium
     *          di un vettore di musica pubblicata in input
     * @param   vector<const Release*> r
     * @return  unsigned int
     */
    uint getTotNumbers(const vector<const Music*> &r) const;
    /*
     * @brief   restituisce tutta la musica dell'etichetta discografica, quella pubblicata, la ritorna se e solo se e' trascorso almeno un anno dalla sua pubblicazione
     * @return  vector<const Music*>
     */
    vector<const Music*> getAll() const;
    /*
     * @brief   restituisce la musica pubblicata se e solo se e' trascorso almeno un anno dalla sua pubblicazione
     * @return  vector<const Music*>
     */
    vector<const Music*> getReleased() const;
    /*
     * @brief   restituisce la musica non pubblicata
     * @return  vector<const Music*>
     */
    vector<const Music*> getNotReleased() const;
    /*
     * @brief   restituisce tutta la musica pubblicata su supporti fisici
     * @return  vector<const Music*>
     */
    vector<const Music*> getReleaseOnSupport() const;
    /*
     * @brief   restituisce tutta la musica pubblicata su piattaforme digitali
     * @return  vector<const Music*>
     */
    vector<const Music*> getReleaseOnPlatform() const;
    /*
     * @brief   restituisce true se e' trascorso almeno un anno dalla data di pubblicazione di un prodotto musicale in input
     * @param   const Release* release
     * @return  bool
     */
    bool isElapsed1Year(const Release* release) const;
    /*
     * @brief   rimuove prodotto musicale non pubblicato dal catalogo
     * @param   const Music*
     * @ ECCEZIONI  ??
     * @return  void
     */
    void removeNotReleased(const Music* music);
    /*
     * UTILIZZARE L'OVERLOADING DELL'OPERATORE == ??
     * @brief   cerca se un prodotto musicale, passato in input, e' presente nel vettore
     * @param   const Music*
     * @param   const vector<const Music*>
     * @ ECCEZIONI  ??
     * @return  bool
     */
    bool areSame(const Music*, const Music*) const;
};

#endif // RECORDLABEL_H
