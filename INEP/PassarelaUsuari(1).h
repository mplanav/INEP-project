#pragma once
#include <iostream>
#include <pqxx/pqxx>
using namespace std;

class PassarelaUsuari
{
public:
	//Constuctora
	PassarelaUsuari();
	PassarelaUsuari(string sU);
	PassarelaUsuari(string sU, string nU, string cU, string ceU, string dnU);

	//Altres
	void insereix()throw(); //{exc UsuariExisteix}{exc CorreuExisiteix}
	void modifica();
	void esborra();

	//Getters
	string obteContrasenya();
	string obteNom();
	string obteSobrenom();
	string obteCorreu();
	string obtedataN();

	//Setters
	void posaNom(string nomU);
	void posaContrasenya(string contraU);
	void posaCorreu(string correuU);
	void posaData(string neixU);

private:
	string _sobrenom;//id
	string _nom;
	string _contrasenya;
	string _correuElectronic;
	string _dataNaixement;
	//pqxx::connection _conn;

	//Funcions privades

	//control d'errors
	static const int  UsuariExisteix = 11;
	static const int  CorreuExisteix = 12;
};
