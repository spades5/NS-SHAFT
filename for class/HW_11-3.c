#include <stdio.h>
#include <string.h>

int main()
{
    int ti, repeatTimes;
    printf("How many sets of test data: ");
    scanf("%d",&repeatTimes); if (getchar() == '\r') getchar();

    char word[1000];
    char divides[1000];
    for (ti = 0; ti < repeatTimes; ti++) {
        printf("Input a string: ");
        fgets(word,sizeof(word),stdin); strtok(word, "\r\n");

        printf("Divided by what symbols: ");
        fgets(divides,sizeof(divides),stdin); strtok(divides, "\r\n");

        char *token=strtok(word,divides);
        while(token != NULL){
            printf("[%s] length = %d\n",token,strlen(token));
            token=strtok(NULL,divides);
        }
        printf("\n");
    }

    return 0;
}
