#include <array>
#include <iostream>
#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Systeme.h"
#include <QDebug>
#include <QVector>


using namespace std;
// ======================================================================
void VueOpenGL::dessine(Systeme const& a_dessiner)
{
  double offsetx = 10.0;
double offsety = -25.0;
double offsetz = -20.0;

QMatrix4x4 matrice;

  for(int i(0); i < a_dessiner.getN()[0]; ++i) {
    for(int j(0); j < a_dessiner.getN()[1]; ++j) {

      //on dessine d abord la pluie
        if(a_dessiner.flaque_deau(i,j)) {
            matrice.setToIdentity();
             matrice.rotate(15.0, -30.0, 45.0, 80.0);
            matrice.translate(offsetx+i, offsetz+a_dessiner.getAltitude(i,j), offsety+j);
            dessineCube(matrice, color_pluie);

        } else {

     //on dessine ensuite le sol cest a dire le point ou l altitude est zero

       if(a_dessiner.getAltitude(i,j) == 0.0) {
            matrice.setToIdentity();
             matrice.rotate(15.0, -30.0, 45.0, 80.0);
            matrice.translate(offsetx +i, offsetz+a_dessiner.getAltitude(i,j),offsety+j);
            dessineCube(matrice, color_floor);
        }

       //on dessine la montagne (neige en dessus de 10)

        matrice.setToIdentity();
         matrice.rotate(15.0, -30.0, 45.0, 80.0);
        matrice.translate(offsetx +i, offsetz+a_dessiner.getAltitude(i,j),offsety+j);
        if(a_dessiner.getAltitude(i,j) > 10) {
        dessineCube(matrice, color_snow);
        } else {
        dessineCube(matrice, color_montagne);}
    }

  }

    //on dessine finalement les nuages

 for(int i(0); i < a_dessiner.getN()[0]; ++i) {
      for(int j(0); j <  a_dessiner.getN()[1]; ++j) {


          for(int k(0); k < a_dessiner.getN()[1]; ++k) {

            if(a_dessiner.nuage(i,j,k)) {

                   matrice.setToIdentity();
                    matrice.rotate(15.0, -30.0, 45.0, 80.0);
                   matrice.translate(offsetx+i, offsetz+k, offsety+j);
                   dessineCube(matrice, color_nuage);

              }

          }

      }
 }

}
}



void VueOpenGL::dessine(const Ciel &a_dessiner) {

}

void VueOpenGL::dessine(const Montagne &a_dessiner) {

}

void VueOpenGL::dessine(const ChaineDeMontagnes &a_dessiner) {

}

void VueOpenGL::dessine(const Montagne_pointu &a_dessiner) {

}



// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   *
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   *
   * Le Back-face culling consiste à ne dessiner que les face avec ordre
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -4.0);
  matrice_vue.rotate(60.0, 0.0, 1.0, 0.0);
  matrice_vue.rotate(45.0, 0.0, 0.0, 1.0);
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue, array<array<double,3>,6> color)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  //prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(CouleurId, color[0][0], color[0][1],color[0][2]);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);

  // face coté X = -1
  //prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(CouleurId, color[1][0], color[1][1],color[1][2]);
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  //prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(CouleurId, color[2][0], color[2][1],color[2][2]);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  //prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(CouleurId, color[3][0], color[3][1],color[3][2]);
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  //prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(CouleurId, color[4][0], color[4][1],color[4][2]);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  //prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(CouleurId, color[5][0], color[5][1],color[5][2]);
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);

  glEnd();
}
