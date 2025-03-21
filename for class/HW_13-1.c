#include <stdio.h>

int main(){
    int rptime,num;
    printf("How many sets of test data: ");
    scanf("%d",&rptime);

    for(int i=1;i<=rptime;i++){
        printf("\nInput: ");
        scanf("%d",&num);

        printf("The 1 bits are at: ");
        int position=0;
        while(num>0){
            if(num & 1){
                printf("%d ",position);
            }
            num >>= 1;
            position++;
        }
        printf("\n");
    }



    return 0;
}
