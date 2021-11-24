#include "unity.h"
#include "gameboard_operations.h"

/* Modify these two lines according to the project */
//#include <gameboard_operations.h>
#define PROJECT_NAME "2048"

/* Prototypes for all the test functions */
void test_setup_gameboard(void);
void test_slam_left(void);
void test_compress_left(void);
void test_transpose(void);
void test_reverse(void);
void test_raw_move_left(void);
void test_move_left(void);
void test_move_up(void);
void test_move_down(void);
void test_move_right(void);
void test_pick_random_tile(void);
//void test_move_left(void);
/*
int gameboard[4][4] = {
      {00, 00, 00, 00},
      {00, 00, 00, 00}, 
      {00, 00, 00, 00},
      {00, 00, 00, 00}};
*/

/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}

/* Start of the application test */
int main()
{
  /* Initiate the Unity Test Framework */
  UNITY_BEGIN();

  /* Run Test functions */

  RUN_TEST(test_setup_gameboard);
  RUN_TEST(test_slam_left);
  RUN_TEST(test_compress_left);
  RUN_TEST(test_transpose);
  RUN_TEST(test_reverse);
  RUN_TEST(test_raw_move_left);
  RUN_TEST(test_move_left);
  RUN_TEST(test_move_up);
  RUN_TEST(test_move_down);
  RUN_TEST(test_move_right);
  RUN_TEST(test_pick_random_tile);
  //RUN_TEST();

  /* Close the Unity Test Framework */
  return UNITY_END();
}



/* Write all the test functions */
void test_setup_gameboard(void)
{
  int new_gameboard[n][n];
  setup_gameboard(new_gameboard);
  //print_gameboard(new_gameboard);

  int test_gameboard[4][4] = {
      {0, 0, 0, 0},
      {0, 0, 0, 0}, 
      {0, 0, 0, 0},
      {0, 0, 0, 0}};

  int result = memcmp(new_gameboard, test_gameboard, 16);

  TEST_ASSERT_EQUAL(0, result);

/* Dummy fail*/
//TEST_ASSERT_EQUAL(15000, add(7500, 7500));
}


void test_slam_left(void)
{
  int new_gameboard[4][4] = {
      {2, 0, 2, 0},
      {0, 0, 0, 8},
      {2, 0, 0, 0},
      {0, 0, 2, 4}};


  slam_left(new_gameboard);
  //print_gameboard();
  
  int test_gameboard[4][4] = {
      {2, 2, 0, 0},
      {8, 0, 0, 0},
      {2, 0, 0, 0},
      {2, 4, 0, 0}};

  int result = memcmp(new_gameboard, test_gameboard, 16);

  TEST_ASSERT_EQUAL(0, result);

}


void test_compress_left(void)
{
  int new_gameboard[4][4] = {
      {2, 0, 2, 0},
      {0, 0, 8, 8},
      {2, 0, 0, 0},
      {0, 4, 4, 4}};


  compress_left(new_gameboard);
  //print_gameboard();
  
  int test_gameboard[4][4] = {
      {2, 0, 2, 0},
      {0, 0, 16, 0},
      {2, 0, 0, 0},
      {0, 8, 0, 4}};

  int result = memcmp(new_gameboard, test_gameboard, 16);

  TEST_ASSERT_EQUAL(0, result);
}



void test_transpose(void)
{
  int new_gameboard[4][4] = {
      {2, 0, 2, 0},
      {0, 0, 8, 8},
      {2, 0, 0, 0},
      {0, 4, 4, 4}};


  transpose(new_gameboard);
  //print_gameboard();
  
  int test_gameboard[4][4] = {
      {2, 0, 2, 0},
      {0, 0, 0, 4},
      {2, 8, 0, 4},
      {0, 8, 0, 4}};

  int result = memcmp(new_gameboard, test_gameboard, 16);

  TEST_ASSERT_EQUAL(0, result);


}

void test_reverse(void)
{
  int new_gameboard[4][4] = {
      {2, 0, 2, 0},
      {0, 0, 8, 8},
      {2, 0, 0, 0},
      {0, 4, 4, 4}};


  reverse(new_gameboard);
  //print_gameboard();
  
  int test_gameboard[4][4] = {
      {0, 2, 0, 2},
      {8, 8, 0, 0},
      {0, 0, 0, 2},
      {4, 4, 4, 0}};

  int result = memcmp(new_gameboard, test_gameboard, 16);

  TEST_ASSERT_EQUAL(0, result);

}

void test_raw_move_left(void)
{
  int new_gameboard[4][4] = {
      {2, 0, 2, 0},
      {0, 0, 8, 8},
      {2, 0, 0, 0},
      {0, 4, 4, 4}};

  raw_move_left(new_gameboard);
  //print_gameboard();

  int test_gameboard[4][4] = {
      {4, 0, 0, 0},
      {16, 0, 0, 0},
      {2, 0, 0, 0},
      {8, 4, 0, 0}};

  int result = memcmp(new_gameboard, test_gameboard, 16);

  TEST_ASSERT_EQUAL(0, result);
}

void test_move_left(void)
{
  int new_gameboard[4][4] = {
      {2, 0, 2, 0},
      {0, 0, 8, 8},
      {2, 0, 0, 0},
      {0, 4, 4, 4}};

  move_left(new_gameboard);
  //print_gameboard();

  int test_gameboard[4][4] = {
      {4, 0, 0, 0},
      {16, 0, 0, 0},
      {2, 0, 0, 0},
      {8, 4, 0, 0}};

  int result = memcmp(new_gameboard, test_gameboard, 16);

  TEST_ASSERT_EQUAL(0, result);
}

void test_move_up(void)
{
  int new_gameboard[4][4] = {
      {2, 0, 2, 0},
      {0, 0, 8, 8},
      {2, 0, 0, 0},
      {0, 4, 4, 4}};

  move_up(new_gameboard);
  //print_gameboard();

  int test_gameboard[4][4] = {
      {4, 4, 2, 8},
      {0, 0, 8, 4},
      {0, 0, 4, 0},
      {0, 0, 0, 0}};

  int result = memcmp(new_gameboard, test_gameboard, 16);

  TEST_ASSERT_EQUAL(0, result);
}

void test_move_right(void)
{
  int new_gameboard[4][4] = {
      {2, 0, 2, 0},
      {0, 0, 8, 8},
      {2, 0, 0, 0},
      {0, 4, 4, 4}};

  move_right(new_gameboard);
  //print_gameboard();

  int test_gameboard[4][4] = {
      {0, 0, 0, 4},
      {0, 0, 0, 16},
      {0, 0, 0, 2},
      {0, 0, 4, 8}};

  int result = memcmp(new_gameboard, test_gameboard, 16);

  TEST_ASSERT_EQUAL(0, result);
}

void test_move_down(void)
{
  int new_gameboard[4][4] = {
      {2, 0, 2, 4},
      {0, 0, 8, 4},
      {2, 0, 0, 0},
      {0, 4, 4, 4}};

  move_down(new_gameboard);
  //print_gameboard();

  int test_gameboard[4][4] = {
      {0, 0, 0, 0},
      {0, 0, 2, 0},
      {0, 0, 8, 4},
      {4, 4, 4, 8}};

  int result = memcmp(new_gameboard, test_gameboard, 16);

  TEST_ASSERT_EQUAL(0, result);
}

void test_pick_random_tile(void)
{
  int new_gameboard[4][4] = {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0}};

  pick_random_tile(new_gameboard);
  //print_gameboard(new_gameboard);

  int result = 0;
  for(int j = 0; j < 4; j++)
  {
    for(int i = 0; i < 4; i++)
    {
      if(new_gameboard[j][i] == 2 || new_gameboard[j][i] == 4)
      {
        result = 1;
        //print_gameboard(new_gameboard);

        break;
      }
    }

    
  }
  TEST_ASSERT_EQUAL(1, result);

}