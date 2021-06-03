//
// Created by Laury Verhoeven on 1/4/2021.
//

#include "Ciel/Nuages.h"
#include "Montagne/Montagne.h"
#include "ChampPotentiels/ChampPotentiels.h"
using namespace std;

//Ça marche pas parce que le constructeur du champPotentiels ont changé.
        
int main() {
        Montagne m(15, 15, 15, 5, 5, 20.0/29.0);
        champPotentiels cp(30, 30, 30, 20.0 / 29.0, m, 20);
        Ciel bleu(cp);
        bleu.affiche(cp);
};
