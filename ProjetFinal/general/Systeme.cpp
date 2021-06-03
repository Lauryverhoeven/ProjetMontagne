//
// Created by Ömer Doruk Süder on 22.04.2021.
//

#include <array>
#include <iostream>
#include "Systeme.h"

using namespace std;
using namespace Physique;

//constructeur de systeme
Systeme::Systeme(unsigned int Nx, unsigned int Ny, unsigned int Nz, double lambda, double ventinfini, double de, double dep,  vector<MontagneAbstraite *> const &chaine) :
            everest(Nx,Ny,chaine),
            champpot(Nx, Ny, Nz, lambda, chaine, ventinfini),
            ciel(champpot)
    {
        delta=de;
        delta_prime=dep;
    }


void Systeme::demarre(unsigned int Nx, unsigned int Ny, unsigned int Nz, double lambda, double ventinfini, double de, double dep, vector<MontagneAbstraite *> chaine2)
{
                everest.initialise_chaine(Nx,Ny,chaine2);
                champpot.initialise_champ(Nx, Ny, Nz, lambda, chaine2, ventinfini);
                ciel.initialise_ciel(champpot);
                delta=de;
                delta_prime=dep;
}
//getters 

double Systeme::getAltitude(int i, int j) const {
    return everest.altitude(i,j) ;
}

array<unsigned int, 2> Systeme::getN() const {
    array<unsigned int, 2> v;
    v[0] = champpot.getNx();
    v[1] = champpot.getNy();
    v[2] = champpot.getNz();
    return v; }

//affichage texte de Systeme
void Systeme::affiche(ostream &out) const {
    everest.affiche(out);
    champpot.affiche_parametres(out);
    ciel.affiche(champpot,out);
}

//recalcule le Ciel au fur et a mesure du temps
void Systeme::evolue(double delta_t) {

    vector<vector<vector<CubedAir>>> collection_evolue; //stocke les nouvelles valeurs du ciel

    for (int i(0); i < champpot.getNx(); ++i) {
        vector<vector<CubedAir>> collectionx;
        for (int j(0); j < champpot.getNy(); ++j) {
            vector<CubedAir> collectiony;
            for (int k(0); k < champpot.getNz(); ++k){
                CubedAir cube(i,j,k, champpot);
                collectiony.push_back(cube);
            }
            collectionx.push_back(collectiony);
        }
        collection_evolue.push_back(collectionx);
    }
            
            pluie(); //recalcule l'humidite en fonction de la pluie sous les nuages

    for (int i(0); i < champpot.getNx(); ++i) {
        for (int j(0); j < champpot.getNy(); ++j) {
            for (int k(0); k < champpot.getNz(); ++k) {

                array<int, 3> cellule_precedente = ciel.precedente(i,j,k, delta_t);
                array<int, 3> cellule_courante = {i,j,k};

                if(not Est_Cellule_Courante(cellule_precedente, cellule_courante, delta_t) and Est_Dans_La_Boite(cellule_precedente, delta_t)) {
                        collection_evolue[i][j][k] = deplacer_nuage(delta_t, cellule_precedente, i, j, k);

                } else if(not Est_Dans_La_Boite(cellule_precedente, delta_t) and Est_Nuageuse(cellule_courante)) {
                        collection_evolue[i][j][k] = deplacement_sans_precedente(i,j,k);

                } else {
                    collection_evolue[i][j][k] = ciel.getCollection(i,j,k);
                }
            }
        }
    }

    for (int i(0); i < champpot.getNx(); ++i) {
        for (int j(0); j < champpot.getNy(); ++j) {
            for (int k(0); k < champpot.getNz(); ++k) {
                ciel.SetCollection(i,j,k, collection_evolue[i][j][k]);
            }
        }
    }
}

bool Systeme::Est_Cellule_Courante(array<int,3> precedente, array<int, 3> courante, double delta_t) {
        if(precedente[0] == courante[0] and precedente[1]==courante[1] and precedente[2] == courante[2]) {
            return true;
        } else {return false;}
}


bool Systeme::Est_Dans_La_Boite(array<int, 3> precedente, double delta_t) {

    if(precedente[0] < 0 or precedente[0] > champpot.getNx()-1
    or precedente[1] < 0 or precedente[1] > champpot.getNy()-1
    or precedente[2] < 0 or precedente[2] > champpot.getNz()-1) {
        return false;
    } else {
        return true;
    }
}

//surchage d'operateur
ostream& operator<<(ostream& sortie , const Systeme& systeme){
    systeme.affiche(sortie);
    return sortie;
}


//determine s'il y a un nuage pour une case du ciel du systeme
bool Systeme::nuage(int i, int j, int k) const {
    return ciel.getetat(i,j,k);
}

//methode pour calculer le deplacement d'un nuage sur une case donnée
CubedAir Systeme::deplacer_nuage(double delta_t, array<int, 3> precedente, int i, int j, int k) {
    CubedAir p;
    int a = precedente[0];
    int b = precedente[1];
    int c = precedente[2];
    if (ciel.getetat(i, j, k) && !ciel.getetat(a, b, c)) {
       p = ciel.recalcul_nuage(i,j,k,delta);
    } else if (!ciel.getetat(i, j, k) && ciel.getetat(a, b, c)) {
       p = ciel.recalcul_nuage(i,j,k,-delta_prime);
    } else {
    p = ciel.getCollection(i,j,k);
    }
    return p;
}

//Pour une case C donnée, si sa case precedente sort de la boite, elle est consideree non nuageuse donc dans ce cas là on recalcule C grâce à cette methode
CubedAir Systeme::deplacement_sans_precedente(int i, int j, int k) {
    CubedAir p;
    p = ciel.recalcul_nuage(i,j,k,delta);
    return p;
}

//determine si une cellule du ciel est nuageuse
bool Systeme::Est_Nuageuse(array<int, 3> cellule) {

if(ciel.getCollection(cellule[0],cellule[1],cellule[2]).isNuage()) {
    return true;
} else {
return false;}
}

//recalcule la baisse d humidite due a la pluie
void Systeme::pluie() { 
    for(int i(0); i < ciel.getNx(); ++i) {
        for(int j(0); j < ciel.getNy(); ++j) {
            for (int k(0); k < ciel.getNz(); ++k) {
                if(ciel.il_pleut(i,j,k)) {
                    ciel.getCollection(i,j,k).maj_humidite(delta);
                }
            }
        }
    }
}

//permet de dessiner la pluie dans vue_open_gl
bool Systeme::flaque_deau(int i, int j) const { 
    bool fete_de_la_grenouille(false);
    for(unsigned int k(0); k < ciel.getNz(); ++k) {
        if(ciel.il_pleut(i,j,k)) {
        fete_de_la_grenouille = true;
        }
    }
    return fete_de_la_grenouille;
}





