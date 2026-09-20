// WAP to calculate the sum of n numbers using Pointer.
#include <stdio.h>

void main()
{
    int n, sum = 0;

    printf("ENTER THE ARRAY SIZE : ");
    scanf("%d", &n);

    int arry[n];
    int *a = arry;

    for (int i = 0; i < n; i++)
    {
        printf("ENTER THE ARRAY SIZE : ");
        scanf("%d", (a + i));
    }

    for (int i = 0; i < n; i++)
    {
        sum = sum + *(a + i);
    }

    printf("sum =  %d ", sum);
}