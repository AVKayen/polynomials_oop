#include <iostream>
#include "polynomials.h"

using namespace std;

int main() {
    double values1[3] = {1.0, 2.0, 3.0};            // 1 + 2x + 3x^2
    double values2[3] = {3.0,  3.5};                    // 3 + 3.5x
    Polynomial poly1(3, values1);
    Polynomial poly2(3, values2);
    Polynomial poly3 = poly1 * poly2;                           // ( 1 + 2x + 3x^2 ) * ( 3 + 3.5x ) = 3 9.5x 16x^2 10.5x^3
    cout << poly3.getDegree() << endl;
    for (int i = 0; i < poly3.getDegree(); ++i) {
        if (i == 0) {
            cout << poly3.getValue(0);
        } else if (i == 1) {
            cout << " + " << poly3.getValue(1) << "x";
        } else {
            cout << " + " << poly3.getValue(i) << "x^" << i << " ";
        }
    }
    cout << endl;

    Polynomial poly4 = poly1 + poly2;
    cout << poly4.getDegree() << endl;
    for (int i = 0; i < poly4.getDegree(); ++i) {
        if (i == 0) {
            cout << poly4.getValue(0);
        } else if (i == 1) {
            cout << " + " << poly4.getValue(1) << "x";
        } else {
            cout << " + " << poly4.getValue(i) << "x^" << i << " ";
        }
    }
    return 0;
}