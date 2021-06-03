//
// Created by Ömer Doruk Süder on 22.04.2021.
//


#ifndef PROGICC_NUAGES_H
#define PROGICC_NUAGES_H
#pragma once
#include <array>
#include "ChampPotentiels.h"
#include "constantes.h"
#include "Echantillon.h"
#include "support_a_dessin.h"
#include "Dessinable.h"

class CubedAir {
private :
    std::array<double,3> vitessevent; //vitesse du vent
    bool etat; //nuage ou non
    double T; //temperature
    double P; //pression
    double peau; //pression partielle de vapeur d'eau
    double tauxhum; //taux d'humidité
    double h; //enthalpie
    double prosee; //pression de vapeur saturante d'eau (fonction de la temperature)

public :
    CubedAir() = default;
    CubedAir(int i, int j, int k, champPotentiels& cp);
    //constructeur qui initialise un cube d'air à une position i j k donnée, va permettre d'initialiser un Ciel en itérant sur chaque coordonnée (utile pour le 1er constructeur de Ciel)
    explicit CubedAir(double v);
    //permet d'initialiser le ciel avec le deuxieme constructeur de Ciel
    double geth() const {return h;}
    double getT() const {return T;}
    double getpeau() const {return peau;}
    double getP() const {return P;}
    double getprosee() const {return prosee;}
    double get_hum() const {return tauxhum;}
    bool isNuage() const; //determine s'il y a un nuage sur le cube d'air
    bool set_etat(bool cloud) const {return cloud;}
    std::array<double, 3> getvent() {return(vitessevent);}
    void setvent(std::array<double, 3> v);
    void seth(double a);
    void set_humidite(double hum);
    void setpeau(double d) {peau = d;}
    void maj_humidite(double d);
    bool pluie();

};

class Ciel : public Echantillon, public Dessinable {
public:
    explicit Ciel(champPotentiels &cp);

    Ciel(unsigned int Nx, unsigned int Ny, unsigned int Nz, double lambda, double v);
    Ciel(unsigned int Nx, unsigned int Ny, unsigned int Nz, double lambda) : Echantillon(Nx, Ny, Nz, lambda) {}
    void initialise_ciel(champPotentiels& cp);
    void affiche( const champPotentiels& cp,std:: ostream& out=std::cout) const ;
    bool getetat(int i, int j, int k) const; //determine s'il y a nuage pour une case du ciel donnée
    void set_humidite(int i, int j, int k, double hum); 
    double get_hum(int i, int j, int k);
    void dessine_sur(SupportADessin& support) override;
    double getP(int i, int j,int k) const {return collectioncubes[i][j][k].getP();}
    double getprosee(int i, int j, int k) const {return collectioncubes[i][j][k].getprosee();}
    double getpeau(int i, int j, int k) const {return collectioncubes[i][j][k].getpeau();}
    double get_hum(int i, int j, int k) const {return collectioncubes[i][j][k].get_hum();}
    void setpeau(int i, int j, int k, double d) {collectioncubes[i][j][k].setpeau(d);}
    CubedAir recalcul_nuage(int i, int j, int k, double d);
    std::array<int, 3> precedente(int i,int j, int k ,double delta_t);
    CubedAir getCollection(int i, int j, int k);
    void SetCollection(int i, int j, int k, CubedAir w);
    bool il_pleut(int i, int j, int k) const;


private:
    std::vector<std::vector<std::vector<CubedAir>>> collectioncubes; //contient tous les cubes d'air qui forment le ciel 

};

#endif //PROGICC_NUAGES_H

