#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QObject>
#include "MontagneAbstraite.h"

class Parameters
{
public:
    unsigned int nx;
    unsigned int ny;
    unsigned int nz;
    double lambda;
    double vent;
    double delta;
    double delta_prime;
    std::vector<MontagneAbstraite *> chaine;

    Parameters(unsigned int x, unsigned int y, unsigned int z, double l, double v, double d, double d_prime,std::vector<MontagneAbstraite *> c);

};

#endif // PARAMETERS_H
