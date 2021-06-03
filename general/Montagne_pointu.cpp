//
// Created by Ömer Doruk Süder on 20.05.2021.
//

//
// Created by Ömer Doruk Süder on 27.05.2021.
//

#include "Montagne_pointu.h"
#include <array>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;


double Montagne_pointu::altitude(double x, double y) const {
    double retour;

    for (auto el: collection){
        if(round(x)==el[0] and round(y)==el[1]) {
            retour= el[2];
            break;
        } else  {
            retour = 0;
        }
    }

    if(retour<=0) return 0;
    return retour;
}

/*
void Montagne_pointu::affiche_parametres(ostream &out) const {
    for (int i(0); i < 40; ++i) {
        for (int j(0); j < 40; ++j) {
            out << i <<" " << j << " " ;
            out <<altitude(i,j)<< std:: endl;
        }
    }
}
 */


Montagne_pointu::Montagne_pointu(const string &InputFile) : fichier(InputFile){
    ifstream entree(fichier);

    string a, b, c;
    int x, y, z;

    array<int,3> valeurs{};

    while (entree >> a >> b >> c) {
        stringstream geek1(a);
        stringstream geek2(b);
        stringstream geek3(c);

        geek1 >> x;
        geek2 >> y;

        valeurs[0]=x;
        valeurs[1]=y;

        if(!c.compare("nan")) {
            valeurs[2] = 0;
        }else{
            geek3 >> z;
            valeurs[2]=z;
        }
        collection.push_back(valeurs);
    }
    entree.close();
}


void Montagne_pointu::dessine_sur(SupportADessin &support) {
    support.dessine(*this);
}


