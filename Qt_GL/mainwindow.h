#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glwidget.h"
#include "parameters.h"

class MainWindow
{
    //Q_OBJECT
public:
    explicit MainWindow();
    void displayMountains(Parameters *params);

signals:

private:
    GLWidget myWidget;

};

#endif // MAINWINDOW_H
