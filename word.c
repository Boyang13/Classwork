#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//adds character to end of string array
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
void Scoreboard(int guesses, int a)
{
   //open scoreboard or write to it
    if (a == 1)
    {
        char name[20];
        char date[20];
        FILE *scoreboard = fopen("scoreboard.txt", "a");
        Player player;
        char playerName[100];
        player.points = (guesses + 1) * 10;
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
        //prints if letter is guessed
        if (strchr(x, y[i]))
        {
            printf("%c", y[i]);
        }
        else
        //hides if not printed
        {
            printf("_ ");
            over = 1;
        }
    }
    printf("\nLetters you have guessed: %s", x);
    printf("\nEnter your guess:");
    return over;
}

int receive(int x, int y)
{
    int w = 0;
    while (w == 0)
    {
        //checks for integer input
        if (scanf("%d", &w) != 1)
        {
            //
            int c;
            while ((c = getchar()) != '\n' && c != EOF){}
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

//contains my two lists and main function to the game
void list(int x)
{
    const char *a[10] = {"society", "integratedphysicsandchemistry", "americanidea", "calculusbc", "waterpolo", "frenchtwohonors", "computerscience", "freeblock"};
    const char *b[20] = {"balloon", "golem", "lavahound", "elixergolem", "miner", "rocket", "giant", "electrogiant", "royalgiant", "goblingiant", "royalhogs", "hogrider", "icegolem", "wallbreakers"};
    //random pick
    int r = rand() % 20;
    int attempts = 5;
    char correct[26];
    //clears array
    correct[0] = '\0';
    //stores user input
    char g[2];
    //chooses random word
    char answer[strlen(a[r])];
    char answer1[strlen(b[r])];
    //gives word based on list chosen by user
    if (x == 1)
    {
        strcpy(answer, a[r]);
    }
    else
    {
        strcpy(answer, b[r]);
    }
    //prints word until game ends
    while (attempts > 0 && printword(correct, answer, attempts) == 1)
    {
        //asks for user input
        if (scanf("%1s", g) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }
        if (strpbrk(correct, &g[0]) != 0)
        {
            //no response if guessed letter is alreayd guessed
        }
        else if (strpbrk(answer, &g[0]) != 0)
        {
            //adds letter to guessed letters if right
            append(correct, g[0]);
        }
        else
        {
            //if not right, add to guessed letters and decrease attempt
            append(correct, g[0]);
            attempts--;
        }
    }
    system("clear");
    //prints message depending on game outcome
    if (attempts == 0)
    {
        printf("You lose! The answer was: %s.", answer);
    }
    else
    {
        printf("You win! Guesses left: %i. ", attempts);
        Scoreboard(attempts, 1);
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
        //1 = returns to menu to play again after game ends
        list(1);
        receive(1,1);
        menu();
    }
    if (input == 2)
    {
        list(2);
        receive(1,1);
        menu();
    }
    if (input == 3)
    {
        //goes back to menu when pressed 1
        printf("You have five tries to guess the word from the list. \n The asterisks represent the missing letters, which do not include capitol letters. \n You may type more than one letter at a time. \n The scoreboard will record your points and name. \n Press 1 to return. ");
        receive(1, 1);
        menu();
    }
    if (input == 4)
    {
        //prints scoreboard with previous attempts
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
    //start with menu
    menu();
}
