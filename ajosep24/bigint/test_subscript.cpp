// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main()
{

    {
        // Setup
        bigint bi(4);

        // Test
        int digit = bi[0];

        // Verify
        assert(bi == 4); // Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }

    // Add test cases!!
    {
        // testing past the first digit
        bigint bi(12);

        int digit = bi[1];
        assert(digit == 1);
    }

    {
        // testing middle of number
        bigint bi(123);

        int digit = bi[1];

        assert(digit == 2);
    }
    std::cout << "Done testing subscript." << std::endl;
    return 0;
}
