#include "PassarelaUsuari.h"
#include "Videoconsola.h"
#include <fstream>

using namespace std;
using namespace pqxx;

PassarelaUsuari::PassarelaUsuari()
{
	_sobrenom = "";
	_nom = "";
	_contrasenya = "";
	_correuElectronic = "";
	_dataNaixement = "";
}

PassarelaUsuari::PassarelaUsuari(string sU)
{
	ifstream file("conn.txt");
	string credentials;
	getline(file, credentials);
	

	try {
		pqxx::connection conn(credentials);
		if (conn.is_open()) {
			std::cout << "PassarelaUsuari: Connexio exitosa amb la base de dades." << std::endl << std::endl;
		}
		else {
			std::cerr << "PassarelaUsuari: Error de connexio amb la base de dades." << std::endl << std::endl;
			return;
		}
		pqxx::work txn(conn);
		pqxx::result result = txn.exec("SELECT * FROM usuari");
		for (size_t i = 0; i < result.size(); ++i) {
			if (string(result[i][0].c_str()) == sU){
				for (size_t j = 0; j < result[i].size(); ++j) {
					if (string(result[i][j].name()) == "nom") {
						_nom = string(result[i][j].c_str());// ACCES NOM
					}
					if (string(result[i][j].name()) == "contrasenya") {
						_contrasenya = string(result[i][j].c_str());// ACCES contrasenya
					}
					if (string(result[i][j].name()) == "correu_electronic") {
						_correuElectronic = string(result[i][j].c_str());// ACCES correuElectronic
					}
					if (string(result[i][j].name()) == "data_naixement") {
						_dataNaixement = string(result[i][j].c_str());// ACCES dataNaixement
					}
				}
			}
		}
		_sobrenom = sU;
		/*cout << _nom << endl;
		cout << _contrasenya << endl;
		cout << _correuElectronic << endl;
		cout << _dataNaixement << endl;*/

		txn.commit();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
PassarelaUsuari::PassarelaUsuari(string sU, string nU, string cU, string ceU, string dnU) {
	_sobrenom = sU;
	_nom = nU;
	_contrasenya = cU;
	_correuElectronic = ceU;
	_dataNaixement = dnU;
}

void PassarelaUsuari::insereix() throw(){
	//char* sql;

	ifstream file("conn.txt");
	string credentials;
	getline(file, credentials);

    try {
        connection conn(credentials);
		if (conn.is_open()) {
			cout << "PassarelaUsuari: Connexio exitosa amb la base de dades." << endl << endl;
		}
        else {
            cerr << "PassarelaUsuari: Error de connexio amb la base de dades." << endl << endl;
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

		string sql = "INSERT INTO usuari (sobrenom, nom, contrasenya, correu_electronic, data_naixement) VALUES ('" + _sobrenom + "', '" + _nom + "', '" + _contrasenya + "', '" + _correuElectronic + "', '" + _dataNaixement + "')";
			
			
			
			
			
		txn.exec(sql);

        txn.commit();

        std::cout << "Usuari registrat exitosament" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error al registrar l'usuari: " << e.what() << std::endl;
    }
	
}

void PassarelaUsuari::modifica() //exc
{
	Videoconsola& vc = Videoconsola::getInstance();
	vc.modificarUsuari(*this);

	ifstream file("conn.txt");
	string credentials;
	getline(file, credentials);

	try {
		connection conn(credentials);
		if (conn.is_open()) {
			cout << "PassarelaUsuari: Connexio exitosa amb la base de dades." << endl << endl;
		}
		else {
			cerr << "PassarelaUsuari: Error de connexio amb la base de dades." << endl << endl;
			return;
		}
		work txn(conn);
		// SELECT the row with the given ID
		std::string selectQuery = "SELECT * FROM usuari WHERE sobrenom = $1";
		pqxx::result result = txn.exec_params(selectQuery.c_str(), _sobrenom);

		// Check if the row with the given ID exists
		if (!result.empty()) {
			// Modify the values as needed
			result[0][1].as<string>() = _nom;
			result[0][2].as<string>() = _contrasenya;
			result[0][3].as<string>() = _correuElectronic;
			result[0][4].as<string>() = _dataNaixement;

			// UPDATE the row with the modified values
			std::string updateQuery = "UPDATE usuari SET nom = $1, contrasenya = $2, correu_electronic = $3, data_naixement = $4 WHERE sobrenom = $5";
			txn.exec_params(updateQuery.c_str(), _nom, _contrasenya, _correuElectronic, _dataNaixement, _sobrenom);

			std::cout << "Row with ID " << _sobrenom << " modified successfully." << std::endl;
		}
		else {
			std::cout << "Row with ID " << _sobrenom << " not found." << std::endl;
		}
		txn.commit();
	}
	catch (const std::exception& e) {
		std::cerr << "Error al modificar l'usuari: " << e.what() << std::endl;
	}
}

void PassarelaUsuari::esborra() //exc
{
	ifstream file("conn.txt");
	string credentials;
	getline(file, credentials);
	try {
		connection conn(credentials);
		if (conn.is_open()) {
			cout << "PassarelaUsuari: Connexi exitosa amb la base de dades." << endl << endl;
		}
		else {
			cerr << "PassarelaUsuari: Error de connexio amb la base de dades." << endl << endl;
			return;
		}

		work txn(conn);

		// Construct the DELETE query
		string rowIdentifier = "sobrenom = '" + _sobrenom + "'";
		string query = "DELETE FROM usuari WHERE " + rowIdentifier;
		// Execute the query
		txn.exec(query);
		// Commit the transaction
		txn.commit();
		std::cout << "Usuari esborrat exitosament" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error al esborrar l'usuari: " << e.what() << std::endl;
	}
}

string PassarelaUsuari::obteContrasenya()
{
	return _contrasenya;
}

string PassarelaUsuari::obteNom()
{
	return _nom;
}

string PassarelaUsuari::obteSobrenom()
{
	return _sobrenom;
}

string PassarelaUsuari::obteCorreu()
{
	return _correuElectronic;
}

string PassarelaUsuari::obtedataN()
{
	return _dataNaixement;
}

void PassarelaUsuari::posaNom(string nomU)
{
	_nom = nomU;
}

void PassarelaUsuari::posaContrasenya(string contraU)
{
	_contrasenya = contraU;
}

void PassarelaUsuari::posaCorreu(string correuU)
{
	//verificar si el correuU ja existeix a la base de daes
	_correuElectronic = correuU;
}

void PassarelaUsuari::posaData(string neixU)
{
	_dataNaixement = neixU;
}
