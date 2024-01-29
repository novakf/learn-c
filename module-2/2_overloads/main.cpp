#include <iomanip>
#include <iostream>

#include "algo.h"
using namespace std;
int main() {
  cout << "Введите дробь: \n";
  Fraction z;
  cin >> z;
  cout << "z=" << z << endl << endl;

  cout << "Создание по числам fr1(10,14), fr2(пусто):" << endl;
  Fraction fr1(10, 14), fr2;  // создание по числам
  cout << "fr2=" << fr2 << endl;
  cout << "fr1=" << fr1 << endl << endl;

  cout << "Создание по строке -1 4/8:" << endl;
  Fraction fr;
  fr = "-1 4/8";  // создание по строке
  cout << "fr=" << fr << endl;

  cout << "x(z):" << endl;
  Fraction x(z), y;  // создание
  cout << "x=" << x << endl;

  cout << "Создание по типу double -1.25:" << endl;
  double dbl = -1.25;
  Fraction f;
  f = dbl;  // создание по вещественному
  cout << "f=" << f << endl;

  // проверка перегруженной операции "+"
  cout << "y=x+z:" << endl;
  y = x + z;
  cout << "y=" << y << endl;

  cout << "y+=x:" << endl;
  y += x;
  cout << "y=" << y << endl;

  cout << "f+=dbl/2:" << endl;
  f += dbl / 2;
  cout << "f=" << f << endl;

  cout << "y=x+dbl:" << endl;
  y = x + dbl;
  cout << "y=" << y << endl;

  cout << "y = dbl + y:" << endl;
  y = dbl + y;
  cout << "y=" << y << endl;

  cout << "y += dbl:" << endl;
  y += dbl;
  cout << "y=" << y << endl;

  int i = 5;

  cout << "y+=i:" << endl;
  y += i;
  cout << "y=" << y << endl;

  cout << "y=i+x:" << endl;
  y = i + x;
  cout << "y=" << y << endl;

  cout << "y=x+i:" << endl;
  y = x + i;
  cout << "y=" << y << endl;

  cout << "y += dbl + i + x:" << endl;
  y += dbl + i + x;
  cout << "y=" << y << endl;

  return 0;
}
