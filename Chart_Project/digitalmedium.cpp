#include "digitalmedium.h"

const double DigitalMedium::price = 0.35;

DigitalMedium::DigitalMedium( string _genre, string _album_name, string _album_artist, Date _rd, string _sn, uint _listeners) :
    Release(_genre, _album_name, _album_artist, _rd),
    service_name(_sn),
    listeners(_listeners)
{
    DigitalMedium::setProfit();
}

void DigitalMedium::setProfit(){
    profit = price * listeners;
}

string DigitalMedium::getServiceName() const{
    return service_name;
}

uint DigitalMedium::getListeners() const{
    return listeners;
}
