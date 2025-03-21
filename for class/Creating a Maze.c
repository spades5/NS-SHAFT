#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define width 10
#define height 5
char maze[2*height+1][2*width+1];

void initMaze(){
    for (int i=0;i<2*height+ 1;i++) {
        for (int j=0;j<2*width+1;j++) {
            if (i%2==1 && j%2==1) {
            //Cells with both odd coordinates are set to be '?' (path candidates but undecided).
                maze[i][j] = '?';
            } else {
            //All cells are set to be '#' (thus become walls).
                maze[i][j] = '#';
            }
        }
    }
    //he two cells in the upper-left corner are set to be ' ' (thus becomes the entry).
     maze[2][1]=' ';
     maze[2][2]=' ';
}

void createMaze(int x, int y) {
    //Note that choosing an adjacent cell can be done by declaring offset arrays
    int offsetX[4]={-2,2,0,0};
    int offsetY[4]={0,0,-2,2};
    int visited[4]={0,0,0,0};//紀錄已選擇位置
    int attempts=0;//紀錄方向嘗試次數

    while (attempts<4) {
        int direction=rand()%4;

        //如果這方向去過了(1)，跳過
        if (visited[direction]) {
            continue;
        }

        //記錄去過了
        visited[direction]=1;
        attempts++;

        int nx=x+offsetX[direction];// up = (x-2, y); down = (x+2, y)
        int ny=y+offsetY[direction];//left = (x, y-2); right = (x, y+2)

        if (nx>0 && nx<2*height && ny>0 && ny<2*width && maze[nx][ny]=='?') {
            maze[(x+nx)/2][(y+ny)/2]=' ';
            maze[nx][ny]=' ';

            //嘗試從當前位置 (x, y) 隨機選擇一個方向前進，並尋找通向未訪問格子的路徑。
            createMaze(nx, ny);

            //計數器歸零
            for (int i=0; i<4;i++){
                visited[i] = 0;
            }
            attempts = 0;
        }
    }
}

void printMaze(){
    for (int i=0;i<2*height+1;i++) {
        for (int j=0; j<2*width+1;j++) {
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand((unsigned int)time(NULL));
    initMaze();
    createMaze(1, 1);
    printMaze();
    return 0;
}
