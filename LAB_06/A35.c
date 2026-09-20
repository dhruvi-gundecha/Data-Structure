// WAP to get and print the array elements using Pointer.
#include <stdio.h>

void main()
{
    int n;

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
        printf(" %d ", *(a + i));
    }
}