#include <cstring>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int l_word = 31;

struct Dictionary
{
  char eng[l_word];
  char rus[l_word];
};

int menu()
{
  int n;
  cout << "Enter number from 1 to 7" << endl
       << "1. add word to dictionary;" << endl
       << "2. delete word from dictionary;" << endl
       << "3. translate from ENG to RUS;" << endl
       << "4. translate from RUS to ENG;" << endl
       << "5. show me dictionary;" << endl
       << "6. output dictionary to file;" << endl
       << "7. exit." << endl;
  cin >> n;
  if (n < 1 or n > 7)
  {
    cout << "Incorrect number" << endl;
    return 0;
  }
  else
    return n;
}

void add_w(Dictionary *dict, int &num_w)
{
  cout << "Enter word (eng): " << endl;
  cin.get();
  cin.getline(dict[num_w].eng, 31);
  cout << "Enter word (rus): " << endl;
  cin.getline(dict[num_w].rus, 31);
  num_w++;
}

void sort_dict(Dictionary *dict, int num_w)
{
  for (int i = 0; i < num_w; i++)
  {
    for (int j = i + 1; j < num_w; j++)
      if (strcmp(dict[i].eng, dict[j].eng) > 0)
      {
        Dictionary tmp = dict[i];
        dict[i] = dict[j];
        dict[j] = tmp;
      }
  }
}

void print_dict(Dictionary *dict, int num_w)
{
  sort_dict(dict, num_w);
  cout << "Your recent dictionary: " << num_w << endl;

  for (int j = 0; j < num_w; j++)
  {
    cout << j + 1 << ". ";
    for (int i = 0; i < strlen(dict[j].eng); i++)
    {
      cout << dict[j].eng[i];
    }
    cout << " - ";
    for (int i = 0; i < strlen(dict[j].rus); i++)
    {
      cout << dict[j].rus[i];
    }
    cout << endl;
  }
}

void delete_w(Dictionary *dict, int &num_w)
{
  int k;
  print_dict(dict, num_w);
  cout << "Select word you want to delete: " << endl;
  cin >> k;
  k--;

  for (int i = k; i < num_w - 1; i++)
    for (int j = 0; j < 31; j++)
      dict[i].eng[j] = dict[i + 1].eng[j];

  for (int i = k; i < num_w - 1; i++)
    for (int j = 0; j < 31; j++)
      dict[i].rus[j] = dict[i + 1].rus[j];

  num_w--;
}

void overwrite(Dictionary *dict, int num_w)
{
  fstream file("dictionary", ios::out | ios::binary);
  for (int j = 0; j < num_w; j++)
  {
    for (int i = 0; i < strlen(dict[j].eng); i++)
    {
      file << dict[j].eng[i];
    }
    file << endl;
    for (int i = 0; i < strlen(dict[j].rus); i++)
    {
      file << dict[j].rus[i];
    }
    file << endl;
  }
  file.close();
}

void transl_en_ru(Dictionary *dict, int num_w)
{
  char word[31];
  cout << "Enter english word: " << endl;
  cout << "EN: ";
  cin.get();
  cin.getline(word, 31);
  int t, fl;
  for (int r = 0; r < num_w; r++)
  {
    fl = 0;
    if (strcmp(word, dict[r].eng) == 0)
    {
      fl = 1;
      t = r;
      break;
    }
  }
  if (fl == 0)
    cout << "Not found" << endl;
  else
    cout << "RU: " << dict[t].rus << endl;
}

void transl_ru_en(Dictionary *dict, int num_w)
{
  char word[31];
  cout << "Enter russian word: " << endl;
  cout << "RU: ";
  cin.get();
  cin.getline(word, 31);
  int t, fl;
  for (int r = 0; r < num_w; r++)
  {
    fl = 0;
    if (strcmp(word, dict[r].rus) == 0)
    {
      fl = 1;
      t = r;
      break;
    }
  }
  if (fl == 0)
    cout << "Not found" << endl;
  else
    cout << "EN: " << dict[t].eng << endl;
}

void fill_arr_from_dict(Dictionary *dict, int &num_w)
{
  ifstream file("dictionary", ios::in | ios::binary);
  int len = 100;
  const char ch = '\n';
  char mass[len][31];
  for (int i = 0; i < len; i++)
    for (int j = 0; j < 31; j++)
      mass[i][j] = '\0';
  int h = 0;
  for (int r = 0; !file.eof(); r++)
  {
    file.getline(mass[r], len - 1, ch);
    if (r % 2 == 0)
      for (int j = 0; j < strlen(mass[r]); j++)
        dict[num_w].eng[j] = mass[r][j];
    if (r % 2 != 0)
    {
      for (int j = 0; j < strlen(mass[r]); j++)
        dict[num_w].rus[j] = mass[r][j];
      num_w++;
    }
  }
  file.close();
}