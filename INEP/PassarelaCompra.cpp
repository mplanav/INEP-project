#include "PassarelaCompra.h"
#include <fstream>

using namespace std;
using namespace pqxx;

PassarelaCompra::PassarelaCompra()
{
	usuari = " ";
	element = "";
	data = "";
	preuPagat = 0;
}

PassarelaCompra::PassarelaCompra(string sU)
{
	usuari = sU;
	element = "";
	data = "";
	preuPagat = 0;
}
/*
PassarelaCompra::PassarelaCompra(string nU, string sE)
{
	data = "";
	preuPagat = 0;
	
	ifstream file("conn.txt");
	string credentials;
	getline(file, credentials);

	try {
		pqxx::connection conn(credentials);
		if (conn.is_open()) {
			std::cout << "PassarelaCompra: Connexio exitosa amb la base de dades." << std::endl << std::endl;
		}
		else {
			std::cerr << "PassarelaCompra: Error de connexio amb la base de dades." << std::endl << std::endl;
			return;
		}
		pqxx::work txn(conn);
		pqxx::result result = txn.exec("SELECT * FROM compra");
		for (size_t i = 0; i < result.size(); ++i) {
				for (size_t j = 0; j < result[i].size(); ++j) {
					if (string(result[i][j].name()) == "data") {
						data = string(result[i][j].c_str());
					}
					if (string(result[i][j].name()) == "preuPagat") {
						preuPagat = result[i][j].as<int>();
					}
				}
			}
        usuari = nU;
        element = sE;

		txn.commit();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
*/
PassarelaCompra::PassarelaCompra(string nU, string sE, string sD, int pP) {
	usuari = nU;
	element = sE;
	data = sD;
	preuPagat = pP;
}

void PassarelaCompra::novaCompra() throw(){
	//char* sql;

	ifstream file("conn.txt");
	string credentials;
	getline(file, credentials);
    try {
        connection conn(credentials);
		if (conn.is_open()) {
			cout << "PassarelaCompra: Connexi exitosa amb la base de dades." << endl << endl;
		}
        else {
            cerr << "PassarelaCompra: Error de connexio amb la base de dades." << endl << endl;
            return;
        }

		work txn(conn);

        // Verificar si el usuario ya existe por sobrenom
        /*
        pqxx::result result = txn.exec("SELECT * FROM usuari WHERE sobrenom = " + string(txn.quote(_sobrenom)));

        if (!result.empty()) {
            txn.abort();
			cout << ("El sobrenom ja existeix") << endl;
            throw UsuariExisteix;
        }*/

        // Verificar si el usuario ya existe por correo electrónico
       /* result = txn.exec("SELECT * FROM usuari WHERE correuElectronic = " + txn.quote(_correuElectronic));

        if (!result.empty()) {
            txn.abort();
			cout << ("El correu ja existeix") << endl;
            throw CorreuExisteix;
        }*/

        // Insertar el nuevo usuario

		// Construct a parameterized query
		std::string query = "INSERT INTO compra (usuari, element, data, preuPagat) VALUES ($1, $2, $3, $4)";

		// Execute the query with parameters
		txn.exec_prepared(query.c_str(), usuari, element, data, to_string(preuPagat));

        txn.commit();

        std::cout << "Compra registrada exitosament" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error al registrar la compra: " << e.what() << std::endl;
    }
	
}

void PassarelaCompra::modifica() //exc
{
}

void PassarelaCompra::esborra() //exc
{
	
}

int PassarelaCompra::connexio()
{
	/*
	try {
		pqxx::connection conn("dbname=INEP user=postgres password=inep2023 hostaddr = 127.0.0.1 port = 5432");
		if (conn.is_open()) {
			std::cout << "Connexi� exitosa amb la base de dades." << std::endl << std::endl;
		}
		else {
			std::cerr << "Error de connexi� amb la base de dades." << std::endl << std::endl;
			return 1;
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	_conn = conn;
	*/

	return 0;
}

vector<PassarelaCompra> PassarelaCompra::obteTotCompres()
{
	vector<PassarelaCompra> vectorResultat;
	ifstream file("conn.txt");
	string credentials;
	getline(file, credentials);

	try {
		pqxx::connection conn(credentials);
		if (conn.is_open()) {
			std::cout << "PassarelaCompra: Connexio exitosa amb la base de dades." << std::endl << std::endl;
		}
		else {
			std::cerr << "PassarelaCompra: Error de connexio amb la base de dades." << std::endl << std::endl;
			return vectorResultat;
		}
		pqxx::work txn(conn);
		pqxx::result result = txn.exec("SELECT * FROM compra");
		for (size_t i = 0; i < result.size(); ++i) {
			if (string(result[i][0].c_str()) == usuari) {
				for (size_t j = 0; j < result[i].size(); ++j) {
					if (string(result[i][j].name()) == "element") {
						element = string(result[i][j].c_str());
					}
					if (string(result[i][j].name()) == "data") {
						data = string(result[i][j].c_str());
					}
					if (string(result[i][j].name()) == "preu_pagat") {
						preuPagat = result[i][j].as<int>();
					}
				}
				PassarelaCompra pResult(usuari, element, data, preuPagat);
				vectorResultat.push_back(pResult);
			}
		}

		txn.commit();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return vectorResultat;
}

string PassarelaCompra::obteUsuari()
{
	return usuari;
}

string PassarelaCompra::obteElementCompra()
{
	return element;
}

string PassarelaCompra::obteData()
{
	return data;
}

int PassarelaCompra::obtePreuPagat()
{
	return preuPagat;
}