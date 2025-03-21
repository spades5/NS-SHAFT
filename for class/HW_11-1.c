#include <stdio.h>
#include <string.h>

typedef struct{
    int year, month, day;
    } DateData;

void getdate(DateData *date) {
    scanf("%d/%d/%d", &date->year, &date->month, &date->day); if (getchar() == '\r') getchar();
}

int datecmp(DateData date1, DateData date2) {
    if (date1.year > date2.year) return 1;
    if (date1.year < date2.year) return -1;

    if (date1.month > date2.month) return 1;
    if (date1.month < date2.month) return -1;

    if (date1.day > date2.day) return 1;
    if (date1.day < date2.day) return -1;

    return 0;
}


int main() {
    DateData date1, date2;
    int ti, repeatTimes;
    printf("How many sets of test data: ");
    scanf("%d",&repeatTimes); if (getchar() == '\r') getchar();


    for (ti = 0; ti < repeatTimes; ti++) {
        printf("\nInput the first date (year/month/day): ");
        getdate(&date1);

        printf("Input the second date (year/month/day): ");
        getdate(&date2);

         int result = datecmp(date1, date2);

        if (result==1) printf("%d-%02d-%02d > %d-%02d-%02d\n", date1.year, date1.month, date1.day, date2.year, date2.month, date2.day);
        if (result==-1) printf("%d-%02d-%02d < %d-%02d-%02d\n", date1.year, date1.month, date1.day, date2.year, date2.month, date2.day);
        if (result==0) printf("%d-%02d-%02d = %d-%02d-%02d\n", date1.year, date1.month, date1.day, date2.year, date2.month, date2.day);
    }
    return 0;
}
