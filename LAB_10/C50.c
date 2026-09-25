// 50. Write a program to swap two consecutive nodes in the linked list. Don’t change the values of nodes,
// implement by changing the link of the nodes.
// Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8
// Output: 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7
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
    struct NODE *NEWNODE = malloc(sizeof(struct NODE));

    NEWNODE->INFO = X;
    NEWNODE->LINK = NULL;

    if (FIRST == NULL)
    {
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
    }
}

void QUICK_SWAP()
{
    if (FIRST == NULL || FIRST->LINK == NULL)
    {
        return;
    }

    struct NODE *PRE = NULL;
    struct NODE *CURRENT = FIRST;

    FIRST = FIRST->LINK;

    while (CURRENT != NULL && CURRENT->LINK != NULL)
    {
        struct NODE *NEXT = CURRENT->LINK;

        // Swap CURRENT and NEXT
        CURRENT->LINK = NEXT->LINK;
        NEXT->LINK = CURRENT;

        // Connect previous pair to new pair
        if (PRE != NULL)
        {
            PRE->LINK = NEXT;
        }

        // Move to next pair
        PRE = CURRENT;
        CURRENT = CURRENT->LINK;
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

    QUICK_SWAP();
    DISPLAY();

    return 0;
}