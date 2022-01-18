#ifndef DATE_H
#define DATE_H

#include <iostream>
using std::cout;
using std::endl;
using std::string;

typedef unsigned int uint;

class Date{
private:
    uint day, month, year;
    /*
     * @brief   restituisce il giorno specifico in base al mese
     * @return  uint
     */
     uint getMonthDay(uint _year, uint _month) const;
public:
    Date(uint _day = 0, uint _month = 0, uint _year = 0);
    ~Date() = default;
     /*
      * @brief   restituisce la data
      * @return  string
      */
     string getDate() const;
};

#endif // DATE_H
