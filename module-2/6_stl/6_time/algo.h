#pragma once
#include <iostream>
using namespace std;
class Time {
 public:
  Time(int, int, int);
  Time();
  friend bool operator==(Time t1, Time t2);
  friend bool operator<(Time t1, Time t2);
  friend ostream &operator<<(ostream &out, Time &d);
  int gethour() { return hour; }
  int getminute() { return minute; }
  int getsec() { return sec; }

 private:
  int hour;
  int minute;
  int sec;
};