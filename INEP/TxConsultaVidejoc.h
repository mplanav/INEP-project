#pragma once
#include "Transaccio.cpp"
#include "CercadoraVideojoc.h"
#include "PassarelaVideojoc.h"
#include <string>
#include <vector>
using namespace std;

class TxConsultaVideojoc : public Transaccio
{
    public:
        void executar();
        PassarelaVideojoc obteVideojoc();
        vector<string> obteResultat();

    private: 
        PassarelaVideojoc _videojoc;
        std::vector<std::string> _resultat;
};