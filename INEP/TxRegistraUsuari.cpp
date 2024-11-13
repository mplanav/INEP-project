#include "TxRegistraUsuari.h"


TxRegistraUsuari::TxRegistraUsuari(string sU, string nU, string cU, string ceU, string dnU)
    : sU(sU), nU(nU), cU(cU), ceU(ceU), dnU(dnU) {
}

void TxRegistraUsuari::executar() {
    PassarelaUsuari pu(sU, nU, cU, ceU, dnU);
    pu.insereix();
}