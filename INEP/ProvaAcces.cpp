#include "ProvaAcces.h"

void ProvaAcces::printInt()
{
	cout << provaInt << endl;
}

void ProvaAcces::printUsuari()
{
	
	pqxx::work txn(conn);
	pqxx::result result = txn.exec("SELECT * FROM public.usuari");
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "Opció de recorrer el resultat amb dos loops" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for (const auto& row : result) {
		// ... i per cada fila, es recorren els camps (l'ordre és el que es veu a les columnes al pgAdmin
		for (const auto& field : row) {
			std::cout << field.name() << ": " << field.c_str() << "\t";
		}
		std::cout << std::endl;
	}
	
}
