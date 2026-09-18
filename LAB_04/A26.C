// 26. Write a program to insert a number in an array that is already sorted in an ascending order.

#include <stdio.h>
int main()
{
    int n, i, ins, loc = 0;

    printf("ENTER THE ARRAY SIZE : ");
    scanf("%d", &n);

    int array[n];

    for (i = 0; i < n; i++)
    {
        printf("ENTER THE ARRAY ELEMENT :");
        scanf("%d", &array[i]);
    }
    printf("ENTER THE NUMBER YOU WANT TO INSERT : ");
    scanf("%d", &ins);

    for (i = 0; i < n; i++)
    {
        if (array[i] <= ins && array[i + 1] >= ins)
        {
            loc = i + 1;
        }
    }
    n++;
    for (int i = n; i > loc; i--)
    {
        array[i] = array[i - 1];
    }
    array[loc] = ins;

    for (i = 0; i < n; i++)
    {
        printf(" %d ", array[i]);
    }
    return 0;
}