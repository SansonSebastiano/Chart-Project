#include "release.h"

Release::Release(const string& _genre, const string& _album_name, const string& _artist_name, const Date& _rd) :
    Album(_genre, _album_name, _artist_name),
    release_date(_rd) { }

Date Release::getReleaseDate() const { return release_date; }

double Release::getProfit() const { return profit; }

uint Release::getElapsedYears() const { return ((Date::getNow() - release_date) / 365); }

string Release::getInfo() const {
    return Album::getInfo() + "\n" +
           "Pubblicato il : " + release_date.getDate();
}

string Release::profit_to_string(double profit) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << profit;

    return ss.str() + " €";
}

