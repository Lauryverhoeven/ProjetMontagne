//
// Created by Laury Verhoeven on 18/3/2021.
//


#include "Montagne/Montagne.h"
#include "ChampPotentiels/ChampPotentiels.h"
#include <iostream>
using namespace std;


//Ça marche pas parce que le constructeur du champPotentiels a changé.

int main() {

    Montagne m(15, 15, 15, 5 ,5, 20.0/29.0);
    champPotentiels cp(30, 30, 30, 20.0 / 29.0, m, 20);
    cp.affichepot();
    //cp.afficheLap();
    //cp.calcul_Laplacien();//
    //cout << cp.erreur() << endl;
    //cp.resolution((20.0/29.0)*(20.0/29.0)*(20.0/29.0)*(20.0/29.0)*(1e-4), 5000, false, 0.1);
    //cp.affichepotvitesse();

    //cp.calcul_Laplacien();
    //cp.afficheLap();
    //cout << cp.erreur();
}



