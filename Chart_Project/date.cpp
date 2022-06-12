#include "date.h"

uint Date::getMonthDay(uint _year, uint _month) const {
    // giorni rispettivi per ciascun mese
    static uint month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((_month == 2) && ((_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0))) return 29;   // anno bisestile
    return month_days[_month];
}

Date::Date(uint _day, uint _month, uint _year) {
    // validazione della data
    if (_year >= 1900 &&
        _month > 0 && _month < 13 &&
        _day > 0 && _day <= getMonthDay(_year, _month)){    // se il giorno e' presente nel mese corrispondente

        day = _day;
        month = _month;
        year = _year;
    }
    //else cout << "Illegal date!" << endl;   // da gestire con le eccezioni?
    else throw err_illegalDate();
}

Date Date::getNow() {
    std::time_t now = std::time(nullptr);
    std::tm *ptm = std::localtime(&now);

    return Date(ptm->tm_mday, 1 + ptm->tm_mon, 1900 + ptm->tm_year);
}

string Date::getDate() const {
    return std::to_string(day) + "/" +
           std::to_string(month) + "/" +
           std::to_string(year);
}

uint Date::getDay() const { return day; }

uint Date::getMonth() const { return month; }

uint Date::getYear() const { return year; }

uint Date::operator-(const Date &d) {
    if(*this < d){
        int count = 0;
        Date res(*this);
        while (1) {
            res += 1;
            count++;
            if(res == d) return count;
        }
    }
    else if (*this > d) {
        int count = 0;
        Date ret(d);
        while (1) {
            ret += 1;
            count++;
            if(ret == *this) return count;
        }
    }
    return 0;
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

Date& Date::operator+=(int _day) {
    day += _day;
    while (day > getMonthDay(year, month)) {
        day -= getMonthDay(year, month);
        month++;
        if(month == 13){
            year++;
            month = 1;
        }
    }
    return *this;
}
