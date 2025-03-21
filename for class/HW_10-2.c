#include <stdio.h>
#include <string.h>

void keywordMasking(char * sentence, char * keyword) {
    int length=strlen(keyword);
    char *maskStr=strstr(sentence, keyword);
    while (maskStr != NULL){
        for (int i=0; i<length;i++) {
            maskStr[i] = '#';
        }
        maskStr=strstr(maskStr+length,keyword);
    }
}

int main() {
    char sentence[1000], keyword[1000];
    int ti, repeatTimes;
    // get repeatTimes from keyboard
    printf("How many sets of test data: ");
    scanf("%d",&repeatTimes); if (getchar() == '\r') getchar();

    for (ti = 0; ti < repeatTimes; ti++) {
        printf("\nInput a sentence: ");
        fgets(sentence, sizeof(sentence), stdin); strtok(sentence, "\r\n");

        printf("Input a keyword: ");
        scanf("%s",keyword); if (getchar() == '\r') getchar();
        keywordMasking(sentence, keyword);

        printf("The masked sentence is [%s]\n", sentence);
    }
    return 0;
}
