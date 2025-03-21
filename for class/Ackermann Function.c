#include <stdio.h>
int Ackermann(int m,int n){
    if(m==0){
        return n+1;
    }
    if(m>0 && n==0){
        return Ackermann(m-1,1);
    }
    if(m>0 && n>0){
        return Ackermann(m-1,Ackermann(m,n-1));
    }
}

int main()
{
    for(int i=0;i<=3;i++){
        for(int j=0;j<=9;j++){
            printf("A(%d, %d) = %d\n",i,j,Ackermann(i,j));
        }
    }

    return 0;
}
