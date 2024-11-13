#include "TxEsborraUsuari.h"
#include "Videoconsola.h"

TxEsborraUsuari::TxEsborraUsuari(string cU)
{
    contraU = cU;
}

void TxEsborraUsuari::executar() throw(error)
{
    Videoconsola& vc = Videoconsola::getInstance();
    PassarelaUsuari pu = vc.obteUsuari();
    string cU = pu.obteContrasenya();
	if (contraU==cU) {
		cout << "Contrasenya correcte!" << endl;
		pu.esborra();
        vc.esborrar();
	}
	else {
		cout << "Contrasenya incorrecte!" << endl;
		throw error(ErrContrasenyaIncorrecta);
	}
    
}
