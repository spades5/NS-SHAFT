#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int repeatTimes, ti;

    printf("How many sets of test data: ");
    scanf("%d", &repeatTimes); if (getchar() == '\r') getchar();

    char sent[300];
    for (ti = 0; ti < repeatTimes; ti++) {
        printf("\nInput a line:\n");

        fgets(sent, sizeof(sent), stdin);
        strtok(sent, "\r\n");

        for (int i = 0; i < strlen(sent); i++) {
            if (!(isdigit(sent[i]) || sent[i] == '.' || sent[i] == '%')) {
                sent[i] = '_';
            }
        }

        printf("Modified line:\n%s\n", sent);
    }
    return 0;
}
