#include "song.h"

Song::Song(string _genre, string _name, string _artist) : Music(_genre), song_name(_name), song_artist(_artist) { }

string Song::getName() const {
    return song_name;
}

string Song::getArtist() const {
    return song_artist;
}
