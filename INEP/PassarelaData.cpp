#include "PassarelaData.h"
#include "Videoconsola.h"
#include <fstream>

using namespace std;
using namespace pqxx;

PassarelaData::PassarelaData()
{
    _data = "";
}

string PassarelaData::obteData()
{
    return _data;
}   