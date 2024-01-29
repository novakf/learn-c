#pragma once
#include <iostream>
#include "Polynomial.h"
using namespace std;

class Term
{
    friend class Polynomial;

public:
    Term();
    Term(int num);
    Term(int num1, int num2);

    friend Term operator+(Term &t1, Term &t2);
    friend Term operator*(Term &t1, Term &t2);
    int Coeff() { return coeff; }
    int Degree() { return degree; }
    friend ostream &operator<<(ostream &out, Term &t);
    friend istream &operator>>(istream &in, Term &t);

    friend bool operator==(Term t1, Term t2);
    friend bool operator!=(Term t1, Term t2);

protected:
    int coeff;
    int degree;
};