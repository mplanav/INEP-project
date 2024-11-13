#pragma once
#include <iostream>
#include <pqxx/pqxx>
using namespace std;

class PassarelaVideojoc
{
    public:
        PassarelaVideojoc();
        PassarelaVideojoc(string nV);
        PassarelaVideojoc(string nV, string gV, string qE, string dL, string mE, string pI);

        void compraV(string nV);

        string obteNom();
        string obteGenere();
        string obteQualificacioEdat();
        string obteDataLlansament();
        string obteMinsEstimat();
        string obteDescripcio();
        string obtePreu();
        string obtePaquetsInclos();

        void posaNom(string nV);
        void posaGenere(string nV);
        void posaQualificacioEdat(string qE);
        void posaDataLlansament(string dL);
        void posaMinsEstimat(string mE);

    private:
        string _nom;
        string _genere;
        string _qualificacioE;
        string _dataLlansament;
        string _minsEstimat;
        string _descripcio;
        string _preu;
        string _paquetsInclos;

        static const int VideojocExisteix = 11;
        static const int NomExisteix = 12;
};