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
    string RL_name;
    // raccolta di tutta la musica prodotta, appartenente all'etichetta discografica:
    //  - pubblicata
    //  - non pubblicata
    vector<const Music*> catalog;
public:
    RecordLabel(const string& _name = "");
    ~RecordLabel();
    /*
     * @brief   ritorna il nome dell'etichetta discografica
     * @return  string
     */
    string getRLName() const;
    /*
     * @brief   inserisce un prodotto musicale nel catalogo dell'etichetta discografica
     * @pre     per gli album pubblicati: deve essere trascorso almeno un anno dalla sua pubblicazione per essere inserito
     * @param   const Music*
     * @ ECCEZIONI  da fare
     * @return  void
     */
    void insert(const Music* music);
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica il cui nome e' dato in input
     * @param   string &name
     * @param   vector<const Music*> v
     * @ ECCEZIONI  nel caso il nome sia errato ??
     * @return  vector<const Music*>
     */
    vector<const Music*> getByName(vector<const Music*> v, const string& name) const;
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica il cui genere e' dato in input
     * @param   string &genre
     * @param   vector<const Music*> v
     * @ ECCEZIONI  nel caso il genere sia errato ??
     * @return  vector<const Music*>
     */
    vector<const Music*> getByGenre(vector<const Music*> v, const string& genre) const;
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica il cui artista e' dato in input
     * @param   string &artist
     * @param   vector<const Music*> v
     * @ ECCEZIONI  nel caso l'artista sia errato ??
     * @return  vector<const Music*>
     */
    vector<const Music*> getByArtist(vector<const Music*> v, const string& artist) const;
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica il cui anno e' dato in input
     * @param   uint year
     * @param   vector<const Music*> v
     * @ ECCEZIONI  nel caso l'anno sia errato ??
     * @return  vector<const Release*>
     */
    vector<const Release*> getByYear(vector<const Music*> v, uint year) const;
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica pubblicata in un intervallo di anni dato in input
     * @param   vector<const Music*> v
     * @param   Date &from
     * @param   Date &to
     * @ ECCEZIONI  ??
     * @return  vector<const Release*>
     */
    vector<const Release*> getBetweenYears(vector<const Music*> v, const Date& from, const Date& to) const;
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica pubblicata in una piattaforma data in input
     * @param   Platform platform
     * @param   vector<const Release*> v
     * @ ECCEZIONI  ??
     * @return  vector<const Release*>
     */
    vector<const Release*> getByPlatform(vector<const Release*> v, Platform platform) const;
    /*
     * @brief   scansiona il vettore in input e restituisce tutta la musica pubblicata in un supporto fisico dato in input
     * @param   Support support
     * @param   vector<const Release*> v
     * @ ECCEZIONI  ??
     * @return  vector<const Release*>
     */
    vector<const Release*> getBySupport(vector<const Release*> v, Support support) const;
    /*
     * @brief   somma e ritorna l'incasso totale di un vettore di musica pubblicata data in input
     * @param   vector<const Release*> r
     * @return  double
     */
    double getTotProfit(vector<const Release*> r) const;
    /*
     * @brief   somma e ritorna il numero totale di
     *              - vendite, se il vettore contiene PhiscycalMedium
     *              - ascolti, se il vettore contiene DigitalMedium
     *          di un vettore di musica pubblicata in input
     * @param   vector<const Release*> r
     * @return  unsigned int
     */
    uint getTotNumbers(vector<const Release*> r) const;
    /*
     * @brief   restituisce tutta la musica dell'etichetta discografica
     * @return  vector<const Music*>
     */
    vector<const Music*> getAll();
    /*
     * @brief   restituisce la musica pubblicata
     * @return  vector<const Music*>
     */
    vector<const Music*> getReleased() const;
    /*
     * @brief   restituisce la musica non pubblicata
     * @return  vector<const Music*>
     */
    vector<const Music*> getNotReleased() const;
    /*
     * €pre     trascorso almeno un anno dalla data di pubblicazione di 'release'
     * @brief   pubblica un prodotto musicale (in input) su un supporto fisico/digitale se e' passato almeno un anno dalla sua pubblicazione
     * @param   const Release* release
     * @ ECCEZIONI  ??
     * @return  void
     */
    void release(const Release* release);
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

    // POSSIBILITA DI TOGLIERE UN ALBUM DA 'released' ?
};

#endif // RECORDLABEL_H
