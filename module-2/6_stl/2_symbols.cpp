#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    int n=0;
    for (int i=0; i<line.size();i++){
        if (line[i]=='a') {
            n++;
        }
        if (n==1 and line[i]!='a') cout <<line[i];
    }
    return 0;
}