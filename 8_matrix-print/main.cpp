#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "algo.h"
using namespace std;

int main() {
  cout << "Введите кол-во элементов ";
  cout.unsetf(ios::scientific | ios::fixed);

  int n;
  int x = 1;
  cin >> n;

  // Создание массива
  double **arr = new double *[n];
  for (int i = 0; i < n; i++) arr[i] = new double[n];

  fill_matr(arr, n, x);

  output(arr, n);

  // sort(arr, n);

  // cout << "Отсортированный массив\n";
  // output(arr, n);

  for (int i = 0; i < n; i++) {
    delete[] arr[i];
  }
  delete[] arr;

  cout << endl;
  int B[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      B[i][j] = i * 10 + j;
      cout << setw(3) << B[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
  cout << B << "  " << B[0] << "  " << B[2] << endl;
  cout << B[0][0] << "  " << **B << "  " << *B[0] << endl;
  cout << *(*(B + 1)) << "  " << *B[1] << endl;
  cout << *(B[0] + 1) << "  " << *(*B + 1) << endl;
  cout << B[0][20] << "  " << *(B[0] + 20) << "  " << *B[2] << endl;

  return 0;
}
