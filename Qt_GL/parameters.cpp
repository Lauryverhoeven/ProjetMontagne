#include "parameters.h"

//constructeur de Parameters
Parameters::Parameters(unsigned int x, unsigned int y, unsigned int z, double l, double v, double d, double d_prime, std::vector<MontagneAbstraite *> c)
{
    nx=x;
    ny=y;
    nz=z;
    lambda=l;
    vent=v;
    delta=d;
    delta_prime=d_prime;
    chaine = c;
}
