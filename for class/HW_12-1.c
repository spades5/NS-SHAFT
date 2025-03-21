#include <stdio.h>

int GCD(int a,int b){
    if(b!=0){
        printf("GCD(%d, %d) =\n",a,b);
        return GCD(b, a%b);
    }
    printf("GCD(%d, %d) = %d\n",a,b,a);
    return a;
}

int main(){
    int rptime,a,b;

    printf("How many sets of test data: ");
    scanf("%d",&rptime);

    for(int i=1;i<=rptime;i++){
        printf("\na = ");
        scanf("%d",&a);
        printf("b = ");
        scanf("%d",&b);
        GCD(a,b);
    }
    return 0;
}
