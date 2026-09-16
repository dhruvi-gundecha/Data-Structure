// 2. WAP to find whether a number is odd or even :-

#include <stdio.h>
int main()
{
    int number;
    printf("ENTER THE NUMBER : ");
    scanf("%d", &number);

    if (number % 2 == 0)
    {
        printf("GIVEN NUMBER IS EVEN NUMBER.");
    }
    else
    {
        printf("GIVEN NUMBER IS ODD NUMBER.");
    }

    return 0;
}
