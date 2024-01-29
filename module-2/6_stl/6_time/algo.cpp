#include "algo.h"

#include <fstream>
#include <iostream>
Time::Time(int h, int m, int s) {
  if (s > 59) {
    m++;
    s -= 60;
  }
  if (m > 59) {
    h++;
    m -= 60;
  }
  if (h > 11) {
    h -= 12;
  }
  hour = h;
  minute = m;
  sec = s;
}
Time::Time() {
  hour = 0;
  minute = 0;
  sec = 0;
}
bool operator==(Time t1, Time t2) {
  if (t1.hour == t2.hour and t1.minute == t2.minute and t1.sec == t2.sec)
    return true;
  else
    return false;
}
bool operator<(Time t1, Time t2) {
  if (t1.hour < t2.hour)
    return true;
  else if (t1.hour > t2.hour)
    return false;
  else if (t1.minute < t2.minute)
    return true;
  else if (t1.minute > t2.minute)
    return false;
  else if (t1.sec < t2.sec)
    return true;
  else
    return false;
}
ostream &operator<<(ostream &out, Time &t) {
  if (t.hour < 10)
    out << "0" << t.hour;
  else
    out << t.hour;
  out << ":";
  if (t.minute < 10)
    out << "0" << t.minute;
  else
    out << t.minute;
  out << ":";
  if (t.sec < 10)
    out << "0" << t.sec;
  else
    out << t.sec;
  return out;
}