// WAP to sort the array elements using Pointer.
#include <stdio.h>

void main()
{
    int n, temp;

    printf("ENTER THE ARRAY SIZE : ");
    scanf("%d", &n);

    int arry[n];
    int *a = arry;

    for (int i = 0; i < n; i++)
    {
        printf("ENTER THE ARRAY ELEMENT : ");
        scanf("%d", (a + i));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(a + i) >= *(a + j))
            {
                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf(" %d ", *(a + i));
    }
}