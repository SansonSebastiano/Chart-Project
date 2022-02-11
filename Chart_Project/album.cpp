#include "album.h"

Album::Album(const string& _genre, const string& _name, const string& _artist) : Music(_genre), name(_name), artist(_artist) { }

string Album::getAlbumName() const { return name; }

string Album::getAlbumArtist() const { return artist; }

string Album::getInfo() const {
    return "Album: " + name + "\n" +
           "Artista: " + artist + "\n" +
           Music::getInfo();
}
