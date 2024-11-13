#include "TxConsultaVidejoc.h"
#include "Videoconsola.h"

void TxConsultaVideojoc::executar()
{
    
    vector<string>v;
    Videoconsola& vc = Videoconsola::getInstance();
    PassarelaVideojoc pv = vc.obteVideojoc();
    _videojoc = pv;
    v.push_back(pv.obteNom());
    v.push_back(pv.obteDescripcio());
    v.push_back(pv.obteQualificacioEdat());
    v.push_back(pv.obteGenere());
    v.push_back(pv.obteDataLlansament());
    v.push_back(pv.obtePreu());
    _resultat = v;
}

vector<string> TxConsultaVideojoc::obteResultat()
{
    return _resultat;
}

PassarelaVideojoc TxConsultaVideojoc::obteVideojoc()
{
    return _videojoc;
}