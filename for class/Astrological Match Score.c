#include <stdio.h>

void getDate(int *year,int *month,int *day){
    while (scanf("%d/%d/%d",year,month,day)!= 3||notLegalDate(*year,*month,*day)){
        printf("這不是合法的日期。\n");
        while (getchar() != '\n');
    }
}

int getZodiacCode(int year, int month, int day) {
    int beginningDay[12] = {20, 19, 21, 20, 21, 21, 23, 23, 23, 23, 22, 22};
     if (day < beginningDay[month - 1]) {
        return (month-2+12) % 12;
    } else {
        return month - 1;
    }
}

int isLeapYear(int year){
    if(year%4==0 && year%100 != 0 || year%400 == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int notLegalDate(int year,int month,int day){
    if(year<1 || month <1 || month>12 || day<1){
        return 1;
    }

    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    if (day > daysInMonth[month - 1]) {
        return 1;
    }
    return 0;
}

int main()
{
    int matchScore[12][12]={90, 75, 82, 47, 94, 65, 85, 70, 99, 58, 88, 79,
                            68, 88, 72, 75, 45, 97, 57, 78, 61, 93, 66, 81,
                            79, 76, 89, 71, 81, 57, 93, 69, 86, 64, 99, 48,
                            52, 82, 78, 89, 61, 84, 66, 92, 70, 87, 74, 97,
                            97, 56, 79, 69, 87, 72, 81, 45, 92, 77, 84, 62,
                            61, 91, 76, 88, 66, 89, 49, 81, 72, 95, 55, 84,
                            85, 74, 98, 58, 88, 77, 90, 71, 80, 47, 95, 64,
                            60, 80, 68, 97, 65, 84, 73, 87, 47, 76, 57, 92,
                            92, 70, 81, 65, 98, 58, 86, 68, 89, 75, 78, 44,
                            43, 97, 70, 80, 59, 92, 51, 85, 64, 88, 74, 77,
                            72, 41, 91, 58, 78, 64, 96, 51, 82, 69, 87, 60,
                            71, 78, 46, 93, 61, 65, 74, 99, 54, 82, 69, 88};

    char *zodiacName[12] = {"水瓶座", "雙魚座","牡羊座", "金牛座", "雙子座", "巨蟹座", "獅子座", "處女座", "天秤座", "天蠍座", "射手座", "摩羯座"};
    int boyYear,boyMonth,boyDay;
    int girlYear,girlMonth,girlDay;

    printf("請輸入男生的生日。\n"); getDate(&boyYear,&boyMonth,&boyDay);
    printf("請輸入女生的生日。\n"); getDate(&girlYear,&girlMonth,&girlDay);

    int boyCode = getZodiacCode(boyYear,boyMonth,boyDay);
    int girlCode = getZodiacCode(girlYear,girlMonth,girlDay);

    printf("男生是%s，女生是%s\n", zodiacName[boyCode],zodiacName[girlCode]);
    printf("兩人的速配指數是：%d！\n", matchScore[girlCode][boyCode]);
}
