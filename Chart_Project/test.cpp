#include <QtXml>
#include <QtDebug>

#include "recordlabel.h"

class test{
public:
    void retrieveData(QDomElement root, QString tag, QString att){
        QDomNodeList nodes = root.elementsByTagName(tag);
        qDebug() << "# nodes = " << nodes.count() << endl;

        for(int i = 0; i < nodes.count(); i++){
            QDomNode node = nodes.at(i);
            if(node.isElement()){
                QDomElement elem = node.toElement();
                qDebug() << elem.attribute(att);
            }
        }
    }

    void testing(){
        QDir dir("../Chart_Project/RecordLabel");
         qDebug() << dir << endl;
    }
};

/*
const Date d (12, 9, 2000);
const Date d1(15, 10, 1981);
const Date d2(21, 3, 1980);
const Date d3(21, 3, 2001);
PhisycalMedium  *pmFlop = new PhisycalMedium("Rap", "Flop", "Salmo", d, CD, 1450);
DigitalMedium *dmFlop = new DigitalMedium("Rap", "Flop", "Salmo", d, Spotify, 1450450);
DigitalMedium *dmNevermind = new DigitalMedium ("Rock", "Nevermind", "Nirvana", d1, AppleMusic, 390);
PhisycalMedium *pmEvening = new PhisycalMedium ("R&B", "An Evening With Silk Sonic", "Silk Sonic", d2, Cassetta,456);
DigitalMedium *dmTheWater = new DigitalMedium ("Jazz", "The Water", "Mick Jenkins", d3, Spotify, 567);

const Album *a = new Album("Rap", "Nessuno", "Articolo 31");

RecordLabel rl("Machete");
rl.insert(pmFlop);
rl.insert(dmFlop);
rl.insert(a);
rl.insert(dmNevermind);
rl.insert(pmEvening);
rl.insert(dmTheWater);
*/
/*
// testato anche con tutti gli altri 'getReleaseBy...'
auto v = rl.getReleasedByPlatform(Spotify);
for(auto it = v.begin(); it != v.end(); ++it)
    cout << (*it)->getInfo() << endl << endl;
*/

// FUNZIONA
/*
//auto v = rl.getReleasedByGenre("Rap");
//auto v = rl.getBetweenYears(rl.getReleasedByGenre("Rock"), d1, d);
for(auto it = v.begin(); it != v.end(); ++it)
    cout << (*it)->getInfo() << endl << endl;
*/

/*
// FUNZIONA
auto x = rl.getReleasedByName("Flop");
for (auto it = x.begin(); it != x.end(); ++it)
    cout << (*it)->getInfo() << endl << endl;


// FUNZIONA
// Attenzione: getTotProfit ora vuole un vettore di release
double y = rl.getTotProfit("Flop");
cout << "Profitto totale: " + Release::profit_to_string(y) << endl;
*/


// FUNZIONA
/*
auto r = rl.getReleased();
auto nr = rl.getNotReleased();

for (auto it = r.begin(); it != r.end(); ++it)
    cout << (*it)->getInfo() << endl << endl;

for (auto it = nr.begin(); it != nr.end(); ++it)
    cout << (*it)->getInfo() << endl << endl;

cout << "----------------------------" << endl;

const Date dt(9, 9, 1998);

rl.release(a, dt, Vinile, 60023);
rl.release(a, dt, AppleMusic, 99999);

rl.removeFromNotReleased(a);

auto r1 = rl.getReleased();
auto nr1 = rl.getNotReleased();

for (auto it = r1.begin(); it != r1.end(); ++it)
    cout << (*it)->getInfo() << endl << endl;

for (auto it = nr1.begin(); it != nr1.end(); ++it)
    cout << (*it)->getInfo() << endl << endl;
*/
