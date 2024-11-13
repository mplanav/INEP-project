#include "TxIniciSessio.h"
#include "Videoconsola.h"
#include <stdexcept>


TxIniciSessio::TxIniciSessio(string sU, string cU)
{
	sobrenomU = sU;
	contrasenyaU = cU;
}

void TxIniciSessio::executar() throw(error)
{
	Videoconsola& vc = Videoconsola::getInstance();
	CercadoraUsuari cerc;
	PassarelaUsuari pu = cerc.cercaUsuari(sobrenomU);
	string contraPU = pu.obteContrasenya();
	if (contrasenyaU==contraPU) {
		cout << "Contrasenya correcte!" << endl;
		vc.iniciaSessio(pu);
	}
	else {
		//controlador d'excepcions
		throw error(contrasenyaIncorrecta);
	}
	
	//PassarelaUsuari usuariLog = vc->obteUsuari();
	//cout << "Usuari logejat: " << usuariLog.obteNom();
}
