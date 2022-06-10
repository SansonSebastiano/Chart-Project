#include "phisycalmedium.h"

// imposta i costi di default per copia di vari tipi di supporti
const double PhisycalMedium::cd_price = 15.00;
const double PhisycalMedium::vnl_price = 25.00;
const double PhisycalMedium::cst_price = 15.00;

const string PhisycalMedium::support_names[] = { FOREACH_SUPPORTS(GENERATE_STRING) };
const uint PhisycalMedium::MAX_PM_VALUES  = None_Support + 1;

PhisycalMedium::PhisycalMedium(const string& _genre, const string& _album_name, const string& _album_artist, const Date& _rd, Support _support, uint _ns) :
    Release(_genre, _album_name, _album_artist, _rd),
    support(_support),
    num_sales(_ns) { PhisycalMedium::calcProfit(); }

void PhisycalMedium::calcProfit() {
    if (support == CD)
        setProfit(cd_price * num_sales * getElapsedYears());    // profitto = costo CD * #vendite medie annuo * anni trascorsi
    else if (support == Vinile)
        setProfit(vnl_price * num_sales * getElapsedYears());   // profitto = costo Vinile * #vendite medie annuo * anni trascorsi
    else
        setProfit(cst_price * num_sales * getElapsedYears());   // profitto = costo Cassetta * #vendite medie annuo * anni trascorsi
}

uint PhisycalMedium::getNumbers() const{ return num_sales; }

Support PhisycalMedium::getSupport() const{ return support; }

string PhisycalMedium::getInfo() const {
    return Release::getInfo() + "\n" +
           "Supporto Fisico: " + support_names[support] + "\n" +
           "Vendite Annue: " + std::to_string(num_sales) + "\n" +
           "Profitto: " + customProfitFormatting(getProfit()) + " €";
}
