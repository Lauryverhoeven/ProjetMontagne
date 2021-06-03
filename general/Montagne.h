//
// Created by Ömer Doruk Süder on 22.04.2021.
//

#ifndef PROGICC_MONTAGNE_H
#define PROGICC_MONTAGNE_H

#endif //PROGICC_MONTAGNE_H

#pragma once
#include <iostream>
#include "Dessinable.h"
#include "support_a_dessin.h"
#include "MontagneAbstraite.h"

class Montagne : public MontagneAbstraite, public Dessinable {
private :
    double i0;
    double j0;
    double h;
    double sigmai;
    double sigmaj;
    double lambda;

public :
    Montagne(double x0, double y0, double H, double sigmax, double sigmay, double lambda);
    void affiche_parametres(std:: ostream& out=std::cout) const;
    void dessine_sur(SupportADessin& support) override;
    double altitude(double x, double y) const override;
    ~Montagne()=default;

};
