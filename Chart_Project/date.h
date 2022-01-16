#ifndef DATE_H
#define DATE_H

#include <iostream>
using std::cout;
using std::endl;

typedef unsigned int uint;

class Date{
private:
    uint day, month, year;
public:
    Date(uint _day = 0, uint _month = 0, uint _year = 0);
    ~Date() = default;
    /*
     * @brief   restituisce il giorno specifico in base al mese
     * @return  uint
     */
     uint getMonthDay(uint _year, uint _month) const;
};

#endif // DATE_H
