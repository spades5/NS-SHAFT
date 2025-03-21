#include <stdio.h>
int combination(int n,int k){
    if (k==0||k==n){
        return 1;
    }
    return combination(n-1, k-1)+combination(n-1,k);
}

int main()
{
    for(int i=1;i<=6;i++){
        for(int j=0;j<=i;j++){
            printf("C(%d, %d) = %d\n",i,j,combination(i,j));
        }
    }
    return 0;
}
