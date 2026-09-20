// WAP to allocate and de-allocate memory for int, char and float variable at runtime.
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int *I;
    float *F;
    char *C;

    I = (int *)malloc(sizeof(int));
    C = (char *)malloc(sizeof(char));
    F = (float *)malloc(sizeof(float));

    *I = 5;
    *C = 'A';
    *F = 5.00;

    printf("SIZE OF INTEGER = %d\n ", *I);
    printf("SIZE OF CHAR = %d\n", *C);
    printf("SIZE OF FLOAT = %d \n", *F);

    free(I);
    free(F);
    free(C);
}