#include "polynomials.h"

Polynomial::Polynomial(int polynomial_level, const double *polynomial_values) {
    degree = polynomial_level;
    values = new double[polynomial_level];
    if (polynomial_values != nullptr) {
        for(int i = 0; i < polynomial_level; i++) {
            values[i] = polynomial_values[i];
        }
    } else {
        for(int i = 0; i < polynomial_level; i++) {
            values[i] = 0;
        }
    }
}


Polynomial::~Polynomial() {
    delete values;
}
Polynomial Polynomial::operator+(Polynomial const& b) {
    Polynomial r;
    r.degree = this->degree > b.degree ? this->degree : b.degree;
    r.values = new double[r.degree];
    for(int i = 0; i < r.degree; i++) {
        r.values[i] = 0;
        if(i < this->degree) {
            r.values[i] += this->values[i];
        }
        if(i < b.degree) {
            r.values[i] += b.values[i];
        }
    }
    return r;
}
Polynomial Polynomial::operator-(Polynomial const& b) {
    Polynomial r;
    r.degree = this->degree > b.degree ? this->degree : b.degree;
    r.values = new double[r.degree];
    for(int i = 0; i < r.degree; i++) {
        r.values[i] = 0;
        if(i < this->degree) {
            r.values[i] += this->values[i];
        }
        if(i < b.degree) {
            r.values[i] -= b.values[i];
        }
    }
    return r;
}

Polynomial Polynomial::operator*(Polynomial const& b) {
    Polynomial r;
    r.degree = this->degree + b.degree - 1;
    r.values = new double[r.degree];
    for(int i = 0; i < this->degree; i++) {
        for(int j = 0; j < b.degree; j++) {
            r.values[i+j] += this->values[i] * b.values[j];
        }
    }
    return r;
}


int Polynomial::getDegree() const {
    return degree;
}

double Polynomial::getValue(int n) {
    return values[n];
}

void Polynomial::setValue(int n, double x) {
    this->values[n] = x;
}

