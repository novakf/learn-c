#include "Term.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Term::Term()
{
    coeff = 0;
    degree = 0;
}

Term::Term(int num)
{
    coeff = num;
    degree = 0;
}

Term::Term(int num1, int num2)
{
    coeff = num1;
    degree = num2;
}

ostream &operator<<(ostream &out, Term &t)
{
    if (t.coeff == 0 and t.degree == 0)
        out << 0;

    if (t.coeff != 0 and t.degree == 0)
        out << t.coeff;

    if (t.coeff != 0 and t.degree != 0)
    {
        if (t.coeff == 1)
        {
            if (t.degree == 1)
                out << "x";
            else
                out << "x^" << t.degree;
        }
        else if (t.coeff == -1)
        {
            if (t.degree == 1)
                out << "-x";
            else
                out << "-x^" << t.degree;
        }
        else if (t.degree == 1 and t.coeff != 1 and t.coeff != -1)
            out << t.coeff << "x";
        else
            out << t.coeff << "x^" << t.degree;
    }
    return out;
}

istream &operator>>(istream &in, Term &t)
{
    char buf[20];
    char clear_buf[20] = " ";

    if (typeid(ifstream) == typeid(in))
        in.getline(buf, 19, '\t');
    else
        in.getline(buf, 19);

    for (int i = 0; i < strlen(buf); i++)
    {
        if (buf[i] != ' ')
            strncat(clear_buf, buf + i, 1);
    }

    for (int i = 0; i < strlen(clear_buf); i++)
    {
        clear_buf[i] = clear_buf[i + 1];
    }

    if (clear_buf[0] == 'x')
    {
        if (clear_buf[1] == '^')
        {
            sscanf(clear_buf, "x^%d", &t.degree);
            t.coeff = 1;
        }
        else
        {
            t.coeff = 1;
            t.degree = 1;
        }
    }
    else if (clear_buf[0] == '-' and clear_buf[1] == 'x')
    {
        if (clear_buf[2] == '^')
        {
            sscanf(clear_buf, "-x^%d", &t.degree);
            t.coeff = -1;
        }
        else
        {
            t.coeff = -1;
            t.degree = 1;
        }
    }
    else if (clear_buf[0] == '-' and clear_buf[3] != '^')
    {
        sscanf(clear_buf, "-%dx", &t.coeff);
        t.coeff = -t.coeff;
        t.degree = 1;
    }
    else if (clear_buf[0] != '-' and clear_buf[1] == 'x' and clear_buf[2] != '^')
    {
        sscanf(clear_buf, "%dx", &t.coeff);
        t.degree = 1;
    }
    else
        sscanf(clear_buf, "%dx^%d", &t.coeff, &t.degree);

    std::cout << "(coef" << t.coeff << " degree" << t.degree << ")";
    return in;
}

Term operator+(Term &t1, Term &t2)
{
    Term res;
    if (t1.degree == t2.degree)
    {
        res.coeff = t1.coeff + t2.coeff;
        res.degree = t1.degree;
    }
    return res;
}

Term operator*(Term &t1, Term &t2)
{
    Term res;
    res.coeff = t1.coeff * t2.coeff;
    res.degree = t1.degree + t2.degree;
    return res;
}

bool operator!=(Term t1, Term t2)
{
    if (t1.coeff != t2.coeff or t1.degree != t2.degree)
        return true;
    else
        return false;
}

bool operator==(Term t1, Term t2)
{
    if (t1.coeff == t2.coeff and t1.degree == t2.degree)
        return true;
    else
        return false;
}