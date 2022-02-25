#include "album.h"

Album::Album(const string& _genre, const string& _name, const string& _artist) : Music(_genre), name(_name), artist(_artist) { }

string Album::getName() const { return name; }

string Album::getArtist() const { return artist; }

string Album::getInfo() const {
    return "Album: " + name + " | " +
           "Artista: " + artist + " | " +
           Music::getInfo();
}

