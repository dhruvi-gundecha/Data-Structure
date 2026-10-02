// 62. Removing starts from a string Problem
// You are given a string s, which contains stars *. In one operation, you can:
// Choose a star in s. Remove the closest non-star character to its left, as well as
// remove the star itself. Return the string after all stars have been removed.

// Note :
//  The input will be generated such that the operation is always possible.
//  It can be shown that the resulting string will always be unique.

// Sample Example-1:
// Input: s = "leet**cod*e".
// Output: "lecoe"

// Sample Example-2:
// Input: s = "erase*****"
// Output: ""

#include <stdio.h>
#include <string.h>

void operation(char str[], int len)
{
    char result[100];
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        if (str[i] != '*')
        {
            top++;
            result[top] = str[i];
        }
        else
        {
            top--;
        }
    }

    result[top + 1] = '\0';

    printf("ANSWER : %s", result);
}

int main()
{
    int len;
    char str[100];

    printf("ENTER THE STRING : ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0'; // => to remove new line we need this to add zero at end...

    len = strlen(str);

    operation(str, len);

    return 0;
}