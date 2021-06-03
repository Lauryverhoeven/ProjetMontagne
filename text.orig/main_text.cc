#include <iostream>
#include "text_viewer.h"
#include "contenu.h"
using namespace std;

int main()
{
  TextViewer ecran(cout);
  Contenu c;

  cout << "Au départ :" << endl;
  c.dessine_sur(ecran);

  c.evolue(0.1);
  cout << "Après un pas de calcul :" << endl;
  c.dessine_sur(ecran);

  c.evolue(0.1);
  cout << "Après deux pas de calcul :" << endl;
  c.dessine_sur(ecran);

  return 0;
}
