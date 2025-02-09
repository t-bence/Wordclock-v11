#include "unity.h"
#include <ConsoleDisplay.h>
#include <Writer.h>
#include <WordclockWords.h>


// this function checks if the test display works
void test_test_display(void) {
    LightSegment seg = {0, 3};
    ConsoleDisplay testDisplay;

    testDisplay.show(seg);
    TEST_ASSERT_EQUAL_STRING("TIZ", testDisplay.getContent().c_str());

}

void midnight_test(void) {
    ConsoleDisplay testDisplay;
    Writer writer(testDisplay);

    writer.updateTime(60 * (12 * 60));

    TEST_ASSERT_EQUAL_STRING("MOST ORA VAN TIZENKETTO", testDisplay.getContent().c_str());
}

void half_past_four_test(void) {
    ConsoleDisplay testDisplay;
    Writer writer(testDisplay);

    writer.updateTime(60 * (30 + 60 * 4));

    TEST_ASSERT_EQUAL_STRING("MOST FEL VAN OT", testDisplay.getContent().c_str());
}

int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_test_display);
  RUN_TEST(midnight_test);
  RUN_TEST(half_past_four_test);
  return UNITY_END();
}

int main(void) {
  return runUnityTests();
}