// 56. Write a program to simulate music player application using suitable data
// structure. There is no estimation about number of music files to be managed by
// the music player. Your program should support all the basic music player
// operations to play and manage the playlist.

#include <stdio.h>
#include <stdlib.h>

struct MUSIC_SIMULATE
{
    int ID;
    char MUSIC[100];
    char MUSIC_GENRES[100];
    struct MUSIC_SIMULATE *LPTR;
    struct MUSIC_SIMULATE *RPTR;
};

struct MUSIC_SIMULATE *FIRST = NULL;

void INSERT_MUSIC()
{
    struct MUSIC_SIMULATE *NEW_MUSIC = (struct MUSIC_SIMULATE *)malloc(sizeof(struct MUSIC_SIMULATE));

    if (NEW_MUSIC == NULL)
    {
        printf("MEMORY ALLOCATION FAILED...\n");
        return;
    }

    struct MUSIC_SIMULATE *P = FIRST;

    printf("ENTER THE ID :");
    scanf("%d", &NEW_MUSIC->ID);
    getchar(); // removes leftover '\n'
    printf("ENTER THE MUSIC NAME : ");
    fgets(NEW_MUSIC->MUSIC, sizeof(NEW_MUSIC->MUSIC), stdin);
    printf("ENTER THE MUSIC GENRES : ");
    fgets(NEW_MUSIC->MUSIC_GENRES, sizeof(NEW_MUSIC->MUSIC_GENRES), stdin);

    NEW_MUSIC->RPTR = NULL;
    NEW_MUSIC->LPTR = NULL;

    if (FIRST == NULL)
    {
        FIRST = NEW_MUSIC;
        return;
    }

    while (P != NULL)
    {
        if (NEW_MUSIC->ID == P->ID)
        {
            printf("MUSIC PLAYER ID MUST BE UNIQUE...\n");
            free(NEW_MUSIC);
            return;
        }

        if (P->RPTR == NULL)
        {
            break;
        }

        P = P->RPTR;
    }

    P->RPTR = NEW_MUSIC;
    NEW_MUSIC->LPTR = P;

    printf("NEW MUSIC WAS ADDED...\n");
}

void MODIFY_MUSIC()
{
    if (FIRST == NULL)
    {
        printf("YOUR MUSIC PLAYLIST IS EMPTY...\n");
        return;
    }

    int ID;
    struct MUSIC_SIMULATE *MODIFY = FIRST;

    printf("ENTER THE MUSIC ID :");
    scanf("%d", &ID);
    getchar();

    while (MODIFY != NULL)
    {
        if (MODIFY->ID == ID)
        {
            printf("ENTER THE MUSIC NAME : ");
            fgets(MODIFY->MUSIC, sizeof(MODIFY->MUSIC), stdin);
            printf("ENTER THE MUSIC GENRES : ");
            fgets(MODIFY->MUSIC_GENRES, sizeof(MODIFY->MUSIC_GENRES), stdin);
            printf("MUSIC MODIFIED SUCCESSFULLY...\n");
            return;
        }
        MODIFY = MODIFY->RPTR;
    }
    if (MODIFY == NULL)
    {
        printf("YOUR MUSIC ID NOT FOUND.\n");
        return;
    }
}
void DELETE_MUSIC()
{
    if (FIRST == NULL)
    {
        printf("YOUR MUSIC PLAYLIST IS EMPTY...\n");
        return;
    }

    int ID;
    struct MUSIC_SIMULATE *DELETE = FIRST;

    printf("ENTER THE MUSIC ID :");
    scanf("%d", &ID);

    if (ID == FIRST->ID)
    {
        DELETE = FIRST;
        FIRST = FIRST->RPTR;

        if (FIRST != NULL)
        {
            FIRST->LPTR = NULL;
        }

        free(DELETE);

        printf("YOUR MUSIC RECORD IS DELETED.\n");
        return;
    }

    while (DELETE->RPTR != NULL)
    {
        if (DELETE->ID == ID)
        {
            DELETE->RPTR->LPTR = DELETE->LPTR;
            DELETE->LPTR->RPTR = DELETE->RPTR;
            printf("YOUR MUSIC RECORD IS DELETED.\n");
            free(DELETE);
            return;
        }
        DELETE = DELETE->RPTR;
    }

    if (DELETE->ID == ID)
    {
        DELETE->LPTR->RPTR = NULL;
        printf("YOUR MUSIC RECORD IS DELETED.\n");
        free(DELETE);
        return;
    }
    printf("YOUR MUSIC ID NOT FOUND.\n");
    return;
}
void SEARCH_MUSIC()
{
    if (FIRST == NULL)
    {
        printf("YOUR MUSIC PLAYLIST IS EMPTY...\n");
        return;
    }

    int ID;
    struct MUSIC_SIMULATE *SEARCH = FIRST;

    printf("ENTER THE MUSIC ID :");
    scanf("%d", &ID);

    while (SEARCH != NULL)
    {
        if (SEARCH->ID == ID)
        {
            printf("YOUR MUSIC ID IS FOUND : \n");
            printf("DETAILS :-\n");
            printf("MUSIC ID = %d\n", SEARCH->ID);
            printf("MUSIC NAME : \n");
            fputs(SEARCH->MUSIC, stdout);
            printf("MUSIC GENRES : \n");
            fputs(SEARCH->MUSIC_GENRES, stdout);
            return;
        }
        SEARCH = SEARCH->RPTR;
    }

    printf("YOUR MUSIC ID NOT FOUND.\n");
    return;
}
void DISPLAY_MUSIC()
{
    if (FIRST == NULL)
    {
        printf("MUSIC PLAYER LIST IS EMPTY..\n");
        return;
    }
    struct MUSIC_SIMULATE *P = FIRST;

    while (P != NULL)
    {
        printf("MUSIC ID : %d \n", P->ID);
        printf("MUSIC NAME : ");
        fputs(P->MUSIC, stdout);
        printf("MUSIC TYPE : ");
        fputs(P->MUSIC_GENRES, stdout);
        P = P->RPTR;
    }
}
int main()
{
    int choice;

    while (1)
    {
        printf("---------------  YOUR MUSIC SIMULATOR  ---------------\n");
        printf("1 ] ADD MUSIC : \n");
        printf("2 ] MODIFY MUSIC : \n");
        printf("3 ] DELETE MUSIC : \n");
        printf("4 ] DISPLAY MUSIC PLAYLIST : \n");
        printf("5 ] SEARCH MUSIC : \n");
        printf("6 ] QUIT : \n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            INSERT_MUSIC();
            break;
        case 2:
            MODIFY_MUSIC();
            break;
        case 3:
            DELETE_MUSIC();
            break;
        case 4:
            DISPLAY_MUSIC();
            break;
        case 5:
            SEARCH_MUSIC();
            break;
        case 6:
            printf("QUIT !..");
            return 0;
        default:
            printf("INVALID ! PLEASE ENTER VALID CHOICE....\n");
            break;
        }
    }
    return 0;
}