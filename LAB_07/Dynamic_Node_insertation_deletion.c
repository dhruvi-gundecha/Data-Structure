
// MENU DRIVEN PROGRAM WITH SINGLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *LINK;
};
struct NODE *FIRST = NULL;

void DISPLAY()
{
    struct NODE *POINT = FIRST;

    while (POINT != NULL)
    {
        printf("NODE = %d\n", POINT->INFO);
        POINT = POINT->LINK;
    }
}

void FIRST_ELEMENT(int x)
{
    struct NODE *NEW = (struct NODE *)malloc(sizeof(struct NODE));

    if (NEW == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    if (FIRST == NULL)
    {
        NEW->INFO = x;
        NEW->LINK = NULL;
        FIRST = NEW;
    }
    else
    {
        NEW->INFO = x;
        NEW->LINK = FIRST;
        FIRST = NEW;
    }
    DISPLAY();
}

void LAST_ELEMENT(int x)
{
    struct NODE *NEW = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE *P = FIRST;

    if (NEW == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    if (FIRST == NULL)
    {
        NEW->INFO = x;
        NEW->LINK = NULL;
        FIRST = NEW;
    }
    else
    {
        while (P->LINK != NULL)
        {
            P = P->LINK;
        }
        P->LINK = NEW;
        NEW->INFO = x;
        NEW->LINK = NULL;
    }
    DISPLAY();
}

void DELETE_FIRST_ELEMENT()
{
    struct NODE *DEL = NULL;

    if (FIRST == NULL)
    {
        printf("LINKED LIST IS EMPTY....");
    }
    else
    {
        DEL = FIRST;
        FIRST = FIRST->LINK;

        free(DEL);

        DISPLAY();
    }
}

void DELETE_LAST_ELEMENT()
{
    struct NODE *DEL = FIRST;
    struct NODE *PRE = NULL;

    if (FIRST == NULL)
    {
        printf("LINKED LIST IS EMPTY...");
        return;
    }

    if (FIRST->LINK == NULL)
    {
        FIRST = NULL;
        free(DEL);
        DISPLAY();
        return;
    }

    while (DEL->LINK != NULL)
    {
        PRE = DEL;
        DEL = DEL->LINK;
    }
    PRE->LINK = NULL;

    free(DEL);

    DISPLAY();
}

void DELETE_SPECIFIC_ELEMENT(int X)
{
    struct NODE *DEL = FIRST;
    struct NODE *PRE = NULL;

    if (FIRST == NULL)
    {
        printf("YOUR GIVEN ELEMENT IS NOT FOUND...");
        return;
    }

    while (DEL->INFO != X && DEL != NULL)
    {
        PRE = DEL;
        DEL = DEL->LINK;
    }
    if (DEL == NULL)
    {
        printf("YOUR GIVEN ELEMENT IS NOT FOUND.\n");
        return;
    }

    if (PRE == NULL)
    {
        FIRST = DEL->LINK;
    }
    else
    {
        PRE->LINK = DEL->LINK;
    }

    free(DEL);

    DISPLAY();
}

void COUNT_NODE()
{
    struct NODE *PRE = FIRST;
    int COUNT = 0;

    while (PRE != NULL)
    {
        COUNT++;
        PRE = PRE->LINK;
    }

    printf("COUNT = %d\n", COUNT);
}

void INSERT(int x)
{

    struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

    if (NEWNODE == NULL)
    {
        printf("Memory allocation failed.\n");
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

int main()
{
    int n, x, c;

    printf("ENTER THE NODE N0 YOU WANT TO ENTER IN LINKED LIST : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("ENTER THE NODE INFO : ");
        scanf("%d", &x);
        INSERT(x);
    }

    while (1)
    {
        printf("----------------------------------------------------------\n");
        printf("USER MENU  : \n");
        printf("1. DISPLAY ALL NODE'S  : \n");
        printf("2. INSERT AT FIRST  : \n");
        printf("3. INSERT AT LAST  : \n");
        printf("4. DELETE AT FIRST  : \n");
        printf("5. DELETE AT LAST  : \n");
        printf("6. DELETE AT SPECIFIC ELEMENT  : \n");
        printf("7. COUNT NODES : \n");
        printf("8. QUIT : \n");
        scanf("%d", &c);

        if (c > 8 || c < 1)
        {
            printf("INVALID OPRATION");
            continue;
        }
        else if (c == 8)
        {
            printf("QUIT....");
            break;
        }
        switch (c)
        {
        case 1:
            DISPLAY();
            break;
        case 2:
            printf("ENTER THE NODE INFO YOU WANT TO INSERT AT FIRST  : ");
            scanf("%d", &x);

            FIRST_ELEMENT(x);
            break;
        case 3:
            printf("ENTER THE NODE INFO YOU WANT TO INSERT AT LAST  : ");
            scanf("%d", &x);

            LAST_ELEMENT(x);
            break;
        case 4:
            DELETE_FIRST_ELEMENT();
            break;
        case 5:
            DELETE_LAST_ELEMENT();
            break;
        case 6:
            printf("THE SPECIFIC NODE INFO YOU WANT TO DELETE  : \n");
            scanf("%d", &x);

            DELETE_SPECIFIC_ELEMENT(x);
            break;
        case 7:
            COUNT_NODE();
            break;
        }
    }
    return 0;
}