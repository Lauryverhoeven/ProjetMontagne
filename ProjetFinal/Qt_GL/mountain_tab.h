#ifndef MOUNTAIN_TAB_H
#define MOUNTAIN_TAB_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QLabel>


class Mountain_Tab:public QWidget
{
public:
    Mountain_Tab();
    double get_i_zero();
    double get_j_zero();
    double get_sigma_i();
    double get_sigma_j();
    double get_h();

private:
    QDoubleSpinBox i_zero;
    QDoubleSpinBox j_zero;
    QDoubleSpinBox sigma_i;
    QDoubleSpinBox sigma_j;
    QDoubleSpinBox h;
    QLabel i_zero_label;
    QLabel j_zero_label;
    QLabel h_label;
    QLabel sigma_i_label;
    QLabel sigma_j_label;
};

#endif // MOUNTAIN_TAB_H
