#include "music.h"

Music::Music(string _genre) : genre(_genre) { }

string Music::getGenre() const {
    return genre;
}
