//
// Created by Ömer Doruk Süder on 22.04.2021.
//

#include<iostream>
#include "TextViewer.h"
#include "Systeme.h"
#include "Montagne.h"
#include "Nuages.h"
#include "ChaineDeMontagnes.h"
using namespace std;


void TextViewer::dessine(const Ciel &a_dessiner) {

    //flot << a_dessiner; soit on surcharge le << soit on appel les methodes affiche

}

void TextViewer::dessine(const Montagne &a_dessiner) {

    //a_dessiner.affiche_parametres();

}

void TextViewer::dessine(const Systeme &a_dessiner) {


    flot << a_dessiner;


}

void TextViewer::dessine(const ChaineDeMontagnes &a_dessiner) {

    //a_dessiner.affiche();
}
