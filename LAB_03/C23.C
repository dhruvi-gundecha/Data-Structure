// 23. WAP to sort the N names in an alphabetical order.

#include <stdio.h>
#include <string.h>
void main()
{
    char NAME[5][10]; // 5 STRING AND 10 CHARACTER
    char TEMP[2][10]; // 2 STRING AND 10 CHARACTER

    for (int i = 0; i < 5; i++)
    {
        printf("ENTER THE NAME :");
        scanf("%s", NAME[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if ((strcmp(NAME[i], NAME[j]) > 0))
            {
                strcpy(TEMP[1], NAME[i]);
                strcpy(NAME[i], NAME[j]);
                strcpy(NAME[j], TEMP[1]);
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", NAME[i]);
    }
}