#include "album.h"

Album::Album(string _genre, string _name, string _artist) : Music(_genre), album_name(_name), album_artist(_artist) { }

string Album::getName() const {
    return album_name;
}

string Album::getArtist() const {
    return album_artist;
}
