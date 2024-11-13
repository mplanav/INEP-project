#pragma once
#include <iostream>
#include "PassarelaUsuari.h"
#include "PassarelaCompra.h"
#include "PassarelaVideojoc.h"

class Videoconsola {
private:

    // member variables
    PassarelaUsuari usuari;
    PassarelaCompra compra;
    PassarelaVideojoc videojoc;

    // Default constructor
    Videoconsola()
    {
    }

public:

    static Videoconsola& getInstance() {
    static Videoconsola instance;
    return instance;
    }

    PassarelaUsuari obteUsuari()
    {
        return usuari;
    }

    void iniciaSessio(PassarelaUsuari u)
    {
        this->usuari = u;
    }

    void tancaSessio()
    {
        PassarelaUsuari res;
        this->usuari = res;
    }

    void esborrar()
    {
        PassarelaUsuari buit;
        this->usuari = buit;
    }

    PassarelaCompra obteCompra()
    {
        return compra;
    }

    void modificarUsuari(PassarelaUsuari nouPU) 
    {
        usuari = nouPU;
    }

    PassarelaVideojoc obteVideojoc()
    {
        return videojoc;
    }
};