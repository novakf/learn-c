#include <cmath>
#include <iomanip>
#include <iostream>
#include "algo.h"
using namespace std;

static double f(double x, int k) { return x - k * cos(x); }

void fpd(double eps, int k, int precision, int n) {
    cout << "Half Division" << "(" << n << ")" << ": " << endl;
    double x, a, b;
    int i = 0;

    cout << "Input line [a b]:" << endl;
    cin >> a >> b;

    if (f(a, k) * f(b, k) > 0)
        cout << "Error" << endl;
    else {
        while (fabs(a - b) > eps) {
            x = (a + b) / 2;

            if (f(x, k) * f(a, k) <= 0)
                b = x;
            else
                a = x;

            i += 1;
        }

        cout << setprecision(precision) << "x= " << x << endl;
        cout << "i = " << i << endl;
    }
}

static double df(double x, int k) { return 1 + k * sin(x); }

void fn(double eps, int k, int precision, int n) {
    cout << "Newton" << "(" << n << ")" << ": " << endl;
    double a;
    int i = 0;

    cout << "Input a: " << endl;
    cin >> a;

    double x = a - f(a, k) / df(a, k);
    while (fabs(x - a) > eps) {
        a = x;
        x = a - f(a, k) / df(a, k);
        i += 1;
    }

    cout << setprecision(precision) << "x= " << x << endl;
    cout << "i= " << i << endl;
}

void fiter(double eps, int k, int precision, int n) {
    cout << "Iteration" << "(" << n << ")" << ": " << endl;
    double a;
    int i = 0;

    cout << "Input a: " << endl;
    cin >> a;

    double x = a - f(a, k);
    while (fabs(f(x, k) - f(a, k)) > eps) {
        a = x;
        x = a - f(a, k);
        i += 1;
    }

    cout << setprecision(precision) << "x= " << x << endl;
    cout << "i= " << i << endl;
}