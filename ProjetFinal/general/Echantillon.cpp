//
// Created by Ömer Doruk Süder on 22.04.2021.
//


#include "Echantillon.h"
using namespace std;


//getters de dimension
unsigned int Echantillon::getNx() const{
    return nbCubes[0];
}

unsigned int Echantillon::getNy() const {
    return nbCubes[1];
}

unsigned int Echantillon::getNz() const{
    return nbCubes[2];
}

//getter de lambda
double Echantillon::getlambda() const {
    return lambda;
}

void Echantillon::update(unsigned int Nx,unsigned int Ny, unsigned int Nz, double lambda)
{
nbCubes[0] = Nx;
nbCubes[1] = Ny;
nbCubes[2] = Nz;
this->lambda = lambda;
cotes[0] = Nx*lambda;
cotes[1] = Ny*lambda;
cotes[2] = Nz*lambda;


}
