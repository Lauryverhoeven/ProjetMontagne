//
// Created by Laury Verhoeven on 29/4/2021.
//

#include "Montagne/Montagne.h"
#include "ChampPotentiels/ChampPotentiels.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main() {

//Ça marche pas parce que le constructeur du montagne et le contructeur de champ potentiel ont changé.
        
        Montagne m(15, 15, 15, 5 ,5, 20.0/29.0);
        champPotentiels cp(30, 30, 30, 20.0 / 29.0, m, 20);
        cp.calcul_Laplacien();
        //cout << cp.erreur() << endl;
        //cp.afficheLap();
        cp.resolution((20.0/29.0)*(20.0/29.0)*(20.0/29.0)*(20.0/29.0)*(1e-4), 5000, false, 0.1);
        //cout << cp.erreur();
        //cp.afficheLap();
        cp.affichepotvitesse();

}
