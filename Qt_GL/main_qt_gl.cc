#include <QApplication>
#include "glwidget.h"
#include "Systeme.h"
#include "mainwindow.h"
#include "parameters_dialog.h"
#include <QVector>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  MainWindow mainWindow;
    return a.exec();
}
