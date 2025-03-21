#include <stdio.h>

int fa(int n);
int fb(int n);

int main(){
    int rptime,upper;

    printf("How many sets of test data: ");
    scanf("%d",&rptime);

    for(int i=1;i<=rptime;i++){
        printf("\nWhat is the upper limit? ");
        scanf("%d",&upper);

        int n=1;
        while(fa(n)<upper || fb(n)<upper){
            fa(n);
            fb(n);
            printf("n = %d, (a, b) = (%d, %d)\n",n,fa(n),fb(n));
            n++;
        }
    }
}

int fa(int n){
    if (n == 1){
        return 1;
    }
    return fa(n-1)+2*fb(n-1)+1;
}

int fb(int n){
    if (n == 1){
        return 1;
    }
    return 3*fa(n -1)-fb(n-1)+1;
}
