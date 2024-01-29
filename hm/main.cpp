#include "algo.h"
#include <stdio.h>
#include "buffer.cpp"

int main() {
  BufferToggle bt;
  bt.off();

  int count = 0;
  char txt[1000]; //массив введенных символов

  input(txt);

  putchar('\n');

  check_number(txt, count);

  //создаем двумерный массив для символов с количеством строк = count
  char **words = new char *[count];

  for (int i = 0; i < count; i++) {
    words[i] = new char[100];
  }

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < 100; j++) {
      words[i][j] = '\0';
    }
  }

  fill_arr(txt, words);

  //создаем массив символов и записываем в него последнее слово
  char *last_word = new char[100];

  for (int i = 0; i < 100; i++) {
    last_word[i] = '\0';
  }

  last_word = words[count - 1];

  output(words, count, last_word);

  return 0;
}
