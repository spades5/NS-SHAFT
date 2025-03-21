#include <stdio.h>
#include <string.h>

void deleteWord(char *sent,int k){
    char *p=sent;
    char *strEndp=sent+strlen(sent);

    while(p<strEndp){
        printf("[%s]\n",p);
        p +=k;
    }
}

int main(){
    int rptime;

    printf("How many sets of test data: ");
    scanf("%d",&rptime); if (getchar() == '\r') getchar();

    for(int i=1;i<=rptime;i++){
        int k;
        char sent[1000];
        printf("\nInput a string: ");
        fgets(sent,sizeof(sent),stdin); strtok(sent, "\r\n");
        printf("Skipping = ");
        scanf("%d",&k); if (getchar() == '\r') getchar();

        deleteWord(sent,k);
    }
    return 0;
}
