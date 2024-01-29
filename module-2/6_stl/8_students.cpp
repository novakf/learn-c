#include <iostream>
#include <iterator>
#include <map>
using namespace std;
void print(map<string, int> m) {
  map<string, int>::iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second != 0) cout << it->first << " - " << it->second << endl;
  }
}
int main() {
  map<string, int> m = {
      {"1а", 21}, {"1б", 20}, {"2", 25},  {"3а", 20}, {"3б", 23}, {"4а", 25},
      {"4б", 25}, {"5а", 26}, {"5б", 25}, {"6a", 19}, {"6б", 18}, {"7а", 26},
      {"7б", 25}, {"8", 25},  {"9", 17},  {"10", 15}, {"11", 14}};
  map<string, int>::iterator it;
  int sum = 0;
  for (it = m.begin(); it != m.end(); it++) {
    sum += it->second;
  }
  cout << "Result: " << sum << endl;
  print(m);
  return 0;
}