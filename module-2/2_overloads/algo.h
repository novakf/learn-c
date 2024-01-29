#pragma once
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

class Fraction {
 private:
  int sign;
  int intPart;
  int numerator;
  int denominator;

  void GetMixedView();  // создание смешанного вида
  void Cancellation();  // сокращение дроби
  void GetIntPart();    // получение целой части

 public:
  Fraction();
  Fraction(int, int, int = 0, int = 1);
  ~Fraction();
  Fraction operator+(Fraction);
  Fraction operator+(double);
  Fraction operator+(int);
  friend Fraction &operator+=(Fraction &, Fraction &);
  friend Fraction &operator+=(Fraction &, double);
  friend Fraction &operator+=(Fraction &, int);
  operator double();
  friend istream &operator>>(istream &, Fraction &);
  friend ostream &operator<<(ostream &, Fraction &);
  Fraction &operator=(const char buf[7]);
  Fraction &operator=(double d);
};