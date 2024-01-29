#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double x, y, a;
    int n, i;
    cin >> x;
    y = 1;
    a = 1;
    cin >> n;
    for (i = 1;i <= n;i++) {
        a = a * (-x * x / (4 * i * i - 2 * i));
        y += a;
        if (i == 3 || i == 5 || i == 10)
            cout << "For n=" << i << setprecision(10) << " y=" << y << endl;
    }
    cout << "Total sum: " << endl << setprecision(10) << " y=" << y << endl;
    return 0;
}