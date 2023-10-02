// bigint Test Program
//
// Tests:  character constructor, uses ==
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    // Test
    String a('a');

    // Verify
    assert(a == "a");

    std::cout << "Done testing character constructor." << std::endl;
    return 0;
}