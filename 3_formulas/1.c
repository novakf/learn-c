#include <stdio.h>
#include <unistd.h>

int read_int() {
    char digits[100], c;
    int num = 0;
    ssize_t res;

    for (int i = 48, j = 0; i < 58; i++, j++) {
        digits[i] = j;
    }

    res = read(0, &c, 1);

    while(res) {
        if (c == ' ' || c == '\n') break;

        num *= 10;
        num += digits[c];

        res = read(0, &c, 1);
    }

    return num;
}

int main() {
    int n, m, i;

    n = read_int();
    m = read_int();

    printf("%d\n", n);
    printf("%d\n", m);

    return 0;

    int sum = 0;
    for (i = 0; i <= n; i += 5) {
        if (i % m != 0) sum = sum + i;
    }

    printf("%d", sum);

    return 0;
}