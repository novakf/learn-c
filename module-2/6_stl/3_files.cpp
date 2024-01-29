#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string line;
    ifstream fin("fin.txt");
    ofstream fout("fout.txt");
    getline(fin, line);

    for (int i=0; i<line.size(); i++) {
        if (line[i]=='.') {
            fout << "...";
        }
        else fout << line[i];
    }

    fin.close();
    fout.close();

    return 0;
}