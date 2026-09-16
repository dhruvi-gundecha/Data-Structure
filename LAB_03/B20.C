// 20. Write a program to find whether the array contains a duplicate number or not.

#include <stdio.h>
int main()
{

    int i, n;
    printf("ENTER THE ARRAY SIZE :");
    scanf("%d", &n);

    int array[n];

    for (i = 0; i < n; i++)
    {
        printf("ENTER THE ARRAY ELEMENT : ");
        scanf("%d", &array[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                printf("DUPLICATE ELEMENT FOUND.");
                break;
                j--;
            }
        }
    }
}