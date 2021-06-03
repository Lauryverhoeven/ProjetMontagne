#pragma once

#include <QOpenGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "Systeme.h"
#include <QVector>
#include <vector>


class GLWidget : public QOpenGLWidget
/* La fenêtre hérite de QOpenGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
private:
  // Les 3 méthodes clés de la classe QOpenGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event)  override;

  // Méthodes de gestion interne
  void pause();

  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  // objets à dessiner, faire évoluer
  Systeme systeme;
public:
  GLWidget(QWidget* parent = nullptr, unsigned int Nx = 1, unsigned int Ny = 1, unsigned int Nz = 1, double lambda = 0.0, double ventinfini = 0.0, double delta = 0.0, double deltaprime = 0.0, std:: vector<MontagneAbstraite*> montagne={new Montagne(0,0,0,0,0,0.0)})
    : QOpenGLWidget(parent), systeme(Nx,   Ny,   Nz,  lambda,  ventinfini,delta, deltaprime,montagne)
  {
  }

  virtual ~GLWidget() = default;

  QSize sizeHint();
  //Systeme getc() const {return c;}
  void initialise_systeme(unsigned int Nx , unsigned int Ny, unsigned int Nz, double lambda, double ventinfini, double delta, double deltaprime, std:: vector<MontagneAbstraite*> montagne);


};
