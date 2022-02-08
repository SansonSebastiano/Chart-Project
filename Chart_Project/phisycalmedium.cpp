#include "phisycalmedium.h"

const double PhisycalMedium::cd_price = 15.00;
const double PhisycalMedium::vnl_price = 25.00;
const double PhisycalMedium::cst_price = 15.00;

PhisycalMedium::PhisycalMedium(string _genre, string _album_name, string _album_artist, const Date& _rd, Support _support, uint _ns) :
    Release(_genre, _album_name, _album_artist, _rd),
    support(_support),
    num_sales(_ns) { PhisycalMedium::setProfit(); }

void PhisycalMedium::setProfit() {
    if (support == CD)
        profit = cd_price * num_sales;
    else if (support == Vinile)
        profit = vnl_price * num_sales;
    else
        profit = cst_price * num_sales;
}

uint PhisycalMedium::getNumSales() const{
    return num_sales;
}

Support PhisycalMedium::getSupport() const{
    return support;
}

string PhisycalMedium::getInfo() const {
    return Release::getInfo() + "\n" +
           "Supporto Fisico: " + support_names[support] + "\n" +
           "Vendite Annue: " + std::to_string(num_sales) + "\n" +
           "Profitto Annuo: " + profit_to_string(getProfit());
}

string PhisycalMedium::support_to_string(int value) const { return support_names[value]; }
