#include <iostream>
#include <vector>

#include "algo.h"
using namespace std;
void print(vector<Date> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}
int main() {
  vector<Date> v;
  Date d1(1, 2, 1963), d2(14, 7, 1995), d3(7, 12, 2088), d4(5, 3, 2030),
      d5(24, 9, 2013), d6(19, 9, 2020);
  v.push_back(d1);
  v.push_back(d2);
  v.push_back(d3);
  v.push_back(d4);
  v.push_back(d5);
  v.push_back(d6);
  print(v);
  vector<Date> v2;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].getyear() == 2022 and v[i].getmonth() == 6 and
        v[i].getday() > 10) {
      v2.push_back(v[i]);
    }
    if (v[i].getyear() == 2022 and v[i].getmonth() > 6) {
      v2.push_back(v[i]);
    }
    if (v[i].getyear() > 2022) {
      v2.push_back(v[i]);
    }
  }
  cout << endl;
  print(v2);
}