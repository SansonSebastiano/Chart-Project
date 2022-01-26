#include "recordlabel.h"

class test{
public:
    void testing(){
        Date d = Date(12, 01, 2000);
        PhisycalMedium  *pm = new PhisycalMedium("Rap", "Flop", "Salmo", d, CD, 1450);
        DigitalMedium *dm = new DigitalMedium("Rap", "Flop", "Salmo", d, Spotify, 1450450);

        Album *a = new Album("Rap", "Nessuno", "Articolo 31");

        RecordLabel rl;
        rl.insert(pm);
        rl.insert(dm);
        rl.insert(a);


        auto x = rl.getFromReleased("Flop");
        for (auto it = x.begin(); it != x.end(); ++it)
            cout << (*it)->getInfo() << endl << endl;

        // DA Sistemare
        /*
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << rl.getTotProfit("Flop");
        cout << "Tot profit: " << ss.str() + " €";
        */
    }
};
