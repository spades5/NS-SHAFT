#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffling(int card[], int N)
{
    srand( (unsigned)time(NULL) );
    for(int i=N-1;i>0;i--) //反向遞迴，每次迴圈代表我們會選擇當前範圍內的一張卡片，並將其與某個隨機選擇的卡片交換
    {
        int k = rand() % (i + 1);//通過對 rand() 的結果取餘數，將隨機數限制在 0 到 i 之間，這樣每次隨機選擇的索引範圍會隨著迴圈的進行逐漸縮小。 (i+1)的+1是確保card[0]、card[1]有交換到
        int temp = card[k];//card[k] 隨機挑出來的卡
        card[k] = card[i];//card[i] 當前的卡
        card[i] = temp;
    }
}

int main()
{
    char *tarot[22] = {"The Fool", "The Magician", "The High Priestess", "The Empress", "The Emperor", "The Hierophant", "The Lovers", "The Chariot", "Justice", "The Hermit", "Wheel of Fortune", "Strength", "The Hanged Man", "Death", "Temperance", "The Devil", "The Tower", "The Star", "The Moon", "The Sun", "Judgement", "The World"};
    int card[22];
    int i;

    for (int i = 0; i < 22; i++)
    {
        card[i] = i;
    }

    shuffling(card, 22);

    for (int i=0;i<22;i++)
    {
        printf("[%02d]%s\n", card[i], tarot[card[i]]);
    }
    return 0;
}
