//
// Created by Ömer Doruk Süder on 22.04.2021.
//

#ifndef PROGICC_DESSINABLE_H
#define PROGICC_DESSINABLE_H
#pragma once
#include "support_a_dessin.h"

class SupportADessin;

class Dessinable {
public:
    virtual void dessine_sur(SupportADessin& support)=0; //chaque sous classe doit contenir exactement ce code

    virtual ~Dessinable() = default;
    Dessinable(Dessinable const&)            = default;
    Dessinable& operator=(Dessinable const&) = default;
    Dessinable(Dessinable&&)                 = default;
    Dessinable& operator=(Dessinable&&)      = default;

    Dessinable() = default;

};


#endif //PROGICC_DESSIN_H
