#include <stdio.h>

void timeAdd(int *h1,int *m1,int *s1,int *h2,int *m2,int *s2){
    int sec= *s1+*s2;
    if(sec>=60){
        *s1=sec%60;
        *m1+=sec/60;
    }
    else{
        *s1=sec;
    }

    int min= *m1+*m2;
    if(min>=60){
        *m1=min%60;
        *h1+=min/60;
    }
    else{
        *m1=min;
    }

    *h1 +=*h2;
}

int main() {
    int h1, m1, s1, h2, m2, s2;

    h1 = 3; m1 = 18; s1 = 22; h2 = 5; m2 = 22; s2 = 7;
    printf("%d 小時 %d 分鐘 %d 秒鐘 加上 %d 小時 %d 分鐘 %d 秒鐘\n", h1, m1, s1, h2, m2, s2);
    timeAdd(&h1,&m1,&s1,&h2,&m2,&s2);
    printf("\t結果等於 %d 小時 %d 分鐘 %d 秒鐘。\n", h1, m1, s1);

    h1 = 3; m1 = 48; s1 = 32; h2 = 5; m2 = 22; s2 = 57;
    printf("%d 小時 %d 分鐘 %d 秒鐘 加上 %d 小時 %d 分鐘 %d 秒鐘\n", h1, m1, s1, h2, m2, s2);
    timeAdd(&h1,&m1,&s1,&h2,&m2,&s2);
    printf("\t結果等於 %d 小時 %d 分鐘 %d 秒鐘。\n", h1, m1, s1);

    h1 = 3; m1 = 88; s1 = 92; h2 = 5; m2 = 122; s2 = 257;
    printf("%d 小時 %d 分鐘 %d 秒鐘 加上 %d 小時 %d 分鐘 %d 秒鐘\n", h1, m1, s1, h2, m2, s2);
    timeAdd(&h1,&m1,&s1,&h2,&m2,&s2);
    printf("\t結果等於 %d 小時 %d 分鐘 %d 秒鐘。\n", h1, m1, s1);

    return 0;
}
