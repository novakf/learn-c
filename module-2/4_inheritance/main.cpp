#include <iostream>
#include "MyVector.cpp"
#include "MySet1.h"

using namespace std;

int main()
{

    MyVector<int> i((int)1);
    i.add_element((int)2);
    i.add_element((int)3);
    cout << "Вектор i: " << i << endl;

    MyVector<char *> v((char *)"Hello!");
    v.add_element((char *)"Привет!");
    v.add_element((char *)"Привет!");
    v.add_element((char *)"В!");
    v.add_element((char *)"Б!");
    v.add_element((char *)"А!");
    cout << "Вектор v: " << v << endl;

    const char *st = v[0];
    cout << "v[0]: " << st << endl
         << endl;

    v.add_element((char *)"Привет!");
    v.add_element((char *)"Привет!");
    v.add_element((char *)"Привет!");
    cout << "Вектор v: " << v << endl;

    MyVector v1 = v;
    cout << "Вектор v1: " << v1 << endl;

    v1.sort();
    cout << "Вектор v1(sort): " << v1 << endl;

    for (int i = 0; i < MAX_SIZE; i++)
        v1.delete_element(0);
    cout << "Вектор v1: " << v1 << endl;


    MySet<int> si((int)0);
    si.add_element((int)1);
    si.add_element((int)2);
    si.add_element((int)3);
    cout << "Множество si: " << si << endl;

    MySet<char *> s, s1, s2;
    s.add_element((char *)"Привет!");
    s.add_element((char *)"No");
    const char *str = "Hello!";
    s.add_element((char *)str);
    cout << "Множество s: " << s << endl;

    s1.add_element((char *)"Cat");
    s1.add_element((char *)"No");
    s1.add_element((char *)"Привет!");
    cout << "Множество s1: " << s1 << endl;

    s2 = s1 - s;
    cout << "Множество s2=s1-s: " << s2 << endl;
    cout << "Множество s1: " << s1 << endl;
    cout << "Множество s: " << s << endl;

    s2 = s - s1;
    cout << "Множество s2=s-s1: " << s2 << endl;
    cout << "Множество s1: " << s1 << endl;
    cout << "Множество s: " << s << endl;

    s2 = s1 + s;
    cout << "Множество s2=s1+s: " << s2 << endl;
    cout << "Множество s1: " << s1 << endl;
    cout << "Множество s: " << s << endl;

    s2 = s1 * s;
    cout << "Множество s2=s1*s: " << s2 << endl;
    cout << "Множество s1: " << s1 << endl;
    cout << "Множество s: " << s << endl;

    MySet<char *> s3 = s2;
    cout << "Множество s3=s2: " << s3 << endl;

    if (s3 == s2)
        cout << "Множество s3=s2\n";
    else
        cout << "Множество s3!=s2\n";
    if (s3 == s1)
        cout << "Множество s3=s1\n";
    else
        cout << "Множество s3!=s1\n";
    if (s1 == s3)
        cout << "Множество s1=s3\n";
    else
        cout << "Множество s1!=s3\n";
    cout << endl;
    /*
        MySet a1, a2;
        a1.add_element("one");
        a1.add_element("two");
        a2.add_element("three");
        a2.add_element("two");

        a1 += a2;
        cout << a1 << endl;
    */
    return 0;
}