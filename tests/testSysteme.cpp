//
// Created by Laury Verhoeven on 11/4/2021.
//
#include <iostream>
#include "Systeme.h"
#include "SupportADessin.h"
#include "TextViewer.h"
#include <fstream>
using namespace std;

int main() {
    //std::ostream& flot(ostream&);
    //TextViewer t(flot);
    string fichiersortie;
    Systeme final(15, 15, 15, 5, 10,30, 30, 30, 20.0/29.0, 20);
    //final.ecriture_fichier(fichiersortie, final);
    final.demarre(0.1, 1.7/100.0, 5.0/100.0, t);
    //cout << final;

}