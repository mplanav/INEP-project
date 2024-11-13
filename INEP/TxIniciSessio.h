#pragma once
#include"Transaccio.cpp"
#include "CercadoraUsuari.h"

using namespace std;

class TxIniciSessio : public Transaccio
{
public:
	TxIniciSessio(string sU, string cU);

	//Altres
	void executar() throw(error);
private:
	string sobrenomU;
	string contrasenyaU;

	static const int contrasenyaIncorrecta = 2;
};

