#include "phisycalmedium.h"

const double PhisycalMedium::price = 12.00;

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

    setProfit();
}

void PhisycalMedium::setProfit() {
    profit = price * num_sales;
}

uint PhisycalMedium::getNumSales() const{
    return num_sales;
}

string PhisycalMedium::getType() const{
    return type;;
}
