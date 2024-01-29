#include <cstring>
#pragma once

// #define l_name  30

class Man {
 public:
  Man(int l_name = 30);  // конструктор
  char *getname() const { return pName; }
  int getyear() const { return birth_year; }
  float getpay() const { return pay; }
  void setname(char *newname) { strcpy(pName, newname); }
  void setyear(int newyear) { birth_year = newyear; }
  void setpay(float newpay) { pay = newpay; }
  ~Man();  // деконструктор

 private:
  char *pName;     // фамилия
  int birth_year;  // год рождения
  float pay;       // зарплата
};

int read_dbase(char *filename, Man *arr, int &n);  // чтение из файла
int menu();
int menu_f();
void print_dbase(Man *arr, int n);  // печать на экран
int write_dbase(char *filename, Man *arr, int n);  // вывод базы в файл
void add(Man *arr, int &n);     // добавление сотрудника
void remove(Man *arr, int &n);  // удаление сотрудника
void edit(Man *arr, int n);     // корректировка
int find(Man *arr, int n, char *name);  // поиск по фамилии
int find(Man *arr, int n, int birth_year);  // поиск по году (сотрудники старше)
int find(Man *arr, int n, float pay);  // поиск по зарплате(выше)
void find_man(Man *arr, int n);