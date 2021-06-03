//
// Created by Ömer Doruk Süder on 30.04.2021.
//

#ifndef PROGICC_CHAINEDEMONTAGNES_H
#define PROGICC_CHAINEDEMONTAGNES_H


#include <iostream>
#include <vector>
#include <array>
#include "Dessinable.h"
#include "support_a_dessin.h"
#include "Montagne.h"
#include "MontagneAbstraite.h"

class ChaineDeMontagnes: public MontagneAbstraite, public Dessinable {
public:
    ChaineDeMontagnes(int x,int y,std:: vector<MontagneAbstraite*> const& chaine);
    ChaineDeMontagnes()=default;
    ChaineDeMontagnes(ChaineDeMontagnes&)= default;
    void initialise_chaine(int x,int y,std::vector<MontagneAbstraite *> const& chaine);
    double altitude(double, double) const override;
    void dessine_sur(SupportADessin& support) override;
    void ajouter(MontagneAbstraite*);
    void affiche(std:: ostream& out=std::cout) const;
    ~ChaineDeMontagnes() override =default;
private:
    std:: vector<MontagneAbstraite*> chaine;
    std:: array<int,2> NbCubes;


};

#endif //PROGICC_CHAINEDEMONTAGNES_H
