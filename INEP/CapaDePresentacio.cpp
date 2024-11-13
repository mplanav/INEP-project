#pragma once
#include <iostream>
#include <vector>
#include "TxIniciSessio.h"
#include "TxConsultaUsuari.h"
#include "TxEsborraUsuari.h"
#include "TxInfoCompres.h"
#include "TxRegistraUsuari.h"
#include "TxTancaSessio.h"
#include "CtrlModificaUsuari.h"
#include "TxConsultaVidejoc.h"

class CapaDePresentacio {
private:
    static CapaDePresentacio* instancePtr;
    CapaDePresentacio() {}

public:
    // deleting copy constructor
    CapaDePresentacio(const CapaDePresentacio& obj)
        = delete;

    static CapaDePresentacio* getInstance() {
        if (instancePtr == NULL) {
            instancePtr = new CapaDePresentacio();
            return instancePtr;
        }
        else
        {
            // if instancePtr != NULL that means 
            // the class already have an instance. 
            // So, we are returning that instance 
            // and not creating new one.
            return instancePtr;
        }
    }

    // Métodes de la clase
    //Gestio usuari
    void iniciSessio() {
        string sU;
        string cU;
        cout << "** Inici sessio **" << endl;
        cout << "Sobrenom: " << endl;
        cin >> sU;
        cout << "Contrasenya: " << endl;
        cin >> cU;
        TxIniciSessio txI(sU, cU);
        txI.executar();
    }
    void tancaSessio() {
        cout << "** Tancar sessio **" << endl;
        char c=' ';
        cout << "Vols tancar la sessio (S/N): ";
        cin >> c;
        cout << endl;
        if(c == 'S')
        {
            TxTancaSessio txS;
            txS.executar();
            cout << "Sessio tancada correctament!" << endl;
            return;
        }
        else if(c == 'N') return;
        return;
    }
    void registrarUsuari() {
        
        cout << "** Registra usuari **" << endl;
        cout << "Omplir la informacio que es demana ..." << endl;
        string nU;
        string sU;
        string cU;
        string ceU;
        string dnU;
        cout << "Nom complet: ";
        cin >> nU;
        cout << endl;
        cout << "Sobrenom: ";
        cin >> sU;
        cout << endl;
        cout << "Contrasenya: ";
        cin >> cU;
        cout << endl;
        cout << "Correu electronic: ";
        cin >> ceU;
        cout << endl;
        cout << "Data de naixament (DD/MM/AAAA): ";
        cin >> dnU;
        cout << endl;
        TxRegistraUsuari txR(sU, cU, nU, ceU, dnU);
        txR.executar();
        
    }
    void consultaUsuari() {
        TxConsultaUsuari txCU;
        txCU.executar();
        vector<string> usuari(4, "");
        usuari = txCU.obteResultat();
        
        cout << "** Consulta usuari **" << endl;
        cout << "Nom complet: " << usuari[2] << endl;
        cout << "Sobrenom: " << usuari[0] << endl;
        cout << "Correu electronic: " << usuari[3] << endl;
        cout << "Data de naixament (DD/MM/AAAA): " << usuari[4] << endl;

        TxInfoCompres txiC;
        txiC.executar();
        vector<float> compres(3, 0);
        compres = txiC.obteResultat();

        
        cout << endl; cout << endl;
        cout << compres[0] << " videojocs comprats" << endl;
        cout << compres[1] << " paquets de videojocs comprats" << endl;
        cout << compres[2] << " euros gastats en total" << endl;
    }

    void modificaUsuari() {
        CtrlModificaUsuari mU;
        vector<string> infoU;
        infoU = mU.consultaUsuari();
        string nomU = "";
        string contraU = "";
        string correuU = "";
        string neixU = "";
        cout << "** Modificar usuari **" << endl;
        cout << "Nom complet: " << infoU[2] << endl;
        cout << "Sobrenom: " << infoU[0] << endl;
        cout << "Correu electronic: " << infoU[3] << endl;
        cout << "Data de naixament (DD/MM/AAAA): " << infoU[4] << endl << endl;
        
        cout << "Omplir la informacio que es vol modificar..." << endl;
        cout << "Nom complet: " << endl;
        cin >> nomU;
        cout << "Contrasenya: " << endl;
        cin >> contraU;
        cout << "Correu electronic: " << endl;
        cin >> correuU;
        cout << "Data de naixament (DD/MM/AAAA): " << endl;
        cin >> neixU;
        mU.modificaUsuari(nomU, contraU, correuU, neixU);
        //TODO check correu electronic ja existeix (exepcio)
        
        infoU = mU.consultaUsuari();
        cout << endl << "** Dades usuari modificades **" << endl;
        cout << "Nom complet: " << infoU[2] << endl;
        cout << "Sobrenom: " << infoU[0] << endl;
        cout << "Correu electronic: " << infoU[3] << endl;
        cout << "Data de naixament (DD/MM/AAAA): " << infoU[4] << endl;
    }
    void esborraUsuari() {
        cout << "** Esborrar usuari **" << endl;
        cout << "Per confirmar l'esborrat s'ha d'entrar la contrasenya ..." << endl;
        cout << "contrasenya: ";
        string contrasenya; cin >> contrasenya;
        TxEsborraUsuari txeU(contrasenya);
        txeU.executar();
    }

    //Gestio compres
    void comprarVideojoc()
    {
        string nomVideojoc;
        cout << "** Comprar videojoc **" << endl;
        cout << "Nom videojoc: ";
        cin >> nomVideojoc; cout << endl;
        TxConsultaVideojoc txV;
        txV.executar();
        vector<string> resultat;
        resultat = txV.obteResultat();
        cout << "Informacio videojoc ..." << endl;
        cout << "Nom videojoc: " << resultat[0] << endl;
        cout << "Descripcio: " << resultat[1] << endl;
        cout << "Qualificacio edat: " << resultat[2] << endl;
        cout << "Genere: " << resultat[3] << endl;
        cout << "Data llansament: " << resultat[4] << endl;
        cout << "Preu: " << resultat[5] << endl;
        cout << "Vols continuar amb la compra (S/N): " << endl;
        char opcio; cin >> opcio;
        if(opcio == 'S')
        {
            cout << "Compra registrada: ";
            //gestio de la data
            TxData txD;
            txD.executa();
            string data = txD.obteData();
            cout << data << endl;
            cout << "Jocs relacionats: " << endl;
            for(unsigned int i = 0; i < Jrelacionats.size(); i++)
            {
                cout << "- " << Jrelacionats[i].text << "; " << Jrelacionats[i].preu << endl;
            }
        }
        else if(opcio == 'N') return;
    }

    void comprarPaquetVideojocs()
    {

    }

    void consultarCompres()
    {

    }

    //Gestio videojocs
    void consultarVideojoc()
    {
        
        string nV;
        cout << "** Consulta Videojoc **" << endl;
        cout << "Nom videojoc: "; cin >> nV;

        TxConsultaVideojoc txCV(nV);
        txCV.executar();
        vector<string> Videojoc;
        Videojoc = txCV.obteResultat();

        cout << "Descripció: " << Videojoc[0] << endl;
        cout << "Qualificacio edat: " << Videojoc[3] << endl;
        cout << "Genere: " << Videojoc[5] << endl;
        cout << "Data de naixament (DD/MM/AAAA): " << Videojoc[4] << endl;
        cout << "Preu: " << Videojoc[6] << endl;
        cout << "Paquets on està inclòs: " << Videojoc[7] << endl;
    }

    void consultaVideojocs()
    {
        string cV;
        cout << "** Consulta Videojocs **" << endl;
        cout << "Nom videojoc: "; string(getline, cin);

    }

    void consultarVidejocQualificacioEdat()
    {

    }

    void consultaNovetatsVideojoc()
    {
        
    }
};
CapaDePresentacio* CapaDePresentacio::instancePtr = NULL;