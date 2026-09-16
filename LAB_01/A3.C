// 3. WAP to determine whether the entered character is vowel or not :-
// => USING SWITCH CASE :-
#include <stdio.h>
int main()
{
    char ch;
    printf("ENTER THE CHARACTER : ");
    scanf("%c", &ch);

    switch (ch)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'i':
    case 'o':
    case 'e':
    case 'u':
        printf("GIVEN CHARACTER IS VOWEL.");
        break;
    default:
        printf("GIVEN CHARACTER IS CONSONENT.");
        break;
    }
    return 0;
}
