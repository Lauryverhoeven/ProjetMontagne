//
// Created by Ömer Doruk Süder on 22.04.2021.
//


#ifndef PROGICC_CHAMPPOTENTIELS_H
#define PROGICC_CHAMPPOTENTIELS_H
#endif //PROGICC_CHAMPPOTENTIELS_H

#pragma once
#include <vector>
#include <array>
#include "Vecteur2D.h"
#include "Montagne.h"
#include "Echantillon.h"
#include "ChaineDeMontagnes.h"

class Potentiels {
private:
    Vecteur2D potentiel; //vecteur potentiel
    Vecteur2D laplacien; // vecteur laplacien
public:
    Potentiels() = default; //pour que le constructeur par défaut existe malgré le fait qu'il y ait un autre constructeur après
    Potentiels(Vecteur2D L, Vecteur2D pot);
    Vecteur2D getpot()const {return potentiel;}
    Vecteur2D getLap()const {return laplacien;}
    void setLap(Vecteur2D n) {laplacien = n;}
    void setpot(Vecteur2D p){ potentiel=p;}


};

using collectionPot = std:: vector <std:: vector < std:: vector < Potentiels > > >; //renommer un tableau de Potentiels de 3 dim comme collection Pot
using Boite3Ddouble = std:: vector <std:: vector < std:: vector < double>>>; //renommer un tableau de double de 3 dim

class champPotentiels : public Echantillon {
private:
    collectionPot collection; //vecteur 3 dim qui contient le Potentiels de chaque cube //peut etre changer le vector en collectionpot si ca marche
    double ventinfini{};
    ChaineDeMontagnes toblerone;
    Boite3Ddouble VectNorme3carre;

    //---------Methodes pour initialiser le champ potentiel avec les bonnes valeurs-------
    void calcul_Laplacien();
    void iteration(double epsilon);
    void resolution(double seuil, double maxIter, bool verbeuse, double epsilon);

public:

    //constructeur qui initialise le nombre de cubes et le taille de cubes et qui calcule les longueurs a partir de ces deux valeurs et aussi qui definit les dimensions du tabeau de 3 dim
    champPotentiels(unsigned int Nx, unsigned int Ny, unsigned int Nz, double lambda,
                    const std::vector<MontagneAbstraite *>& Toblerone, double ventinfini);
        //---------Methodes pour initialiser le champ potentiel avec les bonnes valeurs-------
    void initialise_champ(unsigned int Nx, unsigned int Ny, unsigned int Nz, double lambda,
                     const std::vector<MontagneAbstraite *>& Toblerone,double ventinfini);
    //-------methodes vitesse------------------------
    double norme3carre(int i, int j, int k);
    std:: vector <std:: vector < std:: vector <double>>> getNorme3() const;
    std::array<double, 3> vitesse(int i, int j, int k);

    double erreur();
    //-------methodes affiches pour verification------------------------
    void affiche_parametres(std:: ostream& out=std::cout) const;
    void afficheN3carre() const;
    void affichepot(std:: ostream& out=std::cout) const;
    void afficheLap() const;
    void affichepotvitesse(std:: ostream& out=std::cout);
};


