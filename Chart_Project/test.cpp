#include <QtXml>
#include <QtDebug>
#include <QTextStream>

#include "controller.h"

class test{
public:
    void testing(){


    }
};

//QDir dir(PROJECT_PATH);
//QString dataSetPath(dir.absolutePath() + "/RecordLabel/");
//qDebug() << dataSetPath << endl;

// writeXMLFile(dataSetPath);

//loadXMLFile(dataSetPath);

//const Date d (12, 9, 2000);
//DigitalMedium *dmFlop = new DigitalMedium("Jazz", "Standard & Ballads", "Wynton Marsalis", d, Spotify, 1450450);

//Controller ctrl;
//ctrl.loadDataFrom("sample");
//ctrl.isExists("sample", dmFlop);

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


/*
 * FUNZIONA
 * Model *model = new Model();

model->insertMusic(pmFlop);
model->insertMusic(dmFlop);
model->insertMusic(dmNevermind);

model->insertMusic(aEvening);
model->insertMusic(aTheWater);
model->insertMusic(aNessuno);

model->getAllInfo();

model->releaseMusic(new PhisycalMedium(aNessuno->getGenre(), aNessuno->getName(), aNessuno->getArtist(), d2, Vinile, 39390));

model->getAllInfo();
 *
auto r = rl->getReleased();
auto nr = rl->getNotReleased();

for (auto it = r.begin(); it != r.end(); ++it)
    cout << (*it)->getInfo() << endl << endl;

for (auto it = nr.begin(); it != nr.end(); ++it)
    cout << (*it)->getInfo() << endl << endl;

cout << "----------------------------" << endl;

auto n = rl->getReleasedBySupport(CD);
for (auto it = n.begin(); it != n.end(); ++it)
    cout << (*it)->getInfo() << endl << endl;
    */


/*
 * Date d (12, 9, 2000);
        Date d1(15, 10, 1981);
        Date d2(21, 3, 1999);
        Date d3(21, 3, 2001);

        Album  *pmFlop = new PhisycalMedium("Rap", "Flop", "Salmo", d, CD, 1450);
        Album *dmFlop = new DigitalMedium("Rap", "Flop", "Salmo", d, Spotify, 1450450);
        Album *dmNevermind = new DigitalMedium ("Rock", "Nevermind", "Nirvana", d1, AppleMusic, 390);
        Album  *pm2001 = new PhisycalMedium("Rap", "2001", "Dr. Dre", d2, Vinile, 300);

        Album *aEvening = new Album ("R&B", "An Evening With Silk Sonic", "Silk Sonic");
        Album *aTheWater = new Album ("Jazz", "The Water", "Mick Jenkins");
        Album *aNessuno = new Album("Rap", "Nessuno", "Articolo 31");

        RecordLabel *rl = new RecordLabel("Machete");
        cout << "Nome Label: " << rl->getRLName() << endl << endl;

        rl->insert(pmFlop);
        rl->insert(dmFlop);
        rl->insert(dmNevermind);
        rl->insert(pm2001);

        rl->insert(aEvening);
        rl->insert(aTheWater);
        rl->insert(aNessuno);

        auto v = rl->getReleased();
        auto out = rl->getByYear(rl->getByGenre(v, "Rap"), 1999);

        for(auto it = out.begin(); it != out.end(); ++it)
            cout << (*it)->getInfo() << endl << endl;
            */
