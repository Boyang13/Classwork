#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>
#include <curses.h>

//declares numbers of the boxes of the game board
int board[10] = {'0','1','2','3','4','5','6','7','8','9'};

//starting menu
void start();

//function prototyping
//prints the menu of the game
void menu();

//puts the player's mark on the box that they have chosen
void select(int, char);

//contains all the winning conditions and checks if a player satisfies one
bool check();

//general procedure of game
void game();

bool check_Full();

//some cases depending on what input user chooses
int main()
{
	int a = -1;
	do
	{
		start();
		scanf("%d", &a);
		switch(a)
		{
		case 1:
			game();
			break;
		case 0:
			exit(-1);
		default:
			printf("Error! Please try again!\n");
			break;
		}
	}while(a);
	return 0;
}

//main function that calls functions and defines players and prints match results
void game()
{
    int choice;
    int player = 1;
    int i;
    int a;
    char piece;
    printf("\n\nWelcome to Tic Tac Toe\n\n");
    do{
        //calls function
        menu();
        if(player % 2)
        {
            player = 1;
        }
        else
        {
            player = 2;
        }
        printf("Player %d, enter a number: \n\n", player);
        scanf("%d", &choice);
        if(player == 1)
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
        player ++;
    }while(i == false && a ==false);
    menu();
    if(i == true)
        printf("Player %d has won the game!\n", --player);
    if(a == true)
        printf("This is a tie game!\n");
    if(i == true || a == true)
        board[1] = '1', board[2] = '2', board[3] = '3', board[4] = '4', board[5] = '5', board[6] = '6', board[7] = '7', board[8] = '8', board[9] = '9';
}

void start()
{
    printf("##########################################\n");
    printf("Tic-Tac_Toe                              #\n");
    printf("Instructions: Line up three to win!      #\n");
    printf("Enter the number displayed on the        #\n");
    printf("specific box furing your turn            #\n");
    printf("#1. Play                                 #\n");
    printf("#0. Exit Program                         #\n");
    printf("##########################################\n");
}

void menu()
{
    printf("Player 1 = (X)    Player 2 = (O)\n\n");
    printf(" %c | %c | %c \n",board[1], board[2], board[3]);
    printf("---|---|--- \n");
    printf(" %c | %c | %c \n", board[4], board[5], board[6]);
    printf("---|---|--- \n");
    printf(" %c | %c | %c \n", board[7], board[8], board[9]);
    printf("\n");
}

void select(int choice, char piece)
{
    //inputs players choice to the corresponding board
    if(choice == 1)
        board[1] = piece;
    else if(choice == 2)
        board[2] = piece;
    else if(choice == 3)
        board[3] = piece;
    else if(choice == 4)
        board[4] = piece;
    else if (choice == 5)
        board[5] = piece;
    else if (choice == 6)
        board[6] = piece;
    else if (choice == 7)
        board[7] = piece;
    else if (choice == 8)
        board[8] = piece;
    else if (choice == 9)
        board[9] = piece;
    else
    {
        printf("Invalid move");
    }
}

bool check()
{
    //checks the vertical columns for a winning line
    if (board[1]== board[4] && board[4]== board[7])
        return true;
    else if(board[2]== board[5] && board[5]== board[8])
        return true;
    else if(board[3]== board[6] && board[6]== board[9])
        return true;

    //checks the horizontal rows for a winning line
    else if(board[1] == board[2] && board[2] == board[3])
        return true;
    else if(board[4]== board[5] && board[5]== board[6])
        return true;
    else if (board[7]== board[8] && board[8]== board[9])
        return true;

    //checks the two diagonals for a winning line
    else if(board[1]== board[5] && board[5]== board[9])
        return true;
    else if(board[3]== board[5] && board[5]== board[7])
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
        return  false;
}
