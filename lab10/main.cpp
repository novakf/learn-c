#include <iostream>
#include <iomanip>
#include "algo.h"
using namespace std;

int main()
{
    int n;
    cout << "Finding the inverse matrix." << endl;
    cout << "Enter the matrix's size: ";

    cin >> n;

    //исходная матрица
    double **matr_start = new double *[n];
    for (int i = 0; i < n; i++)
        matr_start[i] = new double[n];

    cout << "Enter the matrix's elements: " << endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matr_start[i][j];

    cout << "Your recent matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matr_start[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    //обратная матрица
    if (reverse(matr_start, n) != 0)
    {
        double **matr_rev = reverse(matr_start, n);

        cout << "Inverse matrix: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << setw(8) << fixed << setprecision(3) << matr_rev[i][j] << " ";
            cout << endl;
        }

        multiple(matr_start, matr_rev, n);
    }
    else
        cout << "Inverse matrix don't resist!" << endl;

    //СЛАУ
    cout << endl
         << "The system of equations." << endl;

    slau();

    return 0;
}