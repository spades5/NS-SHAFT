#include <stdio.h>
#include <string.h>

void swap(char *p, char *q) {
    char t=*p;
    *p=*q;
    *q=t;
}

void reverseStr(char str[]) {
    char *p = str;
    char *q = str + strlen(str) - 1;

    while (p < q) {
        swap(p, q);
        p++;
        q--;
    }
}

int main() {
    char inputStr[10000];
    int repeatTimes, ti;

    printf("How many sets of test data: ");
    scanf("%d", &repeatTimes); if (getchar() == '\r') getchar();

    for (ti = 0; ti < repeatTimes; ti++) {
        printf("\nInput a string: ");
        fgets(inputStr, sizeof(inputStr), stdin);
        strtok(inputStr, "\r\n");

        reverseStr(inputStr);
        printf("The reversed string is [%s]\n", inputStr);
    }

    return 0;
}


