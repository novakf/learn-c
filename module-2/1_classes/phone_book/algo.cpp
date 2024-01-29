#include "algo.h"

#include <string.h>

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

int l_name = 30;
int Phone::total = 0;

Phone::Phone() {
  pName = nullptr;
  birth_year = 0;
  pay = 0.0;
  num = 0;
  total++;
  id = total;
  // cout << "Create ID " << id << endl;
}

Phone::~Phone() {
  if (pName != nullptr) {
    delete[] this->pName;
  }
  // cout << "Delete ID" << id << endl;
  total--;
}

Phone::Phone(const Phone &copy) {
  pName = new char[strlen(copy.pName) + 1];
  strncpy(pName, copy.pName, strlen(copy.pName));
  birth_year = copy.birth_year;
  pay = copy.pay;
  num = copy.num;
  total++;
  id = total;
  // cout << " ID " << id << endl;
}

Phone &Phone::operator=(Phone &n) {
  if (this != &n) {
    if (this->pName != nullptr) {
      delete[] this->pName;
    }
    pName = new char[strlen(n.pName) + 1];
    strncpy(pName, n.pName, strlen(n.pName) + 1);
    birth_year = n.birth_year;
    pay = n.pay;
    num = n.num;
  }
  return (*this);
}

void Phone::setname(char *name) {
  pName = new char[strlen(name) + 1];
  strncpy(pName, name, strlen(name) + 1);
}
Phone *Phone::setyear(int birth_year) {
  this->birth_year = birth_year;
  return this;
}
Phone *Phone::setpay(float pay) {
  this->pay = pay;
  return this;
}
Phone *Phone::setnum(long long num) {
  this->num = num;
  return this;
}

ifstream &operator>>(ifstream &in, Phone &n) {
  char name[30];
  in >> name >> n.birth_year >> n.pay >> n.num;
  n.pName = new char[strlen(name) + 1];
  strncpy(n.pName, name, strlen(name) + 1);
  return in;
}

ofstream &operator<<(ofstream &out, Phone &n) {
  out << n.getname() << ' ' << n.getyear() << ' ' << n.getpay() << ' '
      << n.getnum() << endl;
  return out;
}

bool Phone::operator<(Phone &n2) {
  if (this->birth_year < n2.birth_year) {
    return 1;
  } else {
    return 0;
  }
}

bool Phone::operator==(Phone &n2) {
  if (this->birth_year == n2.birth_year) {
    return 1;
  } else {
    return 0;
  }
}

int menu() {
  cout << " ============== ГЛАВНОЕ МЕНЮ ========================\n";
  cout << "1 - добавление абонента\t\t 4 - корректировка сведений" << endl;
  cout << "2 - удаление абонентa\t\t 5 - вывод базы на экран" << endl;
  cout << "3 - поиск абонента\t\t 6 - вывод базы в файл" << endl;
  cout << "7 - сортировать по плате";
  cout << "\t 8 - выход" << endl;
  cout << "Для выбора операции введите цифру от 1 до 8" << endl;
  int resp;
  cin >> resp;
  cin.clear();
  cin.ignore(10, '\n');
  return resp;
}

// ------------------------------------ Чтение базы из файла
int read_dbase(char *filename, Phone *arr, int &n) {
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
    fin >> arr[i];
  }
  fin.close();
  return 0;
}

void add(Phone *arr, int &n) {
  char buf[31];
  int year;
  float pay;
  long long num;
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
    cout << "Плата: " << endl;
    cin >> pay;
    arr[n].setpay(pay);
    if (pay < 0) {
      cout << "Неправильные данные!" << endl;
      fl == 1;
    } else
      fl = 0;
  }
  fl = 1;
  while (fl == 1) {
    cout << "Номер: " << endl;
    cin >> num;
    arr[n].setnum(num);
    if (num < 0) {
      cout << "Неправильные данные!" << endl;
      fl == 1;
    } else
      fl = 0;
  }
  n++;
}

//------------------------------------ Вывод базы в файл
int write_dbase(char *filename, Phone *arr, int n) {
  ofstream fout(filename, ios::out);
  if (!fout) {
    cout << "Ошибка открытия файла" << endl;
    return 1;
  }
  fout << n;
  for (int i = 0; i < n; i++) fout << arr[i];

  fout.close();
  return 0;
}

//------------------------------ Вывод базы на экран
void print_dbase(Phone *arr, int n) {
  cout << " База Данных " << endl;
  for (int i = 0; i < n; i++) {
    char name[30];
    int year;
    float pay;
    long long num;
    strcpy(name, arr[i].getname());
    year = arr[i].getyear();
    pay = arr[i].getpay();
    num = arr[i].getnum();
    cout << setw(3) << i + 1 << ". ";
    for (int j = 0; j < strlen(name); j++) cout << name[j];
    cout << setw(3) << " " << year << setw(10) << pay << setw(5) << ' ' << num
         << endl;
  }
}

//-----------------------------Поиск абонента в списке по фамилии
int find(Phone *arr, int n,
         char *name)  // возвращает индес элемента с данными о
                      // абоненте в БД,реализованной в виде массива
{
  int ind = -1;
  for (int i = 0; i < n; i++)
    if (!strcmp(arr[i].getname(), name)) {
      cout << arr[i].getname() << setw(20 - strlen(arr[i].getname()) + 6)
           << arr[i].getyear() << setw(10) << arr[i].getpay() << setw(5)
           << arr[i].getnum() << endl;
      ind = i;
    }
  return ind;
}

//------- Поиск и вывод более старших по возрасту абонентов
int find(Phone *arr, int n, int birth_year) {
  int ind = -1;
  for (int i = 0; i < n; i++)
    if (arr[i].getyear() < birth_year) {
      ind = i;
      cout << arr[i].getname() << setw(20 - strlen(arr[i].getname()) + 6)
           << arr[i].getyear() << setw(10) << arr[i].getpay() << setw(5)
           << arr[i].getnum() << endl;
    }
  return ind;
}

//-------- Поиск и вывод абонентов с платой, большим чем "pay"
int find(Phone *arr, int n, float pay) {
  int ind = -1;
  for (int i = 0; i < n; i++)
    if (arr[i].getpay() > pay) {
      ind = i;
      cout << arr[i].getname() << setw(20 - strlen(arr[i].getname()) + 4)
           << arr[i].getyear() << "   " << arr[i].getpay() << "   "
           << arr[i].getnum() << endl;
    }
  return ind;
}

int menu_f() {
  cout << "\n----------------- ПОИСК -----------------\n";
  cout << "1 - поиск по фамилии  2 - по году рождения\n"
       << "3 - по платe     4 - конец поиска\n ";
  cout << "Для выбора операции введите число от 1 до 4\n";
  int resp;
  cin >> resp;
  cin.clear();
  cin.ignore(10, '\n');
  return resp;
}

//-------------------------------------  Поиск
void find_Phone(Phone *arr, int n) {
  char buf[l_name];
  int birth_year;
  float pay;
  long long num;

  while (true) {
    switch (menu_f()) {
      case 1:
        cout << "Введите фамилию абонента\n";
        cin >> buf;
        if (find(arr, n, buf) < 0)
          cout << "Абонента с фамилией " << buf << " в списке нет\n";
        break;
      case 2:
        cout << "Введите год рождения" << endl;
        cin >> birth_year;
        if (find(arr, n, birth_year) < 0)
          cout << "В списке нет абонентов, родившихся до " << birth_year
               << " года\n";
        break;
      case 3:
        cout << "Введите плату" << endl;
        cin >> pay;
        if (find(arr, n, pay) < 0)
          cout << "В списке нет абонентов с платой, большей " << pay
               << " руб.\n";
        break;
      case 4:
        return;
      default:
        cout << "Неверный ввод\n";
    }
  }
}

void remove(Phone *arr, int &n) {
  int k;
  print_dbase(arr, n);

  int fl = 1;
  while (fl == 1) {
    cout << "Какую запись изменить?" << endl;
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
    int year = arr[i + 1].getyear();
    arr[i].setyear(year);
  }

  for (int i = k; i < n - 1; i++) {
    int pay = arr[i + 1].getpay();
    arr[i].setpay(pay);
  }
  n--;
}

void edit(Phone *arr, int n) {
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
  cout << "Вот: ";

  for (int i = 0; i < strlen(arr[t].getname()); i++) {
    cout << arr[t].getname()[i];
  }
  cout << " ";

  cout << arr[t].getyear() << " " << arr[t].getpay() << " " << arr[t].getnum()
       << endl;

  fl = 1;
  while (fl == 1) {
    cout << "Выберите категорию: " << endl
         << "1.Имя" << endl
         << "2.Год рождения" << endl
         << "3.Плата" << endl
         << "4.Номер" << endl;
    cin >> m;
    if (m < 1 or m > 4) {
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
  long long num;
  if (m == 2) {
    fl = 1;
    while (fl == 1) {
      cout << "ГОд рождения: " << endl;
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
      cout << "Плата: " << endl;
      cin >> pay;
      arr[t].setpay(pay);
      if (pay < 0) {
        cout << "Неправильные данные!" << endl;
        fl == 1;
      } else
        fl = 0;
    }
  }
  if (m == 4) {
    fl = 1;
    while (fl == 1) {
      cout << "Номер: " << endl;
      cin >> num;
      arr[t].setpay(num);
      if (num < 0) {
        cout << "Неправильные данные!" << endl;
        fl == 1;
      } else
        fl = 0;
    }
  }
}

void sort(Phone *arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i].getpay() > arr[j].getpay()) {
        Phone tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
}