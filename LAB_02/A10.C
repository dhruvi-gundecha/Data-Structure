// 10. WAP to reverse a number :-

#include <stdio.h>
int main()
{
    int number, rem, sum = 0;
    printf("ENTER THE NUMBER : ");
    scanf("%d", &number);

    while (number != 0)
    {
        rem = number % 10;
        sum = sum * 10 + rem;
        number = number / 10;
    }

    printf("REVERSE NUMBER = %d", sum);

    return 0;
}