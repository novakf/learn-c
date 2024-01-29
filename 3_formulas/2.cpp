#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
    double a, sum1 = 1.0, sum2 = 1.0;
    int i;
    cin >> a;
    if (a >= 0) {
        for (i = 2; i <= 8; i += 2) {
            sum1 = sum1 * i * i;
        }
        cout << setprecision(10) << sum1 - a;
    }
    if (a < 0) {
        for (i = 3; i <= 9; i += 3) {
            sum2 *= i - 2;
        }
        cout << sum2;
    }
    return 0;
}