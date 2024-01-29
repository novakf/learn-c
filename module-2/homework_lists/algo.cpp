#include "algo.h"

#include <iomanip>
#include <iostream>
using namespace std;
int menu() {
  cout << "меню:" << endl;
  cout << "\t 1. добавить заявку" << endl;
  cout << "\t 2. поиск" << endl;
  cout << "\t 3. напечатать весь список" << endl;
  cout << "\t 4. нажмите для выхода" << endl;
  string line;
  int n;
  clean_buff(cin);
  getline(cin, line);
  try {
    n = stoi(line);
  } catch (std::exception &i) {
    cout << "Incorrect number" << endl;
    return 0;
  }
  if (n < 1 or n > 4) {
    cout << "Incorrect number" << endl;
    return 0;
  } else
    return n;
}
void print_flats(list<Flat> List, list<Flat2> List2) {
  list<Flat>::iterator it = List.begin();
  list<Flat2>::iterator it2 = List2.begin();
  int i = 1;
  while (it2 != List2.end()) {
    cout << i << "." << endl;
    cout << "ТРЕБУЕМАЯ: " << endl << *it;
    cout << "ИМЕЮЩАЯСЯ: " << endl << *it2;
    it++;
    it2++;
    i++;
  }
}
Flat Flat::DataInput(list<Flat> &List, int &num) {
  ofstream fout("flats1.txt", ios::app);
  Flat Flat;
  int n;
  string line;
  cout << "ТРЕБУЕМАЯ: " << endl << "район: ";
  clean_buff(cin);
  getline(std::cin, Flat.region);
  int fl = 1;
  while (fl == 1) {
    fl = 0;
    cout << "этаж : ";
    clean_buff(cin);
    getline(cin, line);
    try {
      n = stoi(line);
      fl = 0;
    } catch (std::exception &i) {
      cout << "Incorrect number" << endl;
      fl = 1;
    }
    if (fl != 1) {
      Flat.floor = n;
      if (Flat.floor < 0) {
        cout << "Incorrect, try again!" << endl;
        fl = 1;
      } else
        fl = 0;
    }
  }
  fl = 1;
  while (fl == 1) {
    fl = 0;
    cout << "площадь : ";
    clean_buff(cin);
    getline(cin, line);
    try {
      n = stoi(line);
      fl = 0;
    } catch (std::exception &i) {
      cout << "Incorrect number" << endl;
      fl = 1;
    }
    if (fl != 1) {
      Flat.square = n;
      if (Flat.square < 0) {
        cout << "Incorrect, try again!" << endl;
        fl = 1;
      } else
        fl = 0;
    }
  }
  fl = 1;
  while (fl == 1) {
    fl = 0;
    cout << "кол-во комнат : ";
    clean_buff(cin);
    getline(cin, line);
    try {
      n = stoi(line);
      fl = 0;
    } catch (std::exception &i) {
      cout << "Incorrect number" << endl;
      fl = 1;
    }
    if (fl != 1) {
      Flat.room = n;
      if (Flat.room < 0) {
        cout << "Incorrect, try again!" << endl;
        fl = 1;
      } else
        fl = 0;
    }
  }
  fout << Flat.region << endl;
  fout << Flat.floor << endl;
  fout << Flat.square << endl;
  fout << Flat.room << endl;
  fout.close();
  return Flat;
}
Flat2 Flat2::DataInput2(list<Flat2> &List2, int &num) {
  ofstream fout("flats1.txt", ios::app);
  Flat2 Flat2;
  cout << "ИМЕЮЩАЯСЯ: " << endl << "район: ";
  clean_buff(cin);
  getline(cin, Flat2.region2);
  string line;
  int n;
  int fl = 1;
  while (fl == 1) {
    fl = 0;
    cout << "этаж : ";
    clean_buff(cin);
    getline(cin, line);
    try {
      n = stoi(line);
      fl = 0;
    } catch (std::exception &i) {
      cout << "Incorrect number" << endl;
      fl = 1;
    }
    if (fl != 1) {
      Flat2.floor2 = n;
      if (Flat2.floor2 < 0) {
        cout << "Incorrect, try again!" << endl;
        fl = 1;
      } else
        fl = 0;
    }
  }
  fl = 1;
  while (fl == 1) {
    fl = 0;
    cout << "площадь : ";
    clean_buff(cin);
    getline(cin, line);
    try {
      n = stoi(line);
      fl = 0;
    } catch (std::exception &i) {
      cout << "Incorrect number" << endl;
      fl = 1;
    }
    if (fl != 1) {
      Flat2.square2 = n;
      if (Flat2.square2 < 0) {
        cout << "Incorrect, try again!" << endl;
        fl = 1;
      } else
        fl = 0;
    }
  }
  fl = 1;
  while (fl == 1) {
    fl = 0;
    cout << "кол-во комнат : ";
    clean_buff(cin);
    getline(cin, line);
    try {
      n = stoi(line);
      fl = 0;
    } catch (std::exception &i) {
      cout << "Incorrect number" << endl;
      fl = 1;
    }
    if (fl != 1) {
      Flat2.room2 = n;
      if (Flat2.room2 < 0) {
        cout << "Incorrect, try again!" << endl;
        fl = 1;
      } else
        fl = 0;
    }
  }
  fout << Flat2.region2 << endl;
  fout << Flat2.floor2 << endl;
  fout << Flat2.square2 << endl;
  fout << Flat2.room2 << endl;
  num++;
  fout.close();
  return Flat2;
}
void get_data_from_file(list<Flat> &List, list<Flat2> &List2, int &num) {
  list<Flat>::iterator it = List.begin();
  Flat f[20];
  list<Flat2>::iterator it2 = List2.begin();
  Flat2 f2[20];
  ifstream file("flats1.txt", ios::in | ios::binary);
  if (!file) {
    cout << "Can't find file!" << endl
         << "Automatically creating new file." << endl;
  } else {
    string t;
    for (int r = 0; !file.eof(); r++) {
      getline(file, t);
      if (r % 8 == 0) f[num].setregion(t);
      if (r % 8 == 1) f[num].setfloor(stoi(t));
      if (r % 8 == 2) f[num].setsquare(stoi(t));
      if (r % 8 == 3) f[num].setroom(stoi(t));
      if (r % 8 == 4) f2[num].setregion2(t);
      if (r % 8 == 5) f2[num].setfloor2(stoi(t));
      if (r % 8 == 6) f2[num].setsquare2(stoi(t));
      if (r % 8 == 7) {
        f2[num].setroom2(stoi(t));
        num++;
      }
    }
  }
  file.close();
  for (int i = 0; i < num; i++) {
    List.push_back(f[i]);
    List2.push_back(f2[i]);
  }
}
ostream &operator<<(ostream &out, Flat &f) {
  out << "район: "
      << " " << f.getregion() << endl;
  out << "этаж: "
      << " " << f.getfloor() << endl;
  out << "площадь: "
      << " " << f.getsquare() << endl;
  out << "кол-во комнат: " << f.getroom() << endl;
  return out;
}
ostream &operator<<(ostream &out, Flat2 &f2) {
  out << "район: "
      << " " << f2.getregion2() << endl;
  out << "этаж: "
      << " " << f2.getfloor2() << endl;
  out << "площадь: "
      << " " << f2.getsquare2() << endl;
  out << "кол-во комнат: " << f2.getroom2() << endl;
  return out;
}
void find(list<Flat> &List, list<Flat2> &List2, int num) {
  Flat f;
  Flat2 f2;
  list<Flat>::iterator it = List.begin();
  list<Flat2>::iterator it2 = List2.begin();
  int n;
  int flag = -1;
  string line;
  string reg;
  int flo, sq, r;
  cout << "Требуемая квартира: " << endl << "район: ";
  clean_buff(cin);
  getline(std::cin, reg);
  f.setregion(reg);
  int fl = 1;
  while (fl == 1) {
    fl = 0;
    cout << "этаж : ";
    clean_buff(cin);
    getline(cin, line);
    try {
      n = stoi(line);
      fl = 0;
    } catch (std::exception &i) {
      cout << "Incorrect number" << endl;
      fl = 1;
    }
    if (fl != 1) {
      flo = n;
      if (flo < 0) {
        cout << "Incorrect, try again!" << endl;
        fl = 1;
      } else
        fl = 0;
    }
  }
  f.setfloor(flo);
  fl = 1;
  while (fl == 1) {
    fl = 0;
    cout << "площадь : ";
    clean_buff(cin);
    getline(cin, line);
    try {
      n = stoi(line);
      fl = 0;
    } catch (std::exception &i) {
      cout << "Incorrect number" << endl;
      fl = 1;
    }
    if (fl != 1) {
      sq = n;
      if (sq < 0) {
        cout << "Incorrect, try again!" << endl;
        fl = 1;
      } else
        fl = 0;
    }
  }
  f.setsquare(sq);
  fl = 1;
  while (fl == 1) {
    fl = 0;
    cout << "кол-во комнат : ";
    clean_buff(cin);
    getline(cin, line);
    try {
      n = stoi(line);
      fl = 0;
    } catch (std::exception &i) {
      cout << "Incorrect number" << endl;
      fl = 1;
    }
    if (fl != 1) {
      r = n;
      if (r < 0) {
        cout << "Incorrect, try again!" << endl;
        fl = 1;
      } else
        fl = 0;
    }
  }
  f.setroom(r);
  for (int i = 0; i < num; i++) {
    if (((*it2).getfloor2() == f.getfloor()) &&
        ((*it2).getroom2() == f.getroom()) &&
        abs((double)((*it2).getsquare2() - f.getsquare()) /
            (double)(f.getsquare())) < 0.1) {
      flag = i;
    }
    it2++;
  }
  if (flag == -1) {
    cout << endl
         << "Объявление не найдено" << endl
         << "Добавим заявку в картотеку" << endl;
    ofstream fout("flats1.txt", ios::app);
    List.push_back(f);
    fout << f.getregion() << endl;
    fout << f.getfloor() << endl;
    fout << f.getsquare() << endl;
    fout << f.getroom() << endl;
    fout.close();
    cout << "Опишите имеющаюся квартиру: " << endl;
    List2.push_back(f2.DataInput2(List2, num));
  } else {
    cout << endl << "Предложение найдено!" << endl;
    it2 = List2.begin();
    for (int i = 0; i < flag; i++) {
      it++;
      it2++;
    }
    cout << "ТРЕБУЕМАЯ: " << endl << *it;
    cout << "ИМЕЮЩАЯСЯ: " << endl << *it2;
  }
}
void clean_buff(istream &cin) {
  if (char(cin.peek()) == '\n') cin.ignore();
  if (cin.fail()) {
    cin.clear();
    cin.ignore(32767, '\n');
  }
