#include <iostream>
#include <string>

using namespace std;

int main() {
    string surname, name, mid, total;
    cout << "Enter name: ";
    getline(cin, name);
    cout << endl << "middle name: ";
    getline (cin, mid);
    cout << endl << "surname: ";
    getline (cin, surname);

    total = name[0];
    total +=". ";
    total+=mid[0];
    total+=". ";
    total+=surname[0];
    total+=".";
    cout << endl << total;

    return 0;
}