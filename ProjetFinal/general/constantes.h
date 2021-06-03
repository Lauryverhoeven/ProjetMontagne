//
// Created by Ömer Doruk Süder on 22.04.2021.
//

#ifndef PROGICC_CONSTANTES_H
#define PROGICC_CONSTANTES_H
#endif //PROGICC_CONSTANTES_H
#include <cmath>


namespace Physique {
    constexpr double ventinfini = 20; //(en m/s)
    constexpr double R = 8.3144621; //constante des gaz parfaits en J / (mol K)
    constexpr double mairsec = 0.02896; //masse molaire de l'air sec (en kg / mol)
    constexpr double meau = 0.0180153; //masse molaire de l'eau (en kg / mol)
    constexpr double Tinf = 284.5; //temperature au sol au loin dans la plaine (en K)
    constexpr double Pref = 101325; //pression de réference (en Pa)
    constexpr double g = 9.81;
    constexpr double Pinf = 101325; //pression de l'air au sol au loin dans la plaine (en Pa)
    constexpr double hinf = (7.0/2.0)*(R/mairsec) * Tinf;
    constexpr double cteBernouilli =(1.0/2.0)*ventinfini*ventinfini + hinf;
    constexpr double tau_inf = 8e-3;
}
