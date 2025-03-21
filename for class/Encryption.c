#include <stdio.h>

char Upper[26]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char Lower[26]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char num[10]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{
    char name=getchar();
    while (name != '\r' && name != '\n') {
        int index = name-'A';
        if(name>='A' && name<='Z'){
            char nextUpper = Upper[(index + 2) % 26];
            printf("%c", nextUpper);
        }
        else if(name>='a' && name<='z'){
            char nextLower = Lower[(index + 2) % 26];
            printf("%c", nextLower);
        }
        else if(name>='0' && name<='9'){
            int index = name-'0';
            char nextNum = num[(index + 9) % 10];
            printf("%c",nextNum);
        }
        else{
            printf("%c",name);
        }
        name = getchar();
    }
    return 0;
}
