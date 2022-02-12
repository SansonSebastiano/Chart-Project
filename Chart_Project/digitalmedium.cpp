#include "digitalmedium.h"

const double DigitalMedium::price = 0.25;

const string DigitalMedium::platform_names[]  = { FOREACH_PLATFORMS(GENERATE_STRING) };
const uint DigitalMedium::MAX_SVALUES  = None_Platform + 1;

DigitalMedium::DigitalMedium(const string& _genre, const string& _album_name, const string& _album_artist, const Date& _rd, Platform _platform, uint _listeners) :
    Release(_genre, _album_name, _album_artist, _rd),
    platform(_platform),
    listeners(_listeners) { DigitalMedium::setProfit(); }

void DigitalMedium::setProfit(){
    profit = price * listeners * getElapsedYears();
}

Platform DigitalMedium::getPlatform() const{
    return platform;
}

uint DigitalMedium::getNumbers() const{
    return listeners;
}

string DigitalMedium::getInfo() const {

    return Release::getInfo() + "\n" +
           "Piattaforma: " + platform_names[platform] + "\n" +
           "Ascoltatori Annui: " + std::to_string(listeners) + "\n" +
           "Profitto Annuo: " + double_to_string(getProfit()) + " €";
}
