#pragma once
#include <iostream>
#include <pqxx/pqxx>
using namespace std;

class PassarelaData
{
    public:

        PassarelaData();
        
        //Getter
        string obteData();

        
    private: 
        string _data;
}