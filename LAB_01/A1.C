// 1. WAP to calculate area of a Circle (A = πr2) :-

#include <stdio.h>
int main()
{
    int r;
    float result;
    printf("ENTER THE REDIUS: ");
    scanf("%d", &r);

    result = 3.14 * r * r;

    printf("RESULT = %f ", result);

    return 0;
}
