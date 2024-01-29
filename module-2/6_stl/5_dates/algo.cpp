#include "algo.h"

#include <fstream>
#include <iostream>
Date::Date(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
}
bool operator==(Date d1, Date d2) {
  if (d1.day == d2.day and d1.month == d2.month and d1.year == d2.year)
    return true;
  else
    return false;
}
bool operator<(Date d1, Date d2) {
  if (d1.year < d2.year)
    return true;
  else if (d1.year > d2.year)
    return false;
  else if (d1.month < d2.month)
    return true;
  else if (d1.month > d2.month)
    return false;
  else if (d1.day < d2.day)
    return true;
  else
    return false;
}
ostream &operator<<(ostream &out, Date &d) {
  if (d.day < 10)
    out << "0" << d.day;
  else
    out << d.day;
  out << ".";
  if (d.month < 10)
    out << "0" << d.month;
  else
    out << d.month;
  out << ".";
  out << d.year;
  return out;
}