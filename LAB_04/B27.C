// 27. Write a program to delete a number from an array that is already sorted in
// an ascending order.

#include <stdio.h>
int main()
{
    int i, n, d, loc;

    printf("ENTER THE ARRAY SIZE : ");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("ENTER THE ARRAY ELEMENT : ");
        scanf("%d", &array[i]);
    }

    printf("ENTER THE NUMBER YOU WANT TO DELETE  : ");
    scanf("%d", &d);

    for (i = 0; i < n; i++)
    {
        if (array[i] == d)
        {
            loc = i;
        }
    }
    for (int i = loc; i < n; i++)
    {
        array[i] = array[i + 1];
    }
    n--;

    for (int i = 0; i < n; i++)
    {
        printf("  %d  ", array[i]);
    }
    return 0;
}
