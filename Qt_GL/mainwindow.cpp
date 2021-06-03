#include "mainwindow.h"
#include <QtGui>
#include <QLayout>
#include "parameters_dialog.h"
#include "parameters.h"
#include "glwidget.h"
#include "Systeme.h"
#include <QVector>
#include <vector>

MainWindow::MainWindow() :  myWidget()
{
//affiche la fenetre des parametres
    Parameters_Dialog *parameters = new Parameters_Dialog(this);
 parameters->show();


}

//affiche la fenetre des montagnes
void MainWindow::displayMountains(Parameters *params){

    //initialisation du systeme grace aux valeurs rentrees dans la fenetre des parametres paer l' utilisateur
        myWidget.initialise_systeme(params->nx,
                                   params->ny,
                                   params->nz,
                                   params->lambda,
                                   params->vent,
                                   params->delta,
                                   params->delta_prime,
                                   params->chaine);
        myWidget.show();
}

