#include "digitalmedium.h"

const double DigitalMedium::price = 0.35;
const char* DigitalMedium::platform_str[] = {"Spotify", "AppleMusic", "Tidal", "AmazonMusic", "Deezer", "YouTubeMusic"};

DigitalMedium::DigitalMedium( string _genre, string _album_name, string _album_artist, const Date& _rd, Platform _platform, uint _listeners) :
    Release(_genre, _album_name, _album_artist, _rd),
    platform(_platform),
    listeners(_listeners) { DigitalMedium::setProfit(); }

void DigitalMedium::setProfit(){
    profit = price * listeners;
}

string DigitalMedium::getPlatform() const{
    return platform_str[platform];
}

uint DigitalMedium::getListeners() const{
    return listeners;
}

string DigitalMedium::getInfo() const {

    return Release::getInfo() + "\n" +
           "Piattaforma: " + platform_str[platform] + "\n" +
           "Ascoltatori Annui: " + std::to_string(listeners) + "\n" +
           "Profitto Annuo: " + profit_to_string(getProfit());
}
