// 17. Write a program to calculate sum of numbers from m to n.

#include <stdio.h>
int main()
{
    int i, j, sum = 0, m, n;

    printf("ENTER THE ARRAY SIZE :");
    scanf("%d", &j);

    printf("ENTER THE STARTING NUMBER :");
    scanf("%d", &m);
    printf("ENTER THE STOP NUMBER :");
    scanf("%d", &n);
    int array[j];

    for (i = 0; i < j; i++)
    {
        printf("ENTER THE ARRAY ELEMENT : ");
        scanf("%d", &array[i]);
    }

    for (i = m; i <= n; i++)
    {
        sum = sum + array[i];
    }

    printf("SUM = %d", sum);
}