//
// Created by Laury Verhoeven on 11/3/2021.
//
#include <iostream>
#include "Montagne/Montagne.h"
#include <iomanip>
using namespace std;


int main() {
    Montagne m(15, 15, 18, 5 ,5, 20.0/29.0);
    for(int i(0); i < 30; ++i) {
        for(int j(0); j < 30; ++j) {
            cout << i << " " << j << " " << m.altitude(i, j) << endl;
        }
        cout << endl;
    }
}
