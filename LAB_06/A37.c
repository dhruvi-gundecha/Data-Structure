// WAP to find the largest element in the array using Pointer.
#include <stdio.h>

void main()
{
    int n, sum = 0, large;

    printf("ENTER THE ARRAY SIZE : ");
    scanf("%d", &n);

    int arry[n];
    int *a = arry;

    for (int i = 0; i < n; i++)
    {
        printf("ENTER THE ARRAY ELEMENT : ");
        scanf("%d", (a + i));
    }
    large = arry[0];

    for (int i = 0; i < n; i++)
    {
        if (large <= *(a + i))
        {
            large = *(a + i);
        }
    }

    printf("largest =  %d ", large);
}