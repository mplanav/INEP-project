#pragma once
#include <iostream>
#include <pqxx/pqxx>
using namespace std;
using namespace pqxx;

class PassarelaElemCompra
{
public:
	PassarelaElemCompra(string elem);
	string obteNom();
	string obteDescripcio();
	string obtePreu();
	string obteTipus();

private:
	string _nom;//id
	string _descripcio;
	float _preu;
	string _tipus;
};

