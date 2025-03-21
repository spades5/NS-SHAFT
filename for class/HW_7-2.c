#include <stdio.h>

int main()
{
    int data,base,number;
    printf("How many sets of test data: ");
    scanf("%d",&data);

    for(int i=1;i<=data;i++){
        printf("\nInput base: (1) decimal (2) octal (3) hexadecimal: ");
        scanf("%d",&base);

        //decimal
        if(base==1){
            printf("Input a number: ");
            scanf("%d",&number);
            printf("This number is\n");
            printf("%d in decimal\n",number);
            printf("%o in octal, and\n",number);
            printf("%x in hexadecimal.\n",number);
        }
        //octal
        if(base==2){
            printf("Input a number: ");
            scanf("%o",&number);
            printf("This number is\n");
            printf("%d in decimal\n",number);
            printf("%o in octal, and\n",number);
            printf("%x in hexadecimal.\n",number);
        }
        //hexadecimal
        if(base==3){
            printf("Input a number: ");
            scanf("%x",&number);
            printf("This number is\n");
            printf("%d in decimal\n",number);
            printf("%o in octal, and\n",number);
            printf("%x in hexadecimal.\n",number);
        }
    }
    return 0;
}
