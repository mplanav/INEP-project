#include "CercadoraCompres.h"

CercadoraCompres::CercadoraCompres(){}
vector<PassarelaCompra> CercadoraCompres::cercaCompres(string sobrenomU)
{
    PassarelaCompra p(sobrenomU);
    vector<PassarelaCompra> c;
    c = p.obteTotCompres();
    return c;
}
