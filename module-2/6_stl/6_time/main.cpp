#include <iostream>
#include <iterator>
#include <list>

#include "algo.h"
using namespace std;
void print(list<Time> v) {
  for (auto iter = v.begin(); iter != v.end(); iter++) {
    cout << *iter << "\n";
  }
}
int main() {
  list<Time> v;
  Time d1(1, 2, 63), d2(14, 57, 19), d3(7, 32, 20), d4(5, 13, 23),
      d5(10, 19, 45), d6(19, 9, 59);
  v.push_back(d1);
  v.push_back(d2);
  v.push_back(d3);
  v.push_back(d4);
  v.push_back(d5);
  v.push_back(d6);
  print(v);
  list<Time> v2;
  while (v.size() != 0) {
    if (v.front().gethour() >= 0 and v.front().gethour() < 5) {
      v2.push_back(v.front());
    }
    v.pop_front();
  }
  cout << endl;
  print(v2);
}