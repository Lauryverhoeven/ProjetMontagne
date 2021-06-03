//
// Created by Ömer Doruk Süder on 6.05.2021.
//

#ifndef PROGICC_MONTAGNEABSTRAITE_H
#define PROGICC_MONTAGNEABSTRAITE_H


class MontagneAbstraite {
public:
    virtual double altitude(double ,double ) const=0; //methode virtuelle pure surchargée dans les sous classes de MontagneAbstraite
   // virtual double altitude2() const=0;
    virtual ~MontagneAbstraite(){}
};


#endif //PROGICC_MONTAGNEABSTRAITE_H
