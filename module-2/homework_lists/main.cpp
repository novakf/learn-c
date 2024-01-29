#include <iostream>

#include "algo.h"
using namespace std;
int main() {
  list<Flat> FlatList;
  list<Flat2> FlatList2;
  Flat Flat;
  Flat2 Flat2;
  int num = 0;
  get_data_from_file(FlatList, FlatList2, num);
  while (true) {
    switch (menu()) {
      case 1:
        FlatList.push_back(Flat.DataInput(FlatList, num));
        FlatList2.push_back(Flat2.DataInput2(FlatList2, num));
        break;
      case 2:
        find(FlatList, FlatList2, num);
        break;
      case 3:
        print_flats(FlatList, FlatList2);
        break;
      case 4:
        cout << num;
        return 0;
    }
    cout << endl;
  }
  return 0;
