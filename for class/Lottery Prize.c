#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffling(int a[], int N) //¬~¼Æ¦r(«e¸m)
{
    for(int i = N - 1; i > 0; i--)
    {
        int k = rand() % (i + 1);
        int temp = a[k];
        a[k] = a[i];
        a[i] = temp;
    }
}

int checkPrize(int ticket[], int firstPrize[], int special){
    int matched = 0;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (ticket[i] == firstPrize[j])
            {
                matched++;
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        if (ticket[i] == special)
        {
            return 8;
        }
    }
    if (matched == 6) return 7;  //First
    if (matched == 5) return 6;  //Second
    if (matched == 4) return 5;  //Third
    if (matched == 3) return 4;  //Fourth
    if (matched == 2) return 3;  //Fifth
    if (matched == 1) return 2;  //Sixth

    return 0;  // no prize
}

int main() {
    srand((unsigned)time(NULL));

    char *prizeName[9] = {"", "General", "Seventh", "Sixth", "Fifth", "Fourth", "Third", "Second", "First"};
    int prize[9] = {0,400,400,1000,1286,9781,32705,1569878,19100192};
    int first[6], ticket[6], special, i;

    printf("Input the first-prize numbers: ");
    for (i = 0; i < 6; i++) {
        scanf("%d", &first[i]);
    }

    printf("Input the special number: ");
    scanf("%d", &special);

    printf("Input the numbers on the lottery ticket: ");
    for (i = 0; i < 6; i++) {
        scanf("%d", &ticket[i]);
    }

    int a[48];
    for (i = 0; i < 48; i++) {
        a[i] = i + 1;
    }

    printf("\n[Random simulation for 5 times]\n");

    for (int k = 1; k <= 5; k++) {
        shuffling(a, 48);

        printf("The first-prize numbers are ");
        for (i = 0; i < 6; i++) {
            first[i] = a[i];
            printf("%d ", first[i]);
        }

        special = a[6];
        printf("\nThe special number is: %d\n", special);

        int b[48];
        for (i = 0; i < 48; i++) {
            b[i] = i + 1;
        }
        shuffling(b, 48);

        printf("Your ticket numbers are ");
        for (i = 0; i < 6; i++) {
            ticket[i] = b[i + 7];
            printf("%d ", ticket[i]);
        }
        printf("\n");

        int prizeCode = checkPrize(ticket, first, special);
        if (prizeCode > 0)
            printf("You have won the %s Prize which is NT$%d!!\n", prizeName[prizeCode], prize[prizeCode]);
        else
            printf("You did not win any prize.\n");
        printf("\n");
    }

    return 0;
}

