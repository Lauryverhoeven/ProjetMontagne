//
// Created by Ömer Doruk Süder on 22.04.2021.
//



#ifndef PROGICC_SYSTEME_H
#define PROGICC_SYSTEME_H
#pragma once
#include <iostream>
#include <string>
#include "Nuages.h"
#include "Dessinable.h"
#include "support_a_dessin.h"
#include "ChaineDeMontagnes.h"
#include "Montagne_pointu.h"

class SupportADessin;
class Systeme : public Dessinable {
private :
    ChaineDeMontagnes everest;
    champPotentiels champpot;
    Ciel ciel;
    double delta;
    double delta_prime;

public :
    double getAltitude(int i, int j) const;
    //constructeur qui initialise la montagne puis le champpotentiel puis le ciel
    Systeme(unsigned int Nx, unsigned int Ny, unsigned int Nz, double lambda,
            double ventinfini,double de, double dep, std:: vector<MontagneAbstraite*> const& chaine);
    void demarre(unsigned int Nx, unsigned int Ny, unsigned int Nz, double lambda, double ventinfini, double de, double dep,std::vector<MontagneAbstraite *> chaine2);

    void affiche(std:: ostream& out=std::cout) const;
    void evolue(double delta_t);
    void resoudre();
    
    virtual ~Systeme() = default;
    Systeme(Systeme &)=default;
    Systeme& operator=(Systeme const&) = default;
    Systeme(Systeme&&)                 = default;
    Systeme& operator=(Systeme&&)      = default;


    virtual void dessine_sur(SupportADessin& support) override
    { support.dessine(*this); }
    
    std::array<unsigned int, 2> getN() const;
    bool nuage(int i, int j, int k) const;

    CubedAir deplacer_nuage(double delta_t, std::array<int, 3> precedente, int i, int j, int k);
    bool Est_Dans_La_Boite(std::array<int ,3> precedente, double delta_t);
    bool Est_Cellule_Courante(std::array<int ,3> precedente, std::array<int, 3> courante, double delta_t);
    CubedAir deplacement_sans_precedente(int i, int j, int k);
    bool Est_Nuageuse(std::array<int ,3>);
    bool flaque_deau(int i, int j) const;
    void pluie();

};

std::ostream& operator<<(std::ostream& sortie, const Systeme& systeme);

#endif //PROGICC_SYSTEME_H



