#include "MyVector.h"
#include <cstring>

using namespace std;
int i = 0;
template <class T>
MyVector<T>::MyVector(MyVector<T> &v)
{
    size = v.size;
    maxsize = v.maxsize;
    pdata = new T[maxsize];
    for (int i = 0; i < size; i++)
    {
        *(pdata + i) = *(v.pdata + i);
    }
    i++;
    // cout << "CONSTR" << i;
}

template <>
MyVector<char *>::MyVector(MyVector<char *> &v)
{
    size = v.size;
    maxsize = v.maxsize;
    pdata = new char *[maxsize];

    for (int i = 0; i < size; i++)
    {
        *(pdata + i) = *(v.pdata + i);
    }
    i++;
    // cout << "CONSTR" << i;
}

template <class T>
MyVector<T>::MyVector(T el, int maxsz)
{
    maxsize = maxsz;
    size = 0;
pdata = new T [maxsize];
    if (el != 0)
    {
        size++;
        pdata[0] = el;
    }
    i++;
    // cout << "CONSTR" << i;
}

template <>
MyVector<char*>::MyVector(char *el, int maxsz)
{
    maxsize = maxsz;
    size = 0;
    pdata = new char *[maxsize];

    if (el != NULL)
    {
        size++;
        *pdata = el;
    }
    i++;
    // cout << "CONSTR" << i;
}

template <class T>
MyVector<T>::~MyVector()
{
    i--;
    // cout << "DESTR" << i;
    delete[] pdata;
}
/*
template <>
MyVector<char*>::~MyVector()
{
    for (int i = 0; i < maxsize; i++)
        delete[] pdata[i];

    delete[] pdata;
}
*/
template <class T>
void MyVector<T>::sort()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (*(pdata + i) > *(pdata + j))
            {
                swap(pdata[i], pdata[j]);
            }
        }
    }
}

template <>
void MyVector<char *>::sort()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(*(pdata + i), *(pdata + j)) > 0)
            {
                char *t = *(pdata + i);
                *(pdata + i) = *(pdata + j);
                *(pdata + j) = t;
            }
        }
    }
}

template <class T>
void MyVector<T>::resize(int new_size)
{
    if (new_size <= maxsize)
        return;

    T *new_pdata = new T[new_size];

    for (int i = 0; i < size; i++)
    {
        *(new_pdata + i) = *(pdata + i);
    }

    delete[] pdata;

    pdata = new_pdata;
    maxsize = new_size;
}

template <>
void MyVector<char *>::resize(int new_size)
{
    if (new_size <= maxsize)
        return;

    char **new_pdata = new char *[new_size];

    for (int i = 0; i < size; i++)
    {
        *(new_pdata + i) = *(pdata + i);
    }

    delete[] pdata;

    pdata = new_pdata;
    maxsize = new_size;
}

template <class T>
void MyVector<T>::add_element(T el)
{
    pdata[size++] = el;
    if (size >= maxsize)
        resize(maxsize * 1.5);
}

template <>
void MyVector<char *>::add_element(char *el)
{
    if (size >= maxsize)
    {
        resize(maxsize * 1.5);
    }

    *(pdata + size) = el;
    size++;
    sort();
}

template <class T>
void MyVector<T>::delete_element(int i)
{
    if (i >= size)
        return;

    if (i == size - 1)
    {
        size--;
        return;
    }

    for (int j = 0, nj = 0; nj < size; j++, nj++)
    {
        if (i == j)
            nj++;

        *(pdata + j) = *(pdata + nj);
    }

    size--;

    if (size < maxsize / 2)
    {
        resize(maxsize * 2 / 3);
    }
    if (maxsize < MAX_SIZE)
        maxsize = MAX_SIZE;
}

template <>
void MyVector<char *>::delete_element(int i)
{
    if (i >= size)
        return;

    if (i == size - 1)
    {
        size--;
        return;
    }

    for (int j = 0, nj = 0; nj < size; j++, nj++)
    {
        if (i == j)
            nj++;

        *(pdata + j) = *(pdata + nj);
    }

    size--;

    if (size < maxsize / 2)
    {
        resize(maxsize * 2 / 3);
    }
    if (maxsize < MAX_SIZE)
        maxsize = MAX_SIZE;
}

template <class T>
int MyVector<T>::find(T el)
{
    int n = -1;
    for (int i = 0; i < size; i++)
    {
        if (*(pdata + i) == el)
            n = i;
    }
    return n;
}

template <>
int MyVector<char *>::find(char *el)
{
    int n = -1;
    for (int i = 0; i < size; i++)
    {
        if (*(pdata + i) == el)
            n = i;
    }
    return n;
}

template <class T>
char *MyVector<T>::operator[](int i)
{
    return (*pdata + i);
}

template <class T>
MyVector<T> &MyVector<T>::operator=(MyVector<T> &v)
{
    delete[] pdata;
    maxsize = v.maxsize;
    size = v.size;
    pdata = new T[maxsize];
    for (int i = 0; i < size; i++)
    {
        pdata[i] = v.pdata[i];
    }
}

template <>
MyVector<char *> &MyVector<char *>::operator=(MyVector<char *> &v)
{
    delete[] pdata;
    size = v.size;
    maxsize = v.maxsize;
    pdata = new char *[maxsize];

    for (int i = 0; i < size; i++)
    {
        *(pdata + i) = *(v.pdata + i);
    }
    return (*this);
}

template <class T>
ostream &operator<<(ostream &out, MyVector<T> &v)
{
    for (int i = 0; i < v.getsize(); i++)
    {
        out << *(v.getpdata() + i) << endl;
    }

    return out;
}