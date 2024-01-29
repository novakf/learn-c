#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
/*
class MyVector
{
public:
  MyVector(const char *el = NULL, int maxsz = MAX_SIZE);

  MyVector(MyVector &v);
  ~MyVector();

  void add_element(const char *el);
  void delete_element(int i);
  char *operator[](int i);

  void sort();

  int Size() { return size; }
  int Maxsize() { return maxsize; }
  int find(const char *el);
  MyVector &operator=(MyVector &v);
  friend ostream &operator<<(ostream &out, MyVector &v);

protected:
  int maxsize;
  int size;
  char **pdata;

  void resize(int new_size);
};
*/

template <class T>
class MyVector
{
public:
  MyVector(T el = NULL, int maxsz = MAX_SIZE);

  MyVector(MyVector<T> &v);
  ~MyVector();

  void add_element(T el);
  void delete_element(int i);
  char *operator[](int i);

  void sort();

  int find(T el);
  MyVector &operator=(MyVector<T> &v);

  template <T>
  friend ostream &operator<<(ostream &out, MyVector<T> &v);

  T *getpdata() const { return pdata; }
  int getmaxsize() const { return maxsize; }
  int getsize() const { return size; }

protected:
  int maxsize;
  int size;
  T *pdata;

  void resize(int new_size);
};