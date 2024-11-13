#pragma once
#include <iostream>
#include <pqxx/pqxx>
using namespace std;
using namespace pqxx;

class PassarelaCompra
{

public:
	//Constuctora
	PassarelaCompra();
	PassarelaCompra(string sU);
	//PassarelaCompra(string nU, string sE);
	PassarelaCompra(string nU, string sE, string sD, int pP);

	//Altres
	void novaCompra()throw(); //{exc UsuariExisteix}{exc CorreuExisiteix}
	void modifica();
	void esborra();
	int connexio();
	vector<PassarelaCompra> obteTotCompres();
	string obteUsuari();
	string obteElementCompra();
	string obteData();
	int obtePreuPagat();

private:
	private:
	string usuari;//id
	string element;//id
	string data;
	int preuPagat;

	//Funcions privades

	//control d'errors
	static const int  UsuariExisteix = 11;
	static const int  CorreuExisteix = 12;
};



