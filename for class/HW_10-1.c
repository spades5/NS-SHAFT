#include <stdio.h>
#include <string.h>

void duplicateStr(char dest[], char *src, int n) {
    dest[0]='\0';
    for(int i=1;i<=n;i++){
         strcat(dest,src);
    }
}

int main() {
    char newStr[1000], inputStr[1000];
    int ti, repeatTimes, rpTimes;
    // get repeatTimes from keyboard
    printf("How many sets of test data:");
    scanf("%d",&repeatTimes); if (getchar() == '\r') getchar();

    for (ti = 0; ti < repeatTimes; ti++) {
        printf("\nInput a string: ");
        scanf("%s",inputStr);if (getchar() == '\r') getchar();

        printf("Duplicate how many times: ");
        scanf("%d",&rpTimes); if (getchar() == '\r') getchar();

        duplicateStr(newStr, inputStr, rpTimes);
        printf("The new string is [%s]\n", newStr);
    }
    return 0;
}
