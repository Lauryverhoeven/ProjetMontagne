#include <QKeyEvent>
#include <QTimerEvent>
#include <QMatrix4x4>
#include "glwidget.h"
#include <QVector>
#include <vector>



// ======================================================================
void GLWidget::initializeGL()
{
  vue.init();
  timerId = startTimer(1000);

 vue.rotate(15.0, -3.0, 0.0, 0.0);
 vue.rotate(35.0, 0.0, +7.0, 0.0);
 vue.translate( 25.0, 0.0, 0.0);
 vue.rotate(35.0, 0.0, +7.0, 0.0);
 vue.translate( 25.0, 0.0, 0.0);
 vue.rotate(35.0, 0.0, 0.0, +7.0);
 vue.rotate(20.0, -4.0, 0.0, 0.0);
 vue.rotate(35.0, 0.0, +7.0, 0.0);
 vue.translate( 15.0, 0.0, 0.0);
 vue.rotate(30.0, 0.0, +7.0, 0.0);
 vue.translate( 15.0, 0.0, 0.0);
 vue.translate( 0.0, 0.0, -7.0);
 vue.rotate(15.0, 0.0, 0.0, +3.0);
 vue.rotate(15.0, +3.0, 0.0, 0.0);
 vue.translate( 0.0, -4.0, 0.0);
 vue.translate( 0.0, 0.0, -3.0);
 vue.rotate(5.0, -1.0, 0.0, 0.0);


  //key A
  //vue.translate( 250, 0.0, 0.0);
  //key fleche droit
  //vue.rotate(15.0, 0.0, +3.0, 0.0);
  //key E
  //vue.rotate(25.0, 0.0, 0.0, +1.0);
  //key F
  //vue.translate(0.0, 5.0, 0.0);
  //key up
  //vue.rotate(10.0, -2.0, 0.0, 0.0);


  /*
  vue.rotate(30.0, 0.0, -1.0, 0.0);
  vue.rotate(30.0,0.0,1.0,0.0);
  vue.rotate(15.0, -1.0, 0.0, 0.0);
  vue.rotate(15.0, 0.0, 0.0,  -1.0);
  vue.rotate(15.0, +1.0, 0.0, 0.0);
  vue.rotate(15.0, -1.0, 0.0, 0.0);
  */
}

// ======================================================================
void GLWidget::resizeGL(int width, int height)
{
  /* On commance par dire sur quelle partie de la 
   * fenêtre OpenGL doit dessiner.
   * Ici on lui demande de dessiner sur toute la fenêtre.
   */
  glViewport(0, 0, width, height);


  /* Puis on modifie la matrice de projection du shader.
   * Pour ce faire on crée une matrice identité (constructeur
   * par défaut), on la multiplie par la droite par une matrice
   * de perspective.
   */
  QMatrix4x4 matrice;
  matrice.perspective(70.0, qreal(width) / qreal(height ? height : 1.0), 1e-3, 1e5);
  vue.setProjection(matrice);
}

// ======================================================================
void GLWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(1.0,1.0,1.0,1.0);
  systeme.dessine_sur(vue);
}


// ======================================================================
void GLWidget::keyPressEvent(QKeyEvent* event)
{
  constexpr double petit_angle(5.0); // en degrés
  constexpr double petit_pas(1.0);

  switch (event->key()) {

  case Qt::Key_Left:
    vue.rotate(petit_angle, 0.0, -1.0, 0.0);
    break;

  case Qt::Key_Right:
    vue.rotate(petit_angle, 0.0, +1.0, 0.0);
    break;

  case Qt::Key_Up:
    vue.rotate(petit_angle, -1.0, 0.0, 0.0);
    break;

  case Qt::Key_Down:
    vue.rotate(petit_angle, +1.0, 0.0, 0.0);
    break;

  case Qt::Key_PageUp:
  case Qt::Key_W:
    vue.translate(0.0, 0.0,  petit_pas);
    break;

  case Qt::Key_PageDown:
  case Qt::Key_S:
    vue.translate(0.0, 0.0, -petit_pas);
    break;

  case Qt::Key_A:
    vue.translate( petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_D:
    vue.translate(-petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_R:
    vue.translate(0.0, -petit_pas, 0.0);
    break;

  case Qt::Key_F:
    vue.translate(0.0,  petit_pas, 0.0);
    break;

  case Qt::Key_Q:
    vue.rotate(petit_angle, 0.0, 0.0, -1.0);
    break;

  case Qt::Key_E:
    vue.rotate(petit_angle, 0.0, 0.0, +1.0);
    break;

  case Qt::Key_Home:
    vue.initializePosition();
    break;

  case Qt::Key_Space:
	pause();
	break;
  };

  update(); // redessine
}

// ======================================================================
void GLWidget::timerEvent(QTimerEvent* event)
{
  Q_UNUSED(event);

  double dt = chronometre.restart() / 6000.0;

  systeme.evolue(dt);
  update();
}

// ======================================================================
void GLWidget::pause()
{
  if (timerId == 0) {
	// dans ce cas le timer ne tourne pas alors on le lance
    timerId = startTimer(1000);
	chronometre.restart();
  } else {
	// le timer tourne alors on l'arrête
	killTimer(timerId);
	timerId = 0;
  }
}

QSize GLWidget::sizeHint()
{
  return QSize(rect().width()+1, rect().height() );
}

void GLWidget::initialise_systeme(unsigned int Nx, unsigned int Ny, unsigned int Nz, double lambda, double ventinfini, double delta, double deltaprime, std::vector<MontagneAbstraite *> montagne)
{
    systeme.demarre(Nx,Ny,Nz,lambda,ventinfini,delta,deltaprime, montagne);
}
