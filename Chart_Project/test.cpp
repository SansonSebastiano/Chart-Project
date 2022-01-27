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
        auto x = rl.getFromReleased("Flop");
        for (auto it = x.begin(); it != x.end(); ++it)
            cout << (*it)->getInfo() << endl << endl;
        */

        /*
        // problema
        cout << "debug 1" << endl;
        double y = rl.getTotProfit("Flop");
        cout << "debug 2";      // non viene stampato
        cout << Release::profit_to_string(y);
        */

        auto r = rl.getReleased();
        auto nr = rl.getNotReleased();

        for (auto it = r.begin(); it != r.end(); ++it)
            cout << (*it)->getInfo() << endl << endl;

        for (auto it = nr.begin(); it != nr.end(); ++it)
            cout << (*it)->getInfo() << endl << endl;

        const Date dt(9, 9, 1998);

        rl.release(a, dt, Vinile, 60023);
        rl.release(a, dt, AppleMusic, 99999);


    }
};
