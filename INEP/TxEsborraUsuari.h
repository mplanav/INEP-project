#pragma once
#include"Transaccio.cpp"
using namespace std;

class TxEsborraUsuari : public Transaccio
{
public:
	TxEsborraUsuari(string cU);
	//Altres
	void executar() throw(error);
private:
	string contraU;

	static const int ErrContrasenyaIncorrecta = 1;
};


