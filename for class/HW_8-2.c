#include <stdio.h>

int main() {
    char ch;
    ch = getchar();
    while (ch != '\r' && ch != '\n') {
        char nextChar = ch + 1;

        printf("[%c] %d ==> [%c] %d\n", ch, ch, nextChar, nextChar);

        ch = getchar();
    }

    return 0;
}
