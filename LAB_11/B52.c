// 52. WAP to split a circular linked list into two halves.
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *LINK;
};

struct NODE *FIRST = NULL;

void INSERT(int X)
{
    struct NODE *NEWNODE =
        (struct NODE *)malloc(sizeof(struct NODE));

    if (NEWNODE == NULL)
    {
        printf("MEMORY ALLOCATION FAILED\n");
        return;
    }

    NEWNODE->INFO = X;

    if (FIRST == NULL)
    {
        FIRST = NEWNODE;
        NEWNODE->LINK = FIRST;
    }
    else
    {
        struct NODE *POINT = FIRST;

        while (POINT->LINK != FIRST)
        {
            POINT = POINT->LINK;
        }

        POINT->LINK = NEWNODE;
        NEWNODE->LINK = FIRST;
    }
}

void DISPLAY(struct NODE *START)
{
    if (START == NULL)
        return;

    struct NODE *POINT = START;

    do
    {
        printf(" %d ", POINT->INFO);
        POINT = POINT->LINK;

    } while (POINT != START);

    printf("\n");
}

void SPLIT()
{
    if (FIRST == NULL || FIRST->LINK == FIRST)
    {
        printf("LIST CANNOT BE SPLIT\n");
        return;
    }

    struct NODE *SLOW = FIRST;
    struct NODE *FAST = FIRST;

    // =>   Find middle of circular linked list

    while (FAST->LINK != FIRST &&
           FAST->LINK->LINK != FIRST)
    {
        SLOW = SLOW->LINK;
        FAST = FAST->LINK->LINK;
    }

    //   => FIRST half starts from FIRST
    //   => SECOND half starts after SLOW

    struct NODE *FIRST_HALF = FIRST;
    struct NODE *SECOND_HALF = SLOW->LINK;

    // =>   Make first half circular

    SLOW->LINK = FIRST_HALF;

    // =>   Find last node of second half

    struct NODE *POINT = SECOND_HALF;

    while (POINT->LINK != FIRST)
    {
        POINT = POINT->LINK;
    }

    //  =>  Make second half circular

    POINT->LINK = SECOND_HALF;

    printf("\nFIRST HALF : ");
    DISPLAY(FIRST_HALF);

    printf("SECOND HALF: ");
    DISPLAY(SECOND_HALF);
}

int main()
{
    int n, x;

    printf("ENTER THE NUM HOW MANY NODE YOU WANT TO ENTER : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("ENTER THE NODE INFO : ");
        scanf("%d", &x);

        INSERT(x);
    }

    printf("\nORIGINAL LIST: ");
    DISPLAY(FIRST);

    SPLIT();

    return 0;
}