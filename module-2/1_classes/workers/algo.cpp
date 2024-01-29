#include "algo.h"

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int l_name = 30;

Man::Man(int l_name) { pName = new char[l_name]; }
Man::~Man() { delete[] pName; }

int menu() {
  cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
  cout << "1 - добавление сотрудника\t 4 - корректировка сведений" << endl;
  cout << "2 - удаление coтpyдникa\t\t 5 - вывод базы на экран" << endl;
  cout << "3 - поиск сотрудника\t\t 6 - вывод базы в файл" << endl;
  cout << "\t\t\t\t 7 - выход" << endl;
  cout << "Для выбора операции введите цифру от 1 до 7" << endl;
  int resp;
  cin >> resp;
  cin.clear();
  cin.ignore(10, '\n');
  return resp;
}

// ------------------------------------ Чтение базы из файла
int read_dbase(char *filename, Man *arr, int &n) {
  ifstream fin(filename, ios::in);
  if (!fin) {
    cout << "Heт файла " << filename << endl;
    return 1;
  }
  fin >> n;
  if (n > 100) {
    cout << "Переполнение БД. n= " << n << endl;
    return 1;
  }

  for (int i = 0; i < n; i++) {
    char name[30];
    int year;
    float pay;
    // strcpy(name, arr[i].getname());
    // year = arr[i].getyear();
    // pay = arr[i].getpay();
    // for (int i = 0; i < 30; i++)
    //{
    fin >> name;
    // if (name[i] <= 'z' and name[i] >= 'a' or name[i] == ' ')
    //  break;
    //}
    fin >> year >> pay;
    arr[i].setname(name);
    arr[i].setyear(year);
    arr[i].setpay(pay);
  }
  fin.close();
  return 0;
}

void add(Man *arr, int &n) {
  char buf[31];
  int year;
  float pay;
  int fl = 1;
  cout << "Фамилия: " << endl;
  cin.getline(buf, 31);
  arr[n].setname(buf);

  while (fl == 1) {
    cout << "Год рождения: " << endl;
    cin >> year;
    arr[n].setyear(year);
    if (year < 0) {
      cout << "Неправильные данные!" << endl;
      fl == 1;
    } else
      fl = 0;
  }
  fl = 1;
  while (fl == 1) {
    cout << "Зарплата: " << endl;
    cin >> pay;
    arr[n].setpay(pay);
    if (pay < 0) {
      cout << "Неправилльные данные!" << endl;
      fl == 1;
    } else
      fl = 0;
  }
  n++;
}

//------------------------------------ Вывод базы в файл
int write_dbase(char *filename, Man *arr, int n) {
  ofstream fout(filename, ios::out);
  if (!fout) {
    cout << "Ошибка открытия файла" << endl;
    return 1;
  }
  fout << n;
  for (int i = 0; i < n; i++)
    fout << arr[i].getname() << ' ' << arr[i].getyear() << ' '
         << arr[i].getpay() << endl;

  fout.close();
  return 0;
}

//------------------------------ Вывод базы на экран
void print_dbase(Man *arr, int n) {
  cout << " База Данных " << endl;
  for (int i = 0; i < n; i++) {
    char name[30];
    int year;
    float pay;
    strcpy(name, arr[i].getname());
    year = arr[i].getyear();
    pay = arr[i].getpay();
    cout << setw(3) << i + 1 << ". ";
    for (int j = 0; j < strlen(name); j++) cout << name[j];
    cout << setw(3) << " " << year << setw(10) << pay << endl;
  }
}

//-----------------------------Поиск сотрудника в списке по фамилии
int find(Man *arr, int n,
         char *name)  // возвращает индес элемента с данными о
                      // сотруднике в БД,реализованной в виде массива
{
  int ind = -1;
  for (int i = 0; i < n; i++)
    if (!strcmp(arr[i].getname(), name)) {
      cout << arr[i].getname() << setw(20 - strlen(arr[i].getname()) + 6)
           << arr[i].getyear() << setw(10) << arr[i].getpay() << endl;
      ind = i;
    }
  return ind;
}

//------- Поиск и вывод более старших по возрасту сотрудников
int find(Man *arr, int n, int birth_year) {
  int ind = -1;
  for (int i = 0; i < n; i++)
    if (arr[i].getyear() < birth_year) {
      ind = i;
      cout << arr[i].getname() << setw(20 - strlen(arr[i].getname()) + 6)
           << arr[i].getyear() << setw(10) << arr[i].getpay() << endl;
    }
  return ind;
}

//-------- Поиск и вывод сотрудников с окладом, большим чем "pay"
int find(Man *arr, int n, float pay) {
  int ind = -1;
  for (int i = 0; i < n; i++)
    if (arr[i].getpay() > pay) {
      ind = i;
      cout << arr[i].getname() << setw(20 - strlen(arr[i].getname()) + 6)
           << arr[i].getyear() << setw(10) << arr[i].getpay() << endl;
    }
  return ind;
}

int menu_f() {
  cout << "\n----------------- ПОИСК -----------------\n";
  cout << "1 - поиск по фамилии  2 - по году рождения\n"
       << "3 - по окладу   4 - конец поиска\n ";
  cout << "Для выбора операции введите число от 1 до 4\n";
  int resp;
  cin >> resp;
  cin.clear();
  cin.ignore(10, '\n');
  return resp;
}

//-------------------------------------  Поиск
void find_man(Man *arr, int n) {
  char buf[l_name];
  int birth_year;
  float pay;

  while (true) {
    switch (menu_f()) {
      case 1:
        cout << "Введите фамилию сотрудника\n";
        cin >> buf;
        if (find(arr, n, buf) < 0)
          cout << "Сотрудника с фамилией " << buf << " в списке нет\n";
        break;
      case 2:
        cout << "Введите год рождения" << endl;
        cin >> birth_year;
        if (find(arr, n, birth_year) < 0)
          cout << "В списке нет сотрудников, родившихся до " << birth_year
               << " года\n";
        break;
      case 3:
        cout << "Введите оклад" << endl;
        cin >> pay;
        if (find(arr, n, pay) < 0)
          cout << "В списке нет сотрудников с окладом, большим " << pay
               << " руб.\n";
        break;
      case 4:
        return;
      default:
        cout << "Неверный ввод\n";
    }
  }
}

void remove(Man *arr, int &n) {
  int k;
  print_dbase(arr, n);
  int fl = 1;
  while (fl == 1) {
    cout << "Какую запись удалить?" << endl;
    cin >> k;
    if (k < 1 or k > n) {
      cout << "Неправильные данные!" << endl;
      fl = 1;
    } else
      fl = 0;
  }
  k--;

  for (int i = k; i < n - 1; i++)
    strcpy(arr[i].getname(), arr[i + 1].getname());

  for (int i = k; i < n - 1; i++) {
    // arr[i].getyear() = arr[i + 1].getyear();
    int year = arr[i + 1].getyear();
    arr[i].setyear(year);
  }

  for (int i = k; i < n - 1; i++) {
    int pay = arr[i + 1].getpay();
    arr[i].setpay(pay);
  }
  n--;
}

void edit(Man *arr, int n) {
  print_dbase(arr, n);

  int t, m, fl = 1;
  while (fl == 1) {
    cout << "Какую запись изменить?" << endl;
    cin >> t;
    if (t < 1 or t > n) {
      cout << "Неправильные данные!" << endl;
      fl = 1;
    } else
      fl = 0;
  }
  t--;
  cout << "Готово: ";

  for (int i = 0; i < strlen(arr[t].getname()); i++) {
    cout << arr[t].getname()[i];
  }
  cout << " ";

  cout << arr[t].getyear() << " " << arr[t].getpay() << endl;

  fl = 1;
  while (fl == 1) {
    cout << "Выберите категориюy: " << endl
         << "1.Имя" << endl
         << "2.Дата рождения" << endl
         << "3.Зарплата" << endl;
    cin >> m;
    if (m < 1 or m > 3) {
      cout << "Неправильные данные!" << endl;
      fl = 1;
    } else
      fl = 0;
  }

  char buf[30];

  if (m == 1) {
    cout << "Имя: ";
    cin.get();
    cin.getline(buf, 31);
    arr[t].setname(buf);
  }

  int year;
  float pay;
  if (m == 2) {
    fl = 1;
    while (fl == 1) {
      cout << "Год рождения: " << endl;
      cin >> year;
      arr[t].setyear(year);
      if (year < 0) {
        cout << "Неправильные данные!" << endl;
        fl == 1;
      } else
        fl = 0;
    }
  }
  if (m == 3) {
    fl = 1;
    while (fl == 1) {
      cout << "Зарплата: " << endl;
      cin >> pay;
      arr[t].setpay(pay);
      if (pay < 0) {
        cout << "Неправильные данные!" << endl;
        fl == 1;
      } else
        fl = 0;
    }
  }
}