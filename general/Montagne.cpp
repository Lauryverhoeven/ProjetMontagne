//
// Created by Ömer Doruk Süder on 22.04.2021.
//

#include <cmath>
#include <iomanip>
#include "Montagne.h"
using namespace std;

//donne l'altitude de la montagne pour chaque point
double Montagne::altitude(double x, double y) const { 
    cout << fixed << setprecision(6);
    double alt(h * exp(-pow(x-i0, 2) / (2 * pow(sigmai, 2)) - (pow(y-j0,2) / (2 * pow(sigmaj,2)))));
    if(alt > 0.5) {
        return (alt);
    } else {
        return(0);
    }
}

Montagne::Montagne(double i0, double j0, double h, double sigmai, double sigmaj,double lambda) : 
    i0(i0), j0(j0), h(h), sigmai(sigmai), sigmaj(sigmaj), lambda(lambda){}

//affiche les parametres de la montagne (methode utilisée pour l'affichage texte du systeme)
void Montagne::affiche_parametres(std:: ostream& out) const {
    out << "i0 = " << i0 << " (x0 = " << i0 * lambda << ") " << endl;
    out << "j0 = " << j0 << " (y0 = " << j0 * lambda << ") " << endl;
    out << "h = " << h << " (H = " << h * lambda << ") " << endl;
    out << "Si0 = " << sigmai << " (Sx0 = " << sigmai * lambda << ") " << endl;
    out << "Sj0 = " << sigmaj << " (Sy0 = " << sigmaj * lambda << ") " << endl;
}
 
//surcharge de dessine_sur
void Montagne::dessine_sur(SupportADessin& support) {
    support.dessine(*this);
}
