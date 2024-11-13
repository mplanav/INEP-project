#include "PassarelaVideojoc.h"
#include "Videoconsola.h"
#include <fstream>

using namespace std;
using namespace pqxx;

PassarelaVideojoc::PassarelaVideojoc()
{
    _nom = "";
    _genere = "";
    _qualificacioE = "";
    _dataLlansament = "";
    _minsEstimat = "";
    _paquetsInclos = "";
}

PassarelaVideojoc::PassarelaVideojoc(string nV)
{
    /*Constructora per nom*/
}

PassarelaVideojoc::PassarelaVideojoc(string nV, string gV, string qE, string dL, string mE, string pI)
{
    _nom = nV;
    _genere = gV;
    _qualificacioE = qE;
    _dataLlansament = dL;
    _minsEstimat = mE;
    _paquetsInclos = pI;
}

string PassarelaVideojoc::obteNom()
{
    return _nom;
}

string PassarelaVideojoc::obteGenere()
{
    return _genere;
}

string PassarelaVideojoc::obteQualificacioEdat()
{
    return _qualificacioE;
}

string PassarelaVideojoc::obteDataLlansament()
{
    return _dataLlansament;
}

string PassarelaVideojoc::obteMinsEstimat()
{
    return _minsEstimat;
}

string PassarelaVideojoc::obteDescripcio()
{
    return _descripcio;
}

string PassarelaVideojoc::obtePreu()
{
    return _preu;
}

string PassarelaVideojoc::obtePaquetsInclos()
{
    return _paquetsInclos;
}