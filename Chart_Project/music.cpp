#include "music.h"

Music::Music(string _genre) : genre(_genre) { }

Music::~Music() {}

string Music::getGenre() const {
    return genre;
}
