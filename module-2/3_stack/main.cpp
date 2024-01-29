#include <iostream>

#include "MyStack.cpp"

using namespace std;

int main() {
  Stack<int> st;

  int i = 0;
  int n;
  cin >> n;

  multipliers(n, st);
  int s = st.size() - 1;

  Stack<int> st2 = st;

  cout << n << "=";
  while (!st.isEmpty()) {
    cout << *st.top();
    if (i != s) cout << "*";
    st.pop();
    i++;
  }

  cout << endl;

  i = 0;

  st2.reverse();

  cout << n << "=";
  while (!st2.isEmpty()) {
    cout << *st2.top();
    if (i != s) cout << "*";
    st2.pop();
    i++;
  }

  cout << endl;

  return 0;
}