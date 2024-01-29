#include "algo.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  int num_w = 0;
  int words_num = 100;
  Dictionary dict[words_num];

  for (int i = 0; i < words_num; i++)
    for (int j = 0; j < 31; j++)
    {
      dict[i].eng[j] = '\0';
      dict[i].rus[j] = '\0';
    }

  fill_arr_from_dict(dict, num_w);

  sort_dict(dict, num_w);

  while (true)
  {
    switch (menu())
    {
    case 0:
      break;
    case 1:
      add_w(dict, num_w);
      break;
    case 2:
      delete_w(dict, num_w);
      break;
    case 3:
      transl_en_ru(dict, num_w);
      break;
    case 4:
      transl_ru_en(dict, num_w);
      break;
    case 5:
      print_dict(dict, num_w);
      break;
    case 6:
      overwrite(dict, num_w);
      break;
    case 7:
      return 0;
    }
    cout << endl;
  }
  return 0;
}
