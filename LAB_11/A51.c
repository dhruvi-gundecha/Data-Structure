// 51. Write a menu driven program to implement following operations on the circular linked list.
//  Insert a node at the front of the linked list.
//  Delete a node from specified position.
//  Insert a node at the end of the linked list.
//  Display all nodes.
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *LINK;
};
struct NODE *FIRST = NULL;
struct NODE *LAST;

void DISPLAY()
{
    if (FIRST == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }

    struct NODE *P = FIRST;

    do
    {
        printf("NODE = %d\n", P->INFO);
        P = P->LINK;
    } while (P != FIRST);
}

void INSERT_AT_FIRST(int x)
{

    struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

    if (FIRST == NULL)
    {
        NEWNODE->INFO = x;
        NEWNODE->LINK = NEWNODE;
        FIRST = LAST = NEWNODE;
    }
    else
    {
        NEWNODE->INFO = x;
        NEWNODE->LINK = FIRST;
        FIRST = NEWNODE;
        LAST->LINK = FIRST;
    }
}

void INSERT_AT_LAST(int x)
{
    struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

    if (NEWNODE == NULL)
    {
        printf("MEMORY ALLOCATION FAILED...");
        return;
    }
    if (FIRST == NULL)
    {
        NEWNODE->INFO = x;
        NEWNODE->LINK = NEWNODE;
        FIRST = LAST = NEWNODE;
    }
    else
    {
        struct NODE *POINT = FIRST;
        while (POINT != LAST)
        {
            POINT = POINT->LINK;
        }

        POINT->LINK = NEWNODE;
        NEWNODE->INFO = x;
        NEWNODE->LINK = FIRST;
        LAST = NEWNODE;
    }
}

void DELETE_SPECIFIC_ELEMENT(int x)
{
    if (FIRST == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }

    struct NODE *DEL = FIRST;
    struct NODE *PRE = LAST;

    // Search the node
    do
    {
        if (DEL->INFO == x)
        {
            break;
        }

        PRE = DEL;
        DEL = DEL->LINK;

    } while (DEL != FIRST);

    // Element not found
    if (DEL->INFO != x)
    {
        printf("YOUR GIVEN ELEMENT IS NOT FOUND.....\n");
        return;
    }

    // Only one node
    if (FIRST == LAST)
    {
        FIRST = NULL;
        LAST = NULL;
        free(DEL);
        return;
    }

    // Deleting FIRST
    if (DEL == FIRST)
    {
        FIRST = FIRST->LINK;
        LAST->LINK = FIRST;
        free(DEL);
        return;
    }

    // Deleting LAST or middle node
    PRE->LINK = DEL->LINK;

    if (DEL == LAST)
    {
        LAST = PRE;
    }

    free(DEL);
}

int main()
{
    while (1)
    {
        int x, n, choice;

        printf("ENTER THE OPERATION YOU WANT : \n");
        printf("1.  INSERT INTO FIRST : \n");
        printf("2.  INSERT INTO LAST  : \n");
        printf("3.  DELETE SPECIFIC NODE  : \n");
        printf("4.  DISPLAY THIS LINKED LIST : \n");
        printf("5.  EXIT : \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("ENTER THE NODE INFO YOU WANT TO ADD AT FIRST : ");
            scanf("%d", &x);
            INSERT_AT_FIRST(x);
            break;
        case 2:
            printf("ENTER THE NODE INFO YOU WANT TO ADD AT LAST : ");
            scanf("%d", &x);
            INSERT_AT_LAST(x);
            break;
        case 3:
            printf("ENTER THE NODE INFO YOU WANT TO DELETE : ");
            scanf("%d", &x);
            DELETE_SPECIFIC_ELEMENT(x);
            break;
        case 4:
            DISPLAY();
            break;
        case 5:
            printf("QUIT... ");
            return 0;
        default:
            printf("ENTER THE VAILD CHOICE!....\n");
        }
        continue;
    }
    return 0;
}