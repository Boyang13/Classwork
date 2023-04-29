#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>
#include <curses.h>
#include <ctype.h>
#include <unistd.h>

//Overall code inspired by https://www.geeksforgeeks.org/validity-of-a-given-tic-tac-toe-board-configuration/#

// declares numbers of the boxes of the game board
char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// starting menu
void start();

// function prototyping
// prints the menu of the game
void menu();

// puts the player's mark on the box that they have chosen
void select(int, char);

// contains all the winning conditions and checks if a player satisfies one
bool check();

// general procedure of game
void game();

// checks if it is a tie
bool check_Full();

// asks user whether they want to use X or O. This is a 2 person game so who goes first depends on the person's answer
char letter();

// some cases depending on what input user chooses
int main()
{
    int a = -1;
    do
    {
        start();
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            game();
            break;
        case 0:
            printf("Goodbye\n");
            exit(-1);
        default:
            printf("Error! Please try again!\n");
            break;
        }
    } while (a);
    return 0;
}

// main function that calls functions and defines players and prints match results
void game()
{
    int choice, player = 1, i;
    int a;
    char piece;
    piece = letter();
    printf("\n\nWelcome to Tic Tac Toe\n\n");
    do
    {
        // calls function
        menu();
        if (player % 2)
        {
            player = 1;
        }
        else
        {
            player = 2;
        }
        printf("Player %d, enter a number: \n\n", player);
        scanf("%d", &choice);
        if (player == 1)
        {
            piece = 'X';
        }
        else
        {
            piece = 'O';
        }
        select(choice, piece);
        i = check();
        a = check_Full();
        player++;
    } while (i == false && a == false);
    menu();
    if (i == true)
    {
        printf("Player %d has won the game!\n", --player);
    }
    if (a == true)
    {
        printf("This is a tie game!\n");
    }
    if (i == true || a == true)
    {
        board[1] = '1', board[2] = '2', board[3] = '3', board[4] = '4', board[5] = '5', board[6] = '6', board[7] = '7', board[8] = '8', board[9] = '9';
    }
}

void start()
{
    printf("loading...\n");
    sleep(3);
    printf("\e[1;1H\e[2J");
    printf("##########################################\n");
    printf("#Tic-Tac_Toe                             #\n");
    printf("#Instructions: Line up three to win!     #\n");
    printf("# Enter the number displayed on the      #\n");
    printf("# specific box during your turn.         #\n");
    printf("#1. Play                                 #\n");
    printf("#0. Exit Program                         #\n");
    printf("##########################################\n");
}

void menu()
{
    printf("generating...\n");
    sleep(2);
    printf("\e[1;1H\e[2J");
    printf("Player 1 = (X)    Player 2 = (O)\n\n");
    printf(" %c | %c | %c \n", board[1], board[2], board[3]);
    printf("---|---|--- \n");
    printf(" %c | %c | %c \n", board[4], board[5], board[6]);
    printf("---|---|--- \n");
    printf(" %c | %c | %c \n", board[7], board[8], board[9]);
    printf("\n");
}

char letter()
{
    char piece;
    //credit: https://stackoverflow.com/questions/66927511/what-does-e-do-what-does-e11h-e2j-do
    printf("\e[1;1H\e[2J");
    printf("Use X or O?");
    do
    {
        piece = toupper(getchar());
        if (piece == '\n')
            continue;
        if (piece != 'X' && piece != 'O')
            puts("INVALID");
    } while (piece != 'X' && piece != 'O');
    return piece;
}

void select(int choice, char piece)
{
    // inputs players choice to the corresponding board
    int a = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (choice == i && board[i] != 'X' && board[i] != 'O')
        {
            board[i] = piece;
            a++;
        }
    }
    if (a == 0)
    {
        //credit: https://notes.burke.libbey.me/ansi-escape-codes/
        printf("\x1b[1F");
        printf("\x1b[2K");
        printf("INVALID MOVE\n");
    }
}

bool check()
{
    // checks the vertical columns for a winning line
    if (board[1] == board[4] && board[4] == board[7])
        return true;
    else if (board[2] == board[5] && board[5] == board[8])
        return true;
    else if (board[3] == board[6] && board[6] == board[9])
        return true;

    // checks the horizontal rows for a winning line
    else if (board[1] == board[2] && board[2] == board[3])
        return true;
    else if (board[4] == board[5] && board[5] == board[6])
        return true;
    else if (board[7] == board[8] && board[8] == board[9])
        return true;

    // checks the two diagonals for a winning line
    else if (board[1] == board[5] && board[5] == board[9])
        return true;
    else if (board[3] == board[5] && board[5] == board[7])
        return true;

    else
    {
        return false;
    }
}

bool check_Full()
{
    if (board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9')
        return true;
    else
        return false;
}
