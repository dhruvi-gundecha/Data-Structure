// 60. Write a program to determine if an input character string is of the form a^i b^i
// where i >= 1 i.e., Number of 'a' should be equal to number of 'b'.

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

int CHECK_STRING(char str[])
{
    int i = 0;
    int a_count = 0;
    char ch;

    // Push all 'a' characters
    while (str[i] == 'a')
    {
        PUSH(str[i]);
        a_count++;
        i++;
    }

    // There must be at least one 'a'
    if (a_count == 0)
    {
        return 0;
    }

    // Now only 'b' characters should be present
    while (str[i] == 'b')
    {
        ch = POP();

        if (ch == '\0')
        {
            return 0;
        }

        i++;
    }

    // If any other character exists, invalid
    if (str[i] != '\0')
    {
        return 0;
    }

    // Stack must be empty
    if (TOP != NULL)
    {
        return 0;
    }

    return 1;
}

int main()
{
    char str[100];

    printf("ENTER STRING: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    if (CHECK_STRING(str))
    {
        printf("Number of 'a' equal to number of 'b'.\n");
    }
    else
    {
        printf("Number of 'a' not equal to number of 'b'.\n");
    }

    return 0;
}