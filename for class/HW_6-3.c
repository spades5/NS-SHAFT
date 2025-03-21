#include <stdio.h>
int isPrime(int n) {
    if(n<=1){
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int repeat_time,num,j,k;
    printf("How many sets of test data: ");
    scanf("%d",&repeat_time);
    for(int i=1; i<=repeat_time; i++) {
        num = 0;
        while(num<6){
            printf("\nInput a number (>= 6): ");
            scanf("%d",&num);
        }
        for (j = 2; j < num; j++) {
            for (k = j; k < num; k++) {
                int remaining = num - j - k;
                if (remaining >= k && isPrime(remaining) && isPrime(j) && isPrime(k)) {

                    int a = remaining, b = j, c = k;

                    if (a > b) { int temp = a; a = b; b = temp; }
                    if (b > c) { int temp = b; b = c; c = temp; }
                    if (a > b) { int temp = a; a = b; b = temp; }
                    printf("%d = %d + %d + %d\n", num, a, b, c);
                }
            }
        }
    }

    return 0;
}
