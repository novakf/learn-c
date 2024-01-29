#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
  double s, x, a1, a2, k;
  int n;
  const double h = 0.2, eps = 0.000001;
  cout << "x=" << setw(19) << " Y(x)=" << setw(15) << "S(x)= " << setw(7)
       << "n=" << endl;
  for (x = 0; x <= 1; x += 0.2) {
    n = 0;
    a1 = x;
    a2 = -100;
    s = a1;
    while (fabs(a2) > eps) {
      k = (-1) * x * x / ((2 * n + 3) * (2 * n + 2));
      a2 = a1 * k;
      s += a2;
      n++;
      a1 = a2;
    }
    cout << fixed << setw(5) << x << setw(15) << sin(x) << setw(15)
         << setprecision(6) << s << setw(5) << n << endl;
  }
  return 0;
}
