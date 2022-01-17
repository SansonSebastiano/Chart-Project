#ifndef RECORDLABEL_H
#define RECORDLABEL_H

#include "phisycalmedium.h"
#include "digitalmedium.h"
#include <vector>
using std::vector;

class RecordLabel{
private:
    enum pm_type {CD, Vinile, Cassetta};
    enum dm_name {Spotify, AppleMusic, Tidal, AmazonMusic, Deezer, YouTubeMusic};
    vector<const Music*> music;
public:
    RecordLabel();
};

#endif // RECORDLABEL_H
