#include <ConsoleDisplay.h>

const std::string LED_STRIP = "TIZUPERCCELTOONAVPTLUMHATNEGYKORAZITOMORAHIWNYOLCEGYHETUOTTEKNEZITFELGKILENCSOAVLUMACREPHAROMNEGYEDCZITOLTSOMB";

void ConsoleDisplay::show(LightSegment seg) {
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

void ConsoleDisplay::setNextColor() {}
void ConsoleDisplay::clear() {
    content = "";
}
void ConsoleDisplay::show() {
    std::cout << content << std::endl;
}

const std::string ConsoleDisplay::getContent() {
    return content;
}