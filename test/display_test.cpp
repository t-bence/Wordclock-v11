#include <string>
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

    TEST_ASSERT_EQUAL_STRING("MOST TIZENKETTO ORA VAN", testDisplay.getContent().c_str());
}

int runUnityTests(void) {
  UNITY_BEGIN();
  RUN_TEST(test_test_display);
  RUN_TEST(midnight_test);
  return UNITY_END();
}

int main(void) {
  return runUnityTests();
}