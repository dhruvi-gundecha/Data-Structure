// 41. Write a program to implement a node structure for singly linked list.
// Read the data in a node, print the node.
#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int INFO;
    struct NODE *LINK;
};

struct NODE *FIRST = NULL;

int main()
{

    struct NODE *N1 = (struct NODE *)malloc(sizeof(struct NODE));

    FIRST = N1;
    N1->LINK = NULL;

    printf("ENTER THE NODE INFO : ");
    scanf("%d", &(N1->INFO));

    printf("NODE N1 = %d\n", N1->INFO);

    free(N1);
    return 0;
}