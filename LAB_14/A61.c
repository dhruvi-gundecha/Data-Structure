#include <stdio.h>
#include <string.h>

int isBalanced(char str[])
{
    char stack[100];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack[++top] = ch;
        }
        else
        {
            if (top == -1)
                return 0;

            char open = stack[top--];

            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '['))
                return 0;
        }
    }

    return (top == -1);
}

int main()
{
    int choice;

    while (1)
    {
        printf("enter your choice : \n");
        printf("1 ] start : \n");
        printf("2 ] stop : \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            char str[100];
            scanf("%s", str);

            int n = isBalanced(str);

            if (n == 1)
            {
                printf("Parenthesis are valid...\n");
            }
            else
            {
                printf("Parenthesis are invalid...%d\n");
            }
            break;
        case 2:
            return 0;
        default:
            printf("invalid choice...\n");
            break;
        }
    }

    return 0;
}