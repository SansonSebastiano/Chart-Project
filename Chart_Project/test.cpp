#include "phisycalmedium.h"
#include "digitalmedium.h"

class test{
public:
    void testing(){
        Date d = Date(12, 01, 2000);
        PhisycalMedium pm =  PhisycalMedium("Rap", "Flop", "Salmo", d, "CD", 1450);
        DigitalMedium dm = DigitalMedium("Rap", "Flop", "Salmo", d, "Spotify", 1450450);

        cout << pm.getInfo() << endl << endl << dm.getInfo() << endl;
    }
};
