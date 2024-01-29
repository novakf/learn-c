#pragma once
 
struct I_print {
    const char* name;
    double I_sum;
    double I_toch;
    int n;
};
 
typedef double (*TPF)(double);
 
double f1(double);
double f2(double);
double f3(double);
double f4(double);
 
double IntRect(TPF, double, double, double, int&);
double IntTrap(TPF, double, double, double, int&);
 
void PrintTabl(I_print[], int);