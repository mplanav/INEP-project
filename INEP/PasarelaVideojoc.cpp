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
}

PassarelaVideojoc