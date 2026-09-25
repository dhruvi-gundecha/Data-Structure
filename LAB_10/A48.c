// 48. WAP to swap Kth node from beginning with Kth node from end in a singly linked list.
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
        printf("MEMORY ALLOCATION FAILED...");
        return;
    }

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

void DISPLAY()
{
    struct NODE *POINT = FIRST;

    while (POINT != NULL)
    {
        printf("%d ", POINT->INFO);
        POINT = POINT->LINK;
    }

    printf("\n");
}

int COUNT_NODE()
{
    int COUNT = 0;
    struct NODE *POINT = FIRST;

    while (POINT != NULL)
    {
        COUNT++;
        POINT = POINT->LINK;
    }

    return COUNT;
}

void SWAP(int K)
{
    int C = COUNT_NODE();

    if (FIRST == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }

    if (K < 1 || K > C)
    {
        printf("INVALID K\n");
        return;
    }

    int END = C - K + 1; // N-I+1 =>SIMILAR TO STACK

    struct NODE *BEGIN_NODE = FIRST;
    struct NODE *END_NODE = FIRST;

    for (int i = 1; i < K; i++)
    {
        BEGIN_NODE = BEGIN_NODE->LINK;
    }

    for (int i = 1; i < END; i++)
    {
        END_NODE = END_NODE->LINK;
    }

    int TEMP = BEGIN_NODE->INFO;
    BEGIN_NODE->INFO = END_NODE->INFO;
    END_NODE->INFO = TEMP;
}

int main()
{
    int x, n, K;

    printf("ENTER THE NUM HOW MANY NODE YOU WANT TO ENTER: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("ENTER THE NODE INFO: ");
        scanf("%d", &x);

        INSERT(x);
    }

    printf("\nBEFORE SWAP: ");
    DISPLAY();

    printf("ENTER K: ");
    scanf("%d", &K);

    SWAP(K);

    printf("AFTER SWAP: ");
    DISPLAY();

    return 0;
}