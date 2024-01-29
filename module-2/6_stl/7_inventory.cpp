#include <iostream>
#include <iterator>
#include <map>
using namespace std;
int main() {
  map<string, int> inv;
  map<string, int>::iterator it;
  inv["Отверка"] = 0;
  inv["Молоток"] = 10;
  inv["Гайки"] = 100;
  inv["Профиль"] = 0;
  inv["Уголок"] = 9;
  inv["Доска"] = 17;
  for (it = inv.begin(); it != inv.end(); it++) {
    if (it->second != 0) cout << it->first << " - " << it->second << endl;
  }
  return 0;
}