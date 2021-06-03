//
// Created by Ömer Doruk Süder on 22.04.2021.
//


#include <vector>
#include <cmath>
#include <iostream>
#include "ChampPotentiels.h"
#include "Nuages.h"
#include "Echantillon.h"


using namespace std;
using namespace Physique;

//------------------------------- methodes CubedAir------------------------------

//constructeur de CubedAir

CubedAir::CubedAir(int i, int j, int k, champPotentiels& cp) {
    h = (1.0/2.0)*pow(ventinfini,2) + hinf - g*k - (1.0/2.0)*cp.norme3carre(i,j,k);
    vitessevent = cp.vitesse(i,j,k);
    T = (2.0/7.0)*(mairsec/R)*h;
    P = Pinf*pow(Tinf, (-7.0/2.0))*pow(T, 7.0/2.0);
    prosee = (Pref*exp(13.96-(5208.0/T)));
    tauxhum= tau_inf;
    peau= ((tauxhum/((meau/mairsec)+tauxhum))*P);
    etat = isNuage(); //peau > prosee

}




//methode permettant de determiner s'il y a formation d'un nuage dans un cube d'air
bool CubedAir::isNuage() const {
    return peau > prosee;
}

//constructeur initialisant seulement la vitesse du vent
CubedAir::CubedAir(double v) : vitessevent({v,0.0,0.0}) {}

//getter
CubedAir Ciel::getCollection(int i, int j, int k) {
return collectioncubes[i][j][k];}

//setters

void CubedAir::setvent(array<double, 3> v) {
    vitessevent = {v[0], v[1], v[2]};
}


void CubedAir::seth(double a) {h = a;}

void CubedAir::set_humidite(double hum) {
    tauxhum = hum;

}


void Ciel::SetCollection(int i, int j, int k, CubedAir w) {
collectioncubes[i][j][k] = w;
}

//met a jour l'humidité pour permettre le deplacement des nuages (utilisé dans evolue() de Systeme)
void CubedAir::maj_humidite(double d) {
    tauxhum = tauxhum *(1-d);
    peau = (tauxhum/((meau/mairsec)+tauxhum))*P;
    etat = isNuage();
}

//decide s'il pleut sur un cube d'air
bool CubedAir::pluie() {
    if (peau/prosee>1.03) return true;
    return false;
}


//------------------------------- methodes Ciel-----------------------------------

//constructeur de Ciel
Ciel::Ciel(champPotentiels &cp) : Echantillon(cp.getNx(), cp.getNy(), cp.getNz(), cp.getlambda()) {
    initialise_ciel(cp);
}


void Ciel::initialise_ciel(champPotentiels& cp) {
    collectioncubes.clear();
    update(cp.getNx(), cp.getNy(), cp.getNz(),cp.getlambda());
    for (unsigned int i(0); i < cp.getNx(); ++i) {
        vector<vector<CubedAir>> collectionx;
        for (unsigned int j(0); j < cp.getNy(); ++j) {
            vector<CubedAir> collectiony;
            for (unsigned int k(0); k < cp.getNz(); ++k){
                CubedAir cube(i,j,k, cp);
                collectiony.push_back(cube);
            }
            collectionx.push_back(collectiony);
        }
        collectioncubes.push_back(collectionx);
    }
}

//affiche pour chaque petit cube : i j k V2 enthalpie T P Peau PressionPartielle vapeurD'eau Nuage
void Ciel::affiche( const champPotentiels& cp,std:: ostream& out) const {
    std::vector<std::vector<std::vector<double>>> vect=cp.getNorme3();
    for(unsigned int i(1); i < nbCubes[0]-1; ++i) {
        for(unsigned int j(1); j < nbCubes[1]-1; ++j) {
            for(unsigned int k(1); k < nbCubes[2]-1; ++k) {
                out << i << " " << j << " " << k << " " << vect[i-1][j-1][k-1] 
                << " " << collectioncubes[i][j][k].geth() << " "
                << collectioncubes[i][j][k].getT() << " "
                << collectioncubes[i][j][k].getP() << " "
                << collectioncubes[i][j][k].getpeau() << " "
                << collectioncubes[i][j][k].getprosee() << " "
                << collectioncubes[i][j][k].isNuage() << endl;
            }
        }
    }

}

// getters 

bool Ciel::getetat(int i, int j, int k) const {
    return collectioncubes[i][j][k].isNuage();
}



double Ciel::get_hum(int i, int j, int k) {
    return  collectioncubes[i][j][k].get_hum();
}

 //setters

void Ciel::set_humidite(int i, int j, int k, double hum) {
    collectioncubes[i][j][k].set_humidite(hum);

}

//surcharge de dessine_sur
void Ciel::dessine_sur(SupportADessin &support) {
    support.dessine(*this);
}

//recalcul s'il y a un nuage ou pas sur le cube d'air apres avoir mis a jour l'humidité (utilisé dans evolue() de Systeme)
CubedAir Ciel::recalcul_nuage(int i, int j, int k, double d) {
    CubedAir v = collectioncubes[i][j][k];
    v.maj_humidite(d);
    return v;
}

//calcul de la cellule precedente dans le sens du vent pour une cellule donnée
array<int, 3> Ciel::precedente(int i,int j, int k ,double delta_t) {
    array<double, 3> v = collectioncubes[i][j][k].getvent();
    int a = trunc((i - delta_t * v[0]));
    int b = trunc((j - delta_t * v[1]));
    int c = trunc((k - delta_t * v[2]));
    return {a,b,c};

}

//decide s il pleut pour des coordonnees de la boite fixées
bool Ciel::il_pleut(int i, int j, int k) const {
    if(collectioncubes[i][j][k].getpeau() > 1.03*collectioncubes[i][j][k].getprosee()) {
        return true;
    }
    return false;
}
