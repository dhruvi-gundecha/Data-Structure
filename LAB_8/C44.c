// 44. Write a program to remove the duplicates nodes from given sorted Linked List.
// Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27
// Output: 1 → 6 → 13 → 27
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *LINK;
};

struct NODE *FIRST = NULL;

void INSERT(int x)
{

    struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

    if (NEWNODE == NULL)
    {
        printf("MEMORY ALLOCTION WAS FAILED...");
        return;
    }

    if (FIRST == NULL)
    {
        NEWNODE->INFO = x;
        NEWNODE->LINK = FIRST;
        FIRST = NEWNODE;
    }

    else
    {
        struct NODE *POINT = FIRST;
        while (POINT->LINK != NULL)
        {
            POINT = POINT->LINK;
        }

        POINT->LINK = NEWNODE;
        NEWNODE->INFO = x;
        NEWNODE->LINK = NULL;
    }
}
void DEL_DUPLICATES()
{

    struct NODE *POINT = FIRST;
    struct NODE *DUP = NULL;

    if (FIRST == NULL)
    {
        printf("LINKED LIST IS EMPTY...");
        return;
    }

    while (POINT->LINK != NULL && POINT != NULL)
    {
        if (POINT->LINK->INFO == POINT->INFO)
        {
            DUP = POINT->LINK;
            POINT->LINK = DUP->LINK;
            free(DUP);
        }
        else
        {
            POINT = POINT->LINK;
        }
    }
}

void DISPLAY()
{
    struct NODE *POINT = FIRST;

    if (FIRST == NULL)
    {
        printf("LINKED LIST IS EMPTY...");
        return;
    }
    while (POINT != NULL)
    {
        printf(" %d ", POINT->INFO);
        POINT = POINT->LINK;
    }
}
int main()
{
    int n, x;

    printf("ENTER THE SIZE HOW MANY NODE YOU WANT TO ENTER : ");
    scanf("%d", &n);

    printf("ENTER THE SORTED  LIST ELEMENT : \n");
    for (int i = 1; i <= n; i++)
    {
        printf("ENTER THE VALUE OF NODE : ");
        scanf("%d", &x);
        INSERT(x);
    }

    DEL_DUPLICATES();
    DISPLAY();
    return 0;
}