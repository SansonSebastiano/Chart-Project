#ifndef RECORDLABEL_H
#define RECORDLABEL_H

#include "phisycalmedium.h"
typedef PhisycalMedium PM;

#include "digitalmedium.h"
typedef DigitalMedium DM;

#include "exceptions.h"

#include <vector>
using std::vector;

class RecordLabel{
private:
    string RL_name;
    // raccolta di tutta la musica prodotta, appartenente all'etichetta discografica:
    //  - pubblicata
    //  NB: un album pubblicato, lo e' sia su supporto fisico che digitale !
    //  NB: un album puo' essere in vendita/pubblicato su piu' supporti fisici/digitali
    vector<const Release*> released;
    // - non ancora pubblicata
    vector<const Music*> not_released;
public:
    RecordLabel(const string& _name = ""); // TOGLIERE IL PARAMETRO DI DEFAULT ??
    ~RecordLabel();
    /*
     * @brief   ritorna il nome dell'etichetta discografica
     * @return  string
     */
    string getRLName() const;
    /*
     * @brief   pensa a come fare la insert:
     *          - PER GLI ALBUM PUBBLICATI (ovvero che andranno nel vettore 'released'
     *              - in ordine cronologico? (ovviamente per gli album pubblicati)
     *              -
     *          - PER GLI ALBUM ANCORA NON PUBBLICATI (ovvero che andranno nel vettore 'not_released'
     *              -
     * @param   const Album*
     * @ ECCEZIONI  da fare
     * @return  void
     */
    void insert(const Music* music);
    /*
     * @brief   scansiona il vettore in input ed "estrae" tutti gli album (e le relative pubblicazioni, se pubblicato) il cui nome e' dato in input
     * @pre     per gli album pubblicati: deve essere trascorso almeno un anno dalla sua pubblicazione per essere inserito
     * @param   string album_name, vector<const Music*> v
     * @ ECCEZIONI  nel caso il nome dell'album sia errato
     * @return  vector<const Music*>
     */
    vector<const Music*> getByName(vector<const Music*> v, const string& album_name) const;
    vector<const Music*> getByGenre(vector<const Music*> v, const string& genre) const;
    vector<const Music*> getByArtist(vector<const Music*> v, const string& artist) const;

    vector<const Release*> getByYear(vector<const Release*> v, const Date& date) const;
    template<class T>
    vector<const Release*> getByMedium(vector<const Release*> v, T medium) const;
    /*
     * @brief   scansiona 'released' ed "estrae" tutte le pubblicazioni dell'album il cui nome e' dato in input
     * @pre     per gli album pubblicati: deve essere trascorso almeno un anno dalla sua pubblicazione per essere inserito
     * @param   string album_name
     * @ ECCEZIONI  nel caso il nome dell'album sia errato o non sia stato pubblicato
     * @return  vector<const Release*>
     */
    vector<const Release*> getReleasedByName(const string& album_name) const;
    /*
     * @brief   scansiona 'released' ed "estrae" tutti gli album pubblicati dello stesso genere dato in input
     * @param   string genre
     * @ ECCEZIONI  ??
     * @return  vector<const Release*>
     */
    vector<const Release*> getReleasedByGenre(const string& genre) const;
    /*
     * @brief   scansiona 'released' ed "estrae" tutti gli album pubblicati dello stesso artista dato in input
     * @param   string artist
     * @ ECCEZIONI  ??
     * @return  vector<const Release*>
     */
    vector<const Release*> getReleasedByArtist(const string& artist) const;
    /*
     * @brief   scansiona 'released' ed "estrae" tutti gli album pubblicati nella stesso anno dato in input
     * @param   Date date
     * @ ECCEZIONI  ??
     * @return  vector<const Release*>
     */
    vector<const Release*> getReleasedByYear(const Date& date) const;
    /*
     * @brief   scansiona 'released' ed "estrae" tutti gli album pubblicati nella stessa piattaforma data in input
     * @param   Platform platform
     * @ ECCEZIONI  ??
     * @return  vector<const Release*>
     */
    vector<const DigitalMedium*> getReleasedByPlatform(Platform platform) const;
    /*
     * @brief   scansiona 'released' ed "estrae" tutti gli album pubblicati nello stesso supporto fisico dato in input
     * @param   Support support
     * @ ECCEZIONI  ??
     * @return  vector<const Release*>
     */
    vector<const PhisycalMedium*> getReleasedBySupport(Support support) const;
    /*
     * @brief   scansiona 'released' ed "estrae" tutti gli album pubblicati in un intervallo di anni
     * @param   vector<const Release*> v, Date from, Date to
     * @ ECCEZIONI  ??
     * @return  vector<const Release*>
     */
    vector<const Release*> getBetweenYears(vector<const Release*> v, const Date& from, const Date& to) const;
    /*
     * @brief   somma e ritorna l'incasso totale di alcuni album pubblicati
     * @param   vector<const Release*> r
     * @return  double
     */
    double getTotProfit(vector<const Release*> r) const;
    /*
     * @brief   somma e ritorna il numero totale di vendite/ascolti di alcuni album pubblicati
     * @param   vector<const Release*> r
     * @return  unsigned int
     */
    uint getTotNumbers(vector<const Release*> r) const;
    /*
     * @brief   restituisce gli album pubblicati
     * @return  vector<const Music*>
     */
    vector<const Release*> getReleased() const;
    /*
     * @brief   restituisce gli album non pubblicati
     * @return  vector<const Music*>
     */
    vector<const Music*> getNotReleased() const;
    /*
     * @brief   pubblica un album su un supporto fisico/digitale se e' passato almeno un anno dalla sua pubblicazione
     * @param   const Album*, Date, Support/Platform, num_sales/listeners
     * @ ECCEZIONI  ??
     * @return  void
     */
    void release(const Release* album);
    /*
     * @brief   restituisce true se e' trascorso almeno un anno dalla sua pubblicazione
     * @return  bool
     */
    bool isElapsed1Year(const Release* album) const;
    /*
     * @brief   rimuove un album da not_release
     * @param   const Album*
     * @ ECCEZIONI  ??
     * @return  void
     */
    void removeFromNotReleased(const Music* music);

    // POSSIBILITA DI TOGLIERE UN ALBUM DA 'released' ?
};

#endif // RECORDLABEL_H
