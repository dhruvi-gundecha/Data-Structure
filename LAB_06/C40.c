// WAP to define a C structure named Student (roll_no, name, branch and batch_no)
// and also to access the structure members using Pointer.

#include <stdio.h>

struct STUDENT
{
    int ROLL_NO;
    char NAME[10];
    char BRANCH[10];
    int BATCH_NO;
};

void main()
{
    struct STUDENT S1;
    struct STUDENT *P;

    P = &S1;

    printf("ENTER THE NAME : ");
    scanf("%s", P->NAME);
    printf("ENTER THE ROLL NO : ");
    scanf("%d", &P->ROLL_NO);
    printf("ENTER THE BRANCH : ");
    scanf("%s", P->BRANCH);
    printf("ENTER THE BATCH NO : ");
    scanf("%d", &P->BATCH_NO);

    printf("NAME : %s\n", P->NAME);
    printf("ROLL NO : %d\n", P->ROLL_NO);
    printf("BRANCH : %s\n", P->NAME);
    printf("BATCH NO : %d\n", P->BATCH_NO);
}