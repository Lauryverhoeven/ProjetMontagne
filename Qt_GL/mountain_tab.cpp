#include "mountain_tab.h"
#include <QGridLayout>

//Moutain_Tab est la classe qui va permettre de modeliser les onglets qui parametrent les montagnes,
//c' est a dire de definir un champ de valeurs possibles pour chaque parametre d' une montagne et de disposer
//physiquement ces valeurs sur les onglets
Mountain_Tab::Mountain_Tab()
{

    i_zero.setMinimum(0.0); //valeur minimale que l' on peut entrer
    i_zero.setMaximum(30.0); //valeur maximale que l' on peut entrer
    i_zero.setValue(15.0); //definit une valeur par defaut
    i_zero.setDecimals(1); //nombre de decimales dans la valeur i0
    j_zero.setMinimum(0.0);
    j_zero.setMaximum(30.0);
    j_zero.setValue(15.0);
    j_zero.setDecimals(1);
    sigma_i.setMinimum(0.0);
    sigma_i.setMaximum(25.0);
    sigma_i.setValue(5.0);
    sigma_i.setDecimals(1);
    sigma_j.setMinimum(0.0);
    sigma_j.setMaximum(25.0);
    sigma_j.setValue(5.0);
    sigma_j.setDecimals(1);
    h.setMinimum(0.0);
    h.setMaximum(60.0);
    h.setValue(15.0);
    h.setDecimals(1);

    i_zero_label.setText("i0:");

    j_zero_label.setText("j0:");
    h_label.setText("h:");
    sigma_i_label.setText("sigma i:");
    sigma_j_label.setText("sigma j:");

    QGridLayout* layout = new QGridLayout;

    //permet de donner la disposition de chaque parametre dans l' onglet des parametres d' une montagne dans la fenetre des parametres

    layout->addWidget(&i_zero_label,0,0); //le textbox " i0" va s' afficher a la coordonnee 0,0 de l onglet c' est a dire en haut
    layout->addWidget(&i_zero,0,1); //le case pour parametrer i0 va s' afficher a la coordonnee 0,1 c' est a dire a droite de la textbox precedente
    layout->addWidget(&j_zero_label,1,0);
    layout->addWidget(&j_zero,1,1);
    layout->addWidget(&h_label,2,0);
    layout->addWidget(&h,2,1);
    layout->addWidget(&sigma_i_label,3,0);
    layout->addWidget(&sigma_i,3,1);
    layout->addWidget(&sigma_j_label,4,0);
    layout->addWidget(&sigma_j,4,1);

    setLayout(layout);
}

//getters des parametres de la montagne qui vont permettre de pouvoir construire les montagnes a partir des parametres
//recuperes dans l' onglet de la fenetre des parametres

double Mountain_Tab::get_i_zero()
{
    return i_zero.value();
}
double Mountain_Tab::get_j_zero()
{
    return j_zero.value();
}
double Mountain_Tab::get_sigma_i()
{
    return sigma_i.value();
}
double Mountain_Tab::get_sigma_j()
{
    return sigma_j.value();
}
double Mountain_Tab::get_h()
{
    return h.value();
}
