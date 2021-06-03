//
// Created by Ömer Doruk Süder on 22.04.2021.
//

#ifndef PROGICC_SUPPORTADESSIN_H
#define PROGICC_SUPPORTADESSIN_H
#pragma once

class Montagne;
class Ciel;
class Systeme;
class ChaineDeMontagnes;
class MontagneAbstraite;
class Montagne_pointu;

class SupportADessin{
public:
    virtual ~SupportADessin() = default;
    // on ne copie pas les Supports
    SupportADessin(SupportADessin const&)            = delete;
    SupportADessin& operator=(SupportADessin const&) = delete;
    // mais on peut les déplacer
    SupportADessin(SupportADessin&&)            = default;
    SupportADessin& operator=(SupportADessin&&) = default;

    SupportADessin() = default;

    virtual void dessine(Systeme const& a_dessiner) = 0;
    virtual void dessine(Montagne const& a_dessiner) = 0;
    virtual void dessine(Ciel const& a_dessiner) = 0;
    virtual void dessine(ChaineDeMontagnes const& a_dessiner) = 0;
    virtual void dessine(Montagne_pointu const& a_dessiner) = 0;

    /* Mettre ici toutes les méthodes nécessaires pour dessiner tous les
     * objets que l'on veut dessiner. Par exemple :
     *    virtual void dessine(Nounours const& a_dessiner) = 0;
     *    virtual void dessine(Voiture  const& a_dessiner) = 0;
     */
};

#endif //PROGICC_SUPPORTADESSIN_H
