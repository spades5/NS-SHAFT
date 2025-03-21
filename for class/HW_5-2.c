#include <stdio.h>

int main()
{
    int test_data, i, j, k, l, m, n, p;
    printf("A is a matrix with m x n elements and\nB is a matrix with n x p elements.\n");

    printf("\nHow many sets of test data: ");
    scanf("%d", &test_data);

    for(i = 1; i <= test_data; i++)
    {
        printf("\nInput values of m, n, p: ");//A[m]*[n], B[n]*[p], C[m][p]
        scanf("%d %d %d", &m, &n, &p);

        int A[m][n], B[n][p], C[m][p];

        // 輸入A[m]*[n]
        printf("Input numbers in matrix A: ");
        for(j = 0; j < m; j++)
        {
            for(k = 0; k < n; k++)
            {
                scanf("%d", &A[j][k]);
            }
        }

        // 輸入B[n]*[p]
        printf("Input numbers in matrix B: ");
        for(j = 0; j < n; j++)
        {
            for(k = 0; k < p; k++)
            {
                scanf("%d", &B[j][k]);
            }
        }

        // C[m][p] 初始化
        for(j = 0; j < m; j++)
        {
            for(k = 0; k < p; k++)
            {
                C[j][k] = 0;
            }
        }

        // 計算 C = A * B
        for(j = 0; j < m; j++)
        {
            for(k = 0; k < p; k++)
            {
                for(l = 0; l < n; l++)
                {
                    C[j][k] += A[j][l] * B[l][k];
                }
            }
        }

        // 輸出 C 矩陣
        printf("Numbers in matrix C are:\n");
        printf("{{");
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < p; k++)
            {
                printf("%d", C[j][k]);
                if (k < p - 1) {
                    printf(", ");
                }
            }
            if (j < m - 1) {
                printf("},\n{");
            }
        }
        printf("}}\n");
    }

    return 0;
}
