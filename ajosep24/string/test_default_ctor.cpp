// bigint Test Program
//
// Tests:  default constructor, uses ==
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    // Test
    String a;

    // Verify
    assert(a == "");

    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}