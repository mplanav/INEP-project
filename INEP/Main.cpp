#include <iostream>
#include <pqxx/pqxx>
//#include "CapaDePresentacio.h"
#include "TxIniciSessio.h"
#include "PassarelaUsuari.h"
using namespace pqxx;

//Global variables
//int provaInt;
//pqxx::connection conn;

int main() {
	TxIniciSessio tx("fercrat","inep2023");
	tx.executar();

	//a.printUsuari();
	/*
	try {
		// Per establir la connexió amb la base de dades, es crea una pqxx::connection
		// per confirmar el port heu de mirar en el pgAdmin, a les properties hi ha una pestanya "Connection"
		// l'usuari postgres és el superusuari que s'ha creat durant la instal·lació del postgreSQL
		// heu de posar la contrasenya que heu escollit durant el procés d'instal·lació
		//pqxx::connection conn("dbname=INEP user=postgres password=inep2023 hostaddr = 127.0.0.1 port = 5432");
		pqxx::connection conn("dbname=INEP user=postgres password=inep2023 hostaddr = 127.0.0.1 port = 5432");
		if (conn.is_open()) {
			std::cout << "Connexió exitosa amb la base de dades." << std::endl << std::endl;
		}
		else {
			std::cerr << "Error de connexió amb la base de dades." << std::endl << std::endl;
			return 1;
		}
		// Per realitzar una consulta...
		// 1.- es crea un pqxx::work amb la connexió que hem creat
		pqxx::work txn(conn);
		// 2.- s'executa una comanda en SQL que correspon a la consulta
		pqxx::result result = txn.exec("SELECT * FROM public.usuari");
		// si a l'executar us dóna el missatge que no troba la taula, potser necessiteu posar :
		// "SELECT * FROM public.musics" o ""SELECT * FROM public.\"MUSICS\"
			// podeu confirmar la sintaxi de la comanda en el pgAdmin, sobre la taula escollir la opció Scripts\SELECT Script
			// Per mostrar el resultat de la consulta, hem de recórrer les files (primer for) ...
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
		// també es poden recórrer els resultats com si fosin una matriu de files i columnes(amb indexos començant per 0)
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Opció de recorrer el resultat com una matriu" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		for (size_t i = 0; i < result.size(); ++i) {
			for (size_t j = 0; j < result[i].size(); ++j) {
				std::cout << result[i][j].name() << ": " << result[i][j].c_str() << "\t";
			}
			std::cout << std::endl;
		}
		// Finalment, s'ha de confirmar la transacción
		txn.commit();
		// La connexió es tanca automàticament al sortir del try
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	*/
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
