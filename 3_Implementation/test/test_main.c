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
  
  int exp[4][5]={{1,1,1,3,0},{0,1,2,3,0},{0,2,3,3,1},{0,1,3,4,0}};
  
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int *actual1 = test_move(1, 'r','l' );//To ckeck for movement of probes to the roght
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][0],actual1[0],"move1-1");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][1],actual1[1],"move1-2");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][2],actual1[2],"move1-3");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][3],actual1[3],"move1-4");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][4],actual1[4],"move1-5");
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int *actual2 = test_move(1, 'q','l' );//To check for boundry condition working correctly
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][0],actual2[0],"move1-6");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][1],actual2[1],"move1-7");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][2],actual2[2],"move1-8");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][3],actual2[3],"move1-9");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][4],actual2[4],"move1-10");
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int *actual3 = test_move(1, 'w','l' );//To check for user failed
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][0],actual3[0],"move1-11");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][1],actual3[1],"move1-12");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][2],actual3[2],"move1-13");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][3],actual3[3],"move1-14");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][4],actual3[4],"move1-15");
  
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int *actual4 = test_move(1, 'e','j' );//probe movement up and down
  TEST_ASSERT_EQUAL_INT8_ARRAY_MESSAGE(exp[3],actual4,5,"probe apart test");
}

void test_move2(void) {
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int exp[4][5]={{1,1,4,4,0},{0,1,5,4,1},{0,2,6,4,1},{0,1,3,4,0}};
  int *actual1 = test_move(1, 'r','l' );
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][0],actual1[0],"move2-1");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][1],actual1[1],"move2-2");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][2],actual1[2],"move2-3");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][3],actual1[3],"move2-4");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][4],actual1[4],"move2-5");
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int *actual2 = test_move(1, 'q','l' );
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][0],actual2[0],"move2-6");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][1],actual2[1],"move2-7");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][2],actual2[2],"move2-8");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][3],actual2[3],"move2-9");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][4],actual2[4],"move2-10");
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int *actual3 = test_move(1, 'w','l' );
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][0],actual3[0],"move2-11");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][1],actual3[1],"move2-12");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][2],actual3[2],"move2-13");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][3],actual3[3],"move2-14");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][4],actual3[4],"move2-15");
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int *actual4 = test_move(1, 'e','j' );//probe movement up and down
  TEST_ASSERT_EQUAL_INT8_ARRAY_MESSAGE(exp[3],actual4,5,"probe apart test");
}

void test_move3(void) {
  int exp[4][5]={{1,1,7,5,1},{0,1,8,5,1},{0,2,9,5,1},{0,1,3,4,0}};
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int *actual1 = test_move(1, 'r','l' );
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][0],actual1[0],"move3-1");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][1],actual1[1],"move3-2");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][2],actual1[2],"move3-3");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][3],actual1[3],"move3-4");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[0][4],actual1[4],"move3-5");
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int *actual2 = test_move(1, 'q','l' );
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][0],actual2[0],"move3-6");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][1],actual2[1],"move3-7");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][2],actual2[2],"move3-8");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][3],actual2[3],"move3-9");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[1][4],actual2[4],"move3-10");
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int *actual3 = test_move(1, 'w','l' );
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][0],actual3[0],"move3-11");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][1],actual3[1],"move3-12");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][2],actual3[2],"move3-13");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][3],actual3[3],"move3-14");
  TEST_ASSERT_EQUAL_INT8_MESSAGE(exp[2][4],actual3[4],"move3-15");
  result[0] =  0;
  result[1] =  0;
  result[2] =  0;
  result[3] =  0;
  result[4] =  0;
  int *actual4 = test_move(1, 'e','j' );//probe movement up and down
  TEST_ASSERT_EQUAL_INT8_ARRAY_MESSAGE(exp[3],actual4,5,"probe apart test");
}