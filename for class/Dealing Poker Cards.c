#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printCard(int id) {
    char* suitSymbol[4] = {"♣", "♦", "♥", "♠"};
    char* highRank[4] = {"J", "Q", "K", "A"};
    int suit = id / 13; // 花色
    int rank = id % 13; // 數字

    printf("%s", suitSymbol[suit]);
    if (rank < 9) {
        printf("%d ", rank + 2);
    } else {
        printf("%s ", highRank[rank - 9]);
    }
}

void shuffling(int card[], int N) {
    srand((unsigned)time(NULL));
    for (int i = N - 1; i > 0; i--) {
        int k = rand() % (i + 1);
        int temp = card[k];
        card[k] = card[i];
        card[i] = temp;
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    system("chcp 65001");
    int card[52] = {0};
    for (int i = 0; i < 52; i++) {
        card[i] = i;
    }

    shuffling(card, 52);

    int id = 0;
    while (1) {
        printf("Input a card ID: ");
        scanf("%d", &id);
        if (id == -1) break;
        printCard(id);
        putchar('\n');
    }
    printf("\n");

    for (int j = 1; j <= 4; j++) {
        int playerCards[13];
        printf("Player %d: ", j);

        for (int k = 0; k < 13; k++) {
            playerCards[k] = card[(j - 1) * 13 + k];
        }

        qsort(playerCards, 13, sizeof(int), compare);

        for (int k = 0; k < 13; k++) {
            printCard(playerCards[k]);
        }
        printf("\n");
    }

    return 0;
}
