#include <fstream>
#include <iostream>
#include <list>
#include <string>
using namespace std;
class Flat  // класс для требуемой квартиры
{
 public:
  Flat DataInput(list<Flat> &List, int &);  // ввод заявки в картотеку
  string getregion() const { return region; }
  int getroom() const { return room; }
  int getsquare() const { return square; }
  int getfloor() const { return floor; }
  void setregion(string region) { this->region = region; }
  void setroom(int room) { this->room = room; }
  void setsquare(int square) { this->square = square; }
  void setfloor(int floor) { this->floor = floor; }
  friend ostream &operator<<(ostream &out, Flat &f);

 private:
  string region;  // область
  int room;       // количество комнат
  int square;     // площадь
  int floor;      // этаж
};
class Flat2  // класс для имеющейся квартиры
{
 public:
  Flat2 DataInput2(list<Flat2> &List2, int &);
  string getregion2() const { return region2; }
  int getroom2() const { return room2; }
  int getsquare2() const { return square2; }
  int getfloor2() const { return floor2; }
  void setregion2(string region2) { this->region2 = region2; }
  void setroom2(int room2) { this->room2 = room2; }
  void setsquare2(int square2) { this->square2 = square2; }
  void setfloor2(int floor2) { this->floor2 = floor2; }
  friend ostream &operator<<(ostream &out, Flat2 &f2);

 private:
  string region2;
  int room2;
  int square2;
  int floor2;
};
void get_data_from_file(list<Flat> &List, list<Flat2> &List2,
                        int &);  // получить данныеизфайла
void print_flats(list<Flat> List, list<Flat2> List2);  // вывести на экран
int menu();
void find(list<Flat> &List, list<Flat2> &List2, int num);  // поиск заявки
void clean_buff(istream &cin);                             // чистка cin