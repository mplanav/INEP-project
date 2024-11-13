#pragma once
#include"Transaccio.cpp"
#include"CercadoraUsuari.h"
#include"PassarelaUsuari.h"
#include <string>
#include <vector>
using namespace std;

class TxConsultaUsuari : public Transaccio
{
public:

	//Altres
	void executar();
	vector<string> obteResultat();
	PassarelaUsuari obteUsuari();

private:
	PassarelaUsuari _usuari;
	std::vector<std::string> _resultat;
};

