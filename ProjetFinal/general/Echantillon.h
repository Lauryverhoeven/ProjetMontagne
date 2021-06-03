//
// Created by Ömer Doruk Süder on 22.04.2021.
//

#ifndef PROGICC_ECHANTILLON_H
#define PROGICC_ECHANTILLON_H
#endif //PROGICC_ECHANTILLON_H
#pragma once
#include <array>


//superclasse de champPotentiels et Ciel (permet de regrouper leurs attributs communs)
class Echantillon {
protected:
    std:: array <unsigned int,3> nbCubes{}; //vecteur qui contient le nombre de petits cubes dans chaque direction
    std:: array <double,3> cotes{}; //vecteur qui indique la longueur des cotes du gros cube
    double lambda;
public:
    Echantillon() = default; //constructeur par défaut
    Echantillon(unsigned int Nx,unsigned int Ny, unsigned int Nz, double lambda) : 
    nbCubes({Nx, Ny, Nz}),  cotes({(Nx) * lambda, (Ny) * lambda, (Nz) * lambda}),lambda(lambda) {} //constructeur
    unsigned int getNx() const; 
    unsigned int getNy() const;
    unsigned int getNz() const;
    double getlambda() const;
    void update(unsigned int Nx,unsigned int Ny, unsigned int Nz, double lambda);
};
