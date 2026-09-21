// 42. Write a menu driven program to implement following operations on the singly linked list.
//  Insert a node at the front of the linked list.
//  Display all nodes.
//  Delete a first node of the linked list.
//  Insert a node at the end of the linked list.
//  Delete a last node of the linked list.
//  Delete a node from specified position.
//  Count the no. of nodes in the linked list.
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
    struct NODE *P = FIRST;
    while (P != NULL)
    {
        printf("NODE = %d\n", P->INFO);
        P = P->LINK;
    }
}

void FIRST_ELEMENT(int X1)
{
    struct NODE *N3 = (struct NODE *)malloc(sizeof(struct NODE));

    N3->INFO = X1;
    N3->LINK = FIRST;
    FIRST = N3;
}

void LAST_ELEMENT(int X2)
{
    struct NODE *N4 = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE *PTR = (struct NODE *)malloc(sizeof(struct NODE));

    PTR = FIRST;

    while (PTR->LINK != NULL)
    {
        PTR = PTR->LINK;
    }

    PTR->LINK = N4;
    N4->INFO = X2;
    N4->LINK = NULL;
}

void DELETE_FIRST_ELEMENT()
{
    struct NODE *DEL = (struct NODE *)malloc(sizeof(struct NODE));

    DEL = FIRST;
    FIRST = FIRST->LINK;

    free(DEL);
}

void DELETE_LAST_ELEMENT()
{
    struct NODE *DEL = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE *PRE = (struct NODE *)malloc(sizeof(struct NODE));
    DEL = FIRST;
    PRE = NULL;
    while (DEL->LINK != NULL)
    {
        PRE = DEL;
        DEL = DEL->LINK;
    }
    PRE->LINK = NULL;
    free(DEL);
}

void DELETE_SPECIFIC_ELEMENT(int X3)
{
    struct NODE *DEL = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE *PRE = (struct NODE *)malloc(sizeof(struct NODE));

    if (FIRST->INFO == X3)
    {
        DEL = FIRST;
        FIRST = FIRST->LINK;
        free(DEL);
    }
    DEL = FIRST;
    PRE = NULL;

    while (DEL->INFO != X3 || DEL->LINK == NULL)
    {
        PRE = DEL;
        DEL = DEL->LINK;
    }
    PRE->LINK = DEL->LINK;

    free(DEL);
}

void COUNT_NODE()
{
    struct NODE *PRE = (struct NODE *)malloc(sizeof(struct NODE));
    int COUNT = 0;

    PRE = FIRST;

    while (PRE != NULL)
    {
        COUNT++;
        PRE = PRE->LINK;
    }

    printf("COUNT = %d\n", COUNT);
}

int main()
{
    struct NODE *N0 = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE *N1 = (struct NODE *)malloc(sizeof(struct NODE));
    struct NODE *N2 = (struct NODE *)malloc(sizeof(struct NODE));

    printf("ENTER THE NODE N0 INFO : ");
    scanf("%d", &(N0->INFO));
    printf("ENTER THE NODE N1 INFO : ");
    scanf("%d", &(N1->INFO));
    printf("ENTER THE NODE N2 INFO : ");
    scanf("%d", &(N2->INFO));

    FIRST = N0;
    N0->LINK = N1;
    N1->LINK = N2;
    N2->LINK = NULL;

    DISPLAY();

    int X1, X2, X3;

    printf("ENTER THE NODE INFO YOU WANT TO INSERT AT FIRST  : ");
    scanf("%d", &X1);

    FIRST_ELEMENT(X1);

    DISPLAY();

    printf("ENTER THE NODE INFO YOU WANT TO INSERT AT LAST  : ");
    scanf("%d", &X2);

    LAST_ELEMENT(X2);

    DISPLAY();

    printf("THE NODE INFO YOU WANT TO DELETE AT FIRST  : \n");

    DELETE_FIRST_ELEMENT();
    DISPLAY();

    printf("THE NODE INFO YOU WANT TO DELETE AT LAST  : \n");

    DELETE_LAST_ELEMENT();
    DISPLAY();

    printf("THE SPECIFIC NODE INFO YOU WANT TO DELETE  : \n");
    scanf("%d", &X3);

    DELETE_SPECIFIC_ELEMENT(X3);
    DISPLAY();

    printf("THE NODES YOU WANT TO COUNT  : \n");
    COUNT_NODE();
    return 0;
}
