#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;

int main() {
  ifstream fin("input");
  ifstream fkey("keys");
  ofstream fout("output");
  /* if (!fin or !fkey or !fout)
      cout << "Error of file opening."<< endl;
  else cout << "All right, buddy! Let's f*cking do this!"<<endl; */

  const int len = 100000;
  char line[len];
  int keys[len];
  const char *delims = ".,!? /<>|)(*::\"";
  char *token;
  int r = 0;
  while (fkey.getline(line, len)) {
    token = strtok(line, delims);
    while (token != NULL) {
      for (int i = 0; i < strlen(token); i++) {
        keys[r] += (int)(token[i]);
      }
      //keys[r] %= 256;
      r++;

      token = strtok(NULL, delims);
    }
  }
  cout << "keys: " << endl;
  for (int i = 0; i < r; i++)
    cout << keys[i] << " ";

  cout << endl;

  char sim;
  int code = (int)sim;
  int j = 0;
  int f;
  cout << "1. Encrypt;" << endl << "2. Decrypt;" << endl;
  cin>> f;
  if (f == 1) {
    while (fin.get(sim)) {
      j %= r;
      code = (int)sim;
      code += keys[j];
      j++;
      fout << (char)code;
    }
  }
  fin.seekg(0);

j=0;

  if (f == 2) {
    while (fin.get(sim)) {
      j %= r;
      code = (int)sim;
      code -= keys[j];
      j++;
      fout << (char)code;
    }
  }

  fin.close();
  fout.close();
  fkey.close();
  return 0;
}
