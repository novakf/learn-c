#include <cstring>
#include <stdio.h>


void input(char *txt) {
  int i;
  char letter;
  for (int i = 0; i < 1000; i++) {
    txt[i] = '\0';
  }
  i = 0;
  do {
    letter = getchar();
    if (letter <= 'z' and letter >= 'a' or letter == ' ' or letter == '.') {
      // putchar(letter);
      txt[i] = letter;
      i++;
    }
    if (letter == '\b') {
      putchar('\b');
      putchar(' ');
      putchar('\b');
      if (i > 0) {
        --i;
        txt[i] = '\0';
      }
    }

  } while (letter != '.');
}

//считаем кол-во введенных слов в count
void check_number(char *txt, int &count) {
  int division_fl = false, letter_fl = false;

  for (int i = 0; i < strlen(txt); i++) {
    if (txt[i] == ' ' or txt[i] == '.') {
      division_fl = true;
    }
    if (txt[i] != ' ' and txt[i] != '.') {
      letter_fl = true;
      division_fl = false;
    }
    if (letter_fl and division_fl) {
      count++;
      letter_fl = false;
      division_fl = false;
    }
  }
}

//записываем символы из txt[] в созданный words[k][j]
void fill_arr(char *txt, char **words) {
  int k = 0, j = 0;
  int division_fl = false, letter_fl = false;

  for (int i = 0; i < strlen(txt); i++) {
    if (txt[i] == ' ' or txt[i] == '.') {
      division_fl = true;
      j = 0;
    }
    if (txt[i] != ' ' and txt[i] != '.') {
      letter_fl = true;
      division_fl = false;
    }
    if (letter_fl and division_fl) {
      letter_fl = false;
      division_fl = false;
      k++;
    }
    if (txt[i] != ' ' and txt[i] != '.') {
      words[k][j] = txt[i];
      j++;
    }
  }
}

void output(char **words, int count, char *last_word) {
  char sim;
  int fl = 0;
  int oneletter_fl = true;
  int t = 0;

  for (int i = 0; i < count; i++) {
    oneletter_fl = true;

    if (strlen(words[i]) == 1) {
      oneletter_fl = false;
    }

    if (strcmp(last_word, words[i]) != 0) {

      //проверяем условие
      for (int j = 0; j < strlen(words[i]); j++) {
        sim = words[i][j];
        t = 0;
        for (int j = 0; j < strlen(words[i]); j++) {
          if (words[i][j] == sim)
            t++;
        }
        if (t < 2)
          fl += 1;
        else
          fl = 0;
        if (fl != 0)
          break;
      }

      //выводим слова, удовлетворяющие условиям
      if ((fl == 0) && (oneletter_fl == true)) {
        for (int j = 0; j < strlen(words[i]); j++) {
          putchar(words[i][j]);
        }
        putchar(' ');
      }
    }
  }
}
