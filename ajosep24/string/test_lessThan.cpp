// bigint Test Program
//
// Tests:  <, uses ==
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{

    // Test
    String a("abc");
    String b("abcd");
    String c('a');

    // Verify
    // testing String < char[]
    assert(a < "abcd");
    // testing String < String
    assert(a < b);
    // testing String < char
    assert(c < 'b');

    std::cout << "Done testing <." << std::endl;
    return 0;
}