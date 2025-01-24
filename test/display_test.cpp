#include <string>
#include <algorithm>
#include "unity.h"
#include <Display.h>
#include <Writer.h>
#include <WordclockWords.h>

#define HUNGARIAN
#define LEFT_TO_RIGHT

const std::string LED_STRIP = "TIZUPERCCELTOONAVPTLUMHATNEGYKORAZITOMORAHIWNYOLCEGYHETUOTTEKNEZITFELGKILENCSOAVLUMACREPHAROMNEGYEDCZITOLTSOMB";

class TestDisplay : public Display {
    std::string content;

public:
    void show(LightSegment seg) /*override*/ {
        if (!content.empty()) { // add a space before the new word
            content.append(" ");
        }
        std::string addition = LED_STRIP.substr(seg.start, seg.length);

        /*
        Because the matrix is built up from one long LED strand,
        in odd rows, we have to reverse the string, as indices follow
        the LEDs' order and not the words' order.

        Also, because of the algorythm, the hour number is always shown last.
        */

        const int ROW_LENGTH {11};
        int row = seg.start / ROW_LENGTH;
        
        if (row % 2 == 1) {
            std::reverse(addition.begin(), addition.end()); // need to reverse the string
        }
        
        content.append(addition);
    }

    const std::string getContent() const {
        return content;
    }
};

void setUp(void) {
  // set stuff up here
  initializeSegments();
}

void tearDown(void) {
  // clean stuff up here
}

// this function checks if the test display works
void test_test_display(void) {
    LightSegment seg = {0, 3};
    TestDisplay testDisplay;

    testDisplay.show(seg);
    TEST_ASSERT_EQUAL_STRING("TIZ", testDisplay.getContent().c_str());

}

void midnight_test(void) {
    TestDisplay testDisplay;
    Writer writer(testDisplay);

    writer.showTime(12, 0);

    TEST_ASSERT_EQUAL_STRING("MOST ORA VAN TIZENKETTO", testDisplay.getContent().c_str());
}

void half_past_four_test(void) {
    TestDisplay testDisplay;
    Writer writer(testDisplay);

    writer.showTime(16, 30);

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