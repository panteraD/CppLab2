#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "String.h"

//unsigned int Factorial( unsigned int number ) {
//    return number <= 1 ? number : Factorial(number-1)*number;
//}

//
//lets start test
void cmp_string(const String &lhs, const String &rhs) {
    assert(lhs.size()==rhs.size());
    for (std::size_t i = 0; i < lhs.size(); ++i) {
        REQUIRE(lhs[i] == rhs[i]);
    }
}

TEST_CASE( "FUCK YOu" ) {
    String s;
    char  expected[] = "";
    cmp_string(s, expected);

}
