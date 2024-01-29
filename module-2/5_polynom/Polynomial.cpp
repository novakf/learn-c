#include "Polynomial.h"
#include "Term.h"
#include <iostream>
using namespace std;

int MAX = 6;
int q = 1;
int Polynomial::total = 0;

ostream &operator<<(ostream &out, Polynomial &p)
{
    int n;
    Term t(0);
    if (q == 1)
    {
        if (p.degree == 0 and p.poly[0] == t) // polynom 0
            out << p.poly[p.degree];

        for (int i = 0; i < MAX; i++)
            if (p.poly[i] != t)
            {
                n = i;
                break;
            }

        for (int i = 0; i < p.degree + 1; i++)
        {
            if (p.poly[i] != t)
            {
                if (p.poly[i].Coeff() > 0 and i != n)
                    out << "+";
                out << p.poly[i];
            }
        }
    }

    /* if (q == -1)
     {
         if (p.degree == 0 and p.poly[MAX-1] == t) // polynom 0
             out << p.poly[p.degree];

         for (int i = 0; i < MAX; i++)
             if (p.poly[i] != t)
             {
                 n = i;
                 break;
             }

         for (int i = 0; i < p.degree + 1; i++)
         {
             if (p.poly[i] != t)
             {
                 if (p.poly[i].Coeff() > 0 )
                     out << "+";
                 out << p.poly[i];
             }
         }
     }*/

    //           for (int i = 0; i < 6; i++)
    //       {
    //       out << p.poly[i] << " ";
    //}
    return out;
}

Polynomial::Polynomial()
{
    poly = new Term[MAX];
    for (int i = 0; i < MAX; i++)
        poly[i] = 0;
    degree = 0;
    total++;
    id = total;
 //   cout << "Create ID " << id << endl;
}

Polynomial::~Polynomial()
{
    if (poly != nullptr)
    {
        delete[] this->poly;
    }
   // cout << "Delete ID" << id << endl;
    total--;
}

Polynomial::Polynomial(int num)
{
    poly = new Term[MAX];
    for (int i = 0; i < MAX; i++)
        poly[i] = 0;
    Term t(num);
    poly[0] = t;
    degree = 0;
    total++;
    id = total;
   // cout << "Create ID " << id << endl;
}

Polynomial::Polynomial(Term t)
{
    poly = new Term[MAX];
    for (int i = 0; i < MAX; i++)
        poly[i] = 0;
    degree = t.degree;
    poly[degree] = t;
    total++;
    id = total;
  //  cout << "Create ID " << id << endl;
}

Polynomial::Polynomial(const Polynomial &copy)
{
    poly = new Term[MAX];
    for (int i = 0; i < MAX; i++)
        poly[i] = 0;
    degree = copy.degree;
    for (int i = 0; i < degree + 1; i++)
        poly[i] = *(copy.poly + i);
    total++;
    id = total;
   // cout << "Create ID " << id << endl;
}

Polynomial &Polynomial::operator=(Polynomial s)
{
    for (int i = 0; i < MAX; i++)
    {
        (*this).poly[i] = s.poly[i];
    }
    (*this).degree = s.degree;
    // (*this).order(q);
    return (*this);
}

Polynomial operator+(Polynomial &s1, Polynomial &s2)
{
    Term t;
    Polynomial res;
    for (int i = 0; i < MAX; i++)
    {
        if (s1.poly[i].Degree() == s2.poly[i].Degree())
            res.poly[i] = s1.poly[i] + s2.poly[i];
        else
        {
            if (s1.poly[i] != t)
                res.poly[i] = s1.poly[i];
            else
                res.poly[i] = s2.poly[i];
        }
    }
    if (s1.degree > s2.degree)
        res.degree = s1.degree;
    else
        res.degree = s2.degree;
    //   res.order(q);
    return res;
}

Polynomial operator*(Polynomial &s1, Polynomial &s2)
{
    Polynomial mult;
    Polynomial res;
    Term t;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            t = s1.poly[i] * s2.poly[j];
            Polynomial mult(t);
            res = res + mult;
            // cout << mult << "dd " << res << "dd" << endl;
        }
    }

    res.degree = s1.degree * s2.degree;
    //  res.order(q);
    return res;
}

Polynomial &Polynomial::operator+=(Polynomial &s)
{
    (*this) = (*this) + s;
    (*this).order(q);
    return (*this);
}

Polynomial &Polynomial::operator*=(Polynomial &s)
{
    (*this) = (*this) * s;
    (*this).order(q);
    return (*this);
}

void Polynomial::order(int q)
{
    if (q == 1)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = i + 1; j < MAX; j++)
            {
                if (poly[i].degree < poly[j].degree)
                {
                    Term t = *(poly + i);
                    *(poly + i) = *(poly + j);
                    *(poly + j) = t;
                }
            }
        }
        /*int j=0;
        for (int i=MAX-1; i>=0;i--) {
            poly[j]=poly[i];
            j++;
        }*/
    }

    if (q == -1)
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = i + 1; j < MAX; j++)
            {
                if (poly[i].degree > poly[j].degree)
                {
                    Term t = *(poly + i);
                    *(poly + i) = *(poly + j);
                    *(poly + j) = t;
                }
            }
        }
    }
}