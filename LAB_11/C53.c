// 53. Write a program to perform addition of two polynomial equations using appropriate data structure.
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int COEFF;
    int EXP;
    struct NODE *LINK;
};

struct NODE *FIRST1 = NULL;
struct NODE *FIRST2 = NULL;
struct NODE *FIRST3 = NULL;

void INSERT(struct NODE **FIRST, int COEFF, int EXP)
{
    struct NODE *NEWNODE =
        (struct NODE *)malloc(sizeof(struct NODE));

    NEWNODE->COEFF = COEFF;
    NEWNODE->EXP = EXP;
    NEWNODE->LINK = NULL;

    if (*FIRST == NULL)
    {
        *FIRST = NEWNODE;
    }
    else
    {
        struct NODE *POINT = *FIRST;

        while (POINT->LINK != NULL)
        {
            POINT = POINT->LINK;
        }

        POINT->LINK = NEWNODE;
    }
}

void DISPLAY(struct NODE *FIRST)
{
    struct NODE *POINT = FIRST;

    while (POINT != NULL)
    {
        printf("%dx^%d", POINT->COEFF, POINT->EXP);

        if (POINT->LINK != NULL)
        {
            printf(" + ");
        }

        POINT = POINT->LINK;
    }

    printf("\n");
}

void ADD()
{
    struct NODE *P = FIRST1;
    struct NODE *Q = FIRST2;

    while (P != NULL && Q != NULL)
    {
        if (P->EXP == Q->EXP)
        {
            INSERT(&FIRST3, P->COEFF + Q->COEFF, P->EXP);

            P = P->LINK;
            Q = Q->LINK;
        }
        else if (P->EXP > Q->EXP)
        {
            INSERT(&FIRST3, P->COEFF, P->EXP);

            P = P->LINK;
        }
        else
        {
            INSERT(&FIRST3, Q->COEFF, Q->EXP);

            Q = Q->LINK;
        }
    }

    while (P != NULL)
    {
        INSERT(&FIRST3, P->COEFF, P->EXP);
        P = P->LINK;
    }

    while (Q != NULL)
    {
        INSERT(&FIRST3, Q->COEFF, Q->EXP);
        Q = Q->LINK;
    }
}

int main()
{
    int n, coeff, exp;

    printf("ENTER NUMBER OF TERMS IN FIRST POLYNOMIAL: ");
    scanf("%d", &n);

    printf("\nENTER FIRST POLYNOMIAL:\n");

    for (int i = 1; i <= n; i++)
    {
        printf("ENTER COEFFICIENT: ");
        scanf("%d", &coeff);

        printf("ENTER EXPONENT: ");
        scanf("%d", &exp);

        INSERT(&FIRST1, coeff, exp);
    }

    printf("\nENTER NUMBER OF TERMS IN SECOND POLYNOMIAL: ");
    scanf("%d", &n);

    printf("\nENTER SECOND POLYNOMIAL:\n");

    for (int i = 1; i <= n; i++)
    {
        printf("ENTER COEFFICIENT: ");
        scanf("%d", &coeff);

        printf("ENTER EXPONENT: ");
        scanf("%d", &exp);

        INSERT(&FIRST2, coeff, exp);
    }

    printf("\nFIRST POLYNOMIAL : ");
    DISPLAY(FIRST1);

    printf("SECOND POLYNOMIAL: ");
    DISPLAY(FIRST2);

    ADD();

    printf("RESULT            : ");
    DISPLAY(FIRST3);

    return 0;
}