#include "album.h"

Album::Album(string _genre, string _name, string _artist) : Music(_genre), name(_name), artist(_artist) { }

string Album::getAlbumName() const {
    return name;
}

string Album::getAlbumArtist() const {
    return artist;
}
