#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void append(char *a, char b)
{
    int len = strlen(a);
    a[len] = b;
    a[len + 1] = '\0';
}

//Gives structure of scoreboard
typedef struct
{
    int points;
    char playerName[20];
}
Player;

//function that stores player information in file
void Scoreboard(int guesses, int time)
{

        FILE *scoreboard = fopen("scoreboard.txt", "a");
        Player player;
        char playerName[100];
        player.points = (guesses + 1) * 10 - time * 5;
        if(player.points < 0)
        {
            player.points = 0;
        }
        printf("\n\nGive name: ");
        scanf("%s", playerName);
        strcpy(player.playerName, playerName);

        fprintf(scoreboard, "Name: %s \nPoints: %d\n\n", player.playerName, player.points);
        fclose(scoreboard);
}

void printScore(void){
    system("clear");
        FILE *fptr;
        fptr = fopen("scoreboard.txt", "r");
        char c;
        if (fptr == NULL)
        {
            printf("Cannot open file \n");
            exit(0);
        }
        c = fgetc(fptr);
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(fptr);
        }

        fclose(fptr);
        printf("\nPress 1 to return to menu:\n");
}
int printword(char *x, char *y, int z)
{
    system("clear");
    printf("Guesses: %i\n", z);
    int over = 0;
    for (int i = 0; i < strlen(y); i++)
    {
        if (strchr(x, y[i]))
        {
            printf("%c", y[i]);
        }
        else
        {
            printf("_ ");
            over = 1;
        }
    }
    printf("\nGuessed Letters: %s", x);
    printf("\nEnter Guess:");
    return over;
}

int receive(int x, int y)
{
    int w = 0;
    while (w == 0)
    {
        if (scanf("%d", &w) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }

        for (int i = x; i <= y; i++)
        {
            if (w == i)
            {
                return w;
            }
        }
        w = 0;
    }
    return -1;
}

void game(int x)
{
    const char *a[10] = {"society", "integratedphysicsandchemistry", "americanidea", "calculusbc", "waterpolo", "frenchtwohonors", "computerscience", "freeblock"};
    const char *b[20] = {"balloon", "golem", "lavahound", "elixergolem", "miner", "rocket", "giant", "electrogiant", "royalgiant", "goblingiant", "royalhogs", "hogrider", "icegolem", "wallbreakers"};
    srand(time(NULL));
    int r = rand() % 10;
    int chances = 7;
    char right[26];
    right[0] = '\0';
    char g[2];
    char answer[strlen(a[r])];
    char answer1[strlen(b[r])];
    if (x == 1)
    {

        strcpy(answer, a[r]);
    }
    else
    {

        strcpy(answer, b[r]);
    }
    time_t start, end;
    double dif;

    time(&start);

    while (chances > 0 && printword(right, answer, chances) == 1)
    {
        if (scanf("%1s", g) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }
        if (strpbrk(right, &g[0]) != 0)
        {
        }
        else if (strpbrk(answer, &g[0]) != 0)
        {
            append(right, g[0]);

        }
        else
        {
            append(right, g[0]);
            chances--;
        }
    }
    time(&end);
    dif = difftime(end, start);
    system("clear");
    if (chances == 0)
    {
        printf("You lose! The answer was: %s.", answer);
    }
    else
    {
        printf("You win! Guesses left: %i. Time used: %.1f", chances, dif);
        Scoreboard(chances, dif);
    }
    printf(" Press 1 to return to menu: \n");
}

//creates the menu and sets ifs to state what to do when the person enters a number
void menu(void)
{
    system("clear");
    printf("##########################################\n");
    printf("#1. Play List 1: Classes                 #\n");
    printf("#2. Play List 2: Clash Royale.           #\n");
    printf("#3. Instructions                         #\n");
    printf("#4. Scoreboard                           #\n");
    printf("#5. Exit Program                         #\n");
    printf("##########################################\n");
    int input = receive(1, 5);
    if (input == 1)
    {
        game(1);
        receive(1,1);
        menu();
    }
    if (input == 2)
    {
        game(2);
        receive(1,1);
        menu();
    }
    if (input == 3)
    {
        printf("You have five tries to guess the word from the list. \n The asterisks represent the missing letters, which do not include capitol letters. \n You may type more than one letter at a time. \n The scoreboard will record your points and name. \n Press 1 to return. ");
        receive(1, 1);
        menu();
    }
    if (input == 4)
    {
        printScore();
        receive(1, 1);
        menu();
    }
    else
    {
        exit(0);
    }
}

int main(int argc, string argv[])
{
    menu();
}
