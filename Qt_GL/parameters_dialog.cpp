#include "parameters_dialog.h"
#include "ui_parameters_dialog.h"
#include "glwidget.h"
#include "Systeme.h"
#include "mainwindow.h"
#include "parameters.h"
#include "mountain_tab.h"
#include <QVector>
#include <vector>
#include <QFileDialog>

Parameters_Dialog::Parameters_Dialog(MainWindow *parent)
    : QDialog(nullptr)
    , ui(new Ui::Parameters_Dialog)
{
    ui->setupUi(this);
    main=parent;

    //construct the first mountain tab
    Mountain_Tab* first_tab = new Mountain_Tab;
    tabs.push_back(first_tab);
    ui->tabWidget->addTab(first_tab, "Montagne 1");
    //remove the tab that was created by qtcreator
    ui->tabWidget->removeTab(0);
}

Parameters_Dialog::~Parameters_Dialog()
{
    delete ui;
}

//actions qui se deroulent lorsque le bouton "ok" est presse
void Parameters_Dialog::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false); // le bouton "ok" se desactive
    ui->pushButton->repaint(); //le bouton "ok"  devient gris
    ui->label_10->setEnabled(true); //le message "Veuillez patienter svp"  est active
    ui->label_10->repaint(); //le message devient mieux visible

    std::vector<MontagneAbstraite *> chaine;
    //creation les montagnes stockee dans la chaine
    for (unsigned int i(0);i< tabs.size();i++)
    {
        Montagne* mountain = new Montagne(tabs.at(i)->get_i_zero(),
                                  tabs[i]->get_j_zero(), //tabs est
                                  tabs[i]->get_h(),
                                  tabs[i]->get_sigma_i(),
                                  tabs[i]->get_sigma_j(),
                                  ui->lambdaNumSpinBox->value()/ui->lambdaDenSpinBox->value());
        chaine.push_back(mountain);

    }

    std::string filePath;
    //s' occupe d'aller chercher la  montagne pointue
    if (ui->checkBox->isEnabled() && ui->lineEdit->text().size()>0) { //verifie que l' utilisateur a rentre un chemin pour aller chercher cervin_reduced.dat
        filePath = ui->lineEdit->text().toUtf8().constData(); //traduit le fichier cervin_reduced.dat en string nommee filePath
        Montagne_pointu *pointue = new Montagne_pointu(filePath); //construit la montagne pointue a partir de la string filePath
        chaine.push_back(pointue); //ajoute la montagne pointue a la liste des montagnes a dessiner
    }


    //construit une instance de parameters avec les valeurs rentrees par l' utilisateur dans la fenetre des parametres
    Parameters *params = new Parameters(ui->nxSpinBox->value(),
                                        ui->nySpinBox->value(),
                                        ui->nzSpinBox->value(),
                                        ui->lambdaNumSpinBox->value()/ui->lambdaDenSpinBox->value(),
                                        ui->ventSpinBox->value(),
                                        ui->deltaSpinBox->value(),
                                        ui->deltaPrimeSpinBox->value(),
                                        chaine);

    //va permettre de dessiner les objets dans la MainWindoW main
    main->displayMountains(params);
    close();
}

//rajoute ou enleve une montagne a chaque appui sur le curseur du nombre de montagnes dans la fenetre de demande de parametres
void Parameters_Dialog::add_or_remove_mountain(int nb_tabs)
{
    if(ui->tabWidget->count() >  nb_tabs) {
        //enleve la derniere montagne dans la fenetre de demande de parametres
        ui->tabWidget->removeTab(ui->tabWidget->count()-1);
        tabs.pop_back();
    }
    else if (ui->tabWidget->count() <  nb_tabs) {
  //rajoute une montagne dans la fenetre de demande de parametres
        Mountain_Tab* newTab = new Mountain_Tab();
        std::string tabName = "Montagne" + std::to_string(nb_tabs);
        tabs.push_back(newTab);
        ui->tabWidget->addTab(newTab, tabName.c_str());
    }
}

//grace a cette methode si on coche la case pour la montagne pointue, cela autorise l' utilisateur a ecrire dans la case lineEdit
//et a utiliser le browse_button pour ecrire le chemin pour acceder au fichier cervin_reduced.dat
void Parameters_Dialog::montagne_pointu_button(bool button) {
    if (button)
    {
        ui->lineEdit->setEnabled(button);
        ui->browse_button->setEnabled(button);
    }
}

//permet en appuyant sur " browse" d' aller chercher le fichier dans les fichiers de l' utilisateur
//et de remplir lineEdit avec le chemin du fichier
void Parameters_Dialog::browse_files()
{
    QString path = QFileDialog::getOpenFileName(this);
    ui->lineEdit->setText(path);
}

//lorsque nx est modifie, ny et nz le sont aussi (cependant lorsque ny ou nz sont modifies,
//cela ne modifie pas les autres variables afin de laisser la liberte a l' utilisateur quant a la taille de la boite)
void Parameters_Dialog::correction_carre() {
    while(ui->nySpinBox->value() < ui->nxSpinBox->value()) {
        ui->nySpinBox += 1;
    }
    while(ui->nySpinBox->value() > ui->nxSpinBox->value()) {
        ui->nySpinBox -= 1;
    }
    while(ui->nzSpinBox->value() < ui->nxSpinBox->value()) {
        ui->nzSpinBox += 1;
    }
    while(ui->nzSpinBox->value() > ui->nxSpinBox->value()) {
        ui->nzSpinBox -= 1;
    }
}

