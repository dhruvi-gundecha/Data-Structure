// 18. Write a program to calculate average of first n numbers.

#include <stdio.h>
int main()
{
    int i, n;
    float ave, sum = 0.0;
    printf("ENTER THE ARRAY SIZE :");
    scanf("%d", &n);

    int array[n];

    for (i = 0; i < n; i++)
    {
        printf("ENTER THE ARRAY ELEMENT: ");
        scanf("%d", &array[i]);
    }

    for (i = 0; i < n; i++)
    {
        sum = sum + array[i];
    }

    ave = sum / n;

    printf(" AVERAGE =  %.2f  ", ave);
    return 0;
}