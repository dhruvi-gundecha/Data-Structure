//  Design anagram game using array.
// Allow a user to enter N words and store it in an array.
// Generate a random number between 0 to N-1.
// Based on the random number generated display the word stored at that index of an array and allow user to enter its anagram.
// Check whether the word entered by the user is an anagram of displayed number or not and display an appropriate message.
// uGiven a word A and word B. B is said to be an anagram of A if and only if the characters present in B is same as characters present in A, irrespective of their sequence. For ex: “LISTEN” == “SILENT”

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void fun(char[], int);

void fun(char P[], int m)
{
    int temp;
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (P[i] >= P[j])
            {
                temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }
}

int main()
{
    int m, n, len;

    printf("ENTER THE NUMBER OF LETTER'S YOU WANT TO ENTER :");
    scanf("%d", &m);
    printf("ENTER THE NUMBER OF WORD'S YOU WANT TO ENTER :");
    scanf("%d", &n);

    char string[n][m + 1], ana[1][m + 1]; // n STRING AND m CHARACTER

    for (int i = 0; i < n; i++)
    {
        printf("ENTER THE WORD : ");
        scanf("%s", string[i]);
    }

    srand(time(0));
    int r;
    r = rand() % n;
    r = floor(r);

    printf("SELECTED WORD IS : %s\n", string[r]);

    printf("ENTER GIVEN ANAGRAM WORD OF ABOVE: ");
    scanf("%s", ana[0]);
    len = strlen(string[r]);
    fun(string[r], len);
    fun(ana[0], len);

    if (strcmp(ana[0], string[r]) == 0)
    {
        printf("GIVEN WORD IS AN ANAGRAM . ");
    }
    else
    {
        printf("GIVEN WORD IS NOT AN ANAGRAM . ");
    }
    return 0;
}