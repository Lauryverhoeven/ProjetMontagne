#ifndef PARAMETERS_DIALOG_H
#define PARAMETERS_DIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "mountain_tab.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class Parameters_Dialog; }
QT_END_NAMESPACE

class Parameters_Dialog : public QDialog
{
    Q_OBJECT

public:
    Parameters_Dialog(MainWindow *parent = nullptr);
    ~Parameters_Dialog();

private slots:
    void on_pushButton_clicked();
    void add_or_remove_mountain(int nb_tabs);
    void montagne_pointu_button(bool button);
    void browse_files();
    void correction_carre();

private:
    std:: vector<Mountain_Tab*> tabs;
    Ui::Parameters_Dialog *ui;
    MainWindow *main;
};
#endif // PARAMETERS_DIALOG_H
