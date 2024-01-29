#pragma once

const int l_word=31;
struct Dictionary
{
  char eng[l_word];
  char rus[l_word];
};

void add_w(Dictionary* , int&);
void delete_w(Dictionary *, int&);
void transl_en_ru(Dictionary *, int);
void transl_ru_en(Dictionary *, int);
void print_dict(Dictionary *, int);
void overwrite(Dictionary *, int);
void fill_arr_from_dict(Dictionary *, int &);
void sort_dict(Dictionary *, int);
int menu();