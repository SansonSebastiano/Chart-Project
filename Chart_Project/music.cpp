#include "music.h"

Music::Music(const string& _genre) : genre(_genre) { }

string Music::getGenre() const { return genre; }

string Music::getInfo() const { return "Genere: " + genre; }
