#include <stdio.h>
int isLeapYear(int year)
{
    if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main() {
    int ti, repeatTimes, year;
    printf("How many sets of test data: ");
    scanf("%d",&repeatTimes);
    for (ti = 0; ti < repeatTimes; ti++)
    {
        printf("\nInput a year: ");
        scanf("%d", &year);
        printf("%d %s a leap year.\n", year, isLeapYear(year) ? "is" : "is not");
    }
    return 0;
}
