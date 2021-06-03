#pragma once

#include <QOpenGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "support_a_dessin.h"
#include <QVector>
#include <vector>


class VueOpenGL : public SupportADessin {
 public:
  // méthode(s) de dessin (héritée(s) de SupportADessin)
    virtual void dessine(Montagne const& a_dessiner) override;
    virtual void dessine(Ciel const& a_dessiner) override;
    virtual void dessine(Systeme const& a_dessiner) override;
    virtual void dessine(ChaineDeMontagnes const& a_dessiner) override;
    virtual void dessine(Montagne_pointu const& a_dessiner) override;

  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() ,std::array<std::array<double, 3>, 6> color = {{{1.0,0.0,0.0},
  {0.0,1.0,0.0},
  {0.0,0.0,1.0},
  {0.0,1.0,1.0},
  {1.0,1.0,0.0},
  {1.0,0.0,1.0}}});

 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QOpenGLShaderProgram prog;

  // Caméra
  QMatrix4x4 matrice_vue;

 const std::array<std::array<double, 3>, 6> color_montagne = {{{0.5,0.35,0.05},
                                                               {0.5,0.5,0.03},
                                                               {0.5,0.3,0.05},
                                                               {0.4,0.4,0.04},
                                                               {0.5,0.6,0.1},
                                                               {0.3,0.35,0.05}}};

  const std::array<std::array<double, 3>, 6> color_floor = {{{0.0,0.5,0.0},
                                                             {0.0,0.5,0.0},
                                                             {0.0,0.5,0.0},
                                                             {0.0,0.5,0.0},
                                                             {0.0,0.5,0.0},
                                                             {0.0,0.5,0.0}}};



  const std::array<std::array<double, 3>, 6> color_nuage = {{{0.5,0.5,0.5},
                                                               {0.75,0.75,0.75},
                                                               {0.25,0.25,0.25},
                                                               {0.6,0.6,0.6},
                                                               {0.5,0.5,0.5},
                                                               {0.5,0.5,0.5}}};

  const std::array<std::array<double, 3>, 6> color_origin = {{{1.0,0.0,0.0},
                                                              {1.0,0.0,0.0},
                                                              {1.0,0.0,0.0},
                                                              {1.0,0.0,0.0},
                                                              {1.0,0.0,0.0},
                                                              {1.0,0.0,0.0}}};

  const std::array<std::array<double, 3>, 6> color_snow = {{{0.9,0.9,0.9},
                                                              {0.9,0.9,0.9},
                                                              {0.9,0.9,0.9},
                                                              {0.9,0.9,0.9},
                                                              {0.9,0.9,0.9},
                                                              {0.9,0.9,0.9}}};

  const std::array<std::array<double, 3>, 6> color_pluie = {{{0.0, 0.0, 1.0},
                                                              {0.0, 0.0, 1.0},
                                                              {0.0, 0.0, 1.0},
                                                              {0.0, 0.0, 1.0},
                                                              {0.0, 0.0, 1.0},
                                                              {0.0, 0.0, 1.0}}};
};

