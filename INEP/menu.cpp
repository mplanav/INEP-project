#include <iostream>
#include <pqxx/pqxx>
#include "CapaDePresentacio.cpp"

using namespace std;

int main() {
        CapaDePresentacio* capa = CapaDePresentacio::getInstance();
        char opcio;
	    try {
        do {
            std::cout << "******************" << std::endl;
            std::cout << "  Menu Principal  " << std::endl;
            std::cout << "******************" << std::endl;

            std::cout << "1. Iniciar sessio" << std::endl;
            std::cout << "2. Registrar usuari" << std::endl;
            std::cout << "3. Sortir" << std::endl;
            std::cout << "Opcio: ";
            std::cin >> opcio;
            std::cout << std::endl;

            switch (opcio) {
				
                case '1': {
                    // controlador d'excepcions fet
					capa->iniciSessio();

                    char opcioLoggejat;
                    do {
                        std::cout << "********************" << std::endl;
                        std::cout << "  Menu Loggejat  " << std::endl;
                        std::cout << "********************" << std::endl;

                        std::cout << "1. Gestionar Usuari" << std::endl;
                        std::cout << "2. Gestionar compres" << std::endl;
                        std::cout << "3. Consultar" << std::endl;
                        std::cout << "4. Tancar sessio" << std::endl;
                        std::cout << "5. Sortir" << std::endl;
                        std::cout << "Opcio: ";
                        std::cin >> opcioLoggejat;
                        std::cout << std::endl;

                        switch (opcioLoggejat) {
                            case '1': {
                                char opcioGestionarUsuari;
                                do {
                                    std::cout << "--------------------" << std::endl;
                                    std::cout << "  Gestionar Usuari  " << std::endl;
                                    std::cout << "--------------------" << std::endl;

                                    std::cout << "1. Consultar usuari" << std::endl;
                                    std::cout << "2. Modificar usuari" << std::endl;
                                    std::cout << "3. Esborrar usuari" << std::endl;
                                    std::cout << "4. Tornar" << std::endl;
                                    std::cout << "Opcio: ";
                                    std::cin >> opcioGestionarUsuari;
                                    std::cout << std::endl;

                                    switch (opcioGestionarUsuari) {
                                        case '1'://CONSULTA USUARI
                                            capa->consultaUsuari();
                                            std::cout << "Usuari consultat" << std::endl;
                                            break;
                                        case '2'://MODIFICAR USUARI
                                            capa->modificaUsuari();
                                            std::cout << "Usuari modificat" << std::endl;
                                            break;
                                        case '3'://ESBORRAR USUARI
                                            capa->esborraUsuari();
                                            opcioGestionarUsuari = '4';
                                            opcioLoggejat = '5';
                                            opcio = '1';
                                            std::cout << "Usuari esborrat" << std::endl;
                                            break;
                                        case '4':
                                            break;
                                        default:
                                            std::cout << "Opcio no valida" << std::endl;
                                    }
                                } while (opcioGestionarUsuari != '4');
                                break;
                            }
                            case'2': {
                                // Gestionar Compres
                                char opcioGestionarCompres;
                                do {
                                    std::cout << "---------------------" << std::endl;
                                    std::cout << "  Gestionar Compres" << std::endl;
                                    std::cout << "---------------------" << std::endl;

                                    std::cout << "1. Comprar Videojoc" << std::endl;
                                    std::cout << "2. Comprar Paquet videojocs" << std::endl;
                                    std::cout << "3. Consultar compres" << std::endl;
                                    std::cout << "4. Tornar" << std::endl;
                                    std::cout << "Opcio: ";
                                    std::cin >> opcioGestionarCompres;
                                    std::cout << std::endl;

                                    switch (opcioGestionarCompres) {
                                        case '1':
                                            capa->comprarVideojoc();
                                            std::cout << "Videojoc comprat" << std::endl;
                                            break;
                                        case '2':
                                            // comprarP()
                                            std::cout << "Paquet comprat" << std::endl;
                                            break;
                                        case '3':
                                            // consultarC()
                                            std::cout << "Compres consultades" << std::endl;
                                            break;
                                        case '4':
                                            break;
                                        default:
                                            std::cout << "Opcio no valida" << std::endl;
                                    }
                                } while (opcioGestionarCompres != '4');
                                break;
                            }
                            case '3':
                                //Consultar
                                //TODO
                                break;
                            case '4':
                                //Tancar sessio
                                capa->tancaSessio();
                                opcioLoggejat = '5';
                                break;
                            case '5':
                                //Sortir
                                //TODO
                                break;
                            default:
                                std::cout << "Opcio no valida" << std::endl;
                        }
                    } while (opcioLoggejat != '5');
                    break;
                }
                case '2':
                    // Registrar usuari
                    capa->registrarUsuari();
                    std::cout << "Usuari registrat" << std::endl;
                    break;
                case '3':
                    // Sortir
                    //TODO
                    break;
                default:
                    std::cout << "Opcio no valida" << std::endl;
            }
        } while (opcio != '3');
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

