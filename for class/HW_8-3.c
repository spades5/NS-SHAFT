#include <stdio.h>

void pay_amount(int dollars, int *fifties, int *tens, int *fives, int *ones){

    *fifties=dollars/50;
    dollars%=50;

    *tens=dollars/10;
    dollars%=10;

    *fives=dollars/5;
    dollars%=5;

    *ones=dollars;
}

int main() {
    int price, num1, num5, num10, num50, ti, repeatTimes;

    printf("How many sets of test data:");
    scanf("%d",&repeatTimes);

    for (ti = 0; ti < repeatTimes; ti++) {
        printf("\nPlease enter the price: ");
        scanf("%d", &price);
        pay_amount(price,&num50,&num10,&num5,&num1);
        printf("You need %d coin(s), including:\n", num50+num10+num5+num1);
        printf("\t$50: %d\n", num50);
        printf("\t$10: %d\n", num10);
        printf("\t$5: %d\n", num5);
        printf("\t$1: %d\n", num1);
    }
    return 0;
}
