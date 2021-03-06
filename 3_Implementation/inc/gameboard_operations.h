/** 
* @file gameboard_operations.h
* Calculator application with 4 mathematical operations
*
*/
#ifndef __CALCULATOR_OPERATIONS_H__
#define __CALCULATOR_OPERATIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <conio.h>

//#include <stdio_ext.h>

#define n 4

int gameboard[n][n];

void setup_gameboard(int gameboard[n][n]);
//initilize with 0s

void slam_left(int gameboard[n][n]);
//join move terms left 3 times till there is no coliisons

void compress_left(int gameboard[n][n]);
//if two of them are the same join and leave the last right one empty

void print_gameboard(int gameboard[n][n]);
//print in pretty format

void transpose(int gameboard[n][n]);
//transpose of 2d array

void reverse(int gameboard[n][n]);
//reverse the 2d array

void pick_random_tile(int gameboard[n][n]);
//place random 

void raw_move_left(int gameboard[n][n]);

void move_left(int gameboard[n][n]);

void move_up(int gameboard[n][n]);

void move_down(int gameboard[n][n]);

void move_right(int gameboard[n][n]);

void game_loop();

typedef struct pos
{
    int y;
    int x;
}pos_t;



#endif  /* #define __CALCULATOR_OPERATIONS_H__ */