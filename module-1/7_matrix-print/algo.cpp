#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

double factorial(int x) {
  int f = 1;
  for (int k = 1; k < (x + 1); k++) f *= k;
  return (double)f;
}

void fill_matr(double **arr, int n, int x) {
  int m, k;
  double f;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (i == j) {
        arr[i][j] = 1;
        m = i;
        k = j;
      }

    for (int j = k + 1; j < n; j++) {
      f = factorial(j);
      arr[i][j] = pow(x, i) / pow(f, i);
    }
    for (int j = 0; j < k; j++) {
      f = factorial(j);
      arr[i][j] = pow(-x, i) / pow(f, i);
    }
  }
}

void output(double **arr, int n) {
  int k, t = 0;
  do {
    k = t;
    t += 19;
    for (int i = 0; i < n; i++) {
      for (int j = k; (j < t) && (j < n); j++)
        cout << setprecision() << fixed << setw(8) << arr[i][j];
      cout << endl;
    }
    cout << endl << endl;

  } while (t < n);
}
