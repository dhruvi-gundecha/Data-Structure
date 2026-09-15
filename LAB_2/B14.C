// 14. WAP to find the sum of 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n) :-

#include <stdio.h>
int main()
{
    int sum, i, n, total;
    sum = 0;
    total = 0;
    printf("ENTER THE NUMBER YOU WANT TO STOP : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
        total += sum;
    }

    printf("RESULT = %d", total);
    return 0;
}