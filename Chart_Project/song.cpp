#include "song.h"

Song::Song(string _genre, string _name, string _artist) : Music(_genre), name(_name), artist(_artist) { }

string Song::getSongName() const {
    return name;
}

string Song::getSongArtist() const {
    return artist;
}
