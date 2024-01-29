#include <cmath>
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;
 
typedef double (*TPF)(double);
 
double f1(double x) { return x; }
double f2(double x) { return sin(22 * x); }
double f3(double x) { return x * x * x * x; }
double f4(double x) { return atan(x); }
 
struct I_print {
    const char* name;
    double I_sum;
    double I_toch;
    int n;
};
 
double IntRect(TPF f, double a, double b, double eps, int& n) {
    double dx, s1, s2;
    dx = b - a;
    s1 = 0;
    s2 = f(b) * dx;
    n = 2;
    while (fabs(s2 - s1) > eps) {
        s1 = s2;
        s2 = 0;
        dx = (double)(b - a) / n;
        for (int i = 0; i < n; i++) {
            s2 += f(a + i * dx);
        }
        s2 *= dx;
        n *= 2;
    }
    n /= 2;
    return s2;
}
 
double IntTrap(TPF f, double a, double b, double eps, int& n) {
    double dx, s1, s2;
    dx = b - a;
    s1 = 0;
    s2 = (f(a) + f(a + dx)) * dx / 2;
    n = 2;
    while (fabs(s2 - s1) > eps) {
        s1 = s2;
        s2 = 0;
        dx = (double)(b - a) / n;
        for (int i = 0; i < n; i++) {
            s2 += f(a + i * dx) + f(a + i * dx + dx);
        }
        s2 *= dx / 2;
        n *= 2;
    }
    n /= 2;
    return s2;
}
 
void PrintTabl(I_print i_prn[], int k) {
    const int m = 4;
    int wn[m] = { 12, 18, 18, 10 };
    const char* title[m] = { "Function", "Integral", "IntSum", "N " };
    int size[m];
 
    for (int i = 0; i < m; i++)
        size[i] = strlen(title[i]);
 
    cout << char(218) << setfill(char(196));
 
    for (int j = 0; j < m - 1; j++) 
        cout << setw(wn[j]) << char(194);
 
    cout << setw(wn[m - 1]) << char(191) << endl;
    cout << char(179);
 
    for (int j = 0; j < m; j++)
        cout << setw((wn[j] - size[j]) / 2) << setfill(' ') << ' ' << title[j] << setw((wn[j] - size[j]) / 2) << char(179);
    
    cout << endl;
 
    for (int i = 0; i < k; i++) {
        cout << char(195) << fixed;
  
        for (int j = 0; j < m - 1; j++)
            cout << setfill(char(196)) << setw(wn[j]) << char(197);
        
        cout << setw(wn[m - 1]) << char(180) << setfill(' ') << endl;
       
        cout << char(179) << setw((wn[0] - strlen(i_prn[i].name)) / 2) << ' '
            << i_prn[i].name << setw((wn[0] - strlen(i_prn[i].name)) / 2)
            << char(179);
        cout << setw(wn[1] - 1) << setprecision(10) << i_prn[i].I_toch << char(179)
            << setw(wn[2] - 1) << i_prn[i].I_sum << setprecision(6) << char(179)
            << setw(wn[3] - 1) << i_prn[i].n << char(179) << endl;
    }
 
    cout << char(192) << setfill(char(196));
 
    for (int j = 0; j < m - 1; j++)
        cout << setw(wn[j]) << char(193);
 
    cout << setw(wn[m - 1]) << char(217) << setfill(' ') << endl;
}
