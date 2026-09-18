// 30. WAP to replace lowercase characters by uppercase & vice-versa in a user specified string.
// EX : This Is An ApPle

#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    char string[30];

    printf("ENTER THE STRING YOU WANT : ");
    scanf("%s", string);

    n = strlen(string);

    for (int i = 0; i < n; i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] = string[i] + 32;
        }
        else if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = string[i] - 32;
        }
    }

    puts(string);
    return 0;
}