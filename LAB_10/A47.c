// 47. Write a program to sort elements of a linked list.
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
    struct NODE *NEWNODE = (struct NODE *)malloc(sizeof(struct NODE));

    if (NEWNODE == NULL)
    {
        printf("MEMORY ALLOCTION WAS FAILED...");
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
        printf("  %d  ", POINT->INFO);
        POINT = POINT->LINK;
    }

    printf("\n");
}

void SORT_LINKLIST_WITH_TEMP()
{
    struct NODE *CURRENT, *NEXT;
    int TEMP;

    if (FIRST == NULL || FIRST->LINK == NULL)
    {
        return;
    }

    for (CURRENT = FIRST; CURRENT != NULL; CURRENT = CURRENT->LINK)
    {
        for (NEXT = CURRENT->LINK; NEXT != NULL; NEXT = NEXT->LINK)
        {
            if (CURRENT->INFO > NEXT->INFO)
            {
                TEMP = CURRENT->INFO;
                CURRENT->INFO = NEXT->INFO;
                NEXT->INFO = TEMP;
            }
        }
    }
}

void SORT_LINKLIST_WITH_ACTUAL_NODES()
{
    if (FIRST == NULL || FIRST->LINK == NULL)
    {
        return;
    }

    // Initialize swapped to 1 so the while loop executes at least once
    int swapped = 1;
    struct NODE *CURRENT, *PREV, *NEXT;

    while (swapped)
    {
        swapped = 0;
        CURRENT = FIRST;
        PREV = NULL;

        while (CURRENT != NULL && CURRENT->LINK != NULL)
        {
            NEXT = CURRENT->LINK;

            if (CURRENT->INFO > NEXT->INFO)
            {

                CURRENT->LINK = NEXT->LINK;
                NEXT->LINK = CURRENT;

                if (PREV == NULL)
                {
                    FIRST = NEXT;
                }
                else
                {
                    PREV->LINK = NEXT;
                }

                PREV = NEXT;
                swapped = 1;
            }
            else
            {
                PREV = CURRENT;
                CURRENT = CURRENT->LINK;
            }
        }
    }
}

int main()
{
    int x, n;

    printf("ENTER THE NUM HOW MANY NODE YOU WANT TO ENTER: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("ENTER THE NODE INFO: ");
        scanf("%d", &x);
        INSERT(x);
    }

    printf("\n=> YOUR LINKED LIST BEFORE SORTING : ");
    DISPLAY();

    SORT_LINKLIST_WITH_ACTUAL_NODES();

    printf("=> YOUR LINKED LIST AFTER SORTING: ");
    DISPLAY();

    return 0;
}