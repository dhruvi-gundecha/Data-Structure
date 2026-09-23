// 45. Write a program to copy a linked list.
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *LINK;
};

struct NODE *FIRST_1 = NULL;
struct NODE *FIRST_2 = NULL;

void INSERT(int x)
{

    struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

    if (NEWNODE == NULL)
    {
        printf("MEMORY ALLOCTION WAS FAILED...");
        return;
    }

    if (FIRST_1 == NULL)
    {
        NEWNODE->INFO = x;
        NEWNODE->LINK = FIRST_1;
        FIRST_1 = NEWNODE;
    }
    else
    {
        struct NODE *POINT = FIRST_1;
        while (POINT->LINK != NULL)
        {
            POINT = POINT->LINK;
        }

        POINT->LINK = NEWNODE;
        NEWNODE->INFO = x;
        NEWNODE->LINK = NULL;
    }
}

void COPY_LINKLIST_OP()
{
    if (FIRST_1 == NULL)
    {
        printf("LINKLIST IS EMPTY.");
        return;
    }
    else
    {

        struct NODE *POINT_1 = FIRST_1;
        struct NODE *POINT_2 = NULL;

        while (POINT_1 != NULL)
        {

            struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

            NEWNODE->INFO = POINT_1->INFO;
            NEWNODE->LINK = NULL;

            if (FIRST_2 == NULL)
            {
                FIRST_2 = NEWNODE;
                POINT_2 = FIRST_2;
            }
            else
            {
                POINT_2->LINK = NEWNODE;
                POINT_2 = POINT_2->LINK;
            }

            POINT_1 = POINT_1->LINK;
        }
    }
}

void DISPLAY(struct NODE *P)
{
    struct NODE *POINT = P;

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

    for (int i = 1; i <= n; i++)
    {
        printf("ENTER THE VALUE OF NODE : ");
        scanf("%d", &x);
        INSERT(x);
    }
    COPY_LINKLIST_OP();
    DISPLAY(FIRST_1);
    printf("\nYOUT LINKED IS COPIED AND PRINTED\n");
    DISPLAY(FIRST_2);
    return 0;
}