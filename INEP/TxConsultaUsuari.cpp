#include "TxConsultaUsuari.h"
#include "Videoconsola.h"

void TxConsultaUsuari::executar()
{
    vector<string>v;
    Videoconsola& vc = Videoconsola::getInstance();
    PassarelaUsuari pu = vc.obteUsuari();
    _usuari = pu;
    v.push_back(pu.obteSobrenom());
    v.push_back(pu.obteContrasenya());
    v.push_back(pu.obteNom());
    v.push_back(pu.obteCorreu());
    v.push_back(pu.obtedataN());
    _resultat = v;
}

vector<string> TxConsultaUsuari::obteResultat()
{
    return _resultat;
}

PassarelaUsuari TxConsultaUsuari::obteUsuari()
{
    return _usuari;
}
