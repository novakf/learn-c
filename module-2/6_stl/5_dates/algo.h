#pragma once
#include <iostream>
using namespace std;
class Date {
 public:
  Date(int, int, int);
  // Date(int d=1, int m=1, int y=1970);
  friend bool operator==(Date d1, Date d2);
  friend bool operator<(Date d1, Date d2);
  friend ostream &operator<<(ostream &out, Date &d);
  int getday() { return day; }
  int getmonth() { return month; }
  int getyear() { return year; }

 private:
  int day;
  int month;
  int year;
};