// 8. WAP to find factorial of a number. (Using loop & recursion)  :-

#include <stdio.h>
int main()
{
    int fact, num;
    fact = 1;
    printf("ENTER THE NUMBER : ");
    scanf("%d", &num);

    while (num != 0)
    {
        fact = fact * num;
        num--;
    }

    printf("RESULT = %d ", fact);

    return 0;
}

// recursion :-

#include <stdio.h>
int fact(int);

int main()
{
    int number, result;

    printf("ENTER THE NUMBER : ");
    scanf("%d", &number);

    result = fact(number);
    printf("RESULT = %d", result);

    return 0;
}

int fact(int number)
{
    if (number == 0 || number == 1)
    {
        return 1;
    }
    else
    {
        return number * fact(number - 1);
    }
}