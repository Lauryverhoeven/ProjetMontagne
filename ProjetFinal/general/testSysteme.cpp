//
// Created by Ömer Doruk Süder on 15.05.2021.
//

#include <iostream>
#include "Systeme.h"
#include "support_a_dessin.h"
#include "TextViewer.h"
#include <fstream>
using namespace std;

int main() {
    //std::ostream& flot(ostream&);
    //TextViewer t(flot);
    //string fichiersortie;

    /* Nous voulons un support à dessin :                          *
      * ici un TextViewer qui écrit sur un flot out                        */
    //std:: ofstream sortie("test_affiche.txt");
    //TextViewer ecran(sortie);
    vector<MontagneAbstraite *> chaine={new Montagne(15, 15, 15, 5 ,5,20.0/29.0)};
    vector<MontagneAbstraite *> chaine1={new Montagne_pointu("../cervin_reduced.dat.txt")};
    //ChaineDeMontagnes m(chaine);
    Systeme final( 30, 30, 30, 20.0/29.0, 20, 0.017, 0.05, chaine1);
  //  final.evolue(0.031);
    cout << final;
    // Nous voulons un contenu à dessiner
    //Montagne montagne(15,15,15,10,10,20.0/29.0);
    //Systeme final(15, 15, 15, 5, 10,30, 30, 30, 20.0/29.0, 20);
    //Ciel ciel();

    // Nous dessinons notre contenu  sur notre support à dessin précédent
    //montagne.dessine_sur(ecran);

  //  final.dessine_sur(ecran);
    //final.evolue(0.031);
    //final.dessine_sur(ecran);

    return 0;

}
