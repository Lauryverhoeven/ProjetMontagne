//
// Created by Ömer Doruk Süder on 20.05.2021.
//


#ifndef MONTAGNEABSTRAITE_MONTAGNE_POINTU_H
#define MONTAGNEABSTRAITE_MONTAGNE_POINTU_H

#include "MontagneAbstraite.h"
#include "support_a_dessin.h"
#include "Dessinable.h"
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <iostream>
#include <utility>

class Montagne_pointu: public MontagneAbstraite, public Dessinable {
private :
    std:: string fichier;
    std:: vector<std:: array<int,3>> collection;
public :
    Montagne_pointu() = default;
    explicit Montagne_pointu(const std::string& InputFile);
    void dessine_sur(SupportADessin& support) override;
    void affiche_parametres(std:: ostream& out=std::cout) const;
    double altitude(double x,double y) const;

};

#endif //MONTAGNEABSTRAITE_MONTAGNE_POINTU_H