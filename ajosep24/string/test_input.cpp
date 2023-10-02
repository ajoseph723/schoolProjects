// bigint Test Program
//
// Tests:  << and >>, uses String
#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
    // Test
    String a;
    std::cout << std::endl
              << "input abc: ";
    std::cin >> a;
    assert(a == "abc");
    std::cout << a << std::endl;

    std::cout << "Done testing input/output." << std::endl;
    return 0;
}