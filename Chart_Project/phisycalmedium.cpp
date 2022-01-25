#include "phisycalmedium.h"

const double PhisycalMedium::price = 12.00;
const char* PhisycalMedium::support_str [] = {"CD", "Vinile", "Cassetta"};

PhisycalMedium::PhisycalMedium(string _genre, string _album_name, string _album_artist, Date _rd, Support _support, uint _ns) :
    Release(_genre, _album_name, _album_artist, _rd),
    support(_support),
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

string PhisycalMedium::getSupport() const{
    return support_str[support];
}

string PhisycalMedium::getInfo() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << getProfit();

    return Release::getInfo() + "\n" +
           "Supporto Fisico: " + support_str[support] + "\n" +
           "Vendite Annue: " + std::to_string(num_sales) + "\n" +
           "Profitto Annuo: " + ss.str() + " €";
}
