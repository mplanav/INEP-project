#pragma once
#include "PassarelaUsuari.h"
#include"Transaccio.cpp"

// En TxRegistraUsuari.h
class TxRegistraUsuari : public Transaccio 
{
public:
    TxRegistraUsuari(string sU, string nU, string cU, string ceU, string dnU);

    void executar();

private:
    string sU;
    string nU;
    string cU;
    string ceU;
    string dnU;
};


