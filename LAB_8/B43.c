// 43. WAP to check whether 2 singly linked lists are same or not.
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *LINK;
};
struct NODE *FIRST_1 = NULL;
struct NODE *FIRST_2 = NULL;

void INSERT_NODE(struct NODE **P, int X)
{

    struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE *PTR = *P;

    if (NEWNODE == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    if (*P == NULL)
    {
        *P = NEWNODE;
        NEWNODE->INFO = X;
        NEWNODE->LINK = NULL;
    }
    else
    {
        while (PTR->LINK != NULL)
        {
            PTR = PTR->LINK;
        }
        PTR->LINK = NEWNODE;
        NEWNODE->INFO = X;
        NEWNODE->LINK = NULL;
    }
}

void LINKLIST_SAME()
{
    struct NODE *ADD_1 = FIRST_1;
    struct NODE *ADD_2 = FIRST_2;

    while (ADD_1 != NULL && ADD_2 != NULL)
    {

        if (ADD_1->INFO != ADD_2->INFO)
        {
            printf("LINKLIST ARE NOT SAME.");
            return;
        }

        ADD_1 = ADD_1->LINK;
        ADD_2 = ADD_2->LINK;
    }
    if (ADD_1 == NULL && ADD_2 == NULL)
        printf("LINKLIST ARE SAME.");
    else
    {
        printf("LINKLIST ARE NOT SAME.");
    }
}

int main()
{
    int X, n1, n2;

    printf("ENTER THE NUM HOW MANY NODE YOU WANT IN FIRST LINKED LIST....... : ");
    scanf("%d", &n1);

    for (int i = 1; i <= n1; i++)
    {
        printf("ENTER THE NODE INFO : ");
        scanf("%d", &X);
        INSERT_NODE(&FIRST_1, X);
    }

    printf("ENTER THE NUM HOW MANY NODE YOU WANT IN SECOND LINKED LIST..... : ");
    scanf("%d", &n2);

    if (n1 == n2)
    {
        for (int i = 1; i <= n2; i++)
        {
            printf("ENTER THE NODE INFO : ");
            scanf("%d", &X);
            INSERT_NODE(&FIRST_2, X);
        }
        printf("=> LINKLIST CHECK OPERATION STARTED..........\n");
        LINKLIST_SAME();
    }
    else
    {
        printf("=>  LINKED LIST SIZED MUST BE SAME FOR CHECK OPREATION ELSE THEY ARE NOT SAME");
    }
    return 0;
}