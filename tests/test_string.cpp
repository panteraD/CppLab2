#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "String.h"

//unsigned int Factorial( unsigned int number ) {
//    return number <= 1 ? number : Factorial(number-1)*number;
//}

//
//lets start test
//void cmp_string(const String &lhs, const String &rhs) {
//    assert(lhs.size()==rhs.size());
//    for (std::size_t i = 0; i < lhs.size(); ++i) {
//        REQUIRE(lhs[i] == rhs[i]);
//    }
//}

TEST_CASE( "TEST 1" ) {
    String s;
    REQUIRE(*(s.data()) == '\0');
    REQUIRE(s.size()==0);
}
