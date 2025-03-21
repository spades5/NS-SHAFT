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
int isInvalidDate(int year, int month, int day)
{
        if (month < 1 || month > 12) {
        return 1;
    }
    int daysInMonth;
    if (month == 2) {
        if (isLeapYear(year)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth= 30;
    } else {
        daysInMonth= 31;
    }

    if (day < 1 || day > daysInMonth) {
        return 1;
    }

    return 0;

}


int main() {
    int ti, repeatTimes, year, month, day;
    printf("How many sets of test data: ");
    scanf("%d",&repeatTimes);
    for (ti = 0; ti < repeatTimes; ti++)
    {
        printf("\nInput a date (year/month/day): ");
        scanf("%d/%d/%d", &year, &month, &day);
        printf("%d/%d/%d %s a valid date.\n", year, month, day, isInvalidDate(year, month, day) ? "is not" : "is");
    }
    return 0;
}
