#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[4][8]={0};
void piceID_name(int pieceID) {
    if(pieceID==1 || pieceID==2 || pieceID==3 || pieceID==4 || pieceID ==5){
        printf("卒");
    }
    if(pieceID==6 || pieceID==7){
        printf("包");
    }
    if(pieceID==8 || pieceID==9){
        printf("馬");
    }
    if(pieceID==10 || pieceID==11){
        printf("車");
    }
    if(pieceID==12 || pieceID==13){
        printf("象");
    }
    if(pieceID==14 || pieceID==15){
        printf("士");
    }
    if(pieceID==16){
        printf("將");
    }

    if(pieceID==17 || pieceID==18 || pieceID==19 || pieceID==20 || pieceID ==21){
        printf("兵");
    }
    if(pieceID==22 || pieceID==23){
        printf("炮");
    }
    if(pieceID==24 || pieceID==25){
        printf("傌");
    }
    if(pieceID==26 || pieceID==27){
        printf("俥");
    }
    if(pieceID==28 || pieceID==29){
        printf("相");
    }
    if(pieceID==30 || pieceID==31){
        printf("仕");
    }
    if(pieceID==32){
        printf("帥");
    }
}

void gameInit(){
    int pieces[32] = {
    -16, -15, -14, -13, -12, -11, -10, -9,  // 黑棋
    -8, -7, -6, -5, -4, -3, -2, -1,
    -32, -31, -30, -29, -28, -27, -26, -25,  // 紅棋
    -24, -23, -22, -21, -20, -19, -18, -17
    };

    //洗牌演算法
    srand((unsigned)time(NULL));
    for(int i=31;i>0;i--)
    {
        int k = rand() % (i + 1);
        int temp = pieces[k];
        pieces[k] = pieces[i];
        pieces[i] = temp;
    }

    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = pieces[index++];
        }
    }
}

void printBoard() {
    //Print the coordinates directly
    printf("x\\y");
    for(int i=0;i<=7;i++){
        printf("%d",i);
    }
    printf("\n┌─┬─┬─┬─┬─┬─┬─┬─┐\n");
    //Use a loop to print grids in pairs: one for border lines and one for pieces
    for(int i=0;i<4;i++){
        printf("%d|", i);
        for (int j=0;j<8;j++){
            if (board[i][j]<0) {
                printf("●│");
            } else if (board[i][j]>0) {
                piceID_name(board[i][j]);;
            } else {
                printf("│");
            }
        }
        if(i==3) break;
        printf("\n ├─┼─┼─┼─┼─┼─┼─┼─┤\n");
    }
    printf("\n└─┴─┴─┴─┴─┴─┴─┴─┘");
}

int main() {
    srand((unsigned int)time(NULL));
    system("chcp 65001 & cls"); // (for Windows users) force the command window to show unicode characters

    gameInit();
    printBoard();
    return 0;
}
