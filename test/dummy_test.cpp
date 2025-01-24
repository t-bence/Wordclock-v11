#include "unity.h"
//#include <WordclockWords.h>

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void dummy_test(void) {
  TEST_ASSERT_EQUAL(4, 2 + 2);
}


int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(dummy_test);
  return UNITY_END();
}


int main(void) {
  return runUnityTests();
}