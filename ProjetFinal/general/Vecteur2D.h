//
// Created by Ömer Doruk Süder on 22.04.2021.
//

#ifndef PROGICC_VECTEUR2D_H
#define PROGICC_VECTEUR2D_H


#pragma once

#include <iostream>

class Vecteur2D{
public:
    explicit Vecteur2D(double x=0, double y=0);
    [[nodiscard]] bool compare(Vecteur2D v) const;
    void afficher(std:: ostream& out) const;
    [[nodiscard]] double getx() const{ return x;}
    [[nodiscard]] double gety() const{ return y;}
    [[nodiscard]] Vecteur2D oppose() const;
    [[nodiscard]] double norme() const;
    [[nodiscard]] double norme2() const;
    [[nodiscard]] Vecteur2D unitaire() const;
    Vecteur2D& operator+=(const Vecteur2D& c);
    Vecteur2D& operator-=(const Vecteur2D &c);
    [[nodiscard]] double produitScalaire(Vecteur2D) const;

private:
    double x;
    double y;
    friend Vecteur2D operator+(Vecteur2D p, const Vecteur2D& q);
    friend Vecteur2D operator-(Vecteur2D p, const Vecteur2D& q);
    friend Vecteur2D operator*(Vecteur2D p, const double& q);
};

std:: ostream& operator<<(std:: ostream& sortie , Vecteur2D complex);
Vecteur2D operator+(Vecteur2D p, const Vecteur2D& q);
Vecteur2D operator-(Vecteur2D p, const Vecteur2D& q);
double operator*(Vecteur2D p, const Vecteur2D& q);
Vecteur2D operator*(Vecteur2D p, const double& q);
Vecteur2D operator*(double q, const Vecteur2D& p);
bool operator==(Vecteur2D p, const Vecteur2D& q);
Vecteur2D operator~(Vecteur2D p);
Vecteur2D operator-(Vecteur2D p);
bool operator!=(Vecteur2D p, const Vecteur2D &q);

#endif //PROGICC_VECTEUR2D_H

