#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
using std::cerr;
using std::endl;
using std::string;

// RAGRUPPARE LE ECCEZIONI SIMILI?

class err_illegalDate {
public:
    err_illegalDate() { cerr << "Illegal date" << endl; }
};

class err_emptyMusic {
public:
    err_emptyMusic() { cerr << "Input error: empty music" << endl; }
};

class err_emptyCollection {
public:
    err_emptyCollection() { cerr << "Empty collection" << endl; }
};

class err_nameNotFound {
public:
    err_nameNotFound() { cerr << "Album's name not found" << endl; }
};

class err_genreNotFound {
public:
    err_genreNotFound() { cerr << "Genre not found" << endl; }
};

class err_artistNotFound {
public:
    err_artistNotFound() { cerr << "Artist not found" << endl; }
};

class err_yearNotFound {
public:
    err_yearNotFound() { cerr << "Year not found" << endl; }
};

class err_platformNotFound {
public:
    err_platformNotFound() { cerr << "Platform not found" << endl; }
};

class err_supportNotFound {
public:
    err_supportNotFound() { cerr << "Support not found" << endl; }
};

class err_readDate{
public:
    err_readDate() { cerr << "Read date failed" << endl; }
};

/*
class err_openFile{
public:
    err_openFile(const string& file) { cerr << file << ".xml " << "opening failed" << endl; }
};

class err_loadFile{
public:
    err_loadFile() { cerr << "Loaded input file failed" << endl; }
};
*/

class err_notInFile{
public:
    err_notInFile(const string& item) { cerr << item << " NOT PRESENT TO DELETE FROM FILE" << endl; }
};


#endif // EXCEPTIONS_H
