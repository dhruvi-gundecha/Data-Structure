// 11. WAP to find factors of a given number  :-

#include <stdio.h>
int main()
{
    int fact, num, i;
    i = 1;
    printf("ENTER THE NUMBER : ");
    scanf("%d", &num);

    while (i <= num)
    {

        if (num % i == 0)
        {
            printf(" %d ", i);
        }
        i++;
    }

    return 0;
}