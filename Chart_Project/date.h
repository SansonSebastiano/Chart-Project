#ifndef DATE_H
#define DATE_H

#include <ctime>
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
     * @brief   restituisce la data attuale
     * @return  Date
     */
    static Date getNow();
     /*
      * @brief   restituisce la data
      * @return  string
      */
     string getDate() const;
     /*
      * @brief   restituisce il giorno
      * @return  unsigned int
      */
     uint getDay() const;
     /*
      * @brief   restituisce il mese
      * @return  unsigned int
      */
     uint getMonth() const;
     /*
      * @brief   restituisce l'anno
      * @return  unsigned int
      */
     uint getYear() const;
     /*
      * @brief      overloading operatori per il confronto tra date
      * @param      const Date &d    data da confrontare
      * @return     bool
      */
     bool operator > (const Date& d) const;
     bool operator >= (const Date& d) const;
     bool operator < (const Date& d) const;
     bool operator <= (const Date& d) const;
     bool operator == (const Date& d) const;
     bool operator != (const Date& d) const;
     /*
      * @brief   restituisce la differenza di giorni tra due date
      * @param   const Date &d
      * @return  unsigned int
      */
     uint operator-(const Date& d);
     /*
      * @brief   incrementa i giorni
      * @param   uint day
      * @return  unsigned int
      */
     Date& operator +=(int _day);


};

#endif // DATE_H
