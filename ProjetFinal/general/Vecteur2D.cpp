//
// Created by Ömer Doruk Süder on 22.04.2021.
//


#include <iostream>
#include <cmath>
#include <iomanip>
#include "Vecteur2D.h"
using namespace std;

//constructeur: initialise deux doubles pour les composontes x et y de la vecteur
Vecteur2D::Vecteur2D(double x, double y) : x(x), y(y){}

//methode affiche dans la classe Vecteur2D
void Vecteur2D::afficher(ostream &out) const {
    double x_(getx());
    double y_(gety());
    cout << "("<<x_ << "," << y_<<")" << endl;

}

//surcharge operator + (addition vectorielle) defini avec friend
Vecteur2D operator+(Vecteur2D p, const Vecteur2D& q){
    Vecteur2D result;
    result.x=p.x+q.x;
    result.y=p.y+q.y;
    return result;
}

//surcharge operator += (addition vectorielle) defini a partir de +
Vecteur2D &Vecteur2D::operator+=(const Vecteur2D &c) {
    return *this=*this+c;
}

//surcharge operator - (soustraction vectorielle) defini avec friend
Vecteur2D operator-(Vecteur2D p, const Vecteur2D& q){
    Vecteur2D result;
    result.x=p.x-q.x;
    result.y=p.y-q.y;
    return result;
}

//surcharge operator -= (soustraction vectorielle) defini a partir de -
Vecteur2D &Vecteur2D::operator-=(const Vecteur2D &c) {
    return *this=*this-c;
}

//surcharge operator << qui uilise la methode affiche
ostream& operator<<(ostream& sortie , Vecteur2D complex){
    complex.afficher(sortie);
    return sortie;
}

//methode comparaison de deux vecteurs
bool Vecteur2D::compare(Vecteur2D v) const {
    cout << fixed << setprecision(1);
    if (x == v.getx() and y == v.gety()) {
        return true;
    } else return false;
}


//methode oppose applique a v qui renvoie -v
Vecteur2D Vecteur2D::oppose() const {
    Vecteur2D vect;
    vect.x=-x;
    vect.y=-y;
    return vect;
}

// methode norme applique a v qui renvoie sa norme
double Vecteur2D::norme() const {
    return (sqrt(x*x+y*y));
}

// methode norme applique a v qui renvoie sa norme au carre
double Vecteur2D::norme2() const {
    return ((x*x+y*y));
}

// methode unitire applique a v qui renvoie sa vecteur directeur normalisee
Vecteur2D Vecteur2D::unitaire() const {
    Vecteur2D vect;
    vect.x=x/sqrt(x*x+y*y);
    vect.y=y/sqrt(x*x+y*y);
    return vect;
}

// methode produit scalaire qui effectue le produit scalaire de deux vecteurs
double Vecteur2D::produitScalaire( Vecteur2D autre) const {
    return (x*autre.getx()+y*autre.gety());
}

//surcharge oparator * pour la multiplication externe avec les scalaires (a droit)
Vecteur2D operator*(Vecteur2D p, const double& q){
    Vecteur2D result;
    result.x=p.x*q;
    result.y=p.y*q;
    return result;
}

//surcharge oparator * pour la multiplication externe avec les scalaires (a gauche)
Vecteur2D operator*(double q, const Vecteur2D& p){
    return p*q;
}

//surcharge oparator == qui utilise la methode compare
bool operator==(Vecteur2D p, const Vecteur2D &q) {
    return p.compare(q);
}

//surcharge oparator * pour la produit scalaire (multiplication interne) avec les vecteurs (a gauche)
double operator*(Vecteur2D p, const Vecteur2D& q){
    return p.produitScalaire(q);
}

//surcharge oparator ~ qui renvoie la vecteur unitaire avec la methode unitaire
Vecteur2D operator~(Vecteur2D p){
    return p.unitaire();
}
//surcharge oparator - qui renvoie l'oppose avec la methode oppose
Vecteur2D operator-(Vecteur2D p){
    return p.oppose();
}

//surcharge oparator != pour la comparaison de deux vecteurs avec la methode compare
bool operator!=(Vecteur2D p, const Vecteur2D &q) {
    return not(p.compare(q));
}