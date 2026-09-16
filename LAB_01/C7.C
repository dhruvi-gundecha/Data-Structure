// 7. WAP to convert number of days into year, week & days
// [e.g. 375 days mean 1 year, 1 week and 3 days] :-

#include <stdio.h>
int main()
{
    int d, w, y;
    w = 0;
    y = 0;
    printf("ENTER THE DAYS : ");
    scanf("%d", &d);

    y = d / 365;
    d = d % 365;
    w = d / 7;
    d = d % 7;

    printf("YEAR:WEEKS:DAYS = %d:%d:%d", y, w, d);
    return 0;
}
