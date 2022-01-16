#include "phisycalmedium.h"

double PhisycalMedium::price = 12.00;

PhisycalMedium::PhisycalMedium(string _genre,
                               string _album_name,
                               string _album_artist,
                               Date _rd,
                               string _type,
                               uint _ns) :
    Release(_genre, _album_name, _album_artist, _rd),
    type(_type),
    num_sales(_ns)
{
    // messaggio di warning:
    // Call to virtual method 'PhisycalMedium::setProfit' during construction bypasses virtual dispatch
    // cercando su stackoverflow : https://stackoverflow.com/questions/16719460/calling-a-virtual-function-from-the-constructor
    // si evince che generalmentee' errato invocare un metodo virtuale all'interno di un costruttore,
    // tuttavia l'eccezione vuole che se il comportamento e' BEN DEFINITO non comporta ad UNDEFINED BEHAVIOUR

    // da testare : dunque sistemare la classe per gli output
    setProfit();
}

void PhisycalMedium::setProfit() {
    profit = price * num_sales;
}

double PhisycalMedium::getProfit() const {
    return profit;
}
