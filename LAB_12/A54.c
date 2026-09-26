// 12 A 54. Write a menu driven program to implement following operations on the doubly
// linked list.
// - Insert a node at the front of the linked list.
// - Delete a node from specified position.
// - Insert a node at the end of the linked list. (Home Work)
// - Display all nodes. (Home Work)

#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *lptr;
    struct NODE *rptr;
};
struct NODE *FIRST = NULL;
void INSERT_AT_FRONT(int NUM)
{
    struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

    if (NEWNODE == NULL)
    {
        printf("oops ! your memory allocation is failed.");
        return;
    }
    NEWNODE->INFO = NUM;
    NEWNODE->lptr = NULL;
    NEWNODE->rptr = NULL;
    if (FIRST == NULL)
    {
        FIRST = NEWNODE;
        return;
    }
    NEWNODE->rptr = FIRST;
    FIRST->lptr = NEWNODE;
    FIRST = NEWNODE;
}
void INSERT_AT_LAST(int NUM)
{
    struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

    if (NEWNODE == NULL)
    {
        printf("oops ! your memory allocation is failed.");
        return;
    }
    NEWNODE->INFO = NUM;
    NEWNODE->lptr = NULL;
    NEWNODE->rptr = NULL;
    if (FIRST == NULL)
    {
        FIRST = NEWNODE;
        return;
    }

    struct NODE *P = FIRST;

    while (P->rptr != NULL)
    {
        P = P->rptr;
    }
    P->rptr = NEWNODE;
    NEWNODE->lptr = P;
}
void INSERT_AT_SPECIFIC(int POS, int NUM)
{
    struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

    if (NEWNODE == NULL)
    {
        printf("Oops! Memory allocation failed.");
        return;
    }

    NEWNODE->INFO = NUM;
    NEWNODE->lptr = NULL;
    NEWNODE->rptr = NULL;

    if (POS == 1)
    {
        NEWNODE->rptr = FIRST;

        if (FIRST != NULL)
        {
            FIRST->lptr = NEWNODE;
        }

        FIRST = NEWNODE;
        return;
    }

    struct NODE *P = FIRST;

    for (int i = 1; i < POS - 1 && P != NULL; i++)
    {
        P = P->rptr;
    }

    if (P == NULL)
    {
        printf("Invalid position.");
        free(NEWNODE);
        return;
    }

    NEWNODE->rptr = P->rptr;
    NEWNODE->lptr = P;

    if (P->rptr != NULL)
    {
        P->rptr->lptr = NEWNODE;
    }

    P->rptr = NEWNODE;
}
void DELETE_AT_FRONT()
{
    if (FIRST == NULL)
    {
        printf("List is empty.");
        return;
    }

    struct NODE *P = FIRST;

    FIRST = FIRST->rptr;

    if (FIRST != NULL)
    {
        FIRST->lptr = NULL;
    }

    free(P);
}
void DELETE_AT_LAST()
{
    if (FIRST == NULL)
    {
        printf("List is empty.");
        return;
    }

    struct NODE *P = FIRST;

    // Only one node
    if (P->rptr == NULL)
    {
        FIRST = NULL;
        free(P);
        return;
    }

    // Move to last node
    while (P->rptr != NULL)
    {
        P = P->rptr;
    }

    P->lptr->rptr = NULL;

    free(P);
}
void DELETE_AT_SPECIFIC(int POS)
{
    if (FIRST == NULL)
    {
        printf("List is empty.");
        return;
    }

    if (POS <= 0)
    {
        printf("Invalid position.");
        return;
    }

    struct NODE *P = FIRST;

    for (int i = 1; i < POS && P != NULL; i++)
    {
        P = P->rptr;
    }

    if (P == NULL)
    {
        printf("Invalid position.");
        return;
    }

    if (P == FIRST)
    {
        FIRST = P->rptr;

        if (FIRST != NULL)
        {
            FIRST->lptr = NULL;
        }

        free(P);
        return;
    }

    P->lptr->rptr = P->rptr;

    if (P->rptr != NULL)
    {
        P->rptr->lptr = P->lptr;
    }

    free(P);
}
void DISPLAY()
{
    if (FIRST == NULL)
    {
        printf("YOUR DOUBLY-LINK-LIST IS EMPTY...");
        return;
    }

    printf("YOUR DOUBLY-LINK-LIST DISPLAY...\n");

    struct NODE *P = FIRST; // => THE POINTER VAR KEEPS NODE ADDRESS

    while (P != NULL)
    {
        printf("  %d  ", P->INFO);

        P = P->rptr;
    }
}
int main()
{
    while (1)
    {
        char CHOICE;
        int NUM, POS;
        printf("----------------------------\n");
        printf("1 ] INSERT AT INFRONT : \n");
        printf("2 ] INSERT AT LAST : \n");
        printf("3 ] INSERT AT SPECIFIC : \n");
        printf("4 ] DELETE AT INFRONT : \n");
        printf("5 ] DELETE AT LAST : \n");
        printf("6 ] DELETE AT SPECIFIC : \n");
        printf("7 ] DISPLAY : \n");
        printf("8 ] QUIT : \n");
        scanf(" %c", &CHOICE);

        switch (CHOICE)
        {
        case 1:
            printf("enter the number : \n");
            scanf("%d", &NUM);
            INSERT_AT_FRONT(NUM);
            break;
        case 2:
            printf("enter the number : \n");
            scanf("%d", &NUM);
            INSERT_AT_LAST(NUM);
            break;
        case 3:
            printf("enter the number : \n");
            scanf("%d", &NUM);
            printf("enter the position you want to insert : \n");
            scanf("%d", &POS);
            INSERT_AT_SPECIFIC(POS, NUM);
            break;
        case 4:
            DELETE_AT_FRONT();
            break;
        case 5:
            DELETE_AT_LAST();
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &POS);
            DELETE_AT_SPECIFIC(POS);
            break;
        case 7:
            DISPLAY();
            break;
        case 8:
            return 0;
        }
    }
    return 0;
}
