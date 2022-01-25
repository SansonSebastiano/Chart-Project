#include "recordlabel.h"

void RecordLabel::insert(const Music* m) {
    if (dynamic_cast<const Release*>(m))    //se m e' un album che e' stato pubblicato
        // forse e' meglio inserire in ordine cronologico?
        released.push_back(m);
    else not_released.push_back(m);
}

double RecordLabel::getTotProfit(const Music* m) const {
    const PM* ptr_pm = dynamic_cast<const PM*>(m);
    const DM* ptr_dm = dynamic_cast<const DM*>(m);
    if (ptr_pm && ptr_dm)
        return ptr_pm->getProfit() + ptr_dm->getProfit();
    else
        //throw (notBothReleased)
        return 0.0;
}
