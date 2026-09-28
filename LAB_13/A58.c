// 58. Write a program to implement stack using singly linked list.
// PEEP , POP , PUSH , CHANGE , DISPLAY

#include <stdio.h>
#include <stdlib.h>

struct STACK
{
    int INFO;
    struct SACK *LINK;
};

struct STACK *TOP = NULL;

void STACK_PUSH(int num)
{
    // => HERE STACK PUSH OPERATION IS INSERT THE ELEMENT INTO FIRST BECAUSE IT IS LIFO PROGRAM.
    // => LIFO = LAST IN FIRST OUT.

    struct STACK *NEW = (struct STACK *)malloc(sizeof(struct STACK));

    if (NEW == NULL)
    {
        printf("STACK OVERFLOW...\n");
        // => LINKED-LIST STACK DOES NOT HAVE A FIXED SIZE.
        // => HOWEVER, IF malloc() FAILS TO ALLOCATE MEMORY,
        // => STACK OVERFLOW CAN OCCUR.

        return;
    }

    // => ASSIGNING THE ELEMENT :-
    NEW->INFO = num;
    NEW->LINK = TOP;
    TOP = NEW;
}

int STACK_POP()
{
    if (TOP == NULL)
    {
        printf("YOUR STACK IS UNDERFLOW...\n");
        return -1;
    }

    struct STACK *TEMP = NULL;
    TEMP = TOP;
    TOP = TOP->LINK;
    int VAL = TEMP->INFO;
    free(TEMP);
    return VAL;
}

void STACK_DISPLAY()
{
    if (TOP == NULL)
    {
        printf("STACK IS UNDERFLOW...\n");
        return;
    }
    struct STACK *P = TOP;

    while (P != NULL)
    {
        printf("   %d   \n", P->INFO);
        P = P->LINK;
    }
}

int STACK_PEEP()
{
    if (TOP == NULL)
    {
        printf("YOUR STACK IS UNDERFLOW...\n");
        return -1;
    }

    int VAL = TOP->INFO;
    return VAL;
}

void STACK_CHANGE()
{
    if (TOP == NULL)
    {
        printf("YOUR STACK IS UNDERFLOW...\n");
        return;
    }

    struct STACK *P = TOP;

    int REPLACE, CHANGE;

    printf("ENTER THE NUMBER YOU WANT TO REPLACE : ");
    scanf("%d", &REPLACE);
    printf("ENTER THE NUMBER YOU WANT TO CHANGE : ");
    scanf("%d", &CHANGE);

    while (P != NULL)
    {
        if (P->INFO == CHANGE)
        {
            P->INFO = REPLACE;
            printf("CHANGED SUCESSFULLY...\n");
            return;
        }
        P = P->LINK;
    }
    printf("YOUR GIVEN ELEMENT NOT FOUND...\n");
    return;
}

int main()
{
    int choice, n;
    while (1)
    {
        printf("\n---------------  STACK MENU  ---------------\n");
        printf("1. PUSH : \n");
        printf("2. POP : \n");
        printf("3. DISPLAY : \n");
        printf("4. PEEP : \n");
        printf("5. CHANGE : \n");
        printf("6. QUIT : \n");
        printf("ENTER THE CHOICE = \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("ENTER THE NUMBER: ");
            scanf("%d", &n);

            STACK_PUSH(n);
            break;

        case 2:
            n = STACK_POP();

            if (n != -1)
            {
                printf("POP ELEMENT = %d\n", n);
            }
            break;

        case 3:
            STACK_DISPLAY();
            break;

        case 4:
            n = STACK_PEEP();

            if (n != -1)
            {
                printf("PEEP ELEMENT = %d\n", n);
            }
            break;

        case 5:
            STACK_CHANGE();
            break;

        case 6:
            printf("QUIT...\n");
            return 0;

        default:
            printf("INVALID CHOICE...\n");
            break;
        }
    }
    return 0;
}
