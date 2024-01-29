#include <iostream>
#include "Term.h"
#include "Polynomial.h"

using namespace std;

int main()
{
    /*
    Term t;
    cout << "Term t(): " << t << endl;
    Term t1(3);
    cout << "Term t1(3): " << t1 << endl;
    Term t2(3, 2);
    cout << "Term t2(3,2): " << t2 << endl;
    Term t3(3, 1);
    cout << "Term t3(3,1): " << t3 << endl;
    Term t4(-1, 3);
    cout << "Term t4(-1,3): " << t4 << endl;
    Term t5(-3, 2);
    cout << "Term t5(-3,2): " << t5 << endl;

    Term t6;
    cin >> t6;
    cout << "Term t6: " << t6 << endl;

    Term t7(3, 3), t8(-2, 3);
    Term t9 = t7 + t8;
    cout << "Term t9=t7+t8:" << t9 << endl;

    cout << endl;
*/
    

    Polynomial p;
    cout << "Polynomial p(): " << p << endl;
    Polynomial p1(3);
    cout << "Polynomial p1(3): " << p1 << endl;
    Term t(3, 2);
    Polynomial p2(t);
    cout << "Polynomial p2(Term t(3,2)): " << p2 << endl;
    Polynomial p3(p2);
    cout << "Polynomial p3(p2): " << p3 << endl;

    Polynomial p4;
    p4 = p1 + p3;
    cout << "Polynomial p4=p1+p3: " << p4 << endl;
    Polynomial p5;
    Polynomial p6(Term(1, 1));
    Polynomial p7(Term(-2, 3));
    p5 = p6 + p7;
    cout << "Polynomial p5=p6+p7: " << p5 << endl;

    Polynomial p8;
    p8 = p4 * p5;
    cout << "Polynomial p8=p4*p5: " << p8 << endl;
    
    return 0;
}