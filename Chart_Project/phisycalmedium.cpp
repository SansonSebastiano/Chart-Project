#include "phisycalmedium.h"

const double PhisycalMedium::cd_price = 15.00;
const double PhisycalMedium::vnl_price = 25.00;
const double PhisycalMedium::cst_price = 15.00;

const string PhisycalMedium::support_names[] = { FOREACH_SUPPORTS(GENERATE_STRING) };
const uint PhisycalMedium::MAX_PVALUES  = None_Support + 1;

PhisycalMedium::PhisycalMedium(const string& _genre, const string& _album_name, const string& _album_artist, const Date& _rd, Support _support, uint _ns) :
    Release(_genre, _album_name, _album_artist, _rd),
    support(_support),
    num_sales(_ns) { PhisycalMedium::setProfit(); }

void PhisycalMedium::setProfit() {
    if (support == CD)
        profit = cd_price * getElapsedYears();
    else if (support == Vinile)
        profit = vnl_price * num_sales * getElapsedYears();
    else
        profit = cst_price * num_sales * getElapsedYears();
}

uint PhisycalMedium::getNumbers() const{ return num_sales; }

Support PhisycalMedium::getSupport() const{ return support; }

string PhisycalMedium::getInfo() const {
    return Release::getInfo() + "\n" +
           "Supporto Fisico: " + support_names[support] + "\n" +
           "Vendite Annue: " + std::to_string(num_sales) + "\n" +
           "Profitto Annuo: " + double_to_string(getProfit()) + " €";
}
