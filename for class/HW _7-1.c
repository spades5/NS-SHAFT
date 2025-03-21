#include <stdio.h>

int main()
{
    int data,interval;
    unsigned long long int large_integer;
    printf("How many sets of test data: ");
    scanf("%d",&data);

    for(int i=1;i<=data;i++){
        printf("\nPlease input a large integer: ");
        scanf("%lld",&large_integer);
        printf("Please input an interval: ");
        scanf("%d",&interval);

        printf("Your input is [%lld]\n",large_integer);
        printf("Its next 10 numbers by adding %d are: \n",interval);

        for(int i=1;i<=10;i++){
            large_integer +=interval;
            printf("%lld\n",large_integer);
        }
        printf("Over!!\n");
    }
    return 0;
}
