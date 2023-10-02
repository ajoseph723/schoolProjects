// bigint Test Program
//
// Tests:  ==, uses String
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{

    // Test
    String a("abc");
    String b("abc");
    String c('a');

    // Verify
    // testing String == char[]
    assert(a == "abc");
    // testing String == String
    assert(a == b);
    // testing String == char
    assert(c == 'a');

    std::cout << "Done testing ==." << std::endl;
    return 0;
}