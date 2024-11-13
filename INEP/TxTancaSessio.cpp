#include "TxTancaSessio.h"
#include "Videoconsola.h"

void TxTancaSessio::executar()
{
	Videoconsola& vc = Videoconsola::getInstance();
	vc.tancaSessio();
}
