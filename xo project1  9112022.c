
//https://www.ideone.com/5SydfG
//the clear code

#include <stdio.h>
#include <stdlib.h>

char places[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
//the main places in shape which appear in shape
//we make it global to use it in any place
//its c char to swap them with x and o

int marked[9] = {0};
//to replace every full block with -1 until user choose umber was chosen tell him its not valid
//and make all it 0 to change it -1
//or we can make int marked[] = {0, 0, 0, 0, 0, 0, 0, 0 ,0};

const int BOARD_SIZE = 9;
//the size of cells instead of write 9 in every loop

const int WIDTH = 3;
//the width of cells which 3 cells in every column

void shape(char arr[]);
//function to draw the main shape
//char arr[] = char places

void play();
//to play game and replace every number with user char


int check_winner(char arr[]);
//function to find the winner
//char arr[] = char places

void new_game();
//to ask user if he want to start a new game or not

void reset();
//to return the shape to his orginal shape when the user enter 1
//to play a new game

int valid_move(int num)
//when the user enter non valid move

int main()
{
    play();

    return 0;
}

void shape(char arr[])
//to draw shape we can't do it with for loop
// int arr[] = char places;
{
    printf(" ");
    printf("-----------------------\n");
    //23 dash
    printf("|\t|\t|\t|\t\n|   %c\t|   %c\t|   %c\t|\t\n|\t|\t|\t|\t\n",arr[0],arr[1],arr[2]);
    //9 in each col
    printf(" ");
    printf("-----------------------\n");
    printf("|\t|\t|\t|\t\n|   %c\t|   %c\t|   %c\t|\t\n|\t|\t|\t|\t\n",arr[3],arr[4],arr[5]);
    printf(" ");
    printf("-----------------------\n");
    printf("|\t|\t|\t|\t\n|   %c\t|   %c\t|   %c\t|\t\n|\t|\t|\t|\t\n",arr[6],arr[7],arr[8]);
    printf(" ");
    printf("-----------------------\n");

    return;
}

void play()
//to start the game
{
    //to update the shape with x or o depend on user choice instead of the same shape with numbers will update with user choice and other valid numbers
    shape(places);

    //for every loop we get number from user 1 to 9
    //for every loop we get char from user x or o
    for(int i = 1; i <= BOARD_SIZE; i++)
    {
        int num;
        char player;

        //to swap turns
        if(i % 2 != 0)
        {
            printf("Enter a number between [1, 9] (inclusive).\nIt's X turn\n");
            player = 'X';
        }
        else
        {
            printf("Enter a number between [1, 9] (inclusive).\nIt's O turn\n");
            player = 'O';
        }
        //get the number from user which we will swap it with x or o depend on who's turn
        scanf("%d",&num);

        //check from user number if its valid or not
        //if the user enter number less than 1 or more than 9 or the array of marked. num-1 because we start with 0
        //equal -1 that mean this place is full

        /*if(num < 1 || num > 9 || (marked[num - 1] == -1))*/
        //we will modify it and make it in function

        if(!valid_move(num))
        {
            printf("Invalid choice\n");

            //to start from 1 again if the user enter invalid number until to start from 1 not 2
            i--;

            //to start loop again without affect on times of loop
            continue;

        }
        //update the array of 0 with -1 enter the block which he choose and we -1 from num because the array started with 0
        marked[num - 1] = -1;

        //update the array of numbers with char depend on number of user with x or o
        places[num - 1] = player;

        //draw the shape again but with char update
        shape(places);

        //after 5 times may be someone win so we will check
        if(i >= 5)
        {
            if(check_winner(places) == 2)
            {
                printf("%c wins the game.Do you want to play another game?",player);
                new_game();
            }
        }

        //if all numbers is finished and we didn't have winner
        //we write check_winner(places) because it's update with char x or o
        if(i == BOARD_SIZE && check_winner(places) == 1)
        {
            printf("drawDo you want to play another game?\n");
            new_game();
        }


    }
    return;
}

int check_winner(char arr[])
//conditions to win the game
// char arr[] = char places
//we can make it with if or for in both cases the time complexity is o(1) because i know the number of repetitions
{
    //to check from row
    for(int i = 0; i < BOARD_SIZE; i+=WIDTH)
    {
        if(arr[i] == arr[i+1] && arr[i] == arr[i+2])
            //1 2 3
            //4 5 6
            //7 8 9
        {
            //the best is to return 1 or 0 which mean true or false
            //return 2;
            return 1;
        }
    }
    //check column
    for(int i = 0; i < WIDTH; i++)
    {
        if(arr[i] == arr[i+3] && arr[i] == arr[i+6])
        {
            //1 4 7
            //2 5 8
            //3 6 9
            //return 2;
            return 1;
        }
    }
    //check diagonal
    if((arr[0] == arr[4] && arr[0] == arr[8]) || (arr[2] == arr[4] && arr[2] == arr[6]))
    {
        //1 5 9
        //3 5 7
        //return 2;
        //return 2;
        return 1;
    }
    //if no winner
    else
    {
        //return 1;
        return 0;
    }

    /*
    if(a[0] == a[1] &&a[1] == a[2])             //1 2 3
        return 2;
    else if(a[0] == a[4] && a[4] == a[8])       //1 5 9
        return 2;
    else if(a[0] == a[3] && a[3] == a[6])       //1 4 7
        return 2;
    else if(a[2] == a[4] && a[4] == a[6])       //3 5 7
        return 2;
    else if(a[2] == a[5] && a[5] == a[8])       //3 6 9
        return 2;
    else if(a[1] == a[4] && a[4] == a[7])       //2 5 8
        return 2;
    else if(a[6] == a[7] && a[7] == a[8])       //7 8 9
        return 2;
    else if(a[3] == a[4] && a[4] == a[5])       //4 5 6
        return 2;
    */
}

void new_game()
{
    printf("Enter 0 to exit, 1 to continue\n");
    int choice;
    scanf("%d",&choice);

    //if the user want to play again return the array of places to its values from 1 to 9 without x or o
    //and return the array of 0 to its values without updates the last game
    /*if(choice == 1)
    {
        places[0] = '1';
        places[1] = '2';
        places[2] = '3';
        places[3] = '4';
        places[4] = '5';
        places[5] = '6';
        places[6] = '7';
        places[7] = '8';
        places[8] = '9';

        marked[0] = 0;
        marked[1] = 0;
        marked[2] = 0;
        marked[3] = 0;
        marked[4] = 0;
        marked[5] = 0;
        marked[6] = 0;
        marked[7] = 0;
        marked[8] = 0;

        */

        //but the best we modify it and make it with loop in a function
        //his name is reset
        reset();

        //and call the function of play game again
        play();
    }
    //if the user want to exit game not play again
    else if(choice == 0)
    {
        //its function in c to exit program
        exit(0);
    }
    //if the user enter number else 0 or 1
    else
    {
        //if the user enter number other than 1 or 0 tell him its not a valid number and
        printf("Invalid number\n");
        //ask the question again
        new_game();
    }
    return;
}


void reset()
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        places[i] = i + '1';
        marked[i] = 0;
    }
}

int valid_move(int num)
{
    return num >= -1 && num <= 9 && !marked[num - 1];
}
