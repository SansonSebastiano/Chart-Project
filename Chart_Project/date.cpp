#include "date.h"

uint Date::getMonthDay(uint _year, uint _month) const {
    static uint month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((_month == 2) && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))) return 29;   // anno bisestile
    return month_days[_month];
}

Date::Date(uint _day, uint _month, uint _year) {
    if (_year >= 1900 &&
        _month > 0 && _month < 13 &&
        _day > 0 && _day <= getMonthDay(_year, _month)){
        day = _day;
        month = _month;
        year = _year;
    }
    else cout << "Illegal date!" << endl;   // da gestire con le eccezioni?
}

string Date::getDate() const {
    if (month > 0 && month < 10)
        return std::to_string(day) + "/" +
               "0" + std::to_string(month) + "/" +
               std::to_string(year);
    return std::to_string(day) + "/" +
           std::to_string(month) + "/" +
           std::to_string(year);
}

// Overloading operatori di confronto tra date

bool Date::operator>(const Date &d) const {
    if (year > d.year) return true;
    else if (year == d.year) {
        if (month > d.month) return true;
        else if (month == d.month)
            if (day > d.day) return true;
    }
    return false;
}

bool Date::operator<(const Date &d) const {
    if ((!(*this > d) && !(*this == d))) return true;
    return false;
}

bool Date::operator==(const Date &d) const {
    if(year == d.year &&
       month == d.month &&
       day == d.day) return true;
    return false;
}

bool Date::operator!=(const Date &d) const {
    if (!(*this == d)) return true;
    return false;
}

bool Date::operator>=(const Date &d) const{
    if ((*this == d) || (*this > d)) return true;
    return false;
}

bool Date::operator<=(const Date &d) const {
    if ((*this == d) || (*this < d)) return true;
    return false;
}
