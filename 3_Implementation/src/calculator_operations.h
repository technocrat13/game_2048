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

//#include <stdio_ext.h>

#define n 4

int gameboard[n][n];

void setup_gameboard();
//initilize with 0s

void slam_left();
//join move terms left 3 times till there is no coliisons

void compress_left();
//if two of them are the same join and leave the last right one empty

void print_gameboard();
//print in pretty format

void transpose();
//transpose of 2d array

void reverse();
//reverse the 2d array

void pick_random_tile();
//place random 





#endif  /* #define __CALCULATOR_OPERATIONS_H__ */