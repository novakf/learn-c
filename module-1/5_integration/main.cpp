// Численное интегрирование функции.

#include <math.h>

#include <iostream>

#include "algo.h"
using namespace std;

int main() {
  I_print arr[4];
  double a = -0.5;
  double b = 3.0;
  cout << sizeof(I_print);
  cout << "Function integration area: " << a << "<=x<=" << b << endl;
  double eps = 0.1;
  int n = 0;
  TPF f[4] = {f1, f2, f3, f4};
  const char* y_title[4] = {"y=x ", "y=sin(22x)", "y=x^4 ", "y=arctg(x)"};

  double toch[] = {
      (b * b - a * a) / 2.0, (cos(a * 22.0) - cos(b * 22.0)) / 22.0,
      (b * b * b * b * b - a * a * a * a * a) / 5.0,
      b * atan(b) - a * atan(a) - (log(b * b + 1) - log(a * a + 1)) / 2.0};

  for (int i = 0; i < 4; i++) {
    arr[i].name = y_title[i];
    arr[i].I_toch = toch[i];
  }

  cout << "Rectangle method: " << endl;

  for (double eps = 0.1; eps >= 0.000001; eps *= 0.1) {
    cout << "Calculation accuracy: " << eps << endl;
    for (int i = 0; i < 4; i++) {
      arr[i].I_sum = IntRect(f[i], a, b, eps, n);
      arr[i].n = n;
    }
    PrintTabl(arr, 4);
  }

  cout << endl;
  cout << "Trapezoid method: " << endl;

  for (double eps = 0.1; eps >= 0.000001; eps *= 0.1) {
    cout << "Calculation accuracy: " << eps << endl;
    for (int i = 0; i < 4; i++) {
      arr[i].I_sum = IntTrap(f[i], a, b, eps, n);
      arr[i].n = n;
    }
    PrintTabl(arr, 4);
  }

  return 0;
}
