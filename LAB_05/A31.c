//  Read two 2x2 matrices and perform addition of matrices into third matrix and print it
#include <stdio.h>
int main()
{
    int m, n;

    printf("ENTER THE ROWS :");
    scanf("%d", &m);
    printf("ENTER THE COLUMNS :");
    scanf("%d", &n);

    int arr1[m][n], arr2[m][n], arr3[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("ENTER THE FIRST ARRAY ELEMENT : ");
            scanf("%d", &arr1[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("ENTER THE SECOND ARRAY ELEMENT : ");
            scanf("%d", &arr2[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}