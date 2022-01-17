#include "release.h"

Release::Release(string _genre, string _album_name, string _artist_name, Date _rd) :
    Album(_genre, _album_name, _artist_name),
    release_date(_rd) {}

Date Release::getReleaseDate() const {
    return release_date;
}

double Release::getProfit() const{
    return profit;
}
