// 21. Read n numbers in an array then read two different numbers,
// replace 1st number with 2nd number in an array and print its index and final array.

#include <stdio.h>
void main()
{
    int position, change, i, n, replace;

    printf("ENTER THE ARRAY SIZE :");
    scanf("%d", &n);

    int array[n];

    for (i = 0; i < n; i++)
    {
        printf("ENTER THE ARRAY ELEMENT : ");
        scanf("%d", &array[i]);
    }

    printf("ENTER THE NUMBER YOU WANT TO CHANGE :");
    scanf("%d", &change);
    printf("ENTER THE NUMBER YOU WANT REPLACE WITH CHANGE NUMBER :");
    scanf("%d", &replace);

    for (i = 0; i < n; i++)
    {
        if (change == array[i])
        {
            array[i] = replace;
            position = i;
        }
    }

    printf("YOUR GIVEN NUMBER IS CHANGED AND REPLACE NUMBER IS ON THE %d POSITION.\n", position);
    printf("FINAL ARRAY PRINT :-\n");
    for (i = 0; i < n; i++)
    {
        printf("  %d  ", array[i]);
    }
}