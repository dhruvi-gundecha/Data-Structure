// WAP to check whether the string is Palindrome or not using Pointer.
#include <stdio.h>
#include <string.h>
void main()
{
    char str1[100], str2[100], *P1, *P2;

    printf("ENTER THE STRING : ");
    scanf("%s", str1);

    int n, i = 0;

    n = strlen(str1);

    P1 = str1;
    P2 = str2;

    while (n >= 0)
    {
        *(P2 + i) = *(P1 + n - 1);
        i++;
        n--;
    }

    if (strcmp(str2, str1) == 0)
    {
        printf("GIVEN STRING IS PALINDROME.\n");
    }
    else
    {
        printf("GIVEN STRING IS NOT PALINDROME.\n");
    }
}
