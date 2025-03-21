#include <stdio.h>
#include <string.h>

void swap(int *p, int *q) {
    int temp=*p;
    *p=*q;
    *q=temp;
}

void strangeFunc(int a[], int size){
    int*p = a;
    int*q = a+size-1;

    while (p < q) {
        while (p<q && *p>= 0) {  // 移動 p 向右直到遇到負數或超過 q
            p++;
        }
        while (p<q && *q>= 0) { // 移動 q 向左直到遇到負數或超過 p
            q--;
        }
        if (p<q) { // 若 p 和 q 都指向負數，則交換元素並繼續向內移動
            swap(p,q);
            p++;
            q--;
        }
    }
}

void printword(int a[], int size){
    printf("{");
    for(int i=0;i<size;i++){
        printf("%d",a[i]);
        if (i < size - 1) printf(", ");
    }
    printf("}\n");
}

int main() {
    int a[13] = {65, 0, -5, -22, 9, 231, 43, -7, 11, -65, 0, -18, 65};
    int b[12] = {65, 0, -5, -22, 9, 231, 43, -7, 11, 65, 0, -18};
    int c[12] = {65, 0, 5, 22, 9, 231, 43, 7, 11, 65, 0, 18};

    printf("原先 a[] 為 ");
    printword(a,13);

    printf("原先 b[] 為 ");
    printword(b,12);

    printf("原先 c[] 為 ");
    printword(c,12);
    printf("\n");

    strangeFunc(a,13);
    strangeFunc(b,12);
    strangeFunc(c,12);

    printf("後來 a[] 為 ");
    printword(a,13);

    printf("後來 b[] 為 ");
    printword(b,12);

    printf("後來 c[] 為 ");
    printword(c,12);

    return 0;
}
