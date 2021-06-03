//
// Created by Ömer Doruk Süder on 30.04.2021.
//


#include "ChaineDeMontagnes.h"
#include "Montagne.h"
#include <vector>


//constructeur de chaine de montagnes qui prend plusieurs MontagneAbstraite pour former la chaine de montagnes
ChaineDeMontagnes::ChaineDeMontagnes(int x,int y,std::  vector<MontagneAbstraite *> const& chaine) {
    initialise_chaine(x,y,chaine);
}

void ChaineDeMontagnes::initialise_chaine(int x,int y,std::  vector<MontagneAbstraite *> const& chaine)
{
    this->chaine.clear();
    for(auto const& el :chaine){
        ajouter(el);
    }
    NbCubes[0]=x;
    NbCubes[1]=y;
}

//donne le max de l'altitude pour toutes les montagnes de la chaine de montagne 
double ChaineDeMontagnes::altitude(double x, double y) const {
    double altfinal(0);
    for (auto const& el : chaine ){
        if(altfinal< el->altitude(x,y))
            altfinal=el->altitude(x,y);
    }
    return altfinal;
}

//ajoute une montagne a la chaine de montagne
void ChaineDeMontagnes::ajouter(MontagneAbstraite * m) {
    chaine.push_back(m);
}


//affiche les coordonnées de la chaine de montagne
void ChaineDeMontagnes::affiche(std:: ostream& out) const { //il faut mettre 30 comme Nx et Ny
    for (int i(0); i < NbCubes[0] ; ++i) {
        for (int j(0); j < NbCubes[1]; ++j) {
            out << i <<" " << j << " " ;
            out <<altitude(i,j)<< std:: endl;
        }
    }
}


//surcharge de dessine_sur
void ChaineDeMontagnes::dessine_sur(SupportADessin& support){support.dessine(*this);}

