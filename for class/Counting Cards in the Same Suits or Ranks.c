#include <stdio.h>

int suitCounting(int card[], int suit[],int numCards) { // to count the number of cards in each suit, i.e. ♣♦♥♠
    for (int i = 0; i < 4; i++) { //初始化
        suit[i] = 0;
    }

    for (int i=0;i<numCards;i++) {
    int suitIndex = card[i] / 13; //0: ♣, 1: ♦, 2: ♥, 3: ♠
    suit[suitIndex]++;
    }
    printf("♣(%d) ♦(%d) ♥(%d) ♠(%d)\n",suit[0],suit[1],suit[2],suit[3]);
}

int rankCounting(int card[],int rank[],int numCards){ //to count the number of cards in each rank, i.e. for A, 2, 3, ... , J, Q, K, and A again
    for (int i = 0; i < 13; i++) { //初始化
    rank[i] = 0;
    }
    for (int i=0;i<numCards;i++) {
    int rankIndex = card[i] % 13;
    rank[rankIndex]++;
    }
    printf("2(%d) 3(%d) 4(%d) 5(%d) 6(%d) 7(%d) 8(%d) 9(%d) 10(%d) J(%d) Q(%d) K(%d) A(%d)\n",rank[0], rank[1], rank[2], rank[3], rank[4], rank[5], rank[6], rank[7],rank[8], rank[9], rank[10], rank[11], rank[12]);
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
    system("chcp 65001");
    int card[52] = {0};
    for (int i = 0; i < 52; i++) {
        card[i] = i;
    }

    for(int i=1;i<=10;i++){
        printf("Input cards: ");
        for (int i=0;i<5;i++) {
            scanf("%d", &card[i]);
            printCard(card[i]);
        }
        printf("have \n");
        suitCounting(card,suitCount,5);
        rankCounting(card,rankCount,5);
        printf("\n");
    }

    return 0;
}
