#include "recordlabel.h"

class test{
public:
    void testing(){

        const Date d (12, 9, 2000);
        PhisycalMedium  *pm = new PhisycalMedium("Rap", "Flop", "Salmo", d, CD, 1450);
        DigitalMedium *dm = new DigitalMedium("Rap", "Flop", "Salmo", d, Spotify, 1450450);

        const Album *a = new Album("Rap", "Nessuno", "Articolo 31");

        RecordLabel rl;
        rl.insert(pm);
        rl.insert(dm);
        rl.insert(a);

        /*
        // FUNZIONA
        auto x = rl.getReleasedByName("Flop");
        for (auto it = x.begin(); it != x.end(); ++it)
            cout << (*it)->getInfo() << endl << endl;


        // FUNZIONA
        double y = rl.getTotProfit("Flop");
        cout << "Profitto totale: " + Release::profit_to_string(y) << endl;
        */


        // FUNZIONA
        /*
        auto r = rl.getReleased();
        auto nr = rl.getNotReleased();

        for (auto it = r.begin(); it != r.end(); ++it)
            cout << (*it)->getInfo() << endl << endl;

        for (auto it = nr.begin(); it != nr.end(); ++it)
            cout << (*it)->getInfo() << endl << endl;

        cout << "----------------------------" << endl;

        const Date dt(9, 9, 1998);

        rl.release(a, dt, Vinile, 60023);
        rl.release(a, dt, AppleMusic, 99999);

        rl.removeFromNotReleased(a);

        auto r1 = rl.getReleased();
        auto nr1 = rl.getNotReleased();

        for (auto it = r1.begin(); it != r1.end(); ++it)
            cout << (*it)->getInfo() << endl << endl;

        for (auto it = nr1.begin(); it != nr1.end(); ++it)
            cout << (*it)->getInfo() << endl << endl;
        */
    }
};
