#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
    return (*(int*)a-*(int*)b);
}

double Gini_Coefficient(int *incomes, int income_len){
    int *dp=(int*)malloc((income_len+1)*sizeof(int));
    dp[0]=0;

    qsort(incomes,income_len,sizeof(int),compare);

    for (int i=1;i<=income_len;i++){
        dp[i]=dp[i-1]+incomes[i-1];
    }

    int totalIncome=dp[income_len];
    double GiniSum=0;

    for (int i=1;i<=income_len;i++){
        GiniSum += dp[i]*(income_len-i);
    }

    double gini=(2.0*GiniSum)/(income_len*totalIncome)-(income_len+1.0)/income_len;

    free(dp);
    return gini;
}

int main() {
    printf("how many income? : ");
    int income_len;
    scanf("%d",&income_len);

    int incomes[income_len];
    for(int i=0;i<income_len;i++){
        scanf("%d",&incomes[i]);
    }

    printf("Gini Coefficient: %.4f\n",Gini_Coefficient(incomes,income_len));
    return 0;
}
