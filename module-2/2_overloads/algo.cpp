#include "algo.h"

#include <string.h>

#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

Fraction::Fraction(int n, int d, int i, int s)  // конструктор
{
  intPart = i;
  numerator = n;
  denominator = d;
  sign = s;
  GetMixedView();
}

Fraction::Fraction()  // конструктор по нулевому параметру
{
  intPart = 0;
  numerator = 0;
  denominator = 1;
  sign = 1;
}

void Fraction::GetMixedView()  // создание смешанного вида
{
  GetIntPart();
  Cancellation();
}

void Fraction::GetIntPart()  // получает целую чать
{
  if (numerator >= denominator) {
    intPart += (numerator / denominator);
    numerator %= denominator;
  }
}

void Fraction::Cancellation()  // сокращение дроби
{
  if (numerator != 0) {
    int m = denominator, n = numerator, ost = m % n;

    while (ost != 0) {
      m = n;
      n = ost;
      ost = m % n;
    }
    int nod = n;
    if (nod != 1) {
      numerator /= nod;
      denominator /= nod;
    }
  }
}

Fraction::~Fraction()  // деконструктор
{
  // cout << " >> Дробь " << (*this)
  //      << " уничтожена." << endl;
}

Fraction::operator double() {
  double res = (double)sign * (intPart * denominator + numerator) / denominator;
  return res;
}

Fraction Fraction::operator+(Fraction a) {
  Fraction res;
  res.numerator =
      sign * (intPart * denominator + numerator) * a.denominator +
      a.sign * (a.intPart * a.denominator + a.numerator) * denominator;
  res.denominator = denominator * a.denominator;
  if (res.numerator < 0) {
    res.numerator *= -1;
    res.sign = -1;
  }
  res.GetMixedView();
  return res;
}

Fraction &operator+=(Fraction &left, Fraction &right) {
  left.numerator =
      left.sign * (left.intPart * left.denominator + left.numerator) *
          right.denominator +
      right.sign * (right.intPart * right.denominator + right.numerator) *
          left.denominator;

  left.denominator = left.denominator * right.denominator;
  if (left.numerator < 0) {
    left.numerator *= -1;
    left.sign = -1;
  }
  left.intPart = 0;
  left.GetMixedView();
  return left;
}

Fraction &operator+=(Fraction &left, double d) {
  Fraction a;
  if (d < 0)
    a.sign = -1;
  else
    a.sign = 1;
  d = abs(d);
  a.intPart = (int)d;
  int q = (int)d;
  d -= q;
  double i;
  int n = 0;
  while (modf(d, &i) != 0) {
    d *= 10;
    n++;
  }
  int den = pow(10, n);
  a.numerator = d;
  a.denominator = den;
  a.GetMixedView();
  left.numerator =
      left.sign * (left.intPart * left.denominator + left.numerator) *
          a.denominator +
      a.sign * (a.intPart * a.denominator + a.numerator) * left.denominator;

  left.denominator = left.denominator * a.denominator;
  if (left.numerator < 0) {
    left.numerator *= -1;
    left.sign = -1;
  }
  left.intPart = 0;
  left.GetMixedView();
  return left;
}

Fraction &operator+=(Fraction &left, int d) {
  Fraction a;
  if (d < 0)
    a.sign = -1;
  else
    a.sign = 1;
  a.intPart = abs(d);
  a.numerator = 0;
  a.denominator = 1;
  a.GetMixedView();

  left.numerator =
      left.sign * (left.intPart * left.denominator + left.numerator) *
          a.denominator +
      a.sign * (a.intPart * a.denominator + a.numerator) * left.denominator;

  left.denominator = left.denominator * a.denominator;
  if (left.numerator < 0) {
    left.numerator *= -1;
    left.sign = -1;
  } else
    left.sign = 1;
  left.intPart = 0;
  left.GetMixedView();

  return left;
}

Fraction Fraction::operator+(double d) {
  Fraction res;
  Fraction a;
  if (d < 0)
    a.sign = -1;
  else
    a.sign = 1;
  d = abs(d);
  a.intPart = (int)d;
  int q = (int)d;
  d -= q;
  double i;
  int n = 0;
  while (modf(d, &i) != 0) {
    d *= 10;
    n++;
  }
  int den = pow(10, n);
  a.numerator = d;
  a.denominator = den;
  a.GetMixedView();
  res = (*this) + a;
  return res;
}

Fraction Fraction::operator+(int a) {
  Fraction res;
  Fraction b(0, 1, abs(a), a / abs(a));
  res = (*this) + b;
  return res;
}

ostream &operator<<(ostream &out, Fraction &a) {
  if (a.sign < 0) out << "-";
  if (a.intPart != 0) out << a.intPart << " ";
  if (a.numerator != 0) out << a.numerator << "/" << a.denominator;
  if (a.intPart == 0 && a.numerator == 0) out << "0";
  if (typeid(ofstream) == typeid(out))
    out << "\t";
  else
    out << " ";
  return out;
}

istream &operator>>(istream &fin, Fraction &a) {
  char buf[30];

  if (typeid(ifstream) == typeid(fin))
    fin.getline(buf, 29, '\t');
  else
    fin.getline(buf, 29);
  char *ps = strchr(buf, '/');
  if (ps == NULL) {
    sscanf(buf, "%d", &a.intPart);
    a.numerator = 0;
    a.denominator = 1;
    if (a.intPart >= 0)
      a.sign = 1;
    else {
      a.sign = -1;
      a.intPart = -a.intPart;
    }
    return fin;
  }
  if (strchr(buf, ' ') == NULL) {
    a.intPart = 0;
    sscanf(buf, "%d/%d", &a.numerator, &a.denominator);
    if (a.numerator >= 0)
      a.sign = 1;
    else {
      a.sign = -1;
      a.numerator = -a.numerator;
    }
    a.GetMixedView();
    return fin;
  }
  sscanf(buf, "%d %d/%d", &a.intPart, &a.numerator, &a.denominator);
  if (a.intPart > 0)
    a.sign = 1;
  else {
    a.sign = -1;
    a.intPart = -a.intPart;
  }
  a.GetMixedView();
  return fin;
}

Fraction &Fraction::operator=(const char buf[7]) {
  Fraction a;
  const char *ps = strchr(buf, '/');
  if (ps == NULL) {
    sscanf(buf, "%d", &a.intPart);
    a.numerator = 0;
    a.denominator = 1;
    if (a.intPart >= 0)
      a.sign = 1;
    else {
      a.sign = -1;
      a.intPart = -a.intPart;
    }
    sign = a.sign;
    intPart = a.intPart;
    numerator = a.numerator;
    denominator = a.denominator;

    return *this;
  }
  if (strchr(buf, ' ') == NULL) {
    a.intPart = 0;
    sscanf(buf, "%d/%d", &a.numerator, &a.denominator);
    if (a.numerator > 0)
      a.sign = 1;
    else {
      a.sign = -1;
      a.numerator = -a.numerator;
    }
    a.GetMixedView();
    sign = a.sign;
    intPart = a.intPart;
    numerator = a.numerator;
    denominator = a.denominator;
    GetMixedView();
    return *this;
  }
  sscanf(buf, "%d %d/%d", &a.intPart, &a.numerator, &a.denominator);
  if (a.intPart > 0)
    a.sign = 1;
  else {
    a.sign = -1;
    a.intPart = -a.intPart;
  }
  a.GetMixedView();
  sign = a.sign;
  intPart = a.intPart;
  numerator = a.numerator;
  denominator = a.denominator;
  GetMixedView();
  return *this;
}

Fraction &Fraction::operator=(double d) {
  Fraction a;
  if (d < 0)
    a.sign = -1;
  else
    a.sign = 1;
  d = abs(d);
  a.intPart = (int)d;
  int q = (int)d;
  d -= q;
  double i;
  int n = 0;
  while (modf(d, &i) != 0) {
    d *= 10;
    n++;
  }
  int den = pow(10, n);
  a.numerator = d;
  a.denominator = den;
  a.GetMixedView();
  sign = a.sign;
  intPart = a.intPart;
  numerator = a.numerator;
  denominator = a.denominator;
  GetMixedView();
  return *this;
}
