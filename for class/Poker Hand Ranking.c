#include <stdio.h>

void suitCounting(int card[], int suit[],int numCards) { // to count the number of cards in each suit, i.e. ♣♦♥♠
    for (int i = 0; i < 4; i++) { //初始化
        suit[i] = 0;
    }

    for (int i=0;i<numCards;i++) {
    int suitIndex = card[i] / 13; //0: ♣, 1: ♦, 2: ♥, 3: ♠
    suit[suitIndex]++;
    }
}

void rankCounting(int card[],int rank[],int numCards){ //to count the number of cards in each rank, i.e. for A, 2, 3, ... , J, Q, K, and A again
    for (int i = 0; i < 13; i++) { //初始化
    rank[i] = 0;
    }
    for (int i=0;i<numCards;i++) {
    int rankIndex = (card[i] % 13)+1;//0: 2, 1: 3, 2: 4, 3: 5.....
    rank[rankIndex-1]++;
    }
}

void countSloting(int countSlot[],int rank[],int numRanks){ //to count values in rankCount[]
    for (int i = 0; i < 5; i++) { //初始化
        countSlot[i]=0;
    }
    for(int i=0; i<numRanks;i++){
        if (rank[i]>0 && rank[i]<5){//統計四張牌(四牌數字組合)
            countSlot[rank[i]]++;//countSlot[2]=兩對,countSlot[3]=三條,countSlot[4]=四條
        }
    }
}

int checkFlush(int suitCount[]){ //確認同花
    for (int i = 0; i < 4; i++) {
        if (suitCount[i] >= 5) {
            return 1;
        }
    }
    return 0;
}

int checkStraight(int rankCount[]) {
    int counter = 0;
    for (int i = 0; i < 13; i++) { //透過迴圈(連續判斷)，累積5次(counter),判斷順子
        if (rankCount[i] > 0) {
            counter++;
            if (counter == 5) {
                return 1;
            }
        }
    else {
            counter=0;
        }
    }

    if (rankCount[12] > 0 && rankCount[0] > 0 && rankCount[1] > 0 && rankCount[2] > 0 && rankCount[3] > 0) { //A 2 3 4 5
        return 1;
    }
    return 0;
}


void printCard(int id) { // print card
    char* suitCount[4] = {"♣", "♦", "♥", "♠"};
    char* highRank[4] = {"J", "Q", "K", "A"};
    int suit = id / 13; // 花色
    int rank = id % 13; // 數字

    printf("%s", suitCount[suit]);
    if (rank < 9) {
        printf("%d ", rank + 2);
    } else {
        printf("%s ", highRank[rank - 9]);
    }
}

int main()
{
    int suitCount[4]={0};
    int rankCount[13]={0};
    int countSlot[5]={0};
    system("chcp 65001");

    printf("♣6 ♣K ♣A ♥4 ♥5 無\n♣5 ♣8 ♦3 ♦8 ♥3 兩對\n♣J ♦J ♥J ♠4 ♠J 四條\n♥8 ♥9 ♥10 ♥J ♥Q 同花順\n♣K ♣A ♦2 ♦3 ♦4 無\n♣8 ♣10 ♦5 ♥10 ♠J 一對\n♣4 ♣A ♦A ♥7 ♠A 三條\n♦4 ♦5 ♦8 ♦10 ♦Q 同花\n♣4 ♦5 ♥3 ♥7 ♠6 順\n♦2 ♦10 ♥2 ♠2 ♠10 葫蘆\n\n");

    //輸入牌
    printf("請輸入 5 張牌：");
    int pocker[5];
    for(int i=0;i<5;i++){
        scanf("%d",&pocker[i]);
        printCard(pocker[i]);
    }

    //統計花色、數字
    suitCounting(pocker,suitCount,5);
    rankCounting(pocker,rankCount,5);
    countSloting(countSlot, rankCount, 13);

    int isFlush = checkFlush(suitCount);
    int isStraight = checkStraight(rankCount);

    if (isFlush) {
        if (isStraight) {
            printf("同花順");
        } else {
            printf("同花");
        }
    }
    else if (isStraight) {
        printf("順");
    } else if (countSlot[4] == 1) {
        printf("四條");
    } else if (countSlot[3] == 1 && countSlot[2] == 1) {
        printf("葫蘆");
    } else if (countSlot[3] == 1) {
        printf("三條");
    } else if (countSlot[2] == 2) {
        printf("兩對");
    } else if (countSlot[2] == 1) {
        printf("一對");
    } else {
        printf("無");
    }
    return 0;
}
