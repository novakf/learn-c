#pragma once
#include <iostream>
#include "Term.h"
using namespace std;

const int size = 6;

class Term;

class Polynomial
{
public:
    Polynomial();
    Polynomial(int num);
    Polynomial(Term);
    ~Polynomial();

    friend ostream &operator<<(ostream &out, Polynomial &p);

    Polynomial(const Polynomial &copy);

    Polynomial &operator=(Polynomial p);
    Polynomial &operator+=(Polynomial &p);
    Polynomial &operator*=(Polynomial &p);

    friend Polynomial operator+(Polynomial &p1, Polynomial &p2);
    friend Polynomial operator*(Polynomial &p1, Polynomial &p2);

protected:
    Term *poly;
    int degree;
    void order(int q);

private:
    static int total;
    int id;
};