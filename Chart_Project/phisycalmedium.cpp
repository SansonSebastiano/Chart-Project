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
    PhisycalMedium::setProfit();
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

string PhisycalMedium::getInfo() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << getProfit();

    return Release::getInfo() + "\n" +
           "Supporto Fisico: " + type + "\n" +
           "Vendite Annue: " + std::to_string(num_sales) + "\n" +
           "Profitto Annuo: " + ss.str() + " €";
}
