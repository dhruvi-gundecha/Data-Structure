// 57. Write a menu driven program to implement following operations on the Stack
// using an Array
//  PUSH, POP, DISPLAY
//  PEEP, CHANGE

#include <stdio.h>

#define MAX 3

int STACK[MAX];
int TOP = -1;

void STACK_PUSH(int n)
{
    if (TOP == MAX - 1)
    {
        printf("STACK OVERFLOW...\n");
        return;
    }

    TOP++;
    STACK[TOP] = n;

    printf("ELEMENT IS INSERTED...\n");
}

int STACK_POP()
{
    if (TOP == -1)
    {
        printf("STACK UNDERFLOW...\n");
        return -1;
    }

    return STACK[TOP--];
}

void STACK_DISPLAY()
{
    if (TOP == -1)
    {
        printf("STACK UNDERFLOW...\n");
        return;
    }

    printf("\nSTACK:\n");

    for (int i = TOP; i >= 0; i--)
    {
        printf("%d\n", STACK[i]);
    }
}

int STACK_PEEP()
{
    if (TOP == -1)
    {
        printf("STACK UNDERFLOW...\n");
        return -1;
    }

    return STACK[TOP];
}

void STACK_CHANGE()
{
    int position, num;

    if (TOP == -1)
    {
        printf("STACK UNDERFLOW...\n");
        return;
    }

    printf("ENTER POSITION TO CHANGE: ");
    scanf("%d", &position);

    if (position < 0 || position > TOP)
    {
        printf("INVALID POSITION...\n");
        return;
    }

    printf("ENTER NEW ELEMENT: ");
    scanf("%d", &num);

    STACK[position] = num;

    printf("ELEMENT CHANGED SUCCESSFULLY...\n");
}

int main()
{
    int choice, n;

    while (1)
    {
        printf("\n---------------- STACK OPERATIONS ----------------\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. PEEP\n");
        printf("5. CHANGE\n");
        printf("6. QUIT\n");

        printf("ENTER YOUR CHOICE: ");
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
        }
    }

    return 0;
}