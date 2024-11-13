#pragma once
#include"Transaccio.cpp"
#include<vector>
using namespace std;

class TxInfoCompres : public Transaccio
{
public:

	//Altres
	void executar();
	vector<float> obteResultat();

private:
	vector<float> _resultat;
};

