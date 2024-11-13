#pragma once
#include "Transaccio.cpp"
#include "PassarelaData.h"
#include <string>
#include <vector>
using namespace std;

class TxData : public Transaccio
{
    public:

        TxData();

        void executar() throw(error);
        PassarelaData obteData();
    private: 
        PassarelaData _data;
}