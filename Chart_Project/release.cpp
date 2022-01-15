#include "release.h"

Release::Release(string _genre, string _rd, double _profit,string _sn, string _sa)
    : Music(_genre),
      Song(_genre, _sn, _sa),
      release_date(_rd),
      profit(_profit) { }

Release::Release(string _an, string _aa, string _genre, string _rd, double _profit)
    : Music(_genre),
      Album(_genre, _an, _aa),
      release_date(_rd),
      profit(_profit) {}

string Release::getReleaseDate() const {
    return release_date;
}
