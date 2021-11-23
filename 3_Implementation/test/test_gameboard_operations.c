#include "unity.h"
#include <gameboard_operations.h>

/* Modify these two lines according to the project */
#include <gameboard_operations.h>
#define PROJECT_NAME "2048"

/* Prototypes for all the test functions */
void test_add(void);
void test_subtract(void);
void test_multiply(void);
void test_divide(void);

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
  //RUN_TEST(test_subtract);
  //RUN_TEST(test_multiply);
  //RUN_TEST(test_divide);

  /* Close the Unity Test Framework */
  return UNITY_END();
}



/* Write all the test functions */
void test_setup_gameboard(void)
{
  setup_gameboard();

  int test_gameboard[4][4] = {
      {00, 00, 00, 00},
      {00, 00, 00, 00}, 
      {00, 00, 00, 00},
      {00, 00, 00, 00}};

  TEST_ASSERT_EQUAL(test_gameboard, gameboard);

/* Dummy fail*/
//TEST_ASSERT_EQUAL(15000, add(7500, 7500));
}

/*
void test_slam_left(void)
{
  gameboard = {
      {2, 0, 2, 0},
      {0, 0, 0, 8},
      {2, 0, 0, 0},
      {0, 0, 2, 4}};
  TEST_ASSERT_EQUAL(-3, subtract(0, 3));


  //TEST_ASSERT_EQUAL(100, subtract(1000, 900));
}

void test_multiply(void)
{
  TEST_ASSERT_EQUAL(0, multiply(1, 0));

  
  TEST_ASSERT_EQUAL(10, multiply(2, 5));
}

void test_divide(void)
{
  TEST_ASSERT_EQUAL(0, divide(1, 0));


  TEST_ASSERT_EQUAL(1, divide(2, 2));
}
*/