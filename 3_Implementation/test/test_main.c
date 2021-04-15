#include"test_game.h"
#include"unity_internals.h"
#include"unity.h"

void test_move1(void);
void test_move2(void);
void test_move3(void);
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_move1);
  RUN_TEST(test_move2);
  RUN_TEST(test_move3);
  
  /* Close the Unity Test Framework */
  return UNITY_END();
}

//result[0] -> up probe x position
//result[1] -> up probe y position
//result[2] -> down probe x position
//result[3] -> down probe y position
//result[4] -> status indicator
//status 1->fail 2->won 3->in progress 4->index out of range

void test_move1(void) {
  int exp[3][5]={{1,1,1,3,3},{0,0,0,0,4},{0,0,0,0,1}};
  int *actual1 = test_move(1, 'r','l' );
  int *actual2 = test_move(1, 'q','l' );
  int *actual3 = test_move(1, 'w','l' );
  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(exp[0], actual1, 5, "move1-1");
  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(exp[1], actual2, 5, "move1-2");
  TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(exp[3], actual3, 5, "move1-3");
}
void test_move2(void) {
  int exp[3][5]={{1,1,0,4,3},{0,0,0,0,4},{0,0,0,0,1}};
  int *actual1 = test_move(2, 'r','j' );
  int *actual2 = test_move(2, 'q','l' );
  int *actual3 = test_move(2, 'r','l' );
  TEST_ASSERT_EQUAL_INT_ARRAY(exp[0], actual1, 5);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp[1], actual2, 5);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp[3], actual3, 5);
}
void test_move3(void) {
  int exp[3][5]={{1,1,1,3,3},{0,0,0,0,4},{0,0,0,0,1}};
  int *actual1 = test_move(3, 'r','j' );
  int *actual2 = test_move(3, 'q','l' );
  int *actual3 = test_move(3, 'r','l' );
  TEST_ASSERT_EQUAL_INT_ARRAY(exp[0], actual1, 5);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp[1], actual2, 5);
  TEST_ASSERT_EQUAL_INT_ARRAY(exp[3], actual3, 5);
}