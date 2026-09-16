// 19. Write a program to find position of the smallest number &
// the largest number from given n numbers.

#include <stdio.h>
int main()
{
    int i, n, large, small, l_p, s_p;

    printf("ENTER THE ARRAY SIZE :");
    scanf("%d", &n);

    int array[n];

    for (i = 0; i < n; i++)
    {
        printf("ENTER THE ARRAY ELEMENT : ");
        scanf("%d", &array[i]);
    }
    large = array[0];
    small = array[0];

    for (i = 0; i < n; i++)
    {
        if (array[i] >= large)
        {
            large = array[i];
            l_p = i;
        }
        if (array[i] <= small)
        {
            small = array[i];
            s_p = i;
        }
    }

    printf(" LARGEST ELEMENT IS ON THE  %d POSITION INDEX \n", l_p);
    printf(" SMALLEST ELEMENT IS ON THE  %d POSITION INDEX ", s_p);
    return 0;
}