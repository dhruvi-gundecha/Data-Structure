// 16. Write a program to read and display n numbers using an array.

#include <stdio.h>
int main()
{
    int i, n;

    printf("ENTER THE ARRAY SIZE :");
    scanf("%d", &n);

    int array[n];

    for (i = 0; i < n; i++)
    {
        printf("ENTER THE ARRAY ELEMENT : ");
        scanf("%d", &array[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("  %d  ", array[i]);
    }
}