// 59. How stack can be used to recognize strings aca, bcb, abcba, abbcbba?
// Write a program to solve the above problem.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE
{
    char INFO;
    struct NODE *LINK;
};

struct NODE *TOP = NULL;

void PUSH(char ch)
{
    struct NODE *NEW = (struct NODE *)malloc(sizeof(struct NODE));

    if (NEW == NULL)
    {
        printf("MEMORY ALLOCATION FAILED...");
        return;
    }

    NEW->INFO = ch;
    NEW->LINK = TOP;
    TOP = NEW;
}

char POP()
{
    struct NODE *TEMP;
    char ch;

    if (TOP == NULL)
    {
        return '\0';
    }

    TEMP = TOP;
    ch = TOP->INFO;
    TOP = TOP->LINK;

    free(TEMP);

    return ch;
}

int CHECK_PALINDROME(char str[])
{
    int length;
    int i;
    char ch;

    length = strlen(str);

    // PUSH all characters into stack
    for (i = 0; i < length; i++)
    {
        PUSH(str[i]);
    }

    // Compare original string with POP result
    for (i = 0; i < length; i++)
    {
        ch = POP();

        if (str[i] != ch)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char str[100];

    printf("ENTER STRING: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    if (CHECK_PALINDROME(str))
    {
        printf("STRING IS RECOGNIZED.\n");
    }
    else
    {
        printf("STRING IS NOT RECOGNIZED.\n");
    }

    return 0;
}