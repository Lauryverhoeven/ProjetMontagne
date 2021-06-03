//
// Created by Ömer Doruk Süder on 22.04.2021.
//
#include <iostream>
#include <iomanip>
#include <cmath>

#include "ChampPotentiels.h"

using namespace std;


//------------------------------- methodes Potentiels------------------------------

//constructeur de Potentiels qui prend deux Vecteur2D comme argument pour initialiser les attributs de Potentiels
Potentiels::Potentiels(Vecteur2D L, Vecteur2D pot) :  potentiel(pot), laplacien(L){}



//------------------------------- methodes ChampPotentiels------------------------------

//constructeur de champ potentiels
champPotentiels::champPotentiels(unsigned int Nx, unsigned int Ny, unsigned int Nz, double lambda,
                                 const vector<MontagneAbstraite *>& Toblerone, double ventinfini) :
                                 Echantillon(Nx, Ny, Nz, lambda), ventinfini(ventinfini),
                                 toblerone(Nx,Ny,Toblerone) {
    initialise_champ(Nx, Ny,Nz,lambda, Toblerone, ventinfini);

}


//initialise le vecteur potentiel de chaque petit cube
void champPotentiels::initialise_champ(unsigned int Nx, unsigned int Ny, unsigned int Nz, double lambda,
                                  const vector<MontagneAbstraite *>& Toblerone, double ventinfini) {
    update(Nx, Ny, Nz, lambda);
    toblerone.initialise_chaine(Nx, Ny, Toblerone);
    this->ventinfini = ventinfini;

    //collection.erase(collection.begin(),collection.end());
    collection.clear();

    for(unsigned int i(0); i < getNx(); ++i) {
        vector<vector<Potentiels>> collectionx;
        for(unsigned int j(0); j < getNy(); ++j) {
            vector<Potentiels> collectiony;
            for(unsigned int k(0); k < getNz(); ++k) {
                double u2;
                double u3;
                if (k >= toblerone.altitude(i, j)) {
                    u2 = (-ventinfini / 2) * k * lambda;
                    u3 = (ventinfini / 2) * (j * lambda - (cotes[1] / 2));
                } else {
                    u2 = u3 = 0;
                }
                Potentiels pot(Vecteur2D(0.0, 0.0), Vecteur2D(u2, u3));
                collectiony.push_back(pot);
            }
            collectionx.push_back(collectiony);
        }
        collection.push_back(collectionx);
    }

    calcul_Laplacien();
    resolution(pow(lambda,4)*(1e-4), 5000, false, 0.1);

    for(unsigned int i(1); i < nbCubes[0]-1; ++i) {
        vector<vector<double>> vectx;
        for(unsigned int j(1); j < nbCubes[1]-1; ++j) {
            vector<double>vecty;
            for(unsigned int k(1); k < nbCubes[2]-1; ++k) {
                vecty.push_back(norme3carre(i,j,k));
            }
            vectx.push_back(vecty);
        }
        VectNorme3carre.push_back(vectx);
    }
}
//affiche le potentiel de chaque petit cube (sans initialisation)
void champPotentiels::affichepot(std:: ostream& out) const{
    for (unsigned int i(0); i < getNx(); ++i) {
        for (unsigned int j(0); j < getNy(); ++j) {
            for (unsigned int k(0); k < getNz(); ++k) {
                //cout << fixed << defaultfloat;
                out << i << " " <<  j << " " << k << " " << collection[i][j][k].getpot().getx() << " " << collection[i][j][k].getpot().gety() << endl;
            }
        }
    }
}

//calcul le vecteur Laplacien pour chaque petit cube
void champPotentiels::calcul_Laplacien() {
    for (unsigned int i(1); i < getNx()-1; ++i) {
        for (unsigned int j(1); j < getNy()-1; ++j) {
            for (unsigned int k(1); k < getNz()-1; ++k) {
                if (k > toblerone.altitude(i, j)) { //METTRE STRICTEMENT INF
                    collection[i][j][k].setLap((collection[i - 1][j][k].getpot() + collection[i][j - 1][k].getpot() +
                                                collection[i][j][k - 1].getpot() -
                                                6 * collection[i][j][k].getpot() + collection[i + 1][j][k].getpot() +
                                                collection[i][j + 1][k].getpot() +
                                                collection[i][j][k + 1].getpot()));
                } else {
                    Vecteur2D nul(0.0, 0.0);
                    collection[i][j][k].setLap(nul);
                }
            }
        }
    }
}

//affiche la valeur des Laplaciens pour chaque petit cube sans initialisation enleve les parametres
void champPotentiels::afficheLap() const{
    for (int i(1); i < getNx(); ++i) {
        for (int j(1); j < getNy() ; ++j) {
            for (int k(1); k < getNz(); ++k) {
                //cout << fixed << defaultfloat;
                cout << i << " " << j << " " << k << " " << collection[i][j][k].getLap().getx() << " "
                     << collection[i][j][k].getLap().gety() << endl;
            }
        }
    }
}

//calcul de la somme des carrés des Laplaciens
double champPotentiels::erreur() {
    double somme(0);
    for (int i(0); i < collection.size(); ++i) {
        for (int j(0); j < collection[i].size(); ++j) {
            for (int k(0); k < collection[i][j].size(); ++k) {
                somme += collection[i][j][k].getLap().norme2();
            }
        }
    }
    return (somme);
}

//methode d'iteration pour la convergence des Laplaciens
void champPotentiels::iteration(double epsilon) {

    for (int i(1); i < collection.size() - 1; ++i) {
        for (int j(1); j < collection[i].size() - 1; ++j) {
            for (int k(1); k < collection[i][j].size() - 1; ++k) {
                collection[i][j][k].setpot(collection[i][j][k].getpot() + epsilon * collection[i][j][k].getLap());
            }
        }
    }
}

//itere jusqu'à obtenir les nouvelles valeurs des Laplaciens pour un seuil d'erreur donné
void champPotentiels::resolution(double seuil, double maxIter, bool verbeuse, double epsilon) {
    unsigned int iter(0);
    while (erreur() > seuil and iter < maxIter) {
        calcul_Laplacien();
        iteration(epsilon);
        ++iter;
    }
}

//calcule la vitesse du vent pour un petit cube de coordonnée i j k
array<double, 3> champPotentiels::vitesse(int i, int j, int k) {
    array<double, 3> p = {0.0,0.0,0.0};
    if ((i == 0) or (j == 0) or (k == 0) or (i == getNx()-1) or (j == getNy()-1) or (k == getNz()-1)) {
        p[0] = ventinfini;
        p[1] = p[2] = 0;
    } else {
        p[0] = (1 / (2 * lambda)) * (collection[i][j + 1][k].getpot().gety()
                                     - collection[i][j - 1][k].getpot().gety()
                                     - collection[i][j][k + 1].getpot().getx()
                                     + collection[i][j][k - 1].getpot().getx());
        p[1] = (1 / (2 * lambda)) * (collection[i - 1][j][k].getpot().gety()
                                     - collection[i + 1][j][k].getpot().gety());
        p[2] = (1 / (2 * lambda)) * (collection[i + 1][j][k].getpot().getx()
                                     - collection[i - 1][j][k].getpot().getx());
    }
    return (p);
}

//affiche pour chaque petit cube de la collection : i j k v1 v2 v3
void champPotentiels::affichepotvitesse(std:: ostream& out) {
    for (int i(0); i < getNx(); ++i) {
        for (int j(0); j < getNy(); ++j) {
            for (int k(0); k < getNz(); ++k) {
                out << i << " " << j << " " << k << " " << setprecision(13) << collection[i][j][k].getpot().getx()
                     << " "
                     << collection[i][j][k].getpot().gety() << defaultfloat << " " << vitesse(i, j, k)[0] << " "
                     << vitesse(i, j, k)[1]
                     << " " << vitesse(i, j, k)[2]
                     << " " << norme3carre(i, j, k) << endl;
            }
        }
    }
}

//calcule la norme de la vitesse pour un vecteur 3D
double champPotentiels::norme3carre(int i, int j, int k) {
    array<double, 3> vit = vitesse(i, j, k);
    return (pow(vit[0], 2) + pow(vit[1], 2) + pow(vit[2], 2));
}

void champPotentiels::affiche_parametres(std:: ostream& out) const {
    out << "Nx = " << getNx() << " Ny = " << getNy() << " Nz = " << getNz() << endl;
    out << "Lx = " << cotes[0] << " Ly = " << cotes[1] << " Lz = " << cotes[2] << endl;
    out << "lambda = " << lambda << endl;
    out << "valeurs : " << endl;
    affichepot(out);
}

//getter de VectNorme3carre
std::vector<std::vector<std::vector<double>>> champPotentiels::getNorme3() const{
    return VectNorme3carre;
}

//affiche les valeurs de la norme de la vitesse pour chaque cube
void champPotentiels:: afficheN3carre() const {
    for(int i(1); i < nbCubes[0]-1; ++i) {
        vector<vector<double>> vectx;
        for(int j(1); j < nbCubes[1]-1; ++j) {
            vector<double>vecty;
            for(int k(1); k < nbCubes[2]-1; ++k) {
                cout << i<<" "<<j <<" "<<k << " "<<VectNorme3carre[i-1][j-1][k-1]<< endl;
            }
        }
    }
}
