// 55. WAP to delete alternate nodes of a doubly linked list.
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *LPTR;
    struct NODE *RPTR;
};

struct NODE *FIRST = NULL;

void INSERT(int X)
{
    struct NODE *NEWNODE =
        (struct NODE *)malloc(sizeof(struct NODE));

    if (NEWNODE == NULL)
    {
        printf("MEMORY ALLOCATION FAILED");
        return 0;
    }
    NEWNODE->INFO = X;
    NEWNODE->LPTR = NULL;
    NEWNODE->RPTR = NULL;

    if (FIRST == NULL)
    {
        FIRST = NEWNODE;
    }
    else
    {
        struct NODE *POINT = FIRST;

        while (POINT->RPTR != NULL)
        {
            POINT = POINT->RPTR;
        }

        POINT->RPTR = NEWNODE;
        NEWNODE->LPTR = POINT;
    }
}

void DISPLAY()
{
    struct NODE *POINT = FIRST;

    while (POINT != NULL)
    {
        printf("%d ", POINT->INFO);
        POINT = POINT->RPTR;
    }

    printf("\n");
}

void DELETE_ALTERNATE()
{
    struct NODE *POINT = FIRST;
    struct NODE *TEMP;

    while (POINT != NULL && POINT->RPTR != NULL)
    {
        // TEMP is the node to be deleted
        TEMP = POINT->RPTR;

        // Connect current node directly to the next node
        POINT->RPTR = TEMP->RPTR;

        // If next node exists,update its LPTR

        if (TEMP->RPTR != NULL)
        {
            TEMP->RPTR->LPTR = POINT;
        }
        // Move to next remaining node

        POINT = POINT->RPTR;

        free(TEMP);
    }
}

int main()
{
    int n, x;

    printf("ENTER THE NUM HOW MANY NODE YOU WANT TO ENTER: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("ENTER THE NODE INFO: ");
        scanf("%d", &x);

        INSERT(x);
    }

    printf("\nBEFORE DELETE: ");
    DISPLAY();

    DELETE_ALTERNATE();

    printf("AFTER DELETE:  ");
    DISPLAY();

    return 0;
}