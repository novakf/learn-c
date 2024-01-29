#include <cstring>
#pragma once
#include <fstream>
#include <iostream>
// #define l_name 30
using namespace std;

class Phone {
 public:
  Phone();
  ~Phone();
  Phone(const Phone &copy);

  char *getname() const { return pName; }
  int getyear() const { return birth_year; }
  float getpay() const { return pay; }
  long long getnum() const { return num; }

  void setname(char *name);
  Phone *setyear(int birth_year);
  Phone *setpay(float pay);
  Phone *setnum(long long num);

  Phone &operator=(Phone &);
  friend ifstream &operator>>(ifstream &in, Phone &n);
  friend ofstream &operator<<(ofstream &, Phone &);
  // friend istream& operator >> (istream& in, Phone& n);
  bool operator<(Phone &);
  bool operator==(Phone &n2);

 private:
  char *pName;
  int birth_year;
  float pay;      // плата за тариф
  long long num;  // номер телефона
  static int total;
  int id;
};

int read_dbase(char *filename, Phone *arr, int &n);  // чтение из файла
int menu();
int menu_f();
void print_dbase(Phone *arr, int n);  // вывод на жкран
int write_dbase(char *filename, Phone *arr, int n);  // вывод в файл
void add(Phone *arr, int &n);     // добавление абонента
void remove(Phone *arr, int &n);  // удаление абонента
void edit(Phone *arr, int n);     // корректировка
int find(Phone *arr, int n, char *name);  // поиск по имени
int find(Phone *arr, int n, int birth_year);  // поиск по году рождения (старше)
int find(Phone *arr, int n, float pay);  // поиск по плате(больше цены)
void find_Phone(Phone *arr, int n);
void sort(Phone *arr, int n);  // сортировка по плате за тариф)
