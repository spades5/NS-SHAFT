#include <stdio.h>
#include <string.h>
void delSpace(char str[]){
    // Step 1. Remove the trailing space
    char *p = str;
    char *q = str + strlen(str) - 1;

    while(p <= q && *q==' '){
        *q='\0';
        q--;
    }

    // Step 2. Remove the leading space
    q=str; //把q移到最前面
    while(*q && *q==' '){
        q++;
    }

    // Step 3. Copy characters and remove redundant space
    while (*q) { //當判斷值非'\0'繼續執行
        if (*q != ' ' || (p > str && *(p - 1) != ' ')) {
            *p++ = *q;
        }
        q++;
    }
    *p = '\0';
}

int main() {
    char str1[] = "Test    string    1";
    char str2[] = "   Test string    2   ";
    char str3[] = "    ";
    printf("Before:\t[%s]\n\t[%s]\n\t[%s]\n", str1, str2, str3);

    delSpace(str1);
    delSpace(str2);
    delSpace(str3);

    printf("\nAfter:\t[%s]\n\t[%s]\n\t[%s]\n", str1, str2, str3);
    return 0;
}
