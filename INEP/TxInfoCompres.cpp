#include "TxInfoCompres.h"
#include "Videoconsola.h"
#include "CercadoraCompres.h"
#include "CercadoraElemCompra.h"

void TxInfoCompres::executar()
{
    Videoconsola& vc = Videoconsola::getInstance();
    PassarelaUsuari u = vc.obteUsuari();
    string sobrenomU = u.obteSobrenom();
    CercadoraCompres cc;
    vector<PassarelaCompra> compresU = cc.cercaCompres(sobrenomU);
    cout << "Compres size: " << compresU.size() << endl;
    cout << "amb nom: " << compresU[0].obteElementCompra() << endl;
    float totalEuros = 0;
    int totalPaquets = 0;
    int totalVideojoc = 0;
    for (unsigned int i = 0; i < compresU.size(); i++)
    {
        float preuE = compresU[i].obtePreuPagat();
        string elem = compresU[i].obteElementCompra();
        CercadoraElemCompra ce;
        PassarelaElemCompra pc = ce.cercaElement(elem);
        string tipusE = pc.obteTipus();
        if (tipusE == "paquet") totalPaquets++;
        else if (tipusE == "videojoc") totalVideojoc++;
        totalEuros += preuE;
    }
    vector<float> resultat(3);
    resultat[0] = totalVideojoc; resultat[1] = totalPaquets; resultat[2] = totalEuros;
    _resultat = resultat;
}

vector<float> TxInfoCompres::obteResultat()
{
    return _resultat;
}
