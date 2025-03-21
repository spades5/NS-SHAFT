#include <stdio.h>
#include <string.h>

int main() {
    int repeatTimes, ti;

    printf("How many sets of test data: ");
    scanf("%d", &repeatTimes); if (getchar() == '\r') getchar();

    char sent[300];
    for (ti = 0; ti < repeatTimes; ti++) {
        printf("\nInput a string: ");

        fgets(sent, sizeof(sent), stdin);
        strtok(sent, "\r\n");

        for (int i = 0; i < strlen(sent); i++) {
            if (sent[i] >= 'a' && sent[i] <= 'z') {
                sent[i] = sent[i]-'a'+'A';
            } else if (sent[i] >= 'A' && sent[i] <= 'Z') {
                sent[i] = sent[i]-'A'+'a';
            }
        }

        printf("The new string [%s]\n", sent);
    }
    return 0;
}

