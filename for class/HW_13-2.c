#include <stdio.h>

int main(){
    int rptime,num,position;

    printf("How many sets of test data: ");
    scanf("%d",&rptime);

    for(int i=1;i<=rptime;i++){
        printf("\nNumber: ");
        scanf("%d",&num);
        printf("Position: ");
        scanf("%d",&position);

        num >>= position;

        if(num & 1){
            printf("It is a 1 bit.\n");
        }
        else{
            printf("It is a 0 bit.\n");
        }
    }

    return 0;
}
