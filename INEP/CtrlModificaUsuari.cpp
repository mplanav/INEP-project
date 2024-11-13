#include "CtrlModificaUsuari.h"

vector<string> CtrlModificaUsuari::consultaUsuari()
{
    TxConsultaUsuari txCu;
    txCu.executar();
    vector<string> infoUsu;
    infoUsu = txCu.obteResultat();
    _usuari = txCu.obteUsuari();
    return infoUsu;
}

void CtrlModificaUsuari::modificaUsuari(string nomU, string contraU, string correU, string neixU)
{
    if (nomU != "") {
        _usuari.posaNom(nomU);
    }
    if (contraU != "") {
        _usuari.posaContrasenya(contraU);
    }
    if (correU != "") {
        _usuari.posaCorreu(correU);
    }
    if (neixU != "") {
        _usuari.posaData(neixU);
    }
    if (nomU != "" or contraU != "" or correU != "" or neixU != "") {
        _usuari.modifica();
    }
}
