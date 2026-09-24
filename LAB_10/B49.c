// 49. WAP to perform given operation in the linked list. There exist a Linked List.
// Add a node that contains the GCD of those two nodes between every pair adjacent node of Linked List.
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *LINK;
};

struct NODE *FIRST = NULL;

int GCD(int x1, int x2)
{

    if (x2 == 0)
    {
        return x1;
    }
    return GCD(x2, x1 % x2);
}

int GCD_FINDER()
{
    struct NODE *SAVE = FIRST->LINK, *PRE = FIRST;
    while (SAVE != NULL)
    {
        struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

        int GCD_ANS = GCD(PRE->INFO, SAVE->INFO);

        NEWNODE->INFO = GCD_ANS;

        NEWNODE->LINK = SAVE;
        PRE->LINK = NEWNODE;

        PRE = SAVE;
        SAVE = SAVE->LINK;
    }
}

void INSERT(int x)
{
    int N1 = x;

    struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

    if (FIRST == NULL)
    {
        NEWNODE->INFO = N1;
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
        NEWNODE->INFO = N1;
        NEWNODE->LINK = NULL;
    }
}

void display()
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

    printf("ENTER  THE SIZE OF NODE YOU WANT TO INSERT :");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("ENTER  THE NODE INFO YOU WANT TO INSERT :");
        scanf("%d", &x);
        INSERT(x);
    }

    GCD_FINDER();
    display();
}