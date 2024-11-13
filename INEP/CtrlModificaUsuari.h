#pragma once
#include"Transaccio.cpp"
#include "TxConsultaUsuari.h"
#include "PassarelaUsuari.h"
using namespace std;

class CtrlModificaUsuari : public Transaccio
{
public:

	//Altres
	vector<string> consultaUsuari();
	void modificaUsuari(string nomU, string contraU, string correU, string neixU);
private:
	PassarelaUsuari _usuari;
};


