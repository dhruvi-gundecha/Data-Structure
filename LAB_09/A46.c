// 46. Write a program to reverse a linked list.
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

void DISPLAY()
{
    struct NODE *POINT = FIRST;

    while (POINT != NULL)
    {
        printf(" %d ", POINT->INFO);
        POINT = POINT->LINK;
    }
}

void REV_LINKLIST()
{
    struct NODE *CUR = FIRST, *PRE = NULL, *NEXT = NULL;

    while (CUR != NULL)
    {
        NEXT = CUR->LINK;
        CUR->LINK = PRE;
        PRE = CUR;
        CUR = NEXT;
    }
    FIRST = PRE;
    return;
}

int main()
{
    int x, n;

    printf("ENTER THE NUM HOW MANY NODE YOU WANT TO ENTER : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("ENTER THE NODE INFO : ");
        scanf("%d", &x);
        INSERT(x);
    }
    REV_LINKLIST();
    DISPLAY();
}