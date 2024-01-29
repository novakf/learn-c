#include <iostream>
#include <vector>
#include <string>
#include "algo.h"
using namespace std;

void print_vector(vector v)
{
    cout << "Ваш вектор." << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << i + 1 << ". " << v[i] << endl;
    }
}