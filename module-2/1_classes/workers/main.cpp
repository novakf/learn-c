#include <fstream>
#include <iomanip>
#include <iostream>

#include "algo.h"

using namespace std;

int main() {
  const int N = 100;
  Man arr[N];
  char filename[] = "dbase.txt";
  int n;
  if (read_dbase(filename, arr, n)) {
    cout << "Ошибка чтения БД" << endl;
    return 1;
  }

  print_dbase(arr, n);

  while (true) {
    switch (menu()) {
      case 1:
        add(arr, n);
        break;
      case 2:
        remove(arr, n);
        break;
      case 3:
        find_man(arr, n);
        break;
      case 4:
        edit(arr, n);
        break;
      case 5:
        print_dbase(arr, n);
        break;
      case 6:
        write_dbase(filename, arr, n);
        break;
      case 7:
        return 0;
      default:
        cout << " Недопустимый номер операции" << endl;
        break;
    }
  }
  return 0;
}
