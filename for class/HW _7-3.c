#include <stdio.h>

int mya(int j,int m,int n,int s,int t){
    if (j == 0){
        return 0;
    }
    else if (j % 2 != 0){
        return m*mya(j-1, m, n, s, t)+n;
    }
    else{
        return s*mya(j-1, m, n, s, t)+t;
    }
}

int main()
{
    int data,m,n,s,t,final_index;
    printf("How many sets of test data: ");
    scanf("%d",&data);

    for(int i=1;i<=data;i++){
        printf("\nm = ");
        scanf("%d",&m);
        printf("n = ");
        scanf("%d",&n);
        printf("s = ");
        scanf("%d",&s);
        printf("t = ");
        scanf("%d",&t);
        printf("Final index = ");
        scanf("%d",&final_index);
    for (int j=0;j<=final_index;j++) {
            int result = mya(j,m,n,s,t);
            printf("a_%d = %d\n",j,result);
        }
    }
    return 0;
}
