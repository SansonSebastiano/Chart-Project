#include <QtXml>
#include <QtDebug>
#include <QTextStream>

#include "controller.h"

class test{
public:
    void writeXMLFile(QString path){
        QFile file(path + "sample_1.xml");
        if(!file.open(QFile::WriteOnly | QFile::Text)){
            qDebug() << "already opened or there is another issue" << endl;
            file.close();
        }
        QTextStream content(&file);

        QDomDocument document;

        QDomElement root = document.createElement("catalog");
        document.appendChild(root);

        QDomElement album = document.createElement("album");
        album.setAttribute("name", "Flop");
        album.setAttribute("artist", "Salmo");
        album.setAttribute("genre", "Rap");
        root.appendChild(album);

        album = document.createElement("album");
        album.setAttribute("name", "Nevermind");
        album.setAttribute("artist", "Nirvana");
        album.setAttribute("genre", "Rock");
        root.appendChild(album);

        QDomElement date = document.createElement("release");
        date.setAttribute("day", "10");
        date.setAttribute("month", "9");
        date.setAttribute("year", "2013");
        QDomElement pm = document.createElement("PM");
        pm.setAttribute("name", "Midnite");
        pm.setAttribute("artist", "Salmo");
        pm.setAttribute("genre", "Rap");
        pm.setAttribute("num_sales", "340243");
        pm.setAttribute("support", "Vinile");
        //pm.setAttribute("profit", "0");       // DA DEFINIRE
        pm.appendChild(date);
        root.appendChild(pm);

        // per DM analogo a PM

        content << document.toString();
    }

    void loadXMLFile(QString path){
        RecordLabel rl;

        QDomDocument document;
        QFile file(path + "sample_1.xml");
        if(!file.open(QIODevice::ReadOnly))
            qDebug() << "Error while loading file" << endl;
        document.setContent(&file);
        file.close();

        QDomElement root = document.documentElement();
        QDomElement node = root.firstChild().toElement();

        while (!node.isNull()) {
            //qDebug() << node.tagName();
            if(node.tagName() == "album"){
                while (!node.isNull()) {
                    QString name = node.attribute("name", "name");
                    QString artist = node.attribute("artist", "artist");
                    QString genre = node.attribute("genre", "genre");

                    rl.insert(new Album(genre.toStdString(), name.toStdString(), artist.toStdString()));

                    node = node.nextSibling().toElement();
                }
            }
            node = node.nextSibling().toElement();
        }
        auto v = rl.getNotReleased();
        for(auto it = v.begin(); it != v.end(); ++it)
            cout << (*it)->getInfo() << endl << endl;
    }

    void testing(){

        QDir dir(PROJECT_PATH);
        QString dataSetPath(dir.absolutePath() + "/RecordLabel/");
        //qDebug() << dataSetPath << endl;

        writeXMLFile(dataSetPath);

        //loadXMLFile(dataSetPath);


        //Controller ctrl;
        //ctrl.loadDataFrom("sample_1");

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
