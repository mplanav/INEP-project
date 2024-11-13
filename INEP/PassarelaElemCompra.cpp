#include "PassarelaElemCompra.h"
#include <fstream>

PassarelaElemCompra::PassarelaElemCompra(string elem){
    _nom = "";
    _descripcio = "";
    _preu = 0;
    _tipus = "";
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
		pqxx::result result = txn.exec("SELECT * FROM element_compra");
		for (size_t i = 0; i < result.size(); ++i) {
			if (string(result[i][0].c_str()) == elem) {
				
				for (size_t j = 0; j < result[i].size(); ++j) {
					if (string(result[i][j].name()) == "descripcio") {
						_descripcio = string(result[i][j].c_str());
					}
					if (string(result[i][j].name()) == "preu") {
						_preu = result[i][j].as<int>();
					}
					if (string(result[i][j].name()) == "tipus") {
						_tipus = string(result[i][j].c_str());
					}
				}
			}
		}
		txn.commit();
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

string PassarelaElemCompra::obteTipus()
{
    return _tipus;
}